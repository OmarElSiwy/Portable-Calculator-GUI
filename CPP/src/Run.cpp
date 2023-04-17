#include <QApplication>
#include "ControlledView.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    ControlledView* window = new ControlledView();
    window->show();
    return app.exec();
}
