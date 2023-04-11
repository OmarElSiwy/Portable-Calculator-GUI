#pragma once

#include <QWidget>
#include "CustomLayouts/BorderLayout.h"

class ControllerScreen : public QWidget {
    Q_OBJECT
public:
    explicit ControllerScreen(QWidget* parent = nullptr);
    ~ControllerScreen();

    ControllerScreen(const ControllerScreen &obj) = delete;
    ControllerScreen& operator=(const ControllerScreen &Other) = delete;

    ControllerScreen(const ControllerScreen &&obj) = delete;
    ControllerScreen& operator=(const ControllerScreen &&Other) = delete;
private slots:
    void SwitchCentralView(); // Switches the Central Widget View between Settings-About Me-Expectations Screen
private:
    BorderLayout* ProgramLayout;
};