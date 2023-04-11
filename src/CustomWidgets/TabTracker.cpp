#include "CustomWidgets/TabTracker.h"
#include <QPainter>
#include <QPainterPath>
#include <QMimeData>
#include <QMouseEvent>
#include <QDrag>

// TabItem Implementation

TabItem::TabItem(QWidget* parent = nullptr) : QWidget(parent) {
	item = new QLabel(this);
	item->setAlignment(Qt::AlignCenter);

	item->setFixedSize(100, 50);

	item->setStyleSheet("background-color: white;");
}

void TabItem::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing);

	QRectF rect = QRectF(0, 0, width() - 1, height() - 1);
	painter.setPen(QPen(Qt::black, 2));

	painter.drawRoundedRect(rect, 10, 10);

	QPainterPath path;
	QPointF p1(rect.right() - 10, rect.bottom() - 5);
	QPointF p2(rect.right() - 5, rect.bottom() - 10);
	path.moveTo(p1);
	path.lineTo(p2);
	path.lineTo(rect.bottomRight());
	painter.drawPath(path);
}

void TabItem::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		QMimeData* mimeData = new QMimeData();
		
		QDrag* drag = new QDrag(this);
		drag->setMimeData(mimeData);

		drag->exec(Qt::CopyAction);
	}
}

void TabItem::dragEnterEvent(QDragEnterEvent* event) {
	if (event->mimeData()->hasText())
		event->acceptProposedAction();
}	

void TabItem::dropEvent(QDropEvent* event) {

}

// Tab Tracker Implementation