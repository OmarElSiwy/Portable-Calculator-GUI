#pragma once

#include <QWidget>
#include "CustomLayouts/QScreenLayout.h"
#include "CustomLayouts/QSideBar.h"
#include "CustomWidgets/QBarWidget.h"
#include "CustomWidgets/QParagraph.h"
#include "CustomWidgets/QTitle.h"

class ControllerScreen : public QWidget {
    Q_OBJECT
public:
    ControllerScreen();
    ~ControllerScreen() = default;

    ControllerScreen(const ControllerScreen &obj) = delete;
    ControllerScreen& operator=(const ControllerScreen &Other) = delete;

    ControllerScreen(const ControllerScreen &&obj) = delete;
    ControllerScreen& operator=(const ControllerScreen &&Other) = delete;
};