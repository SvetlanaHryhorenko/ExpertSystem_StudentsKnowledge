#pragma once
#include "Question.h"
class Question6 :
	public Question
{
public:
	Question6();
	Question6(std::string q, double min, double max, double a, double b);
	~Question6();

	void calculate();

	double getResult(double min, double max, double a, double b);

private:
	double min;
	double max;
	double rightAnswer;

};

