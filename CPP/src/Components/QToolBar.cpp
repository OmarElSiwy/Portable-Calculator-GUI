#include "Components/QToolBar.h"

QToolBars::QToolBars(QWidget* parent) : QWidget(parent) {
    MenuButton = new QPushButton(this);
    Layout = new QHBoxLayout(this);

    // Set Labels and Style Sheets
    Layout->setGeometry(parent->geometry());
    Layout->addWidget(MenuButton);

    setLayout(Layout);
}

QToolBars::~QToolBars() {
    this->deleteLater();
}
