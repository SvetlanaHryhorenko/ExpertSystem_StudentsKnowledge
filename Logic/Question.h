#pragma once
#include <vector>
#include <string>

class Question
{
public:
	Question();
	~Question();

	void setQuestion(std::string q);
	std::string getQuestion();
	std::vector<std::vector<double>> getT();

	virtual void calculate() = 0;

protected:
	std::vector<std::vector<double>> T;
	void initT(int N);


private:
	
	std::string question;

};

