#include "QUpdater.h"
#include <QVBoxLayout>

QUpdater::QUpdater(QWidget* parent) : QWidget(parent) {
    // Setting up Title with QProgressBar
    ProcessName->setText("Updating the Application Using Github Repository");

    QObject::connect(Git, &QProcess::readyReadStandardError, [&] () {
        QString output = Git->readAllStandardError();
        if (output.contains("Receiving")) {
            int progress = output.split(" ")[1].toInt();
            CurrProgress->setValue(progress);
        }
    });
    Git->setWorkingDirectory("");
    Git->start("git clone ");
    Git->waitForFinished();
}
