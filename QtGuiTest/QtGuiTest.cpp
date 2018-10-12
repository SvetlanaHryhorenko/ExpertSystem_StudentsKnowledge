#include "QtGuiTest.h"


QtGuiTest::QtGuiTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	

	//start();
	nextQuestion();
}


void QtGuiTest::start()
{
	info = new QWidget(this);

	QHBoxLayout *layout = new QHBoxLayout(info);

	QPushButton *start_button = new QPushButton(info);
	start_button->setText(tr("Start"));
	layout->addWidget(start_button);
	
	setCentralWidget(info);
	connect(start_button, SIGNAL(clicked()), this, SLOT(nextQuestion()));
}

void QtGuiTest::nextQuestion()
{
	if (questionNumber >= list.size())
	{
		result();
		return;
	}

	if (dynamic_cast<Question1*>(list.get(questionNumber)))
	{
		Question1 *question = dynamic_cast<Question1*>(list.get(questionNumber));
		question1(question);
	}

	if (dynamic_cast<Question2*>(list.get(questionNumber)))
	{
		Question2 *question = dynamic_cast<Question2*>(list.get(questionNumber));
		question2(question);
	}

	if (dynamic_cast<Question3*>(list.get(questionNumber)))
	{
		Question3 *question = dynamic_cast<Question3*>(list.get(questionNumber));
		question3(question);
	}
	
	if (dynamic_cast<Question4*>(list.get(questionNumber)))
	{
		Question4 *question = dynamic_cast<Question4*>(list.get(questionNumber));
		question4(question);
	}
	
	if (dynamic_cast<Question5*>(list.get(questionNumber)))
	{
		Question5 *question = dynamic_cast<Question5*>(list.get(questionNumber));
		question5(question);
	}
	
	if (dynamic_cast<Question6*>(list.get(questionNumber)))
	{
		Question6 *question = dynamic_cast<Question6*>(list.get(questionNumber));
		question6(question);
	}
	
	if (dynamic_cast<Question7*>(list.get(questionNumber)))
	{
		Question7 *question = dynamic_cast<Question7*>(list.get(questionNumber));
		question7(question);
	}

	questionNumber++;
}

void QtGuiTest::question1(Question1 *question)
{
	info = new QWidget(this);

	QVBoxLayout *layout = new QVBoxLayout(info);

	QLabel *label = new QLabel(info);
	label->setText(QString::fromStdString(question->getQuestion()));
	layout->addWidget(label);

	QPushButton *yes_button = new QPushButton(info);
	yes_button->setText(tr("Yes"));
	layout->addWidget(yes_button);

	QPushButton *no_button = new QPushButton(info);
	no_button->setText(tr("No"));
	layout->addWidget(no_button);

	QButtonGroup *_btnGroup = new QButtonGroup(info);
	_btnGroup->addButton(yes_button, 1);
	_btnGroup->addButton(no_button, 0);

	setCentralWidget(info);

	connect(_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(answerQuestion1(int)));

	//connect(no_button, SIGNAL(clicked(bool)), this, SLOT(answerQuestion1(/*question,*/ false)));
	//connect(yes_button, SIGNAL(clicked(true)), this, SLOT(answerQuestion1(/*question,*/ /*true*/bool)));
}

void QtGuiTest::answerQuestion1(/*Question1 *question,*/ /*bool*/int answer)
{
	Question1 *question = dynamic_cast<Question1*>(list.get(questionNumber - 1));
	//question->answerQuestion(answer);
	sum += question->getResult(answer);	
	nextQuestion();
}

void QtGuiTest::question2(Question2 *question)
{
	info = new QWidget(this);

	QVBoxLayout *layout = new QVBoxLayout(info);

	QLabel *label = new QLabel(info);
	label->setText(QString::fromStdString(question->getQuestion()));
	layout->addWidget(label);

	//std::vector<QPushButton *> buttons;
	QButtonGroup *_btnGroup = new QButtonGroup(info);

	for (int i = 0; i < question->answersSize(); i++)
	{
		QPushButton *button = new QPushButton(info);
		layout->addWidget(button);
		_btnGroup->addButton(button, i);
		button->setText(QString::fromStdString(question->getTextAnswer(i)));
	}

	setCentralWidget(info);

	connect(_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(answerQuestion2(int)));

	//connect(no_button, SIGNAL(clicked(bool)), this, SLOT(answerQuestion1(/*question,*/ false)));
	//connect(yes_button, SIGNAL(clicked(true)), this, SLOT(answerQuestion1(/*question,*/ /*true*/bool)));
}

void QtGuiTest::answerQuestion2(/*Question1 *question,*/ /*bool*/int answer)
{
	Question2 *question = dynamic_cast<Question2*>(list.get(questionNumber - 1));
	//question->answerQuestion(answer);
	sum += question->getResult(answer);
	nextQuestion();
}


void QtGuiTest::question3(Question3 *question)
{
	info = new QWidget(this);
	
	checkBox.clear();
	QVBoxLayout *layout = new QVBoxLayout(info);

	QLabel *label = new QLabel(info);
	label->setText(QString::fromStdString(question->getQuestion()));
	layout->addWidget(label);

	//std::vector<QPushButton *> buttons;
	//QButtonGroup *_btnGroup = new QButtonGroup(info);
	//std::vector<QCheckBox *> checkBox;

	for (int i = 0; i < question->answersSize(); i++)
	{
		QCheckBox *button = new QCheckBox(info);
		layout->addWidget(button);
		checkBox.push_back(button);
		//_btnGroup->addButton(button, i);
		button->setText(QString::fromStdString(question->getTextAnswer(i)));

		//connect(button, SIGNAL(stateChanged(int)), SLOT([&](int state) {
		//	boolList[i] = /*!boolList[i];*/state; }));
	}

	setCentralWidget(info);

	QPushButton *ok_button = new QPushButton(info);
	ok_button->setText(tr("OK"));
	layout->addWidget(ok_button);
	connect(ok_button, SIGNAL(clicked()), this, SLOT(answerQuestion3()));

}

void QtGuiTest::answerQuestion3(/*int answer, QList<QCheckBox *> &checkBox*/)
{
	std::vector<bool> boolList;
	Question3 *question = dynamic_cast<Question3*>(list.get(questionNumber - 1));
	for (int i = 0; i < question->answersSize(); i++)
	{
		boolList.push_back(false);
	}
	for (int i = 0; i < checkBox.size(); i++)
	{
		if (checkBox[i]->isChecked())
			boolList[i] = true;
	}
	sum += question->getResult(boolList);
	nextQuestion();
}


void QtGuiTest::question4(Question4 *question)
{
	info = new QWidget(this);
	lines.clear();

	QVBoxLayout *layout = new QVBoxLayout(info);

	QLabel *label = new QLabel(info);
	label->setText(QString::fromStdString(question->getQuestion()));
	layout->addWidget(label);

	QLineEdit *line = new QLineEdit(info);
	lines.push_back(line);
	layout->addWidget(line);

	setCentralWidget(info);

	QPushButton *ok_button = new QPushButton(info);
	ok_button->setText(tr("OK"));
	layout->addWidget(ok_button);
	connect(ok_button, SIGNAL(clicked()), this, SLOT(answerQuestion4()));

}

void QtGuiTest::answerQuestion4(/*int answer, QList<QCheckBox *> &checkBox*/)
{
	Question4 *question = dynamic_cast<Question4*>(list.get(questionNumber - 1));
	
	sum += question->getResult(lines[0]->text().toDouble());
	nextQuestion();
}

void QtGuiTest::question5(Question5 *question)
{
	info = new QWidget(this);
	lines.clear();


	QVBoxLayout *layout = new QVBoxLayout(info);

	QLabel *label = new QLabel(info);
	label->setText(QString::fromStdString(question->getQuestion()));
	layout->addWidget(label);

	QLineEdit *line_min = new QLineEdit(info);
	lines.push_back(line_min);
	layout->addWidget(line_min);

	QLineEdit *line_max = new QLineEdit(info);
	lines.push_back(line_max);
	layout->addWidget(line_max);

	setCentralWidget(info);

	QPushButton *ok_button = new QPushButton(info);
	ok_button->setText(tr("OK"));
	layout->addWidget(ok_button);
	connect(ok_button, SIGNAL(clicked()), this, SLOT(answerQuestion5()));

}

void QtGuiTest::answerQuestion5()
{
	Question5 *question = dynamic_cast<Question5*>(list.get(questionNumber - 1));

	sum += question->getResult(lines[0]->text().toDouble(), lines[1]->text().toDouble());
	nextQuestion();
}


void QtGuiTest::question6(Question6 *question)
{
	info = new QWidget(this);
	lines.clear();


	QVBoxLayout *layout = new QVBoxLayout(info);

	QLabel *label = new QLabel(info);
	label->setText(QString::fromStdString(question->getQuestion()));
	layout->addWidget(label);

	QLabel *label0 = new QLabel(info);
	label0->setText("MIN from");
	layout->addWidget(label0);

	QLineEdit *line_min0 = new QLineEdit(info);
	lines.push_back(line_min0);
	layout->addWidget(line_min0);

	QLabel *label1 = new QLabel(info);
	label1->setText("    to");
	layout->addWidget(label1);

	QLineEdit *line_min1 = new QLineEdit(info);
	lines.push_back(line_min1);
	layout->addWidget(line_min1);

	QLabel *label2 = new QLabel(info);
	label2->setText("MAX from");
	layout->addWidget(label2);

	QLineEdit *line_max0 = new QLineEdit(info);
	lines.push_back(line_max0);
	layout->addWidget(line_max0);

	QLabel *label3 = new QLabel(info);
	label3->setText("    to");
	layout->addWidget(label3);

	QLineEdit *line_max1 = new QLineEdit(info);
	lines.push_back(line_max1);
	layout->addWidget(line_max1);

	setCentralWidget(info);

	QPushButton *ok_button = new QPushButton(info);
	ok_button->setText(tr("OK"));
	layout->addWidget(ok_button);
	connect(ok_button, SIGNAL(clicked()), this, SLOT(answerQuestion6()));

}

void QtGuiTest::answerQuestion6()
{
	Question6 *question = dynamic_cast<Question6*>(list.get(questionNumber - 1));

	sum += question->getResult(lines[1]->text().toDouble(), lines[2]->text().toDouble(),
		lines[1]->text().toDouble()- lines[0]->text().toDouble(), lines[3]->text().toDouble() - lines[2]->text().toDouble());
	nextQuestion();
}

void QtGuiTest::question7(Question7 *question)
{
	info = new QWidget(this);
	lines.clear();


	QVBoxLayout *layout = new QVBoxLayout(info);

	QLabel *label = new QLabel(info);
	label->setText(QString::fromStdString(question->getQuestion()));
	layout->addWidget(label);
	
	QLineEdit *line = new QLineEdit(info);
	lines.push_back(line);
	layout->addWidget(line);

	setCentralWidget(info);

	QPushButton *ok_button = new QPushButton(info);
	ok_button->setText(tr("OK"));
	layout->addWidget(ok_button);
	connect(ok_button, SIGNAL(clicked()), this, SLOT(answerQuestion7()));

}

void QtGuiTest::answerQuestion7()
{
	Question7 *question = dynamic_cast<Question7*>(list.get(questionNumber - 1));

	sum += question->getResult(lines[0]->text().toStdString());
	nextQuestion();
}

void QtGuiTest::menu()
{
	info = new QWidget(this);

	QHBoxLayout *layout = new QHBoxLayout(info);

	QPushButton *expert_button = new QPushButton(info);
	expert_button->setText(tr("New Expert"));
	QPushButton *result_button = new QPushButton("Result");
	
	layout->addWidget(expert_button);
	layout->addWidget(result_button);


	setCentralWidget(info);

	connect(expert_button, SIGNAL(clicked()), this, SLOT(newExpert()));
	connect(result_button, SIGNAL(clicked()), this, SLOT(result()));
}

void QtGuiTest::newExpert()
{
	questionNumber = 0;
	nextQuestion();
}

void QtGuiTest::result()
{
	info = new QWidget(this);
	
	QLabel *label = new QLabel(info);
	QString text;
	
	text += QString::number(sum);
	label->setText(text);

	QPushButton *button = new QPushButton(info);
	button->setText(tr("Try again"));
	connect(button, SIGNAL(clicked()), this, SLOT(newExpert()));

	QVBoxLayout *layout = new QVBoxLayout(info);
	layout->addWidget(label);
	layout->addWidget(button);

	setCentralWidget(info);

}