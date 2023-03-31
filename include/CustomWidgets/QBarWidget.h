#pragma once

#include <QWidget>
#include <QLabel>
#include <QIcon>

class QBarWidget : public QWidget {
    Q_OBJECT
public:
    QBarWidget();
    ~QBarWidget() = default;

    QBarWidget(const QBarWidget &obj) = delete;
    QBarWidget& operator=(const QBarWidget &Other) = delete;

    QBarWidget(const QBarWidget &&obj) = delete;
    QBarWidget& operator=(const QBarWidget &&Other) = delete;
signals:
    void clicked(const QMouseEvent *action);
public slots:
    void FindPath();
private:
    QLabel *MainTitle;
    QIcon *TitleIcon;
};