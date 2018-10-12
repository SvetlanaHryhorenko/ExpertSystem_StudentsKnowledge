#include "Reader.h"



Reader::Reader()
{
}


Reader::~Reader()
{
}

std::vector<Question *> Reader::read()
{
	
	
	int type;
	myfile.open("fantasy.txt");
	if (myfile.is_open())
	{
		while (myfile >> type)
		{
			
			switch (type)
			{
			case 1: readQuestion1();   	break;
			case 2: readQuestion2();	break;
			case 3: readQuestion3();	break;
			case 4: readQuestion4();	break;
			case 5: readQuestion5();	break;
			case 6: readQuestion6();	break;
			case 7: readQuestion7();	break;

			default:
				break;
			}
		}
		myfile.close();
	}
	return List;
}


void Reader::readQuestion1()
{
	std::string line;
	getline(myfile, line);
	getline(myfile, line);
	bool answer;
	myfile >> answer;
	
	Question1 *question = new Question1(line, answer);
	List.push_back(question);
					   
}

void Reader::readQuestion2() 
{
	std::string line;
	getline(myfile, line);
	getline(myfile, line);
	int number;
	myfile >> number;
	std::string answer;
	double point;
	std::vector<std::string> answers;
	std::vector< double> points;

	for(int i=0; i<number; i++)
	{
		getline(myfile, answer);
		getline(myfile, answer);
		answers.push_back(answer);
		myfile >> point;
		points.push_back(point);
	}

	Question2 *question = new Question2(line, answers, points);
	List.push_back(question);
}

void Reader::readQuestion3() 
{
	std::string line;
	getline(myfile, line);
	getline(myfile, line);
	int number;
	myfile >> number;
	std::string answer;
	double point;
	bool boolAnswer;
	std::vector<std::string> answers;
	std::vector< double> points;
	std::vector<bool> boolAnswers;


	for (int i = 0; i<number; i++)
	{
		getline(myfile, answer);
		getline(myfile, answer);
		answers.push_back(answer);
		myfile >> boolAnswer;
		boolAnswers.push_back(boolAnswer);
		myfile >> point;
		points.push_back(point);
	}

	Question3 *question = new Question3(line, answers, points, boolAnswers);
	List.push_back(question);
}

void Reader::readQuestion4() 
{
	std::string line;
	getline(myfile, line);
	getline(myfile, line);
	double answer, min, max;
	myfile >> answer;
	myfile >> min;
	myfile >> max;


	Question4 *question = new Question4(line, answer, min, max);
	List.push_back(question);
}

void Reader::readQuestion5() 
{
	std::string line;
	getline(myfile, line);
	getline(myfile, line);
	double min, max;
	myfile >> min;
	myfile >> max;

	Question5 *question = new Question5(line, min, max);
	List.push_back(question);
}

void Reader::readQuestion6() 
{
	std::string line;
	getline(myfile, line);
	getline(myfile, line);
	double min, max, min1,max1;
	myfile >> min;
	myfile >> min1;
	myfile >> max;
	myfile >> max1;
	

	Question6 *question = new Question6(line, min1, max, min1-min, max1-max);
	List.push_back(question);
}

void Reader::readQuestion7() 
{
	std::string line;
	getline(myfile, line);
	getline(myfile, line);

	int number;
	myfile >> number;
	std::string answer;
	std::vector<std::string> answers;
	getline(myfile, answer);
	for (int i = 0; i<number; i++)
	{
		getline(myfile, answer);
		answers.push_back(answer);
	}

	Question7 *question = new Question7(line, answers);
	List.push_back(question);
}
