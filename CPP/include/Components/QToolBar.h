#pragma once

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QHBoxLayout>
#include "Components/QSideBar.h"

class QToolBars : public QWidget {
    Q_OBJECT
public:
    // Constructor + Destructor
    explicit QToolBars(QWidget* parent = nullptr);
    ~QToolBars();

    // Move + Copy Constructor
    QToolBars(const QToolBars& obj) = delete;
    QToolBars(const QToolBars&& obj) = delete;

    // Move + Copy Assignment
    QToolBars& operator=(const QToolBars &obj) = delete;
    QToolBars& operator=(const QToolBars &&obj) = delete;

    QPushButton* GetButton() {return MenuButton;};
signals:
    // void Clicked(); built-in
private:
    QPushButton* MenuButton;
    QHBoxLayout* Layout;
};
