#include "Question3.h"



Question3::Question3()
{
}

Question3::Question3(std::string q, std::vector<std::string> tA, std::vector<double> s, std::vector<bool> rA)
{
	setQuestion(q);
	textAnswers = tA;
	scores = normalize(s);
	rightAnswer = rA;
}

Question3::~Question3()
{
}

void Question3::calculate()
{}

double Question3::getResult(std::vector<bool> studentsAnswer)
{
	double sum = 0;
	for (int i = 0; i < studentsAnswer.size(); i++)
	{
		if(studentsAnswer[i] ==rightAnswer[i])
			sum += scores[i];
	}
	return sum;
}

std::string Question3::getTextAnswer(int i)
{
	return textAnswers[i];
}

int Question3::answersSize()
{
	return textAnswers.size();
}

std::vector<double> Question3::normalize(std::vector<double> vector)
{
	double sum = 0;
	for (int i = 0; i < vector.size(); i++)
	{
		sum += vector[i];
	}

	for (int i = 0; i < vector.size(); i++)
	{
		vector[i] /= sum;
	}
	return vector;
}