#pragma once
#include "Question.h"
class Question3 :
	public Question
{
public:
	Question3();
	Question3(std::string q, std::vector<std::string> tA, std::vector<double> s, std::vector<bool> rA);
	~Question3();

	void calculate();

	double getResult(std::vector<bool> studentsAnswer);
	std::string getTextAnswer(int i);
	int answersSize();

private:
	std::vector<std::string> textAnswers;
	std::vector<double> scores;
	std::vector<bool> rightAnswer;
	std::vector<double> normalize(std::vector<double> vector);
};

