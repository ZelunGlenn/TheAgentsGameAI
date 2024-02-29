#include "player.h"
#include "cardDecisionTree.h"
Player::Player() {
    commonder = false;
    communication_ability = false;
    communicating = false;
    player_trick = false;
    communication_card = nullptr;
}

Player::~Player() {}

// problem
void Player::receive_one_card(PlayingCard* p_card, std::string color, int num) {
    player_card.push_back(*(p_card));
    if (color == "BLACK" && num == 4) {
        this->comm_set();
    }
}

PlayingCard* Player::get_comm_card() {
    if (communicating == true) {
        return communication_card;
    } else {
        return nullptr;
    }
}

void Player::comms_set() {
    for (size_t i = 0; i < player_card.size(); i++) {
        std::cout << i << ": "
                  << player_card[i].getPlayingCardString(player_card[i].getPlayingCardColor())
                  << " " << player_card[i].getPlayingCardNumber() << std::endl;
    }
    int num = 0;
    // problem: mission error check
    std::cout << "pick one to communicate: ";
    std::cin >> num;

    communication_card = &player_card[num];
    communication_ability = false;
    communicating = true;
}

void Player::comms_remove() {
    delete communication_card;
    communicating = false;
}

std::vector<PlayingCard>& Player::get_cards() {
    return player_card;
}

// problem: 如果出了comms 的牌 需要把comms的牌去掉然后comming 改为false
PlayingCard* Player::place_card_frist(std::vector<TaskCard> mission_tasks,
                                      std::vector<PlayingCard> slot,
                                      std::vector<Player> players,
                                      int current_player_index) {
    game_card_drop.clear();
    int card_index = 0;
    int liner = 0;
    for (size_t i = 0; i < player_card.size(); i++) {
        std::cout << i << "."
                  << player_card[i].getPlayingCardString(player_card[i].getPlayingCardColor())
                  << player_card[i].getPlayingCardNumber() << "  \t";   
        liner++;
        if (liner >= 5) {
            liner = 0;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    // miss error check
    std::cout << "Decision Tree Select:";
    CardDecisionTree tree;

    card_index =
        tree.getResult(mission_tasks, slot, this->get_cards(), players, current_player_index);

    std::cout << card_index << std::endl;
    // std::cin >> card_index;
    // std::cout<<"Are you sure you want to play this "<<player_card[card_num]<<"card ?";
    game_card_drop.push_back(player_card[card_index]);
    std::vector<PlayingCard>::iterator k = this->player_card.begin();
    for (size_t i = 0; i < card_index; i++) {
        k++;
    }
    PlayingCard* copy = new PlayingCard(player_card[card_index]);
    player_card.erase(k);
    // erase(card_index);
    std::cout << "The card you have played is: "
              << copy->getPlayingCardString(copy->getPlayingCardColor())
              << copy->getPlayingCardNumber() << std::endl;
    return copy;
}

PlayingCard* Player::place_card_other(std::vector<TaskCard> mission_tasks,
                                      std::vector<PlayingCard> slot,
                                      std::vector<Player> players,
                                      int current_player_index,
                                      std::string color) {
    game_card_drop.clear();
    std::string p_color = color;
    int card_index = 0;
    std::vector<PlayingCard> temp_cards;

    bool any_same_color_left = check_card(color);
    // problem: no error check.
    if (any_same_color_left) {
        for (size_t i = 0; i < player_card.size(); i++) {
            if (player_card[i].getPlayingCardString(player_card[i].getPlayingCardColor()) ==
                color) {
                std::cout << i << "."
                          << player_card[i].getPlayingCardString(
                                 player_card[i].getPlayingCardColor())
                          << player_card[i].getPlayingCardNumber() << "; ";  //具体信息
                temp_cards.push_back(player_card[i]);
            }
            // problem: try only put the correct color card into a vector.
        }
        std::cout << std::endl;
    } else {
        for (size_t i = 0; i < player_card.size(); i++) {
            // problem: try only put the correct color card into a vector.
            std::cout << i << "."
                      << player_card[i].getPlayingCardString(player_card[i].getPlayingCardColor())
                      << player_card[i].getPlayingCardNumber() << "; ";  //具体信息
        }
        std::cout << std::endl;
    }
    
    CardDecisionTree tree;
    if (any_same_color_left) {
        int card_color_index = tree.getResult(mission_tasks, slot, temp_cards, players, current_player_index);
        int temp_cards_index = 0;
        for (size_t i = 0; i < player_card.size(); i++) {
            if (player_card[i].getPlayingCardString(player_card[i].getPlayingCardColor()) == color) {
                if (temp_cards_index == card_color_index) {
                    card_index = i;
                    break;
                }
                temp_cards_index++;
            }
        }
    } else
        card_index = tree.getResult(mission_tasks, slot, this->get_cards(), players, current_player_index);

    std::cout << "Decision Tree Select:" << card_index << std::endl;
    while (any_same_color_left && player_card[card_index].getPlayingCardString(
                                      player_card[card_index].getPlayingCardColor()) != p_color) {
        std::cout << "ERROR:Must be the same color! " << std::endl;
        card_index = tree.getResult(mission_tasks, slot, this->get_cards(), players, current_player_index);
        std::cout << "Decision Tree Select:" << card_index << std::endl;
    }
    game_card_drop.push_back(player_card[card_index]);
    std::vector<PlayingCard>::iterator k = this->player_card.begin();
    for (size_t i = 0; i < card_index; i++) {
        k++;
    }
    PlayingCard* copy = new PlayingCard(player_card[card_index]);
    player_card.erase(k);
    // player_card.erase(card_num);
    std::cout << "The card you have played is: "
              << copy->getPlayingCardString(copy->getPlayingCardColor())
              << copy->getPlayingCardNumber() << std::endl;
    return copy;
}
void Player::comm_set() {
    commonder = true;
}

void Player::comm_remove() {
    commonder = false;
}

bool Player::commonder_check() {
    return commonder;
}

bool Player::comms_ability_check() {
    return communication_ability;
}

bool Player::comms_current_check() {
    return communicating;
}

void Player::trick_set(bool result) {
    this->player_trick = result;
}

bool Player::trick_check() {
    return player_trick;
}

bool Player::check_card(std::string color) {
    for (size_t i = 0; i < player_card.size(); i++) {
        if (player_card[i].getPlayingCardString(player_card[i].getPlayingCardColor()) == color) {
            return true;
        }
    }
    return false;
}

void Player::add_one_task(TaskCard* tc) {
    my_task.push_back(*tc);
}

void Player::reset_player_card() {
    this->player_card.clear();
}

void Player::reset_my_task() {
    this->my_task.clear();
}

bool Player::check_with_task(PlayingCard* card) {
    for (size_t i = 0; i < my_task.size(); i++) {
        if ((card->getPlayingCardString(card->getPlayingCardColor()) ==
             my_task[i].getTaskColorString(my_task[i].getTaskCardColor())) &&
            (card->getPlayingCardNumber() == my_task[i].getTaskCardNumber())) {
            return true;
        }
    }
    return false;
}
