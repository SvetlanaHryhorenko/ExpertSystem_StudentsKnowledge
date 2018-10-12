#pragma once
#include "Question.h"
class Question4 :
	public Question
{
public:
	Question4();
	Question4(std::string q, double a, double min, double max);
	~Question4();

	void calculate();
	double getResult(double studentsAnswer);

private:
	double min;
	double max;
	double rightAnswer;

};

