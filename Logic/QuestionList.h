#pragma once
#include "Reader.h"

class QuestionList
{
public:
	QuestionList();
	~QuestionList();

	std::vector<double> calculate();
	Question * get(int N);
	const int size();

	

private:
	std::vector<Question *> List;
	std::vector<std::vector<double>> T;
	void initT();
	double calculateExpert(int N);
	void read();
 
};

