#include "CustomWidgets/Sidebar.h"

Sidebar::Sidebar(QWidget* parent = nullptr) : QWidget(parent) {
	HomeButton->setText("Home");
	ExpectationsA->setText("ExpectationsA");
	ExpectationsB->setText("ExpectationsB");
	ExpectationsC->setText("ExpectationsC");
	ExpectationsD->setText("ExpectationsD");
	Search->setText("Search");
	Settings->setText("Settings");

	seperator->setFrameShape(QFrame::VLine);
	seperator->setFrameShadow(QFrame::Sunken);

	Layout->addWidget(HomeButton);
	Layout->addWidget(ExpectationsA);
	Layout->addWidget(ExpectationsB);
	Layout->addWidget(ExpectationsC);
	Layout->addWidget(ExpectationsD);
	Layout->addWidget(Search);
	Layout->addWidget(Settings);
	Layout->addWidget(seperator); // Curr Size is 8

	// Settings Signals and Slots
	connect(HomeButton, &QPushButton::clicked, );
	connect(ExpectationsA, &QPushButton::clicked, );
	connect(ExpectationsB, &QPushButton::clicked, );
	connect(ExpectationsC, &QPushButton::clicked, );
	connect(ExpectationsD, &QPushButton::clicked, );
	connect(Search, &QPushButton::clicked, );
	connect(Settings, &QPushButton::clicked, );

	setLayout(Layout);
}

Sidebar::~Sidebar() {
	delete Layout;
}

void Sidebar::AddBookmark(const char* Title) {
	auto* NewButton = new QPushButton(Title);
	connect(NewButton, &QPushButton::clicked,)
	Layout.addWidget(NewButton);
}

void Sidebar::RemoveBookmark(const char* TargetText) {
	QLayoutItem* item;
	while ((item = Layout->takeAt(0)) != nullptr) {
		if (item->widget() != nullptr && item->widget()->text() == targetText) {
			QWidget* widget = item->widget();
			layout->removeWidget(widget);
			delete widget;
		} else {
			Layout->addItem(item);
		}
	}
}