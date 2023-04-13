#ifndef QPARAGRAPH_H
#define QPARAGRAPH_H

#include <QWidget>
#include <QLabel>
#include <QRect>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFrame>

struct QParagraphSeperatorSection : public QFrame {
    Q_OBJECT
public:
    enum SepType { Horizontal, Vertical };

    explicit QParagraphSeperatorSection(SepType SType, QWidget* parent);
    QParagraphSeperatorSection() = delete;
    ~QParagraphSeperatorSection();

    QParagraphSeperatorSection(QParagraphSeperatorSection &obj) = delete;
    QParagraphSeperatorSection(QParagraphSeperatorSection &&obj) = delete;

    QParagraphSeperatorSection& operator=(QParagraphSeperatorSection &obj) = delete;
    QParagraphSeperatorSection& operator=(QParagraphSeperatorSection &&obj) = delete;
};

struct QParagraphTextSection : public QWidget {
    Q_OBJECT
public:
    explicit QParagraphTextSection(QWidget* parent);
    QParagraphTextSection() = delete;
    ~QParagraphTextSection();

    QParagraphTextSection(QParagraphTextSection &obj) = delete;
    QParagraphTextSection(QParagraphTextSection &&obj) = delete;

    QParagraphTextSection& operator=(QParagraphTextSection &obj) = delete;
    QParagraphTextSection& operator=(QParagraphTextSection &&obj) = delete;
private:
    QLabel* SubTitle;
    QLabel* SubText;
};

struct QParagraphPictureSection : public QWidget {
    Q_OBJECT
public:
    explicit QParagraphPictureSection(QWidget* parent);
    QParagraphPictureSection() = delete;
    ~QParagraphPictureSection();

    QParagraphPictureSection(QParagraphPictureSection &obj) = delete;
    QParagraphPictureSection(QParagraphPictureSection &&obj) = delete;

    QParagraphPictureSection& operator=(QParagraphPictureSection &obj) = delete;
    QParagraphPictureSection& operator=(QParagraphPictureSection &&obj) = delete;
private:
    QLabel* Photo;
    QLabel* PhotoDescription;
};

struct QParagraphCodeSection : public QWidget {
    Q_OBJECT
public:
    explicit QParagraphCodeSection(QWidget* parent);
    QParagraphCodeSection() = delete;
    ~QParagraphCodeSection();

    QParagraphCodeSection(QParagraphCodeSection &obj) = delete;
    QParagraphCodeSection(QParagraphCodeSection &&obj) = delete;

    QParagraphCodeSection& operator=(QParagraphCodeSection &obj) = delete;
    QParagraphCodeSection& operator=(QParagraphCodeSection &&obj) = delete;
private slots:
    void OpenTerminal(const char* CurrentCode); // Opens Terminal with existing code
    void UpdateHighlighting(); // Updates Highlighting using python syntax highlighting
private:
    QRect* CodeBlock;
    QLabel* CodeText;
    QPushButton* RunButton;
};

struct QParagraphDescription : public QWidget {
    Q_OBJECT
public:
    enum OrientationType { SameLine, NextLine };

    explicit QParagraphDescription(std::vector<QPair<QWidget*, OrientationType>> WidgetsToAdd, QWidget* parent);
    QParagraphDescription() = delete;
    ~QParagraphDescription();

    QParagraphDescription(QParagraphDescription &obj) = delete;
    QParagraphDescription(QParagraphDescription &&obj) = delete;

    QParagraphDescription& operator=(QParagraphDescription &obj) = delete;
    QParagraphDescription& operator=(QParagraphDescription &&obj) = delete;
};

struct QParagraphTitle : public QWidget {
    Q_OBJECT
public:
    enum State { ON, OFF };

    explicit QParagraphTitle(QWidget* parent);
    QParagraphTitle() = delete;
    ~QParagraphTitle();

    QParagraphTitle(QParagraphTitle &obj) = delete;
    QParagraphTitle(QParagraphTitle &&obj) = delete;

    QParagraphTitle& operator=(QParagraphTitle &obj) = delete;
    QParagraphTitle& operator=(QParagraphTitle &&obj) = delete;
protected:
    void mousePressEvent(QMouseEvent *event) override;
signals:
    State CurrentState(); // Connected to Parent Widget QParagraph
    State BookmarkIconClicked(); // Connected to Sidebar
private:
    QLabel* TitleName;
    QLabel* BookmarkIcon;
};

class QParagraph : public QWidget {
    Q_OBJECT
public:
    explicit QParagraph(QStyleSheet* StyleToApply, QParagraphTitle* TitleWidget, QParagraphDescription* DescriptionWidget, QWidget* parent);
    QParagraph() = delete;
    ~QParagraph();

    QParagraph(QParagraph &obj) = delete;
    QParagraph(QParagraph &&obj) = delete;

    QParagraph& operator=(QParagraph &obj) = delete;
    QParagraph& operator=(QParagraph &&obj) = delete;
private slots:
    void HideOrShowDescription(QParagraphTitle::State CurrState);
private:
    QParagraphTitle* TitleComponent;
    QParagraphDescription* DescriptionComponent;
    QStyleSheet* CurrStyle;
};

#endif // QPARAGRAPH_H
