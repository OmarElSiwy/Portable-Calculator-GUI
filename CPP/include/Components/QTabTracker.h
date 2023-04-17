#pragma once

#include <QWidget>
#include <QLabel>
#include <QTabWidget>

class TabTracker : public QWidget {
    Q_OBJECT
public:
    // Constructor + Destructor
    explicit TabTracker(QWidget* parent = nullptr);
    ~TabTracker();

    // Move + Copy Constructor
    TabTracker(const TabTracker& obj) = delete;
    TabTracker(const TabTracker&& obj) = delete;

    // Move + Copy Assignment
    TabTracker& operator=(const TabTracker &obj) = delete;
    TabTracker& operator=(const TabTracker &&obj) = delete;

    QTabWidget* GetTabLayout() {return TabLayout;}
signals:
    // void ButtonClicked(); built in
    // void ButtonClosed(); built in
private slots:
    void RemoveTab(int index);
public slots:
    void AddTab(int index);
private:
    QTabWidget* TabLayout;
    const char* Names[6] = {"About Me", "Expectations A",
                            "Expectations B", "Expectations C", "Expectations D", "Extras"};
};
