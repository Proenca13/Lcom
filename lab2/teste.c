#include <lcom/lcf.h>
#include <lcom/lab2.h>

#include <stdbool.h>
#include <stdint.h>

#define BIT(n) (1 << n)
#define TIMER_0 0x20
#define TIMER_1 0x21
#define TIMER_2 0x22
#define CONTROL_REGISTER 0x23
#define STATUS_REGISTER 0x23
#define ALARM BIT(4)
enum l3223_time_units {
l3223_microsecond,
l3223_millisecond,
l3223_second
};
int pp_test_alarm(int timer, int interval, enum l3223_time_units unit){
  if(timer < 0 || timer > 2)return 1;
  uint8_t controlword = 0;
  switch (timer)
  {
  case 1:
    controlword = controlword | BIT(6);
    break;
  case 2:
    controlword = controlword | BIT(7);
    break;
  default:
    return 1;
    break;
  }
  controlword = controlword | ALARM;
  switch (unit)
  {
  case l3223_millisecond:
    controlword = controlword | BIT(0);
    break;
  case l3223_second:
    controlword = controlword | BIT(1);
    break;
  default:
    return 1;
    break;
  }
  if(sys_outb(CONTROL_REGISTER,controlword)!=0)return 1;
  uint8_t MSB,LSB;
  LSB = interval & 0x0F;
  MSB = interval >> 8;
  if(sys_outb(TIMER_0 +timer,LSB)!=0)return 1;
  if(sys_outb(TIMER_0 +timer,MSB)!=0)return 1;
  int hook_id = 0;
  if(sys_irqsetpolicy(10,IRQ_REENABLE,&hook_id)!=0)return 1;
  int ipc_status,r;
  message msg;

  while(true) { /* You may want to use a different condition */
      /* Get a request message. */
      if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0) { 
          printf("driver_receive failed with: %d", r);
          continue;
      }
      if (is_ipc_notify(ipc_status)) { /* received notification */
          switch (_ENDPOINT_P(msg.m_source)) {
              case HARDWARE: /* hardware interrupt notification */				
                  if (msg.m_notify.interrupts & BIT(hook_id)) { /* subscribed interrupt */
                      uint32_t status;
                      if(sys_inb(STATUS_REGISTER,&status)!=0)return 1;
                      status = status & 0xFF;
                      if(status & BIT(timer)){
                        pp_print_alarm(timer,interval,unit);
                        break;
                      }
                  }
                  break;
              default:
                  break; /* no other notifications expected: do nothing */	
          }
      } else { /* received a standard message, not a notification */
          /* no standard messages expected: do nothing */
      }
  }
  if(sys_irqrmpolicy(&hook_id)!=0)return 1;
  return 0;
}
