#ifndef QSIDEBAR_H
#define QSIDEBAR_H

#include <QWidget>
#include <QPushButton>

class QPage {
public:
    enum PageType {Home, ExpectationsA, ExpectationsB, ExpectationsC, ExpectationsD };
};

class QSidebar : public QWidget {
    Q_OBJECT
public:
    explicit QSidebar(QWidget* parent);
    QSidebar() = delete;
    ~QSidebar();

    QSidebar(QSidebar &obj) = delete;
    QSidebar(QSidebar &&obj) = delete;

    QSidebar& operator=(QSidebar &obj) = delete;
    QSidebar& operator=(QSidebar &&obj) = delete;
signals:
    QPage::PageType ChangeRequested(int ButtonID);
private slots:
    void ChangeFocusTab(QPage::PageType obj);
private:
    std::vector<QPushButton*> ButtonIDStorage;
};

#endif // QSIDEBAR_H
