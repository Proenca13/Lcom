#include <lcom/lcf.h>

#include <lcom/lab5.h>

#include <stdint.h>
#include <stdio.h>

int pp_test_line(uint8_t mode, enum lpv_dir_t dir, uint16_t x,uint16_t y, uint16_t len, uint32_t color, uint32_t delay){
    if(lpv_set_mode(mode)!=0)return 1;
    lpv_mode_info_t mode_info;
    if(lpv_get_mode_info(mode, &mode_info)!=0)return 1;
    unsigned int bytes_per_pixel = (mode_info.bpp+7)/8;
    unsigned int vram_size = bytes_per_pixel * mode_info.x_res * mode_info.y_res;
    uint8_t *video_mem = video_map_phys( mode_info.phys_addr, vram_size);
    if(mode == 0)return 0;
    if(mode == 1)color = color;
    else{
        uint8_t red = color >> 16;
        uint8_t green = (color >> 8)&0xFF;
        uint8_t blue = color & 0xFF;
        color = red << mode_info.r_pos| blue << mode_info.b_pos | green << mode_info.green_pos;
    }
    switch (sl_num) {
        case 0:
            for(unsigned i = 0;i < len; i++){
                if(x+i> mode_info.x_res || y > mode_info.y_res)return 1;
                unsigned index = ((mode_info.x_res*y)+(x+i))*bytes_per_pixel;
                if(memcpy(video_mem[index],&color,bytes_per_pixel)!=0)return 1;
            }
            break;
        case 1:
            for(unsigned i = 0;i < len; i++){
                if(x> mode_info.x_res || y+i > mode_info.y_res)return 1;
                unsigned index = ((mode_info.x_res*(y-i))+x+i)*bytes_per_pixel;
                if(memcpy(video_mem[index],&color,bytes_per_pixel)!=0)return 1;
            }
            break;
        default:
            return 1;
    }
    sleep(delay);
    if(lpv_set_mode(0)!=0)return 1;
    return 0;
}