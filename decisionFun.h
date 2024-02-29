#ifndef DECISION_FUN_H
#define DECISION_FUN_H

#include <iostream>
#include "cardManager.h"
#include "player.h"
#include "decisionTree.h"


bool any_task_card_playing(GameStatus* pgameStatus, int& selectCardIndex) {
    for (int i = 0; i < pgameStatus->slot.size(); i++) {
        for (int z = 0; z < pgameStatus->mission_tasks.size(); z++) {
            if ((pgameStatus->slot[i].getPlayingCardString(pgameStatus->slot[i].getPlayingCardColor()) ==
                pgameStatus->mission_tasks[z].getTaskColorString(pgameStatus->mission_tasks[z].getTaskCardColor())) &&
                (pgameStatus->slot[i].getPlayingCardNumber() == pgameStatus->mission_tasks[z].getTaskCardNumber())) {
                return true;
            }
        }
    }
    return false;
}

bool has_task_card(GameStatus* pgameStatus, int& selectCardIndex) {
    if (pgameStatus->player[pgameStatus->current_player_index].getPlayerTaskCards().empty()) {
        return false;
    }
    return true;
}

bool  has_self_required_task_card(GameStatus* pgameStatus, int& selectCardIndex) {
    std::vector<PlayingCard> a = pgameStatus->avaliable_cards;

    for (int i = 0; i < a.size(); i++) {
        if ((pgameStatus->player[pgameStatus->current_player_index].getPlayerTaskCards().at(0).getTaskColorString(
            pgameStatus->player[pgameStatus->current_player_index].getPlayerTaskCards().at(0).getTaskCardColor()) ==
            a[i].getPlayingCardString(a[i].getPlayingCardColor())) &&
            (pgameStatus->player[pgameStatus->current_player_index].getPlayerTaskCards().at(0).getTaskCardNumber() == a[i].getPlayingCardNumber())) {
            return true;
        }
    }
    return false;
}

bool  has_others_required_task_card(GameStatus* pgameStatus, int& selectCardIndex) {
    int next_player_index = 0;
    int current_player_index = pgameStatus->current_player_index;
    if (current_player_index + 1 == (int)pgameStatus->player.size()) {
        next_player_index = 0;
    }
    else {
        next_player_index = 1;
    }
    std::vector<PlayingCard> a = pgameStatus->avaliable_cards;
    for (int i = 0; i < a.size(); i++) {
        if ((pgameStatus->player[next_player_index].getPlayerTaskCards().at(0).getTaskColorString(
            pgameStatus->player[next_player_index].getPlayerTaskCards().at(0).getTaskCardColor()) ==
            a[i].getPlayingCardString(a[i].getPlayingCardColor())) &&
            (pgameStatus->player[next_player_index].getPlayerTaskCards().at(0).getTaskCardNumber() == a[i].getPlayingCardNumber())) {
            return true;
        }
    }
    return false;
}

bool  play_smallest_card(GameStatus* pgameStatus, int& selectCardIndex) {
    int index = 0;
    for (int i = 1; i < pgameStatus->avaliable_cards.size(); i++) {
        if (pgameStatus->avaliable_cards[index].getPlayingCardNumber() > pgameStatus->avaliable_cards[i].getPlayingCardNumber()) {
            index = i;
        }
    }
    selectCardIndex = index;
    return true;
}

bool  play_task_card(GameStatus* pgameStatus, int& selectCardIndex) {
    int index = 0;
    for (int i = 0; i < pgameStatus->avaliable_cards.size(); i++) {
        for (int z = 0; z < pgameStatus->mission_tasks.size(); z++) {
            if ((pgameStatus->mission_tasks[z].getTaskColorString(pgameStatus->mission_tasks[z].getTaskCardColor())
                == pgameStatus->avaliable_cards[i].getPlayingCardString(pgameStatus->avaliable_cards[i].getPlayingCardColor())) &&
                (pgameStatus->mission_tasks[z].getTaskCardNumber() == pgameStatus->avaliable_cards[i].getPlayingCardNumber())) {
                index = i;
                selectCardIndex = index;
            }
        }
    }
    selectCardIndex = index;
    return true;
}

