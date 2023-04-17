#pragma once

#include "Components/QParagraph.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include <QScrollBar>
#include <QPropertyAnimation>

class Pages : public QWidget {
    Q_OBJECT
public:
    // Constructor and Destructor
    explicit Pages(QWidget *parent = nullptr);
    ~Pages();

    // Copy + Move Constructor
    Pages(const Pages &obj) = delete;
    Pages(const Pages &&obj) = delete;

    // Copy + Move Assignment
    Pages& operator=(const Pages& obj) = delete;
    Pages& operator=(const Pages&& obj) = delete;

    void append(QParagraph* a);
    std::vector<QParagraph*> GetList() {return list;}
public slots:
    void ScrollTo(QString TitleName);
private:
    QScrollArea* scrollArea;
    QVBoxLayout* ActualLayout;
    QWidget* scrollWrapper;
    std::vector<QParagraph*> list;
    QPropertyAnimation* ScrollAnimaton;
};
