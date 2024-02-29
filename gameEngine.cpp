#include "gameEngine.h"
#include <iostream>

#include <algorithm>
#include <vector>

GameEngine::GameEngine() {}

GameEngine::~GameEngine() {}

void GameEngine::initEngine(std::vector<Player> players, int totalRoundNumber, int startRound) {
    for (size_t i = 0; i < players.size(); i++) {
        this->players.push_back(players[i]);
    }
    this->totalRoundNumber = totalRoundNumber;
    this->startRound = startRound;
}

void GameEngine::run() {
    // get the Mission package
    MissionPackage* MP = new MissionPackage();
    Mission** missions = MP->get_mission_package();
    TaskCardManager* TM = new TaskCardManager();
    PlayingCardManager* PM = new PlayingCardManager();

    // start loop round<=50
    int roundNumber = startRound;
    while (roundNumber < totalRoundNumber) {
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
        std::cout << "Mission " << roundNumber << ": START\n" << std::endl;
        for (size_t i = 0; i < this->players.size(); i++) {
            this->players[i].reset_my_task();
            this->players[i].reset_player_card();
        }
        TM->reset();
        PM->reset();

        int missionCardNumber = missions[roundNumber]->get_task_cards_number();

        // int random_card_task_number=36;
        // int random_hand_card = 39;
        std::vector<TaskCard> current_available_task_cards;
        // std::cout << "missionCardNumber: " << missionCardNumber << std::endl;
        for (size_t i = 0; i < missionCardNumber; i++) {
            TaskCard* temp = new TaskCard(TM->getOneCard());
            current_available_task_cards.push_back(*temp);
        }
        // for easy to pop back
        std::reverse(current_available_task_cards.begin(), current_available_task_cards.end());

        this->current_task_cards = current_available_task_cards;

        // int missionToken[mission.tokenNumer()]=mission.token();

        // Player player_handcard[playerNumber];
        // int firsthand = 99;
        // for(size_t i = 0; i < playerNumber; i++){
        //     player_handcard[i].getOneCard();
        //     // if(player_handcard[i].getCard() == Card[Card.size()-1] && firsthand = 99){
        //     //     firsthand = i;
        //     // }
        //     if(i = playerNumber - 1){
        //         i = 0;
        //     }
        //     if(Card.size() == 0){
        //         break;
        //     }
        // }
        // problem 2
        int temp_i = 0;
        while (PM->hasCard()) {
            // std::cout << "in" << std::endl;
            PlayingCard* temp = new PlayingCard(PM->getOneCard());
            // std::cout << temp->getPlayingCardString(PM->getOneCard().getPlayingCardColor()) <<
            // temp->getPlayingCardNumber() << std::endl;
            this->players[temp_i].receive_one_card(
                temp, temp->getPlayingCardString(temp->getPlayingCardColor()),
                temp->getPlayingCardNumber());
            // test
            // for(size_t i = 0; i < this->players[temp_i].player_card.size(); i++){
            //     std::cout <<
            //     this->players[temp_i].player_card[i].getPlayingCardString(this->players[temp_i].player_card[i].getPlayingCardColor())
            //     << this->players[temp_i].player_card[i].getPlayingCardNumber() << " ";
            // }
            // std::cout <<std::endl;
            // test
            temp_i++;
            if (temp_i >= this->players.size()) {
                temp_i = 0;
            }
            // std::cout << "out" << std::endl;
        }
        // std::cout << "2" << std::endl; // test
        // std::cout << "2" << std::endl; // test

        // while(firsthand != 0){
        //     x = player_handcard[0];
        //     player_handcard.remove(player_handcard[0]);
        //     player_handcard.push_back(x);
        //     firsthand --;
        // }

        // pick task to every member; commander pick first
        int first_player_index = 0;
        while (this->players[first_player_index].commonder_check() == false) {
            first_player_index++;
        }
        // std::cout << "first_player_index: " << first_player_index << std::endl;
        // std::cout << "3" <<std::endl;
        int ii = first_player_index;
        while (!current_available_task_cards.empty()) {
            TaskCard* copy = new TaskCard(current_available_task_cards.back());
            this->players[ii].add_one_task(copy);
            current_available_task_cards.pop_back();
            ii++;
            if (ii >= this->players.size()) {
                ii = 0;
            }
        }
        // std::cout << "3" <<std::endl;
        // test print out all the tests for all players
        // std::cout << "test card print test" <<std::endl;

        // change
        // string result="";
        // cout << "Right(R) or Left(L) or No(N) \n";
        // cin >> result;
        // if(result == "R" || result == "L"){
        //     token.distress(result,playerNumber,player1,player2,player3,player4);
        //     point++;
        // }

        // std::cout << "2" << std::endl; // test
        // trick
        int round = 0;
        // tricks end reason:
        //                  1. player dont have cards
        //                  2. the mission special rule does not break. ==
        //                  3. mission successed                        ==  mission got the result.
        //                  4. mission failed                           ==

        // check_empty_hand(): check player still have cards or not.
        int current_finished_card_number = 0;
        // std::cout << "check_empty_hand(): " << check_empty_hand() << std::endl;
        // std::cout << "missions[roundNumber]->get_result(): " <<
        // missions[roundNumber]->get_result() << std::endl;
        while (true) {
            if (missions[roundNumber]->get_result() != "")
                break;

            if (check_empty_hand())
                break;

            print_all_current_task();
            // std::cout << "3" <<std::endl;
            // std::cout << "start of the round: current_finished_card_number: " <<
            // current_finished_card_number << std::endl;
            current_finished_card_number =
                trick(roundNumber, round, missionCardNumber, missions[roundNumber],
                      current_finished_card_number);
            // std::cout << "4" <<std::endl;

            round++;
        }

        if (missions[roundNumber]->get_result() == "fail") {
            missions[roundNumber]->set_result("");
        } else {
            roundNumber++;
        }
    }
}

