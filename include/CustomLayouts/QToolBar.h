#pragma once

#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QHBoxLayout>

class QToolBar : public QWidget {
    Q_OBJECT
public:
    QToolBar(const QIcon &&ExitIcon, const QIcon &&SizeIcon, const QIcon &&MinimizeIcon, const QIcon &&SettingsIcons);
    ~QToolBar();

    QToolBar(const QToolBar &other) = delete;
    QToolBar& operator=(const QToolBar &other) = delete;

    QToolBar(const QToolBar &&other) = delete;
    QToolBar& operator=(const QToolBar &&other) = delete;
signals:

private slots:

public slots:

private:
    QHBoxLayout *MainLayout;
    QPushButton *Exit;
    QPushButton *ChangeSize;
    QPushButton *Minimize;
    QPushButton *Settings;
};