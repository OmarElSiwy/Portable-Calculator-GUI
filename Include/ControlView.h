#ifndef CONTROLVIEW_H
#define CONTROLVIEW_H

#include "Include/CustomLayout/BorderLayout.h"
#include <QWidget>

class ControlView : public QWidget {
    Q_OBJECT
public:
    explicit ControlView(QWidget* parent);
    ControlView() = delete;
    ~ControlView();

    ControlView(ControlView &obj) = delete;
    ControlView(ControlView &&obj) = delete;

    ControlView& operator=(ControlView &obj) = delete;
    ControlView& operator=(ControlView &&obj) = delete;
signals:

private:

};

#endif // CONTROLVIEW_H
