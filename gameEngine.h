#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <string>
#include "card.h"
#include "player.h"
#include "mission.h"
#include "missionPackage.h"
#include "vector"

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void initEngine(std::vector <Player> players, int totalRoundNumber, int startRoundNum);
    void run();

private:
    int trick(int missionnumber, int round, int missionCardNumber, Mission* mission, int current_finished_card_number);
    bool check_empty_hand();
    int check_winner(std::vector <PlayingCard> card_slot);
    void print_all_current_task();
    std::string radio(std::vector<PlayingCard> handCard, PlayingCard* x);

private:
    std::vector<Player> players;
    int totalRoundNumber;
    int startRound;

    std::vector<TaskCard> current_task_cards;
};

#endif //GAMEENGINE_H