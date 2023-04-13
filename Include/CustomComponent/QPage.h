#ifndef QPAGE_H
#define QPAGE_H

#include <QWidget>
#include "Include/CustomComponent/QParagraph.h"

class QPage : public QWidget {
    Q_OBJECT
public:
    enum PageType { Home, ExpectationsA, ExpectationsB, ExpectationsC, ExpectationsD };

    explicit QPage(QWidget* parent);
    QPage() = delete;
    ~QPage();

    QPage(QPage &obj) = delete;
    QPage(QPage &&obj) = delete;

    QPage& operator=(QPage &obj) = delete;
    QPage& operator=(QPage &&obj) = delete;
private slots:
    void SwitchPreset(QPage::PageType TargetType);
private:
    PageType* CurrType;
};

#endif // QPAGE_H
