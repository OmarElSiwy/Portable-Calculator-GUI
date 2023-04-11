#pragma once

#include <QWidget>
#include <vector>

struct TabItem : public QWidget {
	Q_OBJECT
public:
	explicit TabItem(QWidget *parent = nullptr);
	TabItem() = delete;
	~TabItem();

	TabItem(const TabItem& other) = delete;
	TabItem(const TabItem&& other) = delete;

	TabItem& operator=(const TabItem& other) = delete;
	TabItem& operator=(const TabItem&& other) = delete;
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	void dropEvent(QDropEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
private:
	QLabel* item;
};

class TabTracker : public QWidget {
	Q_OBJECT
public:
	explicit TabTracker(QWidget* parent = nullptr);
	TabTracker() = delete;
	~TabTracker();

	TabTracker(const TabTracker& other) = delete;
	TabTracker(const TabTracker&& other) = delete;

	TabTracker& operator=(const TabTracker& other) = delete;
	TabTracker& operator=(const TabTracker&& other) = delete;
private slots:
	void OrderChanged();

private:
	std::vector<TabItem*> list;
};