#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiTest.h"

#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include <QButtonGroup>
#include <QCheckBox>
#include <QLineEdit>

#include "QuestionList.h"

class QtGuiTest : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiTest(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiTestClass ui;
	QWidget * info;
	int questionNumber = 0;
	double sum = 0;
	QuestionList list;

	std::vector<QCheckBox *> checkBox;
	std::vector<QLineEdit *> lines;

	void start();
	void nextQuestion();

	void question1(Question1 *question);
	void question2(Question2 *question);
	void question3(Question3 *question);
	void question4(Question4 *question);
	void question5(Question5 *question);
	void question6(Question6 *question);
	void question7(Question7 *question);

	


private slots:
	void menu();
	void newExpert();
	void result();
	

	void answerQuestion1(int answer);
	void answerQuestion2(int answer);
	void answerQuestion3();
	void answerQuestion4();
	void answerQuestion5();
	void answerQuestion6();
	void answerQuestion7();

};
