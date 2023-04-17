#include "Components/QTabTracker.h"
#include <QTabBar>

TabTracker::TabTracker(QWidget* parent) 
    : QWidget(parent), TabLayout(new QTabWidget(this))
{
    // Modify the Tabs Widget
    TabLayout->setTabsClosable(true);
    TabLayout->setMovable(true);
    TabLayout->setStyleSheet("QTabBar::tab:selected { background-color: rgba(255, 255, 255, 0.3); }");

    // Signals and Slots
    // If closed close the tab
    // connect(TabLayout->tabBar(), &QTabBar::tabCloseRequested, &TabTracker::RemoveTab);
}

TabTracker::~TabTracker() {
    TabLayout->deleteLater();
}

void TabTracker::RemoveTab(int index) {
    auto it = TabLayout->widget(index);
    TabLayout->removeTab(index);
    it->deleteLater();
    TabLayout->setCurrentIndex(index-1 >= 0 ? index-1 : NULL);
}

void TabTracker::AddTab(int index) {
    TabLayout->addTab(new QWidget(), Names[index]);
    TabLayout->setCurrentIndex(index);
}
