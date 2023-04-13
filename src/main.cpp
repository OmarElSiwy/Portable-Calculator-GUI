#include "Include/ControlView.h"
#include "Include/QUpdater.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow* w = new QMainWindow();
    w->show();
    return app.exec();
}
