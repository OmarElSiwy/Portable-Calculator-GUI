#ifndef QTABTRACKER_H
#define QTABTRACKER_H

#include <QWidget>
#include <QLabel>

struct QTab : public QWidget {
    Q_OBJECT
public:
    explicit QTab(QWidget* parent);
    QTab() = delete;
    ~QTab();

    QTab(QTab &obj) = delete;
    QTab(QTab &&obj) = delete;

    QTab& operator=(QTab &obj) = delete;
    QTab& operator=(QTab &&obj) = delete;
private:
    QLabel* TabName;
    QLabel* TabCloseButton;
};

class QPage {
public:
    enum PageType {Home, ExpectationsA, ExpectationsB, ExpectationsC, ExpectationsD };
};

class QTabTracker : public QWidget {
    Q_OBJECT
public:
    explicit QTabTracker(QWidget* parent);
    QTabTracker() = delete;
    ~QTabTracker();

    QTabTracker(QTabTracker &obj) = delete;
    QTabTracker(QTabTracker &&obj) = delete;

    QTabTracker& operator=(QTabTracker &obj) = delete;
    QTabTracker& operator=(QTabTracker &&obj) = delete;
signals:
    QPage::PageType PageRequest(int ButtonID);
private slots:
    void ChangeFocusTab(QPage::PageType CurrTab);
    void AddTab(QPage::PageType NewTab);
    void RemoveTab(QPage::PageType NewTab);
private:
    std::vector<QTab*> ActiveTabs;
};

#endif // QTABTRACKER_H
