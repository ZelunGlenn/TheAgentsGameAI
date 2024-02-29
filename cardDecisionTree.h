#ifndef CRAD_DECISION_TREE
#define CRAD_DECISION_TREE
#include <vector>
#include "cardManager.h"
#include "player.h"
#include "decisionTree.h"
class CardDecisionTree {
public:
    CardDecisionTree();
     virtual int getResult(std::vector<TaskCard> mission_tasks,
        std::vector<PlayingCard> slot,
        std::vector<PlayingCard> cards,
        std::vector<Player> player,
        int current_player_index);
     ~CardDecisionTree() {};
     
};
#endif