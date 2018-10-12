#include "Question1.h"



Question1::Question1()
{
}

Question1::Question1(std::string q,bool a)
{
	setQuestion(q);
	answer = a;
}

Question1::~Question1()
{
}

void Question1::calculate()
{
	initT(expertAnswers.size());
	double sum = 0.;
	for (int i = 0; i < expertAnswers.size()-1; i++)
	{
		for (int j = i+1; j < expertAnswers.size(); j++)
		{
			if (expertAnswers[i] == expertAnswers[j])
			{
				T[i][j] = 1.;
				sum++;
			}
		}
	}

	if (sum == 0) return;

	for (int i = 0; i < expertAnswers.size() - 1; i++)
	{
		for (int j = i; j < expertAnswers.size(); j++)
		{
			T[i][j] = T[i][j] / sum;
		}
	}
}

void Question1::answerQuestion(bool answer)
{
	expertAnswers.push_back(answer);
}

double Question1::getResult(bool studentsAnswer)
{
	if (studentsAnswer == answer)
		return 1;
	return 0;
}