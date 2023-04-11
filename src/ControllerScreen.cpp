#include "ControllerScreen.h"
#include "CustomWidgets/TabTracker.h"
#include "CustomWidgets/Sidebar.h"
#include "Views.h"

ControllerScreen::ControllerScreen(QWidget* parent = nullptr) : QWidget(parent) {
    setWindowFlags(Qt::FramelessWindowHint);
    ProgramLayout->addWidget(new TabTracker(this), BorderLayout::South);
    ProgramLayout->addWidget(new Sidebar(this), BorderLayout::West);
    ProgramLayout->addWidget(new Views(this), BorderLayout::Center);

    setLayout(ProgramLayout);
}

ControllerScreen::~ControllerScreen() {
    delete this;
}