#pragma once

#include <QWidget>
#include "CentralViews/Expectations.h"
#include "CentralViews/Home.h"
#include "CentralViews/Settings.h"
#include "CentralViews/Search.h"

class Views : public QWidget {
	Q_OBJECT
public:
    explicit Views(QWidget* parent = nullptr);
    ~Views();

    Views(const Views& obj) = delete;
    Views& operator=(const Views& Other) = delete;

    Views(const Views&& obj) = delete;
    Views& operator=(const Views&& Other) = delete;
signals:
    ActiveView ViewChanged();
private slots:
    void ChangeView();
public:
    enum ActiveView { AboutMe, ExpectationsA, ExpectationsB, ExpectationsC, ExpectationsD, Settings };
    ActiveView CurrView;
};