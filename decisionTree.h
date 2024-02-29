#ifndef DECISION_TREE_H
#define DECISION_TREE_H
 
#include <iostream>
#include "cardManager.h"
#include "player.h"

struct GameStatus
{
    std::vector<TaskCard> mission_tasks;
    std::vector<PlayingCard> slot;
    std::vector<PlayingCard> avaliable_cards;
    std::vector<Player> player;
    int current_player_index;
};

// if this is one leaf node, use the selectCardIndex.
// if this is one non-leaf node, use the return value
typedef bool (*decision_fun_ptr)(GameStatus*, int& selectCardIndex);

 
struct Node
{
    // for leaf
    Node* yesNode; //pointer to the yes leaf
    Node* noNode; //pointer to the no leaf
    bool isLeaf;

    // for node decision tree function
    decision_fun_ptr p_decision_fun_ptr;

    // the decision tree function need use the current game status
    GameStatus* pgameStatus;

    Node(bool isLeaf, decision_fun_ptr p_decision_fun_ptr, GameStatus* pgameStatus)
    {
        this->pgameStatus = pgameStatus;
        this->p_decision_fun_ptr = p_decision_fun_ptr;
        this->isLeaf = isLeaf;
        this->yesNode = NULL;
        this->noNode = NULL;
    };

};

class DecisionTree
{
public:
    DecisionTree(GameStatus* pgameStatus)
    {
        this->pgameStatus = pgameStatus;
        this->root = NULL;
    }

    ~DecisionTree()
    {
        // todo
    }

    Node* initRootNode(bool isLeaf, decision_fun_ptr p_decision_fun_ptr)
    {
        this->root = new Node(isLeaf, p_decision_fun_ptr, this->pgameStatus);
        return this->root;
    }

    // Functions to add new questions:
    Node* addYesChildNodeForNonNode(Node* curr, bool isLeaf, decision_fun_ptr p_decision_fun_ptr)
    {
        if (!curr->isLeaf)
        {
            if (curr->yesNode == nullptr) {
                curr->yesNode = new Node(isLeaf, p_decision_fun_ptr, this->pgameStatus);
            }
            else
            {
                std::cout << "curr node's yes leaf node has value, it can't add yes node" << std::endl;
            }
        }
        else
        {
            std::cout << "curr node is leaf node, it can't add yes node" << std::endl;
        }
        return curr->yesNode;
    }
    Node* addNoChildNodeForNonNode(Node* curr, bool isLeaf, decision_fun_ptr p_decision_fun_ptr)
    {
        if (!curr->isLeaf)
        {
            if (curr->noNode == nullptr) {
                curr->noNode = new Node(isLeaf, p_decision_fun_ptr, this->pgameStatus);
            }
            else
            {
                std::cout << "curr node's yes leaf node has value, it can't add yes node" << std::endl;
            }
        }
        else
        {
            std::cout << "curr node is leaf node, it can't add yes node" << std::endl;
        }
        return curr->noNode;
    }
    int getDecisionTreeResult()
    {
        return doDecision(this->root);
    }

 
    int doDecision(Node* current)
    {
        if (current == NULL)
        {
            std::cout << " this Decision tree is not valid!" << std::endl;
            return -1;
        }
        int resultValue = 0;
        if (current->isLeaf)
        { 
            current->p_decision_fun_ptr(this->pgameStatus, resultValue);
            return resultValue;
        }
        else
        {
            bool deccisionResult = current->p_decision_fun_ptr(this->pgameStatus, resultValue);
            if (deccisionResult)
                return doDecision(current->yesNode);
            else
                return doDecision(current->noNode);
        }
             
    }

private:
    Node* root; // pointer to the root of the tree
    GameStatus* pgameStatus;
};
#endif