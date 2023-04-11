#pragma once

#include <QWidget>
#include <QTextEdit>

class Search : public QWidget {
	Q_OBJECT
public:
	explicit Search(QWidget* parent = nullptr);
	Search() = delete;
	~Search();

	Search(const Settings& obj) = delete;
	Search(const Settings&& obj) = delete;

	Search& operator=(const Search& obj) = delete;
	Search& operator=(const Search&& obj) = delete;
signals:

private slots:

public slots:

private:
	QTextEdit* UserInput;
};