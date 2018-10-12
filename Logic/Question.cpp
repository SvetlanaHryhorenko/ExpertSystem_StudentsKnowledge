#include "Question.h"



Question::Question()
{
}


Question::~Question()
{
}

void Question::setQuestion(std::string q)
{
	question = q;
}

std::string Question::getQuestion()
{
	return question;
}

std::vector<std::vector<double>> Question::getT()
{ 
	calculate();
	return T;
}

void Question::initT(int N)
{
	std::vector<double> column(N, 0);
	for (int i = 0; i < N; i++)
	{
		T.push_back(column);
	}
}

