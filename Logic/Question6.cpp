#include "Question6.h"



Question6::Question6()
{
}


Question6::Question6(std::string q, double mn, double mx, double a, double b)
{
	setQuestion(q);
	max = mx;
	min = mn;
	rightAnswer = 0.5*(mn + mx) + 0.25*(a + b);
}

Question6::~Question6()
{
}

void Question6::calculate()
{}

double Question6::getResult(double mn, double mx, double a, double b)
{
	double studentsAnswer = 0.5*(mn + mx) + 0.25*(a + b);
	return 1 - abs((rightAnswer - studentsAnswer) / (max - min));
}