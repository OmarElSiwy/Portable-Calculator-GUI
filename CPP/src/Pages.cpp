#include "Pages.h"


Pages::Pages(QWidget *parent) : QWidget(parent)
{
    scrollArea = new QScrollArea(this);
    ActualLayout = new QVBoxLayout(scrollArea);
    scrollWrapper = new QWidget(scrollArea);

    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    ActualLayout->setAlignment(Qt::AlignTop);
    ActualLayout->setSpacing(0);
    ActualLayout->setContentsMargins(0, 0, 0, 0);

    scrollWrapper->setLayout(ActualLayout);
    scrollArea->setWidget(scrollWrapper);
    scrollArea->setWidgetResizable(true);
}

Pages::~Pages() {
    this->deleteLater();
}

void Pages::append(QParagraph* a)
{
    ActualLayout->addWidget(a);
    list.push_back(a);
}

void Pages::ScrollTo(QString TitleName)
{
    // Find QParagraphItem with specified TitleName
    for (auto p : list) {
        if (p->GetTitle() == TitleName) {
            auto pos = p->mapTo(scrollArea->widget(), QPoint(0, 0));

            ScrollAnimaton = new QPropertyAnimation(scrollArea->verticalScrollBar());
            ScrollAnimaton->setDuration(500);
            ScrollAnimaton->setStartValue(scrollArea->verticalScrollBar()->value());
            ScrollAnimaton->setEndValue(pos.y());
            ScrollAnimaton->start(QAbstractAnimation::DeleteWhenStopped);
            return;
        }
    }
}
