#pragma once
#include "Question.h"

#include <algorithm>

class Question5 :
	public Question
{
public:
	Question5();
	Question5(std::string q, double min, double max);
	~Question5();

	void calculate();
	double getResult(double studentsMin, double studentsMax);

private:
	double min;
	double max;
};

