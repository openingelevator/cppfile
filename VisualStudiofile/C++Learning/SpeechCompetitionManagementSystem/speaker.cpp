#include "speaker.h"

void Speaker::setName(string name)
{
	this->m_Name = name;
}

string Speaker::getName()const
{
	return this->m_Name;
}

void Speaker::setScore(double val, int index)
{
	if (index >= 0 && index < 2)
	{
		this->m_Score[index] = val;
	}
	else throw out_of_range("invalid index");
}

double Speaker::getScore(int index) const
{
	if (index >= 0 && index < 2)
	{
		return this->m_Score[index];
	}
	else throw out_of_range("invalid index");
}