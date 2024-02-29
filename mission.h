#ifndef MISSION_H
#define MISSION_H
#include <iostream>
#include <string>
// #include <map>

class Mission{
public:
    Mission(int mission_number, std::string story, int task_cards_number,
    int size_tokkens, int* task_tokkens, int size_speical_rules, std::string* speical_rules);
    int get_mission_number();
    std::string get_story();
    int get_task_cards_number();
    int size_tokkens;
    int* get_task_tokkens();
    int size_speical_rules;
    std::string* get_speical_rules();
    std::string get_result();
    void set_result(std::string result);
    ~Mission();
private:
    std::string story;
    int mission_number,task_cards_number;
    int* task_tokkens;
    std::string* speical_rules; 
    std::string result;
};

#endif