// Copyrighted by Omar
// Plz no steal this memmory inefficient code :)

#include "CustomWidgets/QParagraph.h"
#include <QWidget>
#include <vector>

// QParagraphItem Implementation
QParagraphItem::QParagraphItem(ItemType Type) {
	switch (Type) {
		case Description:

		case Picture:

		case Code:

	}
}

QParagraphItem::~QParagraphItem() {
	switch (CurrType) {
		case Description:

		case Picture:

		case Code:

	}
}

// QParagraphTitle Implementation
QParagraphTitle::QParagraphTitle(const char* TitleText) {
	// Setting up Widgets + Style
	DropDownIcon->setPixmap();
	DropDownIcon->setContentsMargins(10, 5, 20, 5);

	BookmarkIcon->setPixmap();
	BookmarkIcon->setContentsMargins(0, 5, 10, 5);

	Title->setPlainText(TitleText);
	Title->setContentsMargins(0, 5, 50, 5);
	Title->setStyleSheet();

	// Setting Signals and Slots
	connect(BookmarkIcon, $QLabel::mousePressEvent, [=](QMouseEvent* event) { // if Bookmark is clicked
		if (event->button() == Qt::LeftButton) {
			
		}
	});

	// Adding them to layout
	ParagraphLayout->addWidget(DropDownIcon);
	ParagraphLayout->addWidget(Title);
	ParagraphLayout->addWidget(BookmarkIcon);

	setLayout(PargraphLayout);
}

QParagraphTitle::~QParagraphTitle() {
	delete DropDownIcon;
	delete BookmarkIcon;
	delete Title;
	delete ParagraphLayout;
}

void QParagraphTitle::mousePressEvent(QMouseEvent* event) {
	if (event->button == Qt::LeftButton) {
		emit [=]() { // Rotate the DropDown Icon and Deal with Parent Class

		};
	}
}

// QParagraph Implementation
QParagraph::QParagraph(const char* Title, std::vector<QParagraphItem*> ParagraphItems) {
	QLabel* TitleLabel(QString(Title));
	TitleLabel->setStyleSheet();

	for (QParagraphItem* Item : ParagraphItems)
		WidgetLayout>addWidget(Item);
	WidgetLayout->setStyleSheet();

	OverallLayout->addWidget(TitleLabel);
	OverallLayout->addLayout(WidgetLayout);
}

QParagraph::~QParagraph() {

}

struct QParagraph : public QWidget {
	Q_OBJECT
public:
	explicit QParagraph(std::vector<QParagraphItem*> ParagraphItems);
	QParagraph() = delete;
	~QParagraph();

	QParagraph(const QParagraph& other) = delete;
	QParagraph(const QParagraph&& other) = delete;

	QParagraph& operator=(const QParagraph& other) = delete;
	QParagraph& operator=(const QParagraph&& other) = delete;
signals:
	bool LabelClicked(QMouseEvent* click);
	bool DropDownClicked(QMouseEvent* click);

protected:

private slots:

public slots:

private:

};