#include "Question7.h"



Question7::Question7()
{
}

Question7::Question7(std::string q, std::vector<std::string> a)
{
	setQuestion(q);
	answers = a;
}

Question7::~Question7()
{
}


void Question7::calculate()
{}

double Question7::getResult(std::string studentsAnswer)
{
	for (int i = 0; i < answers.size(); i++)
	{
		if (studentsAnswer == answers[i])
			return 1;
	}
	return 0;
}