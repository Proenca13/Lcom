#include <lcom/lcf.h>
#include <stdint.h>

int(util_get_LSB)(uint16_t val, uint8_t *lsb) {
  if(lsb == NULL) return 1;

  *lsb = 0x00FF & val;

  return 0; // return 0 -> significa que a função sucedeu
}


int(util_get_MSB)(uint16_t val, uint8_t *msb) {
  if (msb == NULL) return 1;

  *msb = val >> 8;

  return 0; // return 0 -> significa que a função sucedeu
}


int (util_sys_inb)(int port, uint8_t *value) {
  if (value == NULL) return 1;

  uint32_t val;
  int ret_value = sys_inb(port, &val);

  *value = 0xFF & val;

  return ret_value;
}

/**
 * @port - registo do timer que vai receber o comando (Ox40, 0x41, 0x42, 0x43)
 * @command - comando ou valor a escrever na porta selecionada
 *
 * int sys_outb(uint8_t port, uint32_t command);
**/

/**
 * @port - porta do timer a consultar (0x40, 0x41, 0x42)
 * @value - será preenchido pelo valor lido do timer escolhido em @port
 *
 * int sys_inb(uint8_t port, uint32_t *value);
**/ 