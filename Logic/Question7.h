#pragma once
#include "Question.h"
class Question7 :
	public Question
{
public:
	Question7();
	Question7(std::string q, std::vector<std::string> a);
	~Question7();

	void calculate();

	double getResult(std::string studentsAnswer);

private:
	std::vector<std::string> answers;

};

