#include "card.h"

TaskCard::TaskCard(int number, TaskCardColor color)
{
	this->m_color = color;
	this->m_number = number;
}

TaskCard::TaskCard(const TaskCard& pc){
	this->m_color = pc.m_color;
	this->m_number = pc.m_number;
}

PlayingCard::PlayingCard(int number, PlayingCardColor color)
{
	this->m_color = color;
	this->m_number = number;
}

PlayingCard::PlayingCard(const PlayingCard& pc){
	this->m_color = pc.m_color;
	this->m_number = pc.m_number;
}