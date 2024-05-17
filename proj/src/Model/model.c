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
Sprite *play_again_button_sprite;
Sprite *play_again_button2_sprite;
Sprite *restart_button_sprite;
Sprite *restart_button2_sprite;
Sprite *right_click_sprite;
Sprite *left_click_sprite;
Sprite *esc_sprite;
Sprite *f_sprite;
Sprite *space_sprite;
Sprite *grass_sprite;
Sprite *selected_grass_sprite;
Sprite *cobblestone_sprite;
Sprite *selected_cobblestone_sprite;
Sprite *tile1_sprite;
Sprite *selected_tile1_sprite;
Sprite *tile2_sprite;
Sprite *selected_tile2_sprite;
Sprite *tile3_sprite;
Sprite *selected_tile3_sprite;
Sprite *tile4_sprite;
Sprite *selected_tile4_sprite;
Sprite *tile5_sprite;
Sprite *selected_tile5_sprite;
Sprite *tile6_sprite;
Sprite *selected_tile6_sprite;
Sprite *tile7_sprite;
Sprite *selected_tile7_sprite;
Sprite *tile8_sprite;
Sprite *selected_tile8_sprite;
Sprite *flag_sprite;
Sprite *selected_flag_sprite;
Sprite *game_over_sprite;
Sprite *you_won_sprite;
Sprite *tnt_sprite;
Sprite *king_charles;

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
    play_again_button_sprite = create_sprite((xpm_map_t)PlayAgain_xpm);
    play_again_button2_sprite = create_sprite((xpm_map_t)PlayAgain2_xpm);
    restart_button_sprite = create_sprite((xpm_map_t)Restart_xpm);
    restart_button2_sprite = create_sprite((xpm_map_t)Restart2_xpm);
    right_click_sprite = create_sprite((xpm_map_t)Right_click);
    left_click_sprite = create_sprite((xpm_map_t)Left_click);
    esc_sprite = create_sprite((xpm_map_t)ESC);
    f_sprite = create_sprite((xpm_map_t)F);
    space_sprite = create_sprite((xpm_map_t)space);
    grass_sprite = create_sprite((xpm_map_t)grass_xpm);
    selected_grass_sprite = create_sprite((xpm_map_t)selectedgrass_xpm);
    cobblestone_sprite = create_sprite((xpm_map_t)cobblestone_xpm);
    selected_cobblestone_sprite = create_sprite((xpm_map_t)cobblestone2_xpm);
    tile1_sprite = create_sprite((xpm_map_t)tile1_xpm);
    selected_tile1_sprite = create_sprite((xpm_map_t)tile1selected_xpm);
    tile2_sprite = create_sprite((xpm_map_t)tile2_xpm);
    selected_tile2_sprite = create_sprite((xpm_map_t)tile2selected_xpm);
    tile3_sprite = create_sprite((xpm_map_t)tile3_xpm);
    selected_tile3_sprite = create_sprite((xpm_map_t)tile3selected_xpm);
    tile4_sprite = create_sprite((xpm_map_t)tile4_xpm);
    selected_tile4_sprite = create_sprite((xpm_map_t)tile4selected_xpm);
    tile5_sprite = create_sprite((xpm_map_t)tile5_xpm);
    selected_tile5_sprite = create_sprite((xpm_map_t)tile5selected_xpm);
    tile6_sprite = create_sprite((xpm_map_t)tile6_xpm);
    selected_tile6_sprite = create_sprite((xpm_map_t)tile6selected_xpm);
    tile7_sprite = create_sprite((xpm_map_t)tile7_xpm);
    selected_tile7_sprite = create_sprite((xpm_map_t)tile7selected_xpm);
    tile8_sprite = create_sprite((xpm_map_t)tile8_xpm);
    selected_tile8_sprite = create_sprite((xpm_map_t)tile8selected_xpm);
    flag_sprite = create_sprite((xpm_map_t)flag_xpm);
    selected_flag_sprite = create_sprite((xpm_map_t)flagselected_xpm);
    game_over_sprite = create_sprite((xpm_map_t)GameOver_xpm);
    you_won_sprite = create_sprite((xpm_map_t)YouWon_xpm);
    tnt_sprite = create_sprite((xpm_map_t)tnt_xpm);
    king_charles = create_sprite((xpm_map_t)kingcharles_xpm);
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
    destroy_sprite(play_again_button_sprite);
    destroy_sprite(play_again_button2_sprite);
    destroy_sprite(restart_button_sprite);
    destroy_sprite(restart_button2_sprite);
    destroy_sprite(right_click_sprite);
    destroy_sprite(left_click_sprite);
    destroy_sprite(esc_sprite);
    destroy_sprite(f_sprite);
    destroy_sprite(space_sprite);
    destroy_sprite(grass_sprite);
    destroy_sprite(selected_grass_sprite);
    destroy_sprite(cobblestone_sprite);
    destroy_sprite(selected_cobblestone_sprite);
    destroy_sprite(tile1_sprite);
    destroy_sprite(selected_tile1_sprite);
    destroy_sprite(tile2_sprite);
    destroy_sprite(selected_tile2_sprite);
    destroy_sprite(tile3_sprite);
    destroy_sprite(selected_tile3_sprite);
    destroy_sprite(tile4_sprite);
    destroy_sprite(selected_tile4_sprite);
    destroy_sprite(tile5_sprite);
    destroy_sprite(selected_tile5_sprite);
    destroy_sprite(tile6_sprite);
    destroy_sprite(selected_tile6_sprite);
    destroy_sprite(tile7_sprite);
    destroy_sprite(selected_tile7_sprite);
    destroy_sprite(tile8_sprite);
    destroy_sprite(selected_tile8_sprite);
    destroy_sprite(flag_sprite);
    destroy_sprite(selected_flag_sprite);
    destroy_sprite(game_over_sprite);
    destroy_sprite(you_won_sprite);
    destroy_sprite(tnt_sprite);
    destroy_sprite(king_charles);
}

