#include "ControllerScreen.h"
#include <QApplication>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	ControllerScreen *UserScreen;
	UserScreen->show();
	app.exec();
}