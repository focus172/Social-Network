#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QMainWindow>
#include <QTableWidget>
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

#include <stack>
#include "../network/network.h"

QT_BEGIN_NAMESPACE

class ProfilePageUi
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

    void setupUi(QWidget *ProfilePage)
    {
        if (ProfilePage->objectName().isEmpty())
            ProfilePage->setObjectName("ProfilePage");
        ProfilePage->resize(800, 600);
        centralwidget = new QWidget(ProfilePage);
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

        retranslateUi(ProfilePage);

        // QMetaObject::connectSlotsByName(ProfilePage);
    } // setupUi

    void retranslateUi(QWidget *ProfilePage)
    {
        // ProfilePage->setWindowTitle(QCoreApplication::translate("ProfilePage", "ProfilePage", nullptr));
        loginButton->setText(QCoreApplication::translate("ProfilePage", "Login", nullptr));
        enterNameLabel->setText(QCoreApplication::translate("ProfilePage", "Enter your name", nullptr));
        invalidName->setText(QCoreApplication::translate("ProfilePage", "Invalid name, please try again", nullptr));
        personProfile->setText(QCoreApplication::translate("ProfilePage", "My Profile", nullptr));
        recentPosts->setText(QCoreApplication::translate("ProfilePage", "Posts:", nullptr));
        returnHome->setText(QCoreApplication::translate("ProfilePage", "Return to home", nullptr));
        friendSuggestionsLabel->setText(QCoreApplication::translate("ProfilePage", "Friend Suggestions", nullptr));
        addFriend->setText(QCoreApplication::translate("ProfilePage", "Add __ as friend", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE

class ProfilePage : public QWidget
{
    Q_OBJECT

public:
    // CONSTRUCTOR AND DESTRUCTOR

    // pre: none
    // post: creates the window for the ui
    ProfilePage(QWidget *parent = nullptr);

    // pre: none
    // post: deletes the window
    ~ProfilePage();

    // MOTIFICATION MEMBER FUNCTIONS

    // pre: none
    // post: displays login page, and displays home page when valid name is entered
    void login();

    // pre: none
    // post: goes to home profile page
    void goToHome();

    // pre: none
    // post: goes to friend profile page
    void goToFriend(int row, int column);

    // pre: none
    // post: adds a person as a friend
    void addAsFriend();

    // pre: none
    // post: goes to the profile page of the friend suggestion
    void goToFriendSuggestion(int row, int column);

    // pre: none
    // post: likes the post, does nothing if post is already liked by user
    void likePost(int row, int messageId, int userId);

signals:
    void goto_makepost();

private:
    ProfilePageUi *ui;
    Network n;
    User *initialUser;
    User *mostRecentUser;
};

#endif // PROFILEPAGE_H
