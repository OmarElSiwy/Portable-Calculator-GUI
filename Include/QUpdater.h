#ifndef QUPDATER_H
#define QUPDATER_H

#include <QProcess>
#include <QProgressBar>
#include <QLabel>

class QUpdater : public QWidget {
    Q_OBJECT
public:
    explicit QUpdater(QWidget* parent);
    QUpdater() = delete;
    ~QUpdater();

    QUpdater(QUpdater &obj) = delete;
    QUpdater(QUpdater &&obj) = delete;

    QUpdater& operator=(QUpdater &obj) = delete;
    QUpdater& operator=(QUpdater &&obj) = delete;
private:
    QLabel* ProcessName;
    QProcess* Git;
    QProgressBar* CurrProgress;
};

#endif // QUPDATER_H
