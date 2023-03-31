#pragma once

#include <QGridLayout>
#include <QPropertyAnimation>
#include <vector>

class QScreenLayout : public QWidget {
    Q_OBJECT
public:
    QScreenLayout();
    ~QScreenLayout();

    QScreenLayout(const QScreenLayout &other) = delete;
    QScreenLayout& operator=(const QScreenLayout &other) = delete;

    QScreenLayout(const QScreenLayout &&other) = delete;
    QScreenLayout& operator=(const QScreenLayout &&other) = delete;

public slots:
    int ChangedWindow();
    std::vector<QPropertyAnimation> NewBoomarkAdded;
private:
    QGridLayout *ScreenLayout;
};