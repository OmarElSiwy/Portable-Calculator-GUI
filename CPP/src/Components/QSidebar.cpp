#include "Components/QSidebar.h"

#include <QMouseEvent>

SideBar::SideBar(QWidget *parent) : QWidget(parent) {
    Overalllayout = new QVBoxLayout(this);
    seperator = new QFrame(this);

    QFile MenuStyling(":/Styling/Menu/Menu.qss");
    MenuStyling.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&MenuStyling);
    QString styleSheet = stream.readAll();
    MenuStyling.close();

    // Setup main menu
    MainMenu.push_back(new QPushButton("Home", this));
    MainMenu.back()->setIcon(QPixmap(":/MenuIcons/Home.png"));
    MainMenu.push_back(new QPushButton("Search", this));
    MainMenu.back()->setIcon(QPixmap(":/MenuIcons/Search.png"));
    MainMenu.push_back(new QPushButton("Expectations A", this));
    MainMenu.back()->setIcon(QPixmap(":/MenuIcons/ExpectationsA.png"));
    MainMenu.push_back(new QPushButton("Expectations B", this));
    MainMenu.back()->setIcon(QPixmap(":/MenuIcons/ExpectationsB.png"));
    MainMenu.push_back(new QPushButton("Expectations C", this));
    MainMenu.back()->setIcon(QPixmap(":/MenuIcons/ExpectationsC.png"));
    MainMenu.push_back(new QPushButton("Expectations D", this));
    MainMenu.back()->setIcon(QPixmap(":/MenuIcons/ExpectationsD.png"));
    MainMenu.push_back(new QPushButton("Extras", this));
    MainMenu.back()->setIcon(QPixmap(":/MenuIcons/Extras.png"));

    for (QPushButton* a : MainMenu)
        a->setStyleSheet(styleSheet);

    // Setup Seperator Frame
    seperator->setLineWidth(1);
    seperator->setFrameShape(QFrame::HLine);
    seperator->setFrameShadow(QFrame::Sunken);
    seperator->setLineWidth(1);

    for (QPushButton* a : MainMenu) {
        Overalllayout->addWidget(a);
    }
    Overalllayout->addWidget(seperator);
}

void SideBar::mousePressEvent(QMouseEvent* event) {
    for (auto it = MainMenu.begin(); it != MainMenu.end(); it++) {
        if (event->button() == Qt::LeftButton && (*it)->rect().contains(event->pos())) {
            emit MenuButtonClicked(it - MainMenu.begin());
        }
    }
    for (auto it = Bookmarks.begin(); it != Bookmarks.end(); it++) {
        if (event->button() == Qt::LeftButton && (*it)->rect().contains(event->pos())) {
            emit BookmarkButtonClicked(it - Bookmarks.begin(), (*it)->text());
        }
    }
}

void SideBar::AddBookmark(const char* Name) {
    Bookmarks.push_back(new QPushButton(Name));
}

void SideBar::RemoveBookmark(const char* Name) {
    for (auto it = Bookmarks.begin(); it != Bookmarks.end(); it++) {
        if ((*it)->text() == Name) {
            QPushButton* temp = Bookmarks.at(it - Bookmarks.begin());
            Bookmarks.removeAt(it - Bookmarks.begin());
            temp->deleteLater();
            delete temp;
        }
    }
}

void SideBar::HideSideBar() {
    if (this->isHidden())
        this->show();
    else
        this->hide();
}

SideBar::~SideBar() {
    for (auto it = Bookmarks.begin(); it != Bookmarks.end(); it++) {
        (*it)->deleteLater();
    }
    for (auto it = MainMenu.begin(); it != MainMenu.end(); it++) {
        (*it)->deleteLater();
    }
    this->deleteLater();
}
