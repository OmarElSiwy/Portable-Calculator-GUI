#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QFile>

struct QParagraphItem : public QWidget {
    Q_OBJECT
public:
    // Constructor + Destructor
    explicit QParagraphItem(const char* SubTitle, const char* Hyperlink,
                            const char* Paragraph, Qt::AlignmentFlag Paragraphalign,
                            const char* ImageAddres, Qt::AlignmentFlag ImageAlign, const char* ImageDescription = "",
                            QWidget* parent = nullptr);
    ~QParagraphItem();

    // Move + Copy Constructor
    QParagraphItem(const QParagraphItem& obj) = delete;
    QParagraphItem(const QParagraphItem&& obj) = delete;

    // Move + Copy Assignment
    QParagraphItem& operator=(const QParagraphItem &obj) = delete;
    QParagraphItem& operator=(const QParagraphItem &&obj) = delete;
protected:
    void mousePressEvent(QMouseEvent* event) override;
signals:
    void PictureClicked(QLabel* a);
private:
    QLabel* Picture;
    QLabel* Description;
    QLabel* SubTitle;
    QHBoxLayout* Layout;
    bool Image_Exists = false;
    bool Paragraph_Exists = false;
};


class QParagraph : public QWidget {
    Q_OBJECT
public:
    inline void Append(QParagraphItem* Item, Qt::Alignment allign, bool AddSeperator = true);
    inline void Erase(QParagraphItem* Item);

    // Constructor + Destructor
    explicit QParagraph(const char* title, QWidget* parent = nullptr);
    ~QParagraph();

    // Move + Copy Constructor
    QParagraph(const QParagraph& obj) = delete;
    QParagraph(const QParagraph&& obj) = delete;

    // Move + Copy Assignment
    QParagraph& operator=(const QParagraph &obj) = delete;
    QParagraph& operator=(const QParagraph &&obj) = delete;

    QString GetTitle() { return Title->text(); }
protected:
    void mousePressEvent(QMouseEvent* event) override;
signals:
    void BookmarkClicked(bool State);
    void TitleClicked(bool State);

private slots:
    void HideOrShowDescription(bool State);
    void ModifyBookmarkIcon(bool State);

private:
    QHBoxLayout* TitleBar;
    QVBoxLayout* DescriptionBar;
    QVBoxLayout* ParagraphLayout;

    QFrame* HorizontalSeperator;
    QLabel* Title;
    QLabel* BookmarkIcon;
    QLabel* DropDownIcon;

    bool BookmarkState = false;
    bool DropDownState = true;
};
