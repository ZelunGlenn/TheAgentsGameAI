#include "cardManager.h"
#include<time.h>
TaskCardManager::TaskCardManager() {
    reset();
}

void TaskCardManager::reset() {
    TaskCardVector.clear();
    for (size_t i = 0; i < 9; i++) {
        for (int j = 0; j < MAX_C; j++) {
            TaskCard card(i + 1, (TaskCardColor)j);
            this->TaskCardVector.push_back(card);
        }
    }

    shuffle();
}

PlayingCardManager::PlayingCardManager() {
    reset();
}

void PlayingCardManager::reset() {
    PlayingCardVector.clear();
    for (size_t i = 0; i < 9; i++) {
        for (int j = 0; j < MAX_COLOR; j++) {
            PlayingCard card(i + 1, (PlayingCardColor)j);
            this->PlayingCardVector.push_back(card);
        }
    }

    for (size_t i = 0; i < 4; i++) {
        for (int j = BLACK; j < MAX_COLOR; j++) {
            PlayingCard card(i + 1, (PlayingCardColor)j);
            this->PlayingCardVector.push_back(card);
        }
    }

    shuffle();
}

void TaskCardManager::shuffle() {
    
    for (size_t i = 0; i < this->TaskCardVector.size(); i++) {
        srand((unsigned)time(NULL));
        int val = i + rand() % (this->TaskCardVector.size() - i);
        TaskCard tmp = TaskCardVector.at(i);
        TaskCardVector.at(i) = TaskCardVector.at(val);
        TaskCardVector.at(val) = tmp;
    }
}

void PlayingCardManager::shuffle() {
     
    for (size_t i = 0; i < this->PlayingCardVector.size(); i++) {
        srand((unsigned)time(NULL));
        int val = i + rand() % (this->PlayingCardVector.size() - i);
        PlayingCard tmp = PlayingCardVector.at(i);
        PlayingCardVector.at(i) = PlayingCardVector.at(val);
        PlayingCardVector.at(val) = tmp;
    }
}

bool TaskCardManager::hasCard() {
    return this->TaskCardVector.size() > 0;
}

bool PlayingCardManager::hasCard() {
    return this->PlayingCardVector.size() > 0;
}

TaskCard TaskCardManager::getOneCard() {
    TaskCard temp = this->TaskCardVector.at(0);
    std::vector<TaskCard>::iterator k = this->TaskCardVector.begin();
    this->TaskCardVector.erase(k);
    return temp;
}

PlayingCard PlayingCardManager::getOneCard() {
    PlayingCard temp = this->PlayingCardVector.at(0);
    std::vector<PlayingCard>::iterator k = this->PlayingCardVector.begin();
    this->PlayingCardVector.erase(k);
    return temp;
}