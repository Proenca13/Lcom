//
// Created by joao on 14-04-2024.
//
#include <lcom/lcf.h>
#include "graphic.h"
int (set_graphic_mode)(uint16_t mode){
    reg86_t r;
    memset(&r ,0, sizeof(r));
    r.ax = 0x4F02; // VBE call, function 02 -- set VBE mode
    r.bx = BIT(14)|mode; // set bit 14: linear framebuffer
    r.intno = VBE;
    if( sys_int86(&r) != 0 ) {
        printf("set_vbe_mode: sys_int86() failed \n");
        return 1;
    }
    return 0;
}