bool  play_required_task_card(GameStatus* pgameStatus, int& selectCardIndex) {
    // selectCardIndex = -1;
    int index = 0;
    std::vector<PlayingCard> a = pgameStatus->avaliable_cards;
    for (int i = 0; i < a.size(); i++) {
        for (int z = 0; z < pgameStatus->mission_tasks.size(); z++) {
            if ((pgameStatus->mission_tasks[z].getTaskColorString(pgameStatus->mission_tasks[z].getTaskCardColor()) ==
                a[i].getPlayingCardString(a[i].getPlayingCardColor())) &&
                (pgameStatus->mission_tasks[z].getTaskCardNumber() == a[i].getPlayingCardNumber())) {
                index = i;
                selectCardIndex = index;
            }
        }
    }
    selectCardIndex = index;
    return true;
}

bool play_same_color_smallest_card(GameStatus* pgameStatus, int& selectCardIndex) {
    int index = 0;
    int next_player_index = 0;
    int current_player_index = pgameStatus->current_player_index;
    if (current_player_index + 1 == (int)pgameStatus->player.size()) {
        next_player_index = 0;
    }
    else {
        next_player_index = 1;
    }
    std::string color = pgameStatus->player[next_player_index].getPlayerTaskCards()[0].getTaskColorString(
        pgameStatus->player[next_player_index].getPlayerTaskCards().at(0).getTaskCardColor()
    );

    std::vector<PlayingCard> avaliable_cards = pgameStatus->avaliable_cards;
    int come = 0;
    int record_smallest_num = 0;
    for (int i = 0; i < avaliable_cards.size(); i++) {
        if (avaliable_cards[i].getPlayingCardString(avaliable_cards[i].getPlayingCardColor()) == color) {
            if (come == 0) {
                record_smallest_num = avaliable_cards[i].getPlayingCardNumber();
                index = i;
                selectCardIndex = index;
            }
            else {
                if (avaliable_cards[i].getPlayingCardNumber() < record_smallest_num) {
                    record_smallest_num = avaliable_cards[i].getPlayingCardNumber();
                    index = i;
                    selectCardIndex = index;
                }
            }
            come++;
        }
    }
    selectCardIndex = index;
    return true;
}

bool play_same_color_Largest_card(GameStatus* pgameStatus, int& selectCardIndex) {
    int index = 0;
    int next_player_index = 0;
    // int current_player_index = pgameStatus->current_player_index;
    // if (current_player_index + 1 == (int)pgameStatus->player.size()) {
    //     next_player_index = 0;
    // }
    // else {
    //     next_player_index = 1;
    // }
    //pgameStatus->player[pgameStatus->current_player_index].getPlayerTaskCards()[0]
    std::string color = pgameStatus->player[pgameStatus->current_player_index].getPlayerTaskCards().at(0).getTaskColorString(
        pgameStatus->player[pgameStatus->current_player_index].getPlayerTaskCards().at(0).getTaskCardColor()
    );

    std::vector<PlayingCard> avaliable_cards = pgameStatus->avaliable_cards;
    int come = 0;
    int record_smallest_num = 0;
    for (int i = 0; i < avaliable_cards.size(); i++) {
        if (avaliable_cards[i].getPlayingCardString(avaliable_cards[i].getPlayingCardColor()) == color) {
            if (come == 0) {
                record_smallest_num = avaliable_cards[i].getPlayingCardNumber();
                index = i;
                selectCardIndex = index;
            }
            else {
                if (avaliable_cards[i].getPlayingCardNumber() > record_smallest_num) {
                    record_smallest_num = avaliable_cards[i].getPlayingCardNumber();
                    index = i;
                    selectCardIndex = index;
                }
            }
            come++;
        }
    }
    selectCardIndex = index;
    return true;
}

#endif