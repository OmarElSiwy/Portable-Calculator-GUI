#include "ControllerScreen.h"
#include <QApplication>
#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	ControllerScreen *UserScreen;
	UserScreen->show();
	app.exec();
}