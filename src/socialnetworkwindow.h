#ifndef SOCIALNETWORKWINDOW_H
#define SOCIALNETWORKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "loginpage.h"
#include "profilepage.h"

QT_BEGIN_NAMESPACE

class SocialNetworkWindowUi {
public:
  QWidget *centralwidget;
  QGridLayout *grid;
  QHBoxLayout *topbardiv;
  QLabel *label;
  QSpacerItem *horizontalSpacer_3;
  QPushButton *profile_add;
  QPushButton *profile_home;
  QStackedWidget *viewstack;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  LoginPage *loginpage;
  ProfilePage *profilepage;

  SocialNetworkWindowUi(QMainWindow *SocialNetworkWindow) {
    if (SocialNetworkWindow->objectName().isEmpty())
      SocialNetworkWindow->setObjectName("SocialNetworkWindow");
    SocialNetworkWindow->resize(800, 600);

    centralwidget = new QWidget(SocialNetworkWindow);
    centralwidget->setObjectName("centralwidget");

    grid = new QGridLayout(centralwidget);
    grid->setObjectName("grid");

    topbardiv = new QHBoxLayout();
    topbardiv->setObjectName("topbardiv");
    label = new QLabel(centralwidget);
    label->setObjectName("label");

    topbardiv->addWidget(label);

    horizontalSpacer_3 =
        new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    topbardiv->addItem(horizontalSpacer_3);

    profile_add = new QPushButton(centralwidget);
    profile_add->setObjectName("profile_add");

    topbardiv->addWidget(profile_add);

    profile_home = new QPushButton(centralwidget);
    profile_home->setObjectName("profile_home");

    topbardiv->addWidget(profile_home);

    grid->addLayout(topbardiv, 0, 0, 1, 1);

    viewstack = new QStackedWidget(centralwidget);
    viewstack->setObjectName("main_view");

    loginpage = new LoginPage(centralwidget);
    viewstack->addWidget(loginpage);

    // profilepage = new ProfilePage(centralwidget);
    // viewstack->addWidget(profilepage);

    grid->addWidget(viewstack, 1, 0, 1, 1);

    SocialNetworkWindow->setCentralWidget(centralwidget);

    /* *************** Window Setup ************* */
    menubar = new QMenuBar(SocialNetworkWindow);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 800, 19));
    SocialNetworkWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(SocialNetworkWindow);
    statusbar->setObjectName("statusbar");
    SocialNetworkWindow->setStatusBar(statusbar);
    /* ************* End Window Setup ************ */

    reset(SocialNetworkWindow);
  }

  void reset(QMainWindow *SocialNetworkWindow) {
    SocialNetworkWindow->setWindowTitle(QCoreApplication::translate(
        "SocialNetworkWindow", "ClickGameWindow", nullptr));
    label->setText(QCoreApplication::translate("SocialNetworkWindow",
                                               "Social Network", nullptr));
    profile_add->setText(
        QCoreApplication::translate("SocialNetworkWindow", "Add", nullptr));
    profile_home->setText(
        QCoreApplication::translate("SocialNetworkWindow", "Home", nullptr));
  }
};

QT_END_NAMESPACE

#include "network.h"
#include <QAbstractItemView>
#include <QMainWindow>
#include <QStringListModel>

class SelectedUser {
public:
  SelectedUser() : id(-1), model(new QStringListModel) {}
  ~SelectedUser() { delete model; }

  void select(User *user, int uid) {
    // assert(u != nullptr);
    auto strs = QStringList();

    for (auto post : user->getPosts()) {
      // if the current user is the displayed user OR the post is public
      if (uid == user->getId() || post->getIsPublic()) {
        strs.append(QString::fromStdString(post->toString()));
      }
    }

    this->id = user->getId();
    delete this->model;
    this->model = new QStringListModel(strs);
  }

  int id;
  QStringListModel *model;
};

struct WindowOptions {
public:
  char *posts;
  char *users;
};

struct CurrentUser {
public:
  /// id of the logged in user
  int id;
};

class SocialNetworkWindow : public QMainWindow {
  Q_OBJECT

public:
  SocialNetworkWindow(); // WindowOptions options);
  ~SocialNetworkWindow();

  void login();

  void showprofile(int user);
  void gohome();
  void addfriend();

  void gofriend(int row, int col);
  void addsuggestedfriend(int row, int col);

private:
  SocialNetworkWindowUi *ui;
  Network network;

  CurrentUser curr;
  SelectedUser user;
};

// topbardiv = new QHBoxLayout();
// topbardiv->setObjectName("topbardiv");

// label = new QLabel(centralwidget);
// label->setObjectName("label");

// topbardiv->addWidget(label);

// topbar_spacer =
//     new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
// topbardiv->addItem(topbar_spacer);

// profile_add = new QPushButton(centralwidget);
// profile_add->setObjectName("profile_add");

// topbardiv->addWidget(profile_add);

// profile_home = new QPushButton(centralwidget);
// profile_home->setObjectName("profile_home");

// topbardiv->addWidget(profile_home);

#endif // SOCIALNETWORKWINDOW_H
