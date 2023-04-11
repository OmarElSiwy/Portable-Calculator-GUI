#pragma once
// Copyrighted by Omar
// Plz no steal this memmory inefficient code :)

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <vector>
#include <QLabel>

// QPargraphItem

struct QParagraphItem : public QWidget {
	Q_OBJECT
public:
	enum ItemType { Description, Picture, Code };

	explicit QParagraphItem(ItemType Type, QWidget* parent = nullptr);
	QParagraphItem() = delete;
	~QParagraphItem();

	QParagraphItem(const QParagraphItem& other) = delete;
	QParagraphItem(const QParagraphItem&& other) = delete;

	QParagraphItem& operator=(const QParagraphItem& other) = delete;
	QParagraphItem& operator=(const QParagraphItem&& other) = delete;
private:
	ItemType CurrType;
};

// QParagraphTitle

struct QParagraphTitle : public QWidget {
	Q_OBJECT
public:
	explicit QParagraphTitle(const char* Title, QWidget *parent);
	QParagraphTitle() = delete;
	~QParagraphTitle();

	QParagraphTitle(const QParagraphTitle& other) = delete;
	QParagraphTitle(const QParagraphTitle&& other) = delete;

	QParagraphTitle& operator=(const QParagraphTitle& other) = delete;
	QParagraphTitle& operator=(const QParagraphTitle&& other) = delete;
protected:
	void mousePressEvent(QMouseEvent* event) override;
private slots:
	void RotateDropDown();
private:
	bool DropDownState;
	bool BookmarkState;

	QLabel* DropDownIcon;
	QLabel* Title;
	QLabel* BookmarkIcon;

	QHBoxLayout* ParagraphLayout;
};

// QPargraph

class QParagraph : public QWidget {
	Q_OBJECT
public:
	explicit QParagraph(const char* Title, std::vector<QParagraphItem*> ParagraphItems, QWidget* parent);
	QParagraph() = delete;
	~QParagraph();

	QParagraph(const QParagraph& other) = delete;
	QParagraph(const QParagraph&& other) = delete;

	QParagraph& operator=(const QParagraph& other) = delete;
	QParagraph& operator=(const QParagraph&& other) = delete;
protected:

private slots:

public slots:

private:
	const char* CurrTitle;
	QVBoxLayout* WidgetLayout;
	QVBoxLayout* OverallLayout;
};