int GameEngine::trick(int missionnumber,
                      int round,
                      int missionCardNumber,
                      Mission* mission,
                      int current_finished_card_number) {
    std::vector<PlayingCard> card_slot;
    int first_player_index = 0;
    // this is the first round
    // commander play cards
    if (round == 0) {
        // std::cout << "this is round 0" << std::endl;
        // check who is commander
        // std::cout << "Player number: " << this->players.size() << std::endl;
        while (this->players[first_player_index].commonder_check() == false) {
            first_player_index++;
        }
        // this is not the first round
        // who win the last trick play card
    } else {
        // check who win the last trick
        while (this->players[first_player_index].trick_check() == false) {
            first_player_index++;
        }
    }

    // reset the trick check
    this->players[first_player_index].trick_set(false);
    std::vector<int> play_order;
    play_order.push_back(first_player_index);
    int order_index = 1;
    // play order algorithm
    int next_player_index = first_player_index + 1;
    if (next_player_index >= this->players.size()) {
        next_player_index = 0;
    }

    while (next_player_index != first_player_index) {
        play_order.push_back(next_player_index);
        next_player_index++;
        if (next_player_index >= this->players.size()) {
            next_player_index = 0;
        }
    }

    // comms ?
    for (size_t index = 0; index < play_order.size(); index++) {
        if (this->players[play_order[index]].comms_ability_check() == true) {
            std::string typeing;
            std::cout << "Player" << play_order[index] << "use communication token? (y/n): ";
            std::cin >> typeing;
            if (typeing == "y") {
                // set a card to be commsed.
                players[play_order[index]].comm_set();
            } else if (typeing == "n") {
            } else {
                std::cout << "ERROR: invaild communication choose, type again." << std::endl;
                index--;
            }
        }
    }

    // show all the comms cards
    for (size_t index = 0; index < play_order.size(); index++) {
        if (players[play_order[index]].comms_current_check() == true) {
            // problem
            std::string radio_info = radio(players[play_order[index]].get_cards(),
                                           players[play_order[index]].get_comm_card());
            std::cout << players[play_order[index]].get_comm_card()->getPlayingCardNumber() << ", "
                      << players[play_order[index]].get_comm_card()->getPlayingCardColor()
                      << "is the " << radio_info << " card.";
        }
    }

    // player card
    std::cout<<"####################### Player Card information ####################### "<<std::endl;
    std::cout << "Player: " << first_player_index << std::endl;
    card_slot.push_back(*players[first_player_index].place_card_frist(
        this->current_task_cards, card_slot, players, first_player_index));
    std::string round_color = card_slot[0].getPlayingCardString(card_slot[0].getPlayingCardColor());
    // the rest of players play card
    for (size_t index = 1; index < play_order.size(); index++) {
             std::cout<<"####################### Player Card information ####################### "<<std::endl;
    
        std::cout << "Player: " << play_order[index] << std::endl;
        card_slot.push_back(*players[play_order[index]].place_card_other(
            current_task_cards, card_slot, players, play_order[index], round_color));
    }

    // check round status
    std::cout << "___________________ Check Round Result ___________________ " << std::endl;
    int winner_player_index = check_winner(card_slot);
    players[play_order[winner_player_index]].trick_set(true);
    // is the winner of this trick fot any task done?
    bool self_task_done = false;
    for (size_t i = 0; i < card_slot.size(); i++) {
        if (players[play_order[winner_player_index]].check_with_task(&card_slot[i])) {
            self_task_done = true;
            players[play_order[winner_player_index]].reset_my_task();
            // std::cout << "winner get task done? : " << got_any_task_done << std::endl;
            current_finished_card_number++;
            break;
        }
    }
    // is the winner of this trick done any other peoples task?
    bool get_any_others_task_done = false;
    if ( !self_task_done ) {
        int winner_vector_index = play_order[winner_player_index];
        for (size_t j = 0; j <this->players.size(); j++ )
        {
            if(winner_vector_index == j)
                continue;
            for (size_t i = 0; i < card_slot.size(); i++) {
                if (players[j].check_with_task(&card_slot[i])) 
                {
                    get_any_others_task_done = true;
                    break;
                }
            }
            if (get_any_others_task_done)
                break;
        }
    }

    if (get_any_others_task_done) {
        std::cout << std::endl << std::endl;
        std::cout << "**********************Misson Result**********************" << std::endl;
        std::cout << "Mission " << missionnumber << ": FAIL\n" << std::endl;
        mission->set_result(std::string("fail"));
    }
    else
    {
        std::cout << ".......... Task Result.........." << std::endl;
        if(self_task_done){
            std::cout << "Task SUCCESS " << std::endl;
        }else{
            std::cout << "Task PROGRESS " << std::endl;
        }
        
        if (current_finished_card_number == missionCardNumber) {
            std::cout << std::endl << std::endl;
            std::cout << "**********************Misson Result**********************" << std::endl;
            std::cout << "Mission " << missionnumber << ": SUCCESS\n" << std::endl;
            mission->set_result(std::string("success"));
        }
    }
    // are we finish all the task?
    // if -> finished -> mission result is true
    // else if -> someoneelse finished it -> mission result is fail
    // else -> do nothing
    return current_finished_card_number;
}

// check wheather player got no cards or not.
bool GameEngine::check_empty_hand() {
    bool checker = false;
    for (size_t index = 0; index < players.size(); index++) {
        if (players[index].get_cards().size() == 0) {
            checker = true;
        }
    }
    return checker;
}

int GameEngine::check_winner(std::vector<PlayingCard> card_slot) {
    //   std::cout << "1" << std::endl;
    int winner_number = 0;
    PlayingCard* winner_card = nullptr;
    //[card_slot.size()] = {}
    // std::vector <PlayingCard> rockets;
    PlayingCard** rockets = new PlayingCard*[card_slot.size()];

    bool check_rocket = false;
    for (size_t index = 0; index < card_slot.size(); index++) {
        if (card_slot[index].getPlayingCardString(card_slot[index].getPlayingCardColor()) ==
            "ROCKET") {
            rockets[index] = new PlayingCard(card_slot[index]);
            check_rocket = true;
        } else {
            rockets[index] = NULL;
        }
    }
    //   std::cout << "2" << std::endl;
    if (check_rocket == true) {
        for (size_t index = 0; index < card_slot.size(); index++) {
            if (rockets[index] != NULL) {
                if (winner_card != nullptr) {
                    if (winner_card->getPlayingCardNumber() <
                        rockets[index]->getPlayingCardNumber()) {
                        winner_number = index;
                        winner_card = rockets[index];
                    }
                } else {
                    winner_number = index;
                    winner_card = rockets[index];
                }
            }
        }
    } else {
        std::string round_color =
            card_slot[0].getPlayingCardString(card_slot[0].getPlayingCardColor());
        for (size_t index = 0; index < card_slot.size(); index++) {
            if (round_color ==
                card_slot[index].getPlayingCardString(card_slot[index].getPlayingCardColor())) {
                if (winner_card != nullptr) {
                    if (winner_card->getPlayingCardNumber() <
                        card_slot[index].getPlayingCardNumber()) {
                        winner_number = index;
                        winner_card = new PlayingCard(card_slot[index]);
                    }
                } else {
                    winner_number = index;
                    winner_card = new PlayingCard(card_slot[index]);
                }
            }
        }
    }

    return winner_number;
}

std::string GameEngine::radio(std::vector<PlayingCard> handCard, PlayingCard* x) {
    size_t index = 0;
    size_t max = 0;
    size_t min = 0;
    while ((index <= handCard.size() - 1) &&
           (handCard[index].getPlayingCardString(handCard[index].getPlayingCardColor()) ==
            x->getPlayingCardString(x->getPlayingCardColor()))) {
        if (handCard[index].getPlayingCardNumber() >= x->getPlayingCardNumber()) {
            max = handCard[index].getPlayingCardNumber();
        } else {
            max = x->getPlayingCardNumber();
        }
        if (handCard[index].getPlayingCardNumber() <= x->getPlayingCardNumber()) {
            min = handCard[index].getPlayingCardNumber();
        } else {
            min = x->getPlayingCardNumber();
        }
        index++;
    }
    if (max == min) {
        return "only";
    } else if (max == x->getPlayingCardNumber()) {
        return "max";
    } else if (min == x->getPlayingCardNumber()) {
        return "min";
    } else {
        return "wrong selection";
    }
}

void GameEngine::print_all_current_task() {
    std::cout<<"**********************Task information**********************"<<std::endl;
    for (size_t i = 0; i < this->players.size(); i++) {
        std::cout << "Player: " << i << "'s tasks: ";
        for (size_t index = 0; index < this->players[i].getPlayerTaskCards().size(); index++) {
            std::cout << this->players[i].getPlayerTaskCards()[index].getTaskColorString(
                             this->players[i].getPlayerTaskCards()[index].getTaskCardColor())
                      << this->players[i].getPlayerTaskCards()[index].getTaskCardNumber()
                      << "   \t";
        }
        std::cout << std::endl;
    }
}
