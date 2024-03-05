#include <lcom/lcf.h>
#include <lcom/timer.h>
#include <stdint.h>
#include "i8254.h"
int hook_id = 0;
int counter = 0;
int (timer_set_frequency)(uint8_t timer, uint32_t freq) { 
  if (freq > TIMER_FREQ || freq < 19 || timer > 2 || timer < 0) return 1;
  uint8_t status;
  if(timer_get_conf(timer,&status)!=0)return 1;
  status = status & 0x0F;
  uint16_t initial_count = TIMER_FREQ / freq;
  uint8_t lsb ,msb;
  if(util_get_LSB(initial_count,&lsb)!=0 )return 1;
  if(util_get_MSB(initial_count,&msb)!=0)return 1;
  uint8_t selectedtimer = 0;
  status = status | TIMER_LSB_MSB ;
  switch (timer)
  {
  case 0:
    selectedtimer = 0;
    status = status|TIMER_SEL0;
    break;
  case 1:
    selectedtimer = 1;
    status = status|TIMER_SEL1;
  case 2:
    selectedtimer = 2;
    status = status|TIMER_SEL2; 
  default:
    return 1;
  }
  if(sys_outb(TIMER_CTRL,status)!=0)return 1;
  if(sys_outb(selectedtimer,lsb))return 1;
  if(sys_outb(selectedtimer,msb))return 1;
  return 0;
}

int (timer_subscribe_int)(uint8_t *bit_no) {
  if(bit_no == NULL)return 1;
  *bit_no = BIT(hook_id);
  return sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, &hook_id);
}

int (timer_unsubscribe_int)() {
  return sys_irqrmpolicy(&hook_id);
}

void (timer_int_handler)() {
  counter++;
}

int (timer_get_conf)(uint8_t timer, uint8_t *st) {
  if(st == NULL || timer > 2 || timer < 0)return 1;
  uint8_t readbackcommad = (TIMER_RB_CMD|TIMER_RB_COUNT_|TIMER_RB_SEL(timer));
  if(sys_outb(TIMER_CTRL,readbackcommad)!=0)return 1;
  if(util_sys_inb(TIMER_0+timer,st)!=0)return 1;
  return 0;
}

int (timer_display_conf)(uint8_t timer, uint8_t st,enum timer_status_field field) {
  union timer_status_field_val data;//  The of theread back status 6 LSBs match those of the Control Word
  switch(field){
    case(tsf_all):
      data.byte = st;
      break;
    case(tsf_initial):
      st = (st >> 4) & 0x03;
      if(st == 1) data.in_mode = LSB_only;
      if(st == 2) data.in_mode = MSB_only;
      if(st == 3) data.in_mode = MSB_after_LSB;
      else data.in_mode = INVAL_val;
      break;
    case(tsf_mode):
      st = (st >> 1) & 0x07;
      if(st == 6) data.count_mode = 2;
      if(st == 7)data.count_mode = 3;
      else(data.count_mode = st);
      break;
    case(tsf_base):
      st= st & 0x01;
      data.bcd = st;
      break;
    default:
      return 1;  
  }
  if(timer_print_config(timer,field,data)!=0)return 1;
  return 0;
}
