#ifndef SOCIALNETWORKWINDOW_H
#define SOCIALNETWORKWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <stack>
#include "network/network.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class SocialNetworkWindow;
}
QT_END_NAMESPACE

class SocialNetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    // CONSTRUCTOR AND DESTRUCTOR

    // pre: none
    // post: creates the window for the ui
    SocialNetworkWindow(QWidget *parent = nullptr);

    // pre: none
    // post: deletes the window
    ~SocialNetworkWindow();

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

private:
    Ui::SocialNetworkWindow *ui;
    Network n;
    User *initialUser;
    User *mostRecentUser;
};
#endif // SOCIALNETWORKWINDOW_H
