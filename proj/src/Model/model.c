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
Sprite *counter0_sprite;
Sprite *counter1_sprite;
Sprite *counter2_sprite;
Sprite *counter3_sprite;
Sprite *counter4_sprite;
Sprite *counter5_sprite;
Sprite *counter6_sprite;
Sprite *counter7_sprite;
Sprite *counter8_sprite;
Sprite *counter9_sprite;
Sprite *flag_counter_sprite;

void create_sprites(){
    start_button_sprite = create_sprite((xpm_map_t)Start_xpm);
    arrows_sprite = create_sprite((xpm_map_t)arrows_xpm);
    start_button2_sprite = create_sprite((xpm_map_t)Start2_xpm);
    cursor_mouse = create_sprite((xpm_map_t)cursor_xpm);
    controls_button_sprite = create_sprite((xpm_map_t)Controls_xpm);
    controls_button2_sprite = create_sprite((xpm_map_t)Controls2_xpm);
    exit_button_sprite = create_sprite((xpm_map_t)Exit_xpm);
    exit_button2_sprite = create_sprite((xpm_map_t)Exit2_xpm);
    title_sprite = create_sprite((xpm_map_t)Title_xpm);
    control_title_sprite = create_sprite((xpm_map_t)Controls_Title);
    paused_title_sprite = create_sprite((xpm_map_t)paused);
    dirt_block = create_sprite((xpm_map_t)Dirt_block);
    day_sky_sprite = create_sprite((xpm_map_t)Day_sky);
    night_sky_sprite = create_sprite((xpm_map_t)Night_sky);
    afternoon_sky_sprite = create_sprite((xpm_map_t)Afternoon_Sky);
    dyog_sprite = create_sprite((xpm_map_t)dyog);
    dyog2_sprite =  create_sprite((xpm_map_t)dyog2);
    continue_button_sprite = create_sprite((xpm_map_t)Continue_xpm);
    continue_button2_sprite = create_sprite((xpm_map_t)Continue2_xpm);
    play_again_button_sprite = create_sprite((xpm_map_t)PlayAgain_xpm);
    play_again_button2_sprite = create_sprite((xpm_map_t)PlayAgain2_xpm);
    restart_button_sprite = create_sprite((xpm_map_t)Restart_xpm);
    restart_button2_sprite = create_sprite((xpm_map_t)Restart2_xpm);
    right_click_sprite = create_sprite((xpm_map_t)RightClick_xpm);
    left_click_sprite = create_sprite((xpm_map_t)LeftClick_xpm);
    esc_sprite = create_sprite((xpm_map_t)ESC_xpm);
    f_sprite = create_sprite((xpm_map_t)F_xpm);
    space_sprite = create_sprite((xpm_map_t)space_xpm);
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
    counter0_sprite = create_sprite((xpm_map_t)Counter0_xpm);
    counter1_sprite = create_sprite((xpm_map_t)Counter1_xpm);
    counter2_sprite = create_sprite((xpm_map_t)Counter2_xpm);
    counter3_sprite = create_sprite((xpm_map_t)Counter3_xpm);
    counter4_sprite = create_sprite((xpm_map_t)Counter4_xpm);
    counter5_sprite = create_sprite((xpm_map_t)Counter5_xpm);
    counter6_sprite = create_sprite((xpm_map_t)Counter6_xpm);
    counter7_sprite = create_sprite((xpm_map_t)Counter7_xpm);
    counter8_sprite = create_sprite((xpm_map_t)Counter8_xpm);
    counter9_sprite = create_sprite((xpm_map_t)Counter9_xpm);
    flag_counter_sprite = create_sprite((xpm_map_t)FlagCounter_xpm);



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
    destroy_sprite(counter0_sprite);
    destroy_sprite(counter1_sprite);
    destroy_sprite(counter2_sprite);
    destroy_sprite(counter3_sprite);
    destroy_sprite(counter4_sprite);
    destroy_sprite(counter5_sprite);
    destroy_sprite(counter6_sprite);
    destroy_sprite(counter7_sprite);
    destroy_sprite(counter8_sprite);
    destroy_sprite(counter9_sprite);
    destroy_sprite(flag_counter_sprite);
}

