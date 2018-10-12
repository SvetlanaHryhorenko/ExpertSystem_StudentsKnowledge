#include "Question5.h"



Question5::Question5()
{
}

Question5::Question5(std::string q, double mn, double mx)
{
	setQuestion(q);
	min = mn;
	max = mx;

}

Question5::~Question5()
{
}


void Question5::calculate()
{}

double Question5::getResult(double studentsMin, double studentsMax)
{
	if (std::min(max, studentsMax) < std::max(min, studentsMin))
		return 0;
	return 0.5*(std::min(max, studentsMax) - std::max(min, studentsMin))*((1 / (max - min)) + (1 / (studentsMax - studentsMin)));
}