#pragma once

#include <QWidget>
#include "BorderLayout.h"
#include "Components/QSideBar.h"
#include "Components/QTabTracker.h"
#include "Components/QToolBar.h"
#include "Pages.h"
#include "Components/QParagraph.h"
#include <QStackedWidget>

class ControlledView : public QWidget {
    Q_OBJECT
public:
    // Constructor + Destructor
    explicit ControlledView(QWidget* parent = nullptr);
    ~ControlledView();
signals:
    void CurrentPage(int index);
public slots:
    void ChangePage(int index);
private:
    Pages* HomePage;
    Pages* ExpectationsA;
    Pages* ExpectationsB;
    Pages* ExpectationsC;
    Pages* ExpectationsD;
    Pages* Extras;
    std::vector<Pages*> list;

    QStackedWidget* Navigator;

    BorderLayout* layout;
    SideBar* Sidebar;
    TabTracker* TabTrackerW;
    QToolBars* Toolbar;
};
