#include "QuestionList.h"



QuestionList::QuestionList()
{

	Reader reader;
	List = reader.read();
}


QuestionList::~QuestionList()
{
}

std::vector<double> QuestionList::calculate()
{
	initT();
	std::vector<double> levels;
	double sum = 0;
	for (int p = 0; p < T.size(); p++)
	{
		levels.push_back(calculateExpert(p));
		sum += levels[p];
	}
	for (int i = 0; i < levels.size(); i++)
	{
		levels[i] /= sum;
	}
	return levels;
}

Question * QuestionList::get(int N)
{
	return List[N];
}

const int QuestionList::size()
{
	return List.size();
}

void QuestionList::initT()
{
	T = List[0]->getT();
	for (int l = 1; l < List.size(); l++)
	{
		for (int i = 0; i < T.size(); i++)
		{
			for (int j = 0; j < T.size(); j++)
			{
				T[i][j] += List[l]->getT()[i][j];
			}
		}
	}
	
}

double QuestionList::calculateExpert(int N)
{
	double result = 0;
	for (int i = 0; i < T.size(); i++)
	{
		result += T[i][N];
		result += T[N][i];
	}
	return result;
}

void QuestionList::read()
{
	

	
}