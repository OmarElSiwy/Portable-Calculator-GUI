#pragma once

#include <QWidget>

class Sidebar : public QWidget {
	Q_OBJECT
public:
	explicit Sidebar(QWidget* parent = nullptr)
	Sidebar() = delete;
	~Sidebar();

	Sidebar(const Sidebar& other) = delete;
	Sidebar(const Sidebar&& other) = delete;

	Sidebar& operator=(const Sidebar& other) = delete;
	Sidebar& operator=(const Sidebar&& other) = delete;
private slots:
	void AddBookmark(const char* Title);
	void RemoveBookmark(const char* Target);
private:
	// Layout
	QVBoxLayout* Layout;

	// Widget Dependencies
	QPushButton* HomeButton;
	QPushButton* SearchButton;
	QPushButton* ExpectationsA;
	QPushButton* ExpectationsB;
	QPushButton* ExpectationsC;
	QPushButton* ExpectationsD;
	QPushButton* Settings;
	QFrame* seperator;
};