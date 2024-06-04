/********************************************************************************
** Form generated from reading UI file 'socialnetworkwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCIALNETWORKWINDOW_H
#define UI_SOCIALNETWORKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SocialNetworkWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loginButton;
    QLabel *enterNameLabel;
    QTextEdit *loginTextBox;
    QLabel *invalidName;
    QLabel *personProfile;
    QTableWidget *userFriends;
    QLabel *recentPosts;
    QPushButton *returnHome;
    QTableWidget *friendSuggestions;
    QLabel *friendSuggestionsLabel;
    QPushButton *addFriend;
    QTableWidget *postsTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SocialNetworkWindow)
    {
        if (SocialNetworkWindow->objectName().isEmpty())
            SocialNetworkWindow->setObjectName("SocialNetworkWindow");
        SocialNetworkWindow->resize(800, 600);
        centralwidget = new QWidget(SocialNetworkWindow);
        centralwidget->setObjectName("centralwidget");
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(30, 110, 80, 31));
        enterNameLabel = new QLabel(centralwidget);
        enterNameLabel->setObjectName("enterNameLabel");
        enterNameLabel->setGeometry(QRect(30, 50, 91, 16));
        loginTextBox = new QTextEdit(centralwidget);
        loginTextBox->setObjectName("loginTextBox");
        loginTextBox->setGeometry(QRect(30, 70, 151, 31));
        invalidName = new QLabel(centralwidget);
        invalidName->setObjectName("invalidName");
        invalidName->setGeometry(QRect(30, 160, 181, 21));
        personProfile = new QLabel(centralwidget);
        personProfile->setObjectName("personProfile");
        personProfile->setGeometry(QRect(190, 60, 191, 16));
        userFriends = new QTableWidget(centralwidget);
        userFriends->setObjectName("userFriends");
        userFriends->setGeometry(QRect(190, 80, 261, 171));
        userFriends->horizontalHeader()->setCascadingSectionResizes(false);
        userFriends->horizontalHeader()->setMinimumSectionSize(40);
        userFriends->horizontalHeader()->setStretchLastSection(true);
        recentPosts = new QLabel(centralwidget);
        recentPosts->setObjectName("recentPosts");
        recentPosts->setGeometry(QRect(30, 240, 401, 301));
        recentPosts->setWordWrap(true);
        returnHome = new QPushButton(centralwidget);
        returnHome->setObjectName("returnHome");
        returnHome->setGeometry(QRect(470, 40, 121, 21));
        friendSuggestions = new QTableWidget(centralwidget);
        friendSuggestions->setObjectName("friendSuggestions");
        friendSuggestions->setGeometry(QRect(470, 80, 261, 171));
        friendSuggestions->horizontalHeader()->setMinimumSectionSize(40);
        friendSuggestions->horizontalHeader()->setStretchLastSection(true);
        friendSuggestionsLabel = new QLabel(centralwidget);
        friendSuggestionsLabel->setObjectName("friendSuggestionsLabel");
        friendSuggestionsLabel->setGeometry(QRect(470, 60, 151, 21));
        addFriend = new QPushButton(centralwidget);
        addFriend->setObjectName("addFriend");
        addFriend->setGeometry(QRect(190, 40, 261, 21));
        postsTable = new QTableWidget(centralwidget);
        postsTable->setObjectName("postsTable");
        postsTable->setGeometry(QRect(10, 260, 721, 261));
        SocialNetworkWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SocialNetworkWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        SocialNetworkWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SocialNetworkWindow);
        statusbar->setObjectName("statusbar");
        SocialNetworkWindow->setStatusBar(statusbar);

        retranslateUi(SocialNetworkWindow);

        QMetaObject::connectSlotsByName(SocialNetworkWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SocialNetworkWindow)
    {
        SocialNetworkWindow->setWindowTitle(QCoreApplication::translate("SocialNetworkWindow", "SocialNetworkWindow", nullptr));
        loginButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Login", nullptr));
        enterNameLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Enter your name", nullptr));
        invalidName->setText(QCoreApplication::translate("SocialNetworkWindow", "Invalid name, please try again", nullptr));
        personProfile->setText(QCoreApplication::translate("SocialNetworkWindow", "My Profile", nullptr));
        recentPosts->setText(QCoreApplication::translate("SocialNetworkWindow", "Posts:", nullptr));
        returnHome->setText(QCoreApplication::translate("SocialNetworkWindow", "Return to home", nullptr));
        friendSuggestionsLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Friend Suggestions", nullptr));
        addFriend->setText(QCoreApplication::translate("SocialNetworkWindow", "Add __ as friend", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SocialNetworkWindow: public Ui_SocialNetworkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIALNETWORKWINDOW_H
