#include <lcom/lcf.h>

#include <stdint.h>
uint32_t counter = 0;
int(util_get_LSB)(uint16_t val, uint8_t *lsb) {
  if(lsb == NULL){
    return 1;
  }
  *lsb = val & 0xFF;
  return 0;
}

int(util_get_MSB)(uint16_t val, uint8_t *msb) {
  if(msb == NULL){
    return 1;
  }
  *msb = val >> 8;
  return 0;
}

int (util_sys_inb)(int port, uint8_t *value) {
  if(value == NULL)return 1;
  uint32_t val = 0;
  int res = sys_inb(port,&val);
  *value = val &  0xFF ;
  counter++;
  return res;
}

