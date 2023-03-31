#pragma once

#include <QWidget>
#include <QLabel>
#include <QIcon>

class QParagraph : public QWidget {
    Q_OBJECT
public:
    QParagraph();
    ~QParagraph() = default;

    QParagraph(const QParagraph &obj) = delete;
    QParagraph& operator=(const QParagraph &Other) = delete;

    QParagraph(const QParagraph &&obj) = delete;
    QParagraph& operator=(const QParagraph &&Other) = delete;

private slots:
    bool MinimizeParagraph(const bool Minimize);
private:
    QLabel *Paragraph;
};