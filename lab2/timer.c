#include <lcom/lcf.h>
#include <lcom/timer.h>

#include <stdint.h>

#include "i8254.h"

int hook_id = 0;
int counter = 0;

int (timer_set_frequency)(uint8_t timer, uint32_t freq) {
  if (freq > TIMER_FREQ || freq < 19 || timer < 0 || timer > 2) return 1; // validar input
  uint8_t controlWord;
  if (timer_get_conf(timer, &controlWord) != 0) return 1; // consultar a config atual do timer

  controlWord = (controlWord & 0x0F) | TIMER_LSB_MSB;
  /* 
  * Make sure that you do not change the 4 least significant bits (i.e. the counting mode and BCD vs. binary couting) 
  * of the control world, because that may change the timer's operating mode. (This requires you to read the input timer 
  * configuration before you change it.)
  */

  uint32_t initialValue = TIMER_FREQ / freq;
  uint8_t MSB, LSB;

  util_get_MSB(initialValue, &MSB);
  util_get_LSB(initialValue, &LSB);

  uint8_t selectedTimer;      

  switch (timer) {  
    case 0: 
        controlWord |= TIMER_SEL0;
        selectedTimer = TIMER_0;
      break;

    case 1:
        controlWord |= TIMER_SEL1;
        selectedTimer = TIMER_1;
      break;

    case 2:
        controlWord |= TIMER_SEL2;
        selectedTimer = TIMER_2;
      break;

    default:
      return 1;
  }

  if(sys_outb(TIMER_CTRL, controlWord) != 0) return 1;
  if (sys_outb(selectedTimer, LSB) != 0) return 1;
  if (sys_outb(selectedTimer, MSB) != 0) return 1;

  return 0;
}

int (timer_subscribe_int)(uint8_t *bit_no) { // liga a interrupção
  if (bit_no == NULL) return 1;

  *bit_no = BIT(hook_id);
  return sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, &hook_id);
}

int (timer_unsubscribe_int)() { // desliga a interrupção
  if(sys_irqrmpolicy(&hook_id) != 0) return 1;
  return 0;
}

void (timer_int_handler)() {
  counter++;
}

int (timer_get_conf)(uint8_t timer, uint8_t *st) {
  if (st == NULL || timer < 0 || timer > 2) return 1; // validar os inputs: //-> st != NULL //-> timer E {0,1,2}

  uint8_t ReadBackCommand = (TIMER_RB_CMD  | TIMER_RB_COUNT_ | TIMER_RB_SEL(timer)); // constroi o rbc

  if(sys_outb(TIMER_CTRL, ReadBackCommand) != 0) return 1; // avisa o hardware que vamos ler a configuração
  if(util_sys_inb(TIMER_0 + timer, st)) return 1; // lemos a configuração diretamente do registo e colocamo-la em st

  return 0;
}

/** 
 * union timer_status_field_val {
 *  uint8_t byte;              /*!< status 
 *  enum timer_init in_mode;   /*!< initialization mode 
 *  uint8_t count_mode;        /*!< counting mode: 0, 1,.., 5 
 *  bool bcd;                  /*!< counting base, true if BCD 
 * };
**/

/**
 * enum timer_status_field {
 *  tsf_all,      /*!< configuration/status 
 *  tsf_initial,  /*!< timer initialization mode 
 *  tsf_mode,     /*!< timer counting mode 
 *  tsf_base      /*!< timer counting base 
 * };
**/

int (timer_display_conf)(uint8_t timer, uint8_t st, enum timer_status_field field) {
  
  union timer_status_field_val data;

  switch (field) {
    case tsf_all:
      data.byte = st;

    case tsf_initial:
      st = (st >> 4) & 0x3; // é o mesmo que fazer & 0011;

      if (st == 1) data.in_mode = LSB_only;
      if (st == 2) data.in_mode = MSB_only;
      if (st == 3) data.in_mode = MSB_after_LSB;
      else data.in_mode = INVAL_val; // INVALID value

      break;

    case tsf_mode:
      st = (st >> 4) & 0x7; // é o mesmo que fazer & 0111; os valores variam entre 000 e 101

      if (st == 6) data.count_mode = 2;
      if (st == 7) data.count_mode = 3;
      else data.count_mode = st;
      break;

    case tsf_base:
      data.bcd = st & 0x1;
      break;        

    default:
      return 1;
  }

  if (timer_print_config(timer, field, data) != 0) return 1;

  return 0;
}
