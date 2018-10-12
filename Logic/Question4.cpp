#include "Question4.h"



Question4::Question4()
{
}

Question4::Question4(std::string q, double rA, double mn, double mx)
{
	setQuestion(q);
	rightAnswer = rA;
	min = mn;
	max = mx;

}

Question4::~Question4()
{
}

void Question4::calculate()
{}

double Question4::getResult(double studentsAnswer)
{
	return 1 - abs((rightAnswer - studentsAnswer) / (max - min));
}