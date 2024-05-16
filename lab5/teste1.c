#include <lcom/lcf.h>

#include <lcom/lab5.h>

#include <stdint.h>
#include <stdio.h>
enum lpv_dir_t {
    lpv_hor, // horizontal line
    lpv_vert // vertical line
};
typedef struct {
    uint16_t x_res; // horizontal resolution
    uint16_t y_res; // vertical resolution
    uint8_t bpp; // bits per pixel
    uint8_t r_sz; // red component size
    uint8_t r_pos; // red component LSB position
    uint8_t g_sz; // green component size
    uint8_t g_pos; // green component LSB position
    uint8_t b_sz; // blue component size
    uint8_t b_pos; // blue component LSB position
    phys_addr_t phys_addr; // video ram base phys address
} lpv_mode_info_t;
int pp_test_line(uint8_t mode, enum lpv_dir_t dir, uint16_t x,uint16_t y, uint16_t len, uint32_t color, uint32_t delay){
    if(lpv_set_mode(mode)!=0)return 1;

    lpv_mode_info_t mode_info;
    if(lpv_get_mode_info(mode, &mode_info)!=0)return 1;

    uint8_t bytes_per_pixel = (mode_info.bpp +7)/8;
    uint8_t vram_size = bytes_per_pixel * mode_info.x_res*mode_info.y_res;
    uint8_t *vram = video_map_phys(mode_info.phys_addr, vram_size);

    if(mode == 0)return 0;
    else if(mode == 1)color = color;
    else {
        uint8_t red = (color >> 16)&((1<<mode_info.r_sz)-1);
        uint8_t green = ( color >> 8)&((1<< mode_info.g_sz)-1);
        uint8_t blue = color & ((1<<mode_info.b_sz)-1);
        color = red << mode_info.r_pos|blue<< mode_info.b_pos| green << mode_info.g_pos;
    }

    switch (sl_num) {
        case 0:
            for(int i  = 0; i < len; i++){
                if(x <0 || y <0 || x+i >= mode_info.x_res)continue;
                uint8_t index = (mode_info.x_res*y+(x+i))*bytes_per_pixel;
                if(memcpy(vram[index],&color , bytes_per_pixel) == NULL)return 1;
            }
            break;
        case 1:
            for(int i  = 0; i < len; i++){
                if(x <0 || y >= mode_info.y_res || x+i >= mode_info.x_res||y -i < 0)continue;
                uint8_t index = (mode_info.x_res*(y-i)+(x+i))*bytes_per_pixel;
                if(memcpy(vram[index],&color , bytes_per_pixel) == NULL)return 1;
            }
            break;
    }

    sleep(delay);
    return lpv_set_mode(0);
}
