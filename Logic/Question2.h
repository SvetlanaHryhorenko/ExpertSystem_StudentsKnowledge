#pragma once
#include "Question.h"
class Question2 :
	public Question
{
public:
	Question2();
	Question2(std::string q, std::vector<std::string> tA, std::vector<double> s);
	~Question2();

	void calculate();

	double getResult(int studentsAnswer);
	std::string getTextAnswer(int i);
	int answersSize();

private:
	std::vector<double> expertAnswers;
	std::vector<std::string> textAnswers;
	std::vector<double> scores;
};

