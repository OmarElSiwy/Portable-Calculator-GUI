#pragma once

#include <QWidget>
#include <QVBoxLayout>

class QSidebar : public QWidget {
    Q_OBJECT
public:
    QSidebar();
    ~QSidebar();

    QSidebar(const QSidebar &other) = delete;
    QSidebar& operator=(const QSidebar &other) = delete;

    QSidebar(const QSidebar &&other) = delete;
    QSidebar& operator=(const QSidebar &&other) = delete;
signals:

private slots:

public slots:

private:

};