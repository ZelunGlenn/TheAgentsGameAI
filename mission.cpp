#include "mission.h"

Mission::Mission(int mission_number, std::string story, int task_cards_number,
    int size_tokkens, int* task_tokkens, int size_speical_rules, std::string* speical_rules){
        this->mission_number = mission_number;
        this->story = story;
        this->task_cards_number = task_cards_number;
        this->size_tokkens = size_tokkens;
        this->task_tokkens = task_tokkens;
        this->size_speical_rules = size_speical_rules;
        this->speical_rules = speical_rules;
        this->result = "";
    }

int Mission::get_mission_number(){
    return mission_number;
}

std::string Mission::get_story(){
    return story;
}

int Mission::get_task_cards_number(){
    return task_cards_number;
}

int* Mission::get_task_tokkens(){
    return task_tokkens;
}


std::string* Mission::get_speical_rules(){
    return speical_rules;
}

std::string Mission::get_result(){
    return result;
}

void Mission::set_result(std::string result){
    this->result = result;
}

Mission::~Mission(){
    // may be wrong
    delete [] task_tokkens;
}