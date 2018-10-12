#pragma once
#include <fstream>

#include "Question1.h"
#include "Question2.h"
#include "Question3.h"
#include "Question4.h"
#include "Question5.h"
#include "Question6.h"
#include "Question7.h"


class Reader
{
public:
	Reader();
	~Reader();

	std::vector<Question *> read();

private:
	std::vector<Question *> List;
	std::ifstream myfile;

	void readQuestion1();
	void readQuestion2();
	void readQuestion3();
	void readQuestion4();
	void readQuestion5();
	void readQuestion6();
	void readQuestion7();
};

