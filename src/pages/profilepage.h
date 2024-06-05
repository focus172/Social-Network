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
        // ProfilePage->setObjectName("ProfilePage");
        // ProfilePage->resize(800, 600);
        centralwidget = new QWidget(ProfilePage);
        centralwidget->setObjectName("centralwidget");

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

        reset();

        // QMetaObject::connectSlotsByName(ProfilePage);
    } // setupUi

    void reset()
    {
        personProfile->setText(QCoreApplication::translate("ProfilePage", "My Profile", nullptr));
        recentPosts->setText(QCoreApplication::translate("ProfilePage", "Posts:", nullptr));
        returnHome->setText(QCoreApplication::translate("ProfilePage", "Return to home", nullptr));
        friendSuggestionsLabel->setText(QCoreApplication::translate("ProfilePage", "Friend Suggestions", nullptr));
        addFriend->setText(QCoreApplication::translate("ProfilePage", "Add __ as friend", nullptr));
    }

};

QT_END_NAMESPACE

class ProfilePage : public QWidget
{
    Q_OBJECT

public:
    // CONSTRUCTOR AND DESTRUCTOR

    // pre: none
    // post: creates the window for the ui
    ProfilePage(Network *network, QWidget *parent = nullptr);

    // pre: none
    // post: deletes the window
    ~ProfilePage();

    // MOTIFICATION MEMBER FUNCTIONS

    /// Function called when a user logs in. This display is not active before
    /// this function is called.
    void login(User *u);

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
    Network *n;
    User *initialUser;
    User *mostRecentUser;
};

#endif // PROFILEPAGE_H
