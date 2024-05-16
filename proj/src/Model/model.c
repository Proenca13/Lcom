#include "model.h"

Sprite *start_button_sprite;
Sprite *start_button2_sprite;
Sprite *cursor_mouse;
Sprite *controls_button_sprite;
Sprite *controls_button2_sprite;
Sprite *exit_button_sprite;
Sprite *exit_button2_sprite;
Sprite *title_sprite;
Sprite *control_title_sprite;
Sprite *paused_title_sprite;
Sprite *dirt_block;
Sprite *arrows_sprite;
Sprite *day_sky_sprite;
Sprite *night_sky_sprite;
Sprite *afternoon_sky_sprite;
Sprite *dyog_sprite;
Sprite *dyog2_sprite;
Sprite *continue_button_sprite;
Sprite *continue_button2_sprite;
Sprite *right_click_sprite;
Sprite *left_click_sprite;
Sprite *esc_sprite;
Sprite *f_sprite;
Sprite *space_sprite;
Sprite *grass_sprite;
Sprite *selected_grass_sprite;
Sprite *tnt_sprite;

void create_sprites(){
    start_button_sprite = create_sprite((xpm_map_t)start_button_xpm);
    arrows_sprite = create_sprite((xpm_map_t)arrows_xpm);
    start_button2_sprite = create_sprite((xpm_map_t)start_button2_xpm);
    cursor_mouse = create_sprite((xpm_map_t)cursor_xpm);
    controls_button_sprite = create_sprite((xpm_map_t)Controls_button);
    controls_button2_sprite = create_sprite((xpm_map_t)Controls_button2);
    exit_button_sprite = create_sprite((xpm_map_t)Exit);
    exit_button2_sprite = create_sprite((xpm_map_t)Exit2);
    title_sprite = create_sprite((xpm_map_t)Title_xpm);
    control_title_sprite = create_sprite((xpm_map_t)Controls_Title);
    paused_title_sprite = create_sprite((xpm_map_t)paused);
    dirt_block = create_sprite((xpm_map_t)Dirt_block);
    day_sky_sprite = create_sprite((xpm_map_t)Day_sky);
    night_sky_sprite = create_sprite((xpm_map_t)Night_sky);
    afternoon_sky_sprite = create_sprite((xpm_map_t)Afternoon_Sky);
    dyog_sprite = create_sprite((xpm_map_t)dyog);
    dyog2_sprite =  create_sprite((xpm_map_t)dyog2);
    continue_button_sprite = create_sprite((xpm_map_t)continue_button_xpm);
    continue_button2_sprite = create_sprite((xpm_map_t)continue_button2_xpm);
    right_click_sprite = create_sprite((xpm_map_t)Right_click);
    left_click_sprite = create_sprite((xpm_map_t)Left_click);
    esc_sprite = create_sprite((xpm_map_t)ESC);
    f_sprite = create_sprite((xpm_map_t)F);
    space_sprite = create_sprite((xpm_map_t)space);
    grass_sprite = create_sprite((xpm_map_t)grass_xpm);
    selected_grass_sprite = create_sprite((xpm_map_t)selectedgrass_xpm);
    tnt_sprite = create_sprite((xpm_map_t)tnt_xpm);
}

void destroy_sprites(){
    destroy_sprite(start_button_sprite);
    destroy_sprite(start_button2_sprite);
    destroy_sprite(controls_button_sprite);
    destroy_sprite(controls_button2_sprite);
    destroy_sprite(exit_button_sprite);
    destroy_sprite(exit_button2_sprite);
    destroy_sprite(title_sprite);
    destroy_sprite(control_title_sprite);
    destroy_sprite(paused_title_sprite);
    destroy_sprite(dirt_block);
    destroy_sprite(arrows_sprite);
    destroy_sprite(cursor_mouse);
    destroy_sprite(day_sky_sprite);
    destroy_sprite(night_sky_sprite);
    destroy_sprite(afternoon_sky_sprite);
    destroy_sprite(dyog_sprite);
    destroy_sprite(dyog2_sprite);
    destroy_sprite(continue_button_sprite);
    destroy_sprite(continue_button2_sprite);
    destroy_sprite(right_click_sprite);
    destroy_sprite(left_click_sprite);
    destroy_sprite(esc_sprite);
    destroy_sprite(f_sprite);
    destroy_sprite(space_sprite);
    destroy_sprite(grass_sprite);
    destroy_sprite(selected_grass_sprite);
    destroy_sprite(tnt_sprite);
}

