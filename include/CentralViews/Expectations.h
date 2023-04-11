#pragma once

#include <QWidget>

class Expectations : public QWidget {
	Q_OBJECT
public:
	explicit Expectations(QWidget* parent = nullptr);
	Expectations() = delete;
	~Expectations();

	Expectations(const Expectations& obj) = delete;
	Expectations(const Expectations&& obj) = delete;

	Expectations& operator=(const Expectations& obj) = delete;
	Expectations& operator=(const Expectations&& obj) = delete;

	enum ExpectationType { A, B, C, D };
public slots:
	void SetExpectationType(ExpectationType TargetType);
private:
	ExpectationType Type;
};