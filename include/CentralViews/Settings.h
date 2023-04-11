#pragma once

#include <QWidget>
#include <QFormLayout>

class Settings : public QWidget {
	Q_OBJECT
public:
	explicit Settings(QWidget* parent = nullptr);
	Settings() = delete;
	~Settings();

	Settings(const Settings& obj) = delete;
	Settings(const Settings&& obj) = delete;

	Settings& operator=(const Settings& obj) = delete;
	Settings& operator=(const Settings&& obj) = delete;
signals:

private slots:

public slots:

private:
	QFormLayout* ProgramLayout;
};