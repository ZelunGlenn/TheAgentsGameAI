#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
 
#include "cardManager.h"
class Player{
public:
    Player();
	~Player();

 
    void comm_set();
 
    void comm_remove();
 
    void comms_set();
   
    void comms_remove();
 
    void trick_set(bool result); 
 
    std::vector<PlayingCard>& get_cards();
    void add_one_task(TaskCard* tc);
    void reset_player_card();
    void reset_my_task();
    bool check_with_task(PlayingCard* card);
 
    bool commonder_check();
    bool comms_ability_check();
 
    bool comms_current_check();
 
    bool trick_check();   
    void receive_one_card(PlayingCard* p_card, std::string color, int num);
    PlayingCard* get_comm_card();


    // 出牌
    PlayingCard* place_card_frist(
        std::vector<TaskCard> mission_tasks, std::vector<PlayingCard> slot,
         std::vector<Player> player, int current_player_index);

    // 首个花色出现 检查翟帆的.h
    PlayingCard* place_card_other(std::vector<TaskCard> mission_tasks, std::vector<PlayingCard> slot,
        std::vector<Player> player, int current_player_index,std::string color);

    std::vector<TaskCard>& getPlayerTaskCards()
    {
        return this->my_task;
    }

private:

    bool check_card(std::string color);
  




    private:


    std::vector<PlayingCard> player_card; 
    std::vector<PlayingCard> game_card_drop; 
    std::vector<TaskCard> my_task;
    PlayingCard* communication_card;
    bool commonder;  
    bool communication_ability;  
    bool communicating;
    bool player_trick;  

};

#endif