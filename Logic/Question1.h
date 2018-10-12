#pragma once
#include "Question.h"
class Question1 :
	public Question
{
public:
	Question1();
	Question1(std::string q, bool a);
	~Question1();

	void calculate();
	void answerQuestion(bool answer);

	double getResult(bool studentsAnswer);

private:
	std::vector<bool> expertAnswers;
	bool answer;
};

