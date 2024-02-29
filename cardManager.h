#pragma once

#ifndef CM_H
#define CM_H

#include <vector>

#include "card.h"

class TaskCardManager
{
public:
	TaskCardManager();

	void reset();
	bool hasCard();
	TaskCard getOneCard();

private:
	void shuffle();

	std::vector<TaskCard> TaskCardVector;
};

class PlayingCardManager
{
public:
	PlayingCardManager();

	void reset();
	bool hasCard();
	PlayingCard getOneCard();

private:
	void shuffle();

	std::vector<PlayingCard> PlayingCardVector;
};

#endif