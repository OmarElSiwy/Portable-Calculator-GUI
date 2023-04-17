#include "Components/QParagraph.h"

// QParagraphItem
QParagraphItem::QParagraphItem(const char* SubTitleText, const char* ParagraphAddress, const char* Hyperlink, Qt::AlignmentFlag Paragraphalign,
                               const char* ImageAddres, Qt::AlignmentFlag ImageAlign, const char* ImageDescription, QWidget* parent)
    : QWidget(parent)
{
    // All Member Variables Intialized
    Picture = new QLabel(this);
    Description = new QLabel(this);
    SubTitle = new QLabel(this);
    Layout = new QHBoxLayout(this);

    // Open Style Sheet
    QFile file(":/path/to/stylesheet.qss");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    QString styleSheet = stream.readAll();
    file.close();

    // Setting up Subtitle
    QString Hyperlinkurl = Hyperlink;
    SubTitle->setText(QString("<a href=\"%1\">%2</a>").arg(Hyperlinkurl.arg(SubTitleText)).arg(SubTitleText));
    SubTitle->setStyleSheet(styleSheet);
    SubTitle->setTextFormat(Qt::RichText);
    SubTitle->setTextInteractionFlags(Qt::TextBrowserInteraction);
    SubTitle->setOpenExternalLinks(true);

    // Setting up Picture if exists
    if (ImageAddres) {
        Picture->setPixmap(QPixmap(ImageAddres));
        Picture->setAlignment(Qt::AlignCenter);
        Picture->setText(ImageDescription);
        Picture->setStyleSheet(styleSheet);
        Image_Exists = true;
    }

    // Setting up Description if exists
    if (ParagraphAddress) {
        Description->setText(ParagraphAddress);
        Description->setStyleSheet(styleSheet);
        Paragraph_Exists = true;
    }

    // Setup layout
    if (Image_Exists && Paragraph_Exists) {
        if (Paragraphalign == Qt::AlignmentFlag::AlignLeft) {
            Layout->addWidget(Description, 0, Qt::AlignmentFlag::AlignLeft);
            Layout->addWidget(Picture, 0, Qt::AlignmentFlag::AlignRight);
        } else {
            Layout->addWidget(Picture, 0, Qt::AlignmentFlag::AlignLeft);
            Layout->addWidget(Description, 0, Qt::AlignmentFlag::AlignRight);
        }
    } else if (!Image_Exists && Paragraph_Exists) {
        Layout->addWidget(Description, 0, Paragraphalign);
    } else if (Image_Exists && !Paragraph_Exists) {
        Layout->addWidget(Picture, 0, ImageAlign);
    }
    setLayout(Layout);
}

QParagraphItem::~QParagraphItem() {
    this->deleteLater();
}

void QParagraphItem::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && Picture->rect().contains(event->pos())) {
        emit PictureClicked(this->Picture);
    }
}

// QParagraph

QParagraph::QParagraph(const char* label, QWidget* parent)
    : QWidget(parent)
{
    // Initialze everything
    TitleBar = new QHBoxLayout(this);
    DescriptionBar = new QVBoxLayout(this);
    HorizontalSeperator = new QFrame(this);
    Title = new QLabel(this);
    BookmarkIcon = new QLabel(this);
    DropDownIcon = new QLabel(this);
    ParagraphLayout = new QVBoxLayout(this);

    // Setting up Title Bar connections
    connect(this, &QParagraph::TitleClicked, this, &QParagraph::HideOrShowDescription);
    connect(this, &QParagraph::BookmarkClicked, this, &QParagraph::ModifyBookmarkIcon);

    // Setting up Title
    // Setup DropDown Icon
    BookmarkIcon->setPixmap(QPixmap(":/Assets/Bookmark.png").scaled(BookmarkIcon->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Setup Font
    Title->setFont(QFont("Courier New", 24, QFont::Bold, false));
    Title->setText(label);
    Title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    // Setup BookmarkIcon
    BookmarkIcon->setPixmap(QPixmap(":/Assets/Bookmark.png").scaled(BookmarkIcon->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Setup Title Layout
    TitleBar->addWidget(Title);
    TitleBar->addWidget(BookmarkIcon);

    // Setting up Seperator
    HorizontalSeperator->setFrameShape(QFrame::HLine);
    HorizontalSeperator->setFrameShadow(QFrame::Sunken);

    // Setting up Size Constraints
    TitleBar->setContentsMargins(50, 0, 50, 0);
    TitleBar->setSpacing(0);
    TitleBar->setAlignment(Qt::AlignTop);
    DescriptionBar->setContentsMargins(120, 0, 120, 0);
    DescriptionBar->setSpacing(0);
    DescriptionBar->setAlignment(Qt::AlignTop);

    // Add both to the Overall layout
    ParagraphLayout->addLayout(TitleBar);
    ParagraphLayout->addLayout(DescriptionBar);

    // Set Layout of this Paragraph
    setLayout(ParagraphLayout);
}

QParagraph::~QParagraph() {
    this->deleteLater();
}

// Protected
void QParagraph::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        if (BookmarkIcon->geometry().contains(event->pos())) {
            event->accept();
            emit BookmarkClicked(!BookmarkState);
        } else if (TitleBar->geometry().contains(event->pos())) {
            event->accept();
            emit TitleClicked(!DropDownState);
        }
    }
}

// private slots
void QParagraph::HideOrShowDescription(bool state) {
    DropDownState = state;
    if (state) {
        DropDownIcon->setPixmap(QPixmap(":/icons/bookmark-filled.png"));
        if (ParagraphLayout->count() != 2)
            ParagraphLayout->addLayout(DescriptionBar);
    } else {
        DropDownIcon->setPixmap(QPixmap(":/icons/bookmark.png"));
        if (ParagraphLayout->count() == 2)
            ParagraphLayout->removeItem(ParagraphLayout->itemAt(ParagraphLayout->count() - 1));
    }
}


void QParagraph::ModifyBookmarkIcon(bool state) {
    BookmarkState = state;
    if (state) {
        BookmarkIcon->setPixmap(QPixmap(":/icons/bookmark-filled.png"));
    } else {
        BookmarkIcon->setPixmap(QPixmap(":/icons/bookmark.png"));
    }
}

void QParagraph::Append(QParagraphItem* Item, Qt::Alignment allign, bool AddSeperator) {
    ParagraphLayout->addWidget(Item, 0, allign);
    if (AddSeperator)
        ParagraphLayout->addWidget(HorizontalSeperator, 0, Qt::AlignHCenter);
}

void QParagraph::Erase(QParagraphItem* Item) {
    size_t size = ParagraphLayout->count();
    for (int i = 0; i < size; i++) {
        QWidget* ListItem = ParagraphLayout->itemAt(i)->widget();
        if (Item == ListItem) {
            ParagraphLayout->removeWidget(ListItem);
            ListItem->deleteLater();
        }
    }
}
