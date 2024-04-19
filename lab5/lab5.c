// IMPORTANT: you must include the following line in all your C files
#include <lcom/lcf.h>

#include <lcom/lab5.h>

#include <stdint.h>
#include <stdio.h>
#include "graphic.h"
#include "timer.h"
#include "keyboard.h"
extern vbe_mode_info_t modeInfo ;
extern uint8_t* frame_buffer;
extern uint8_t scancode;
// Any header files included below this line should have been created by you

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab5/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab5/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int(video_test_init)(uint16_t mode, uint8_t delay) {
  if(set_graphic_mode(mode)!=0)return 1;
  sleep(delay);
  return  vg_exit();
}

int(video_test_rectangle)(uint16_t mode, uint16_t x, uint16_t y,
                          uint16_t width, uint16_t height, uint32_t color) {
    if(set_frame_buffer(mode)!=0)return 1;
    if(set_graphic_mode(mode)!=0)return 1;
    uint32_t new_color;
    if (normalize_color(color, &new_color) != 0) return 1;
    if(vg_draw_rectangle(x,y,width,height,new_color)!=0)return 1;
    if(waiting_ESC_key()!=0)return 1;
    return vg_exit();
}

int(video_test_pattern)(uint16_t mode, uint8_t no_rectangles, uint32_t first, uint8_t step) {
    if(set_frame_buffer(mode)!=0)return 1;
    if(set_graphic_mode(mode)!=0)return 1;
    int vertical = modeInfo.YResolution / no_rectangles;
    int horizontal = modeInfo.XResolution / no_rectangles;
    for(int i = 0; i < no_rectangles;i++){
        for(int j = 0; j < no_rectangles;j++){
            uint32_t color;
            if(modeInfo.MemoryModel == DIRECT_COLOR){
                uint32_t R = Red(j, step, first);
                uint32_t G = Green(i, step, first);
                uint32_t B = Blue(j, i, step, first);
                color = direct_mode(R, G, B);
            }
            else{
                color = indexed_mode(j, i, step, first, no_rectangles);
            }
            if(vg_draw_rectangle(j*horizontal,i*vertical,horizontal,vertical,color)!=0)return 1;
        }
    }
    if(waiting_ESC_key()!=0)return 1;
    return vg_exit();
}

int(video_test_xpm)(xpm_map_t xpm, uint16_t x, uint16_t y) {
    if(set_frame_buffer(0x105)!=0)return 1;
    if(set_graphic_mode(0x105)!=0)return 1;
    if(print_xpm(xpm,x,y)!=0)return 1;
    if(waiting_ESC_key()!=0)return 1;
    return vg_exit();
}

int(video_test_move)(xpm_map_t xpm, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf,
                     int16_t speed, uint8_t fr_rate) {
    int ipc_status,r;
    uint8_t irq_set,irq_set_timer;
    message msg;
    if(timer_subscribe_int(&irq_set_timer)!=0)return 1;
    if(keyboard_subscribe_interrupts(&irq_set)!=0)return 1;
    if(timer_set_frequency(0,fr_rate)!=0)return 1;
    if(set_frame_buffer(0x105)!=0)return 1;
    if(set_graphic_mode(0x105)!=0)return 1;
    bool direction; // if direction = 0 horizontal, direction = 1 vertical
    if(xi == xf)direction = 1;
    else if(yi == yf)direction = 0;
    if(print_xpm(xpm,xi,yi)!=0)return 1;
    while(scancode != BRK_ESC ) { /* You may want to use a different condition */
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
                    }
                    if(msg.m_notify.interrupts & irq_set_timer){
                        if(direction){
                            yi+= speed;
                            if(yi > yf)yi = yf;
                        }
                        else{
                            xi+= speed;
                            if(xi > xf)xi = xf;
                        }
                        if(print_xpm(xpm,xi,yi)!=0)return 1;
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
    return vg_exit();
}

int(video_test_controller)() {
  /* To be completed */
  printf("%s(): under construction\n", __func__);

  return 1;
}
