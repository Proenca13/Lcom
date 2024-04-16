// IMPORTANT: you must include the following line in all your C files
#include <lcom/lcf.h>

#include <stdint.h>
#include <stdio.h>
#include "mouse.h"
// Any header files included below this line should have been created by you
extern uint8_t byte_counter;
extern int counter_timer ;
extern struct packet mouse_packet;
int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need/ it]
  lcf_trace_calls("/home/lcom/labs/lab4/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab4/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}


int (mouse_test_packet)(uint32_t cnt) {
    int ipc_status,r;
    uint8_t irq_set;
    message msg;
    if(mouse_write(ENABLE_DATA_REPORTING)!=0)return 1;
    if(mouse_subscribe_int(&irq_set)!=0)return 1;
    while(cnt) { /* You may want to use a different condition */
        /* Get a request message. */
        if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0) {
            printf("driver_receive failed with: %d", r);
            continue;
        }
        if (is_ipc_notify(ipc_status)) { /* received notification */
            switch (_ENDPOINT_P(msg.m_source)) {
                case HARDWARE: /* hardware interrupt notification */
                    if (msg.m_notify.interrupts & irq_set) { /* subscribed interrupt */
                        mouse_ih();
                        mouse_sync_bytes();
                        if(byte_counter == 3){
                            mouse_bytes_to_packet();
                            mouse_print_packet(&mouse_packet);
                            byte_counter = 0;
                            cnt--;
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
    if(mouse_unsubscribe_int()!=0)return 1;
    if(mouse_write(DISABLE_DATA_REPORTING)!=0)return 1;
    return 0;
}

int (mouse_test_async)(uint8_t idle_time) {
    uint8_t seconds = 0;
    int ipc_status,r;
    int timer_freq = sys_hz();
    uint8_t irq_set,irq_set_timer;
    message msg;
    if(mouse_write(ENABLE_DATA_REPORTING)!=0)return 1;
    if(mouse_subscribe_int(&irq_set)!=0)return 1;
    if(timer_subscribe_int(&irq_set_timer)!=0)return 1;
    while(seconds < idle_time) {
        if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0) {
            printf("driver_receive failed with: %d", r);
            continue;
        }
        if (is_ipc_notify(ipc_status)) {
            switch (_ENDPOINT_P(msg.m_source)) {
                case HARDWARE:
                    if (msg.m_notify.interrupts & irq_set) {
                        mouse_ih();
                        mouse_sync_bytes();

                        if(byte_counter == 3){
                            mouse_bytes_to_packet();
                            mouse_print_packet(&mouse_packet);
                            byte_counter = 0;
                        }
                        counter_timer = 0;
                        seconds = 0;
                    }
                    if(msg.m_notify.interrupts & irq_set_timer){
                        timer_int_handler();
                        if(counter_timer % timer_freq == 0){
                            seconds++;
                        }
                    }
                    break;
                default:
                    break;
            }
        } else { /* received a standard message, not a notification */
            /* no standard messages expected: do nothing */
        }
    }
    if(mouse_unsubscribe_int()!=0)return 1;
    if(timer_unsubscribe_int()!=0)return 1;
    if(mouse_write(DISABLE_DATA_REPORTING)!=0)return 1;
    return 0;
}

int (mouse_test_gesture)(uint8_t x_len, uint8_t tolerance) {
    /* To be completed */
    printf("%s: under construction\n", __func__);
    return 1;
}

int (mouse_test_remote)(uint16_t period, uint8_t cnt) {
    /* This year you need not implement this. */
    printf("%s(%u, %u): under construction\n", __func__, period, cnt);
    return 1;
}
