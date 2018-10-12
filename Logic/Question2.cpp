#include "Question2.h"



Question2::Question2()
{
}

Question2::Question2(std::string q, std::vector<std::string> tA, std::vector<double> s)
{
	setQuestion(q);
	textAnswers = tA;
	scores = s;
}

Question2::~Question2()
{
}

void Question2::calculate()
{}

double Question2::getResult(int studentsAnswer)
{
	return scores[studentsAnswer];
}

std::string Question2::getTextAnswer(int i)
{
	return textAnswers[i];
}

int Question2::answersSize()
{
	return textAnswers.size();
}