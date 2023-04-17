#include "ControlledView.h"

ControlledView::ControlledView(QWidget* parent)
    : QWidget(parent)
{
    HomePage = new Pages(this);
    ExpectationsA = new Pages(this);
    ExpectationsB = new Pages(this);
    ExpectationsC = new Pages(this);
    ExpectationsD = new Pages(this);
    Extras = new Pages(this);

    // Setting up Pages
    QParagraph* temp = new QParagraph("About Me", HomePage);
    temp->Append(new QParagraphItem("My Experience", "", "", Qt::AlignLeft, "Hello", Qt::AlignBottom, "", HomePage), Qt::AlignLeft, true);
    HomePage->append(temp);

    Navigator = new QStackedWidget(this);
    Navigator->addWidget(HomePage);
    Navigator->addWidget(ExpectationsA);
    Navigator->addWidget(ExpectationsB);
    Navigator->addWidget(ExpectationsC);
    Navigator->addWidget(ExpectationsD);
    Navigator->addWidget(Extras);
    Navigator->setCurrentIndex(0);
    connect(Navigator, &QStackedWidget::currentChanged, this, &ControlledView::CurrentPage);

    list = {HomePage, ExpectationsA, ExpectationsB, ExpectationsC, ExpectationsD, Extras};

    layout = new BorderLayout(this);
    Sidebar = new SideBar(this);
    TabTrackerW = new TabTracker(this);
    Toolbar = new QToolBars(this);

    layout->addWidget(Navigator, BorderLayout::Center);
    layout->addWidget(Toolbar, BorderLayout::North);
    layout->addWidget(Sidebar, BorderLayout::West);
    layout->addWidget(TabTrackerW, BorderLayout::South);

    // Setting up all signals and slots
    // Sidebar to ControledView
    connect(Sidebar, &SideBar::MenuButtonClicked, this, &ControlledView::ChangePage);
    connect(Sidebar, &SideBar::BookmarkButtonClicked, this, [=](int index, QString Name) {
        this->ChangePage(index);
        this->list[index]->ScrollTo(Name);
    });

    // Tabs to ControlledView
    connect(TabTrackerW->GetTabLayout(), &QTabWidget::currentChanged, this, &ControlledView::ChangePage);
    connect(TabTrackerW->GetTabLayout(), &QTabWidget::tabCloseRequested, this, &ControlledView::ChangePage);

    // Toolbar to sidebar
    connect(Toolbar->GetButton(), &QPushButton::clicked, Sidebar, &SideBar::HideSideBar);

    // Page to Sidebar
    // connect(list[Navigator->currentIndex()], &QParagraph::BookmarkClicked, Sidebar, &SideBar::ManageBookmarks);

    // Pages Image to BorderLayout

}

ControlledView::~ControlledView() {
    this->deleteLater();
}

void ControlledView::ChangePage(int index) {
    Navigator->setCurrentIndex(index);
}
