#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QFile>

class SideBar : public QWidget
{
    Q_OBJECT
public:   
    // Constructor + Destructor
    explicit SideBar(QWidget *parent = nullptr);
    ~SideBar();

    // Move + Copy Constructor
    SideBar(const SideBar& obj) = delete;
    SideBar(const SideBar*& obj) = delete;

    // Move + Copy Assignment
    SideBar& operator=(const SideBar& obj) = delete;
    SideBar& operator=(const SideBar&& obj) = delete;
signals:
    void MenuButtonClicked(int index);
    void BookmarkButtonClicked(int index, QString Name);
protected:
    void mousePressEvent(QMouseEvent* event) override;
public slots:
    void AddBookmark(const char* Name);
    void RemoveBookmark(const char* Name);
    void HideSideBar();
private:
    QList<QPushButton*> MainMenu;
    QList<QPushButton*> Bookmarks;
    QFrame* seperator;
    QVBoxLayout* Overalllayout;
};
