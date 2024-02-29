#pragma once

#ifndef CARD_H
#define CARD_H

#include <string> 
enum TaskCardColor {
    Y,  // 9
    P,  // 9
    B,  // 9// 9
    G,  // 9
    // R, // 4
    MAX_C
};
enum PlayingCardColor {
    YELLOW,  // 9
    PINK,    // 9
    BLUE,    // 9// 9
    GREEN,   // 9
    BLACK,   // 4
    MAX_COLOR
};
class TaskCard {
   public:
    TaskCard(int number, TaskCardColor color);
    TaskCard(const TaskCard& pc);

    int getTaskCardNumber() { return this->m_number; }
    TaskCardColor getTaskCardColor() { return this->m_color; }
    static std::string getTaskColorString(TaskCardColor color) {
        switch (color) {
            case Y:
                return std::string("YELLOW");
            case G:
                return std::string("GREEN");
            case B:
                return std::string("BLUE");
            case P:
                return std::string("PINK");
            // case R:
            // 	return std::string("ROCKET");
            default:
                return "unkonow";
        }
    }

   private:
    int m_number;
    TaskCardColor m_color;
};

class PlayingCard {
   public:
    PlayingCard(int number, PlayingCardColor color);
    PlayingCard(const PlayingCard& pc);

    int getPlayingCardNumber() { return this->m_number; }
    PlayingCardColor getPlayingCardColor() { return this->m_color; }
    static std::string getPlayingCardString(PlayingCardColor color) {
        switch (color) {
            case YELLOW:
                return std::string("YELLOW");
            case BLACK:
                return std::string("BLACK");
            case GREEN:
                return std::string("GREEN");
            case BLUE:
                return std::string("BLUE");
            case PINK:
                return std::string("PINK");
            default:
                return "unkonow";
        }
    }

   private:
    int m_number;
    PlayingCardColor m_color;
};

#endif