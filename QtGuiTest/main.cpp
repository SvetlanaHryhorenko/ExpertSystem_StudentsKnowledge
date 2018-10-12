#include "QtGuiTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiTest w;
	w.show();
	return a.exec();
}
