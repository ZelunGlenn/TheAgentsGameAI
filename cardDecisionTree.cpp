#include "cardDecisionTree.h"
#include "decisionTree.h"
#include "decisionFun.h"

CardDecisionTree::CardDecisionTree(){
 
}

int CardDecisionTree::getResult(std::vector<TaskCard> mission_tasks, std::vector<PlayingCard> slot,
    std::vector<PlayingCard> cards, std::vector <Player> player, int current_player_index) {
    GameStatus gameStatus;
    gameStatus.avaliable_cards = cards;
    gameStatus.current_player_index = current_player_index;
    gameStatus.mission_tasks = mission_tasks;
    gameStatus.player = player;
    gameStatus.slot = slot;
    // if(any_task_card_playing()){
    //     play_smallest_card();
    // }else{
    //     if(has_task_card()){
    //         play_task_card();
    //     }else{
    //         if(has_required_task_card()){
    //             play_required_task_card();
    //         }else{
    //             play_same_color_smallest_card();
    //         }
    //     }
    // }
    DecisionTree * pDecisionTree = new DecisionTree(&gameStatus);
 
    Node* root = pDecisionTree->initRootNode(false, any_task_card_playing);
        pDecisionTree->addYesChildNodeForNonNode(root, true, play_smallest_card);
        Node* hasTaskCardNode = pDecisionTree->addNoChildNodeForNonNode(root, false, has_task_card);

            Node* has_required_task_cardNode_self = pDecisionTree->addYesChildNodeForNonNode(hasTaskCardNode, false, has_self_required_task_card);
                pDecisionTree->addYesChildNodeForNonNode(has_required_task_cardNode_self, true, play_required_task_card);
                pDecisionTree->addNoChildNodeForNonNode(has_required_task_cardNode_self, true, play_same_color_Largest_card);

            Node* has_required_task_cardNode_others = pDecisionTree->addNoChildNodeForNonNode(hasTaskCardNode, false, has_others_required_task_card);
                pDecisionTree->addYesChildNodeForNonNode(has_required_task_cardNode_others, true, play_required_task_card);
                pDecisionTree->addNoChildNodeForNonNode(has_required_task_cardNode_others, true, play_same_color_smallest_card);

    int resultValue = pDecisionTree->getDecisionTreeResult();
    delete pDecisionTree;
    return resultValue;
}

