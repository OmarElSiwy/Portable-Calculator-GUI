#pragma once

#include <QWidget>
#include "QParagraph.h"

class QTitle : public QWidget {
    Q_OBJECT
public:
    QTitle(const int &TitleFontSize, const int &ParagraphFontSize, const QParagraph &AssociatedParagraph);
    ~QTitle() = default;

    QTitle(const QTitle &obj) = delete;
    QTitle& operator=(const QTitle &Other) = delete;

    QTitle(const QTitle &&obj) = delete;
    QTitle& operator=(const QTitle &&Other) = delete;

signals:
    bool WidgetHovered(const QMouseEvent *Action);
    bool BookMarkHovered(const QMouseEvent *Action);
    bool MinimizeIconHovered(const QMouseEvent *Action);

    bool BookMarkClicked(const QMouseEvent *Action);
    bool MinimizeIconClicked(const QMouseEvent *Action);

private slots:
    void ShowHover(const int &WidgetID);

public slots:
    void AddBookMarked();

private:
    QLabel *Title;
    QIcon *BookMarkIcon;
    QIcon * MinimizeIcon;
};