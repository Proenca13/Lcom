#include <lcom/lcf.h>

#include <lcom/lab3.h>
#include <keyboard.h>
#include <stdbool.h>
#include <stdint.h>

extern uint8_t scancode;
extern int counter_timer;
extern uint32_t counter;

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab3/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab3/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int(kbd_test_scan)() {
int ipc_status,r;
uint8_t irq_set;
message msg;
if(keyboard_subscribe_interrupts(&irq_set)!=0)return 1;
while(scancode != BRK_ESC) { /* You may want to use a different condition */
    /* Get a request message. */
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0) { 
        printf("driver_receive failed with: %d", r);
        continue;
    }
    if (is_ipc_notify(ipc_status)) { /* received notification */
        switch (_ENDPOINT_P(msg.m_source)) {
            case HARDWARE: /* hardware interrupt notification */				
                if (msg.m_notify.interrupts & irq_set) { /* subscribed interrupt */
                  kbc_ih();
                  if(kbd_print_scancode(!(scancode & BIT(7)),scancode == TWO_BYTE_SCANCODE ? 2: 1, &scancode)!=0)return 1;
                }
                break;
            default:
                break; /* no other notifications expected: do nothing */	
        }
    } else { /* received a standard message, not a notification */
        /* no standard messages expected: do nothing */
    }
}
if(keyboard_unsubscribe_interrupts()!=0)return 1;
if(kbd_print_no_sysinb(counter)!=0)return 1;
return 0;
}

int(kbd_test_poll)() {
  while (scancode != BRK_ESC)
  {
    if(read_KBC_output(KBC_OUT_BUF,&scancode,0)==0){
      if(kbd_print_scancode(!(scancode & BIT(7)),scancode == TWO_BYTE_SCANCODE ? 2: 1, &scancode)!=0)return 1;  
    }
  }
  if(kbd_print_no_sysinb(counter)!=0)return 1;
  return keyboard_restore();
}

int(kbd_test_timed_scan)(uint8_t n) {
int ipc_status,r;
uint8_t irq_set ,irq_set_timer;
message msg;
int time  = 0;
if(timer_subscribe_int(&irq_set_timer)!=0)return 1;
if(keyboard_subscribe_interrupts(&irq_set)!=0)return 1;
while(scancode != BRK_ESC && time < n) { /* You may want to use a different condition */
    /* Get a request message. */
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0) { 
        printf("driver_receive failed with: %d", r);
        continue;
    }
    if (is_ipc_notify(ipc_status)) { /* received notification */
        switch (_ENDPOINT_P(msg.m_source)) {
            case HARDWARE: /* hardware interrupt notification */				
                if (msg.m_notify.interrupts & irq_set) { /* subscribed interrupt */
                  kbc_ih();
                  if(kbd_print_scancode(!(scancode & BIT(7)),scancode == TWO_BYTE_SCANCODE ? 2: 1, &scancode)!=0)return 1;
                  time = 0;
                  counter_timer = 0;
                }
                if (msg.m_notify.interrupts & irq_set_timer){
                  timer_int_handler();
                  if(counter_timer %60 == 0){
                    time++;
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
if(keyboard_unsubscribe_interrupts()!=0)return 1;
if(timer_unsubscribe_int()!=0)return 1;
return 0;
}
