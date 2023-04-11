#pragma once

#include <QWidget>

class Home : public QWidget {
	Q_OBJECT
public:
	explicit Home(QWidget* parent = nullptr);
	Home() = delete;
	~Home();

	Home(const Home& obj) = delete;
	Home(const Home&& obj) = delete;

	Home& operator=(const Home& obj) = delete;
	Home& operator=(const Home&& obj) = delete;
};