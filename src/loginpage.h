#ifndef LOGINWINDOW_H_
#define LOGINWINDOW_H_

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

QT_BEGIN_NAMESPACE

class LoginPage : public QWidget {
  Q_OBJECT

public:
  LoginPage(QWidget *parent = nullptr);
  ~LoginPage();

  void login();

private:
  LoginWindowUi *ui;
};

class LoginPageUi {
public:
  QWidget *centralwidget;
  QGridLayout *gridLayout;
  QHBoxLayout *horizontalLayout_2;
  QLabel *label;
  QSpacerItem *horizontalSpacer_3;
  QStackedWidget *main_view;

  QWidget *loginpage;
  QGridLayout *gridLayout_2;
  QSpacerItem *login_space_top;
  QLabel *login_label;
  QLineEdit *login_input;
  QPushButton *login_button;
  QSpacerItem *login_space_left;
  QLabel *login_error;
  QSpacerItem *login_space_right;
  QSpacerItem *login_space_bot;
  QWidget *profilepage;
  QGridLayout *gridLayout_3;
  QHBoxLayout *name_div;

  QSpacerItem *verticalSpacer;
  QHBoxLayout *horizontalLayout;
  QVBoxLayout *verticalLayout;
  QLabel *label_2;

  QMenuBar *menubar;
  QStatusBar *statusbar;

  LoginPageUi(QWidget *LoginPage) {
    // LoginPage->setObjectName("LoginPage");

    centralwidget = new QWidget(SocialNetworkWindow);
    centralwidget->setObjectName("centralwidget");

    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName("gridLayout");
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName("horizontalLayout_2");
    label = new QLabel(centralwidget);
    label->setObjectName("label");

    horizontalLayout_2->addWidget(label);

    horizontalSpacer_3 =
        new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_2->addItem(horizontalSpacer_3);

    profile_add = new QPushButton(centralwidget);
    profile_add->setObjectName("profile_add");

    horizontalLayout_2->addWidget(profile_add);

    profile_home = new QPushButton(centralwidget);
    profile_home->setObjectName("profile_home");

    horizontalLayout_2->addWidget(profile_home);

    gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

    main_view = new QStackedWidget(centralwidget);
    main_view->setObjectName("main_view");
    loginpage = new QWidget();
    loginpage->setObjectName("loginpage");
    gridLayout_2 = new QGridLayout(loginpage);
    gridLayout_2->setObjectName("gridLayout_2");
    login_space_top =
        new QSpacerItem(20, 193, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(login_space_top, 0, 1, 1, 1);

    login_label = new QLabel(loginpage);
    login_label->setObjectName("login_label");

    gridLayout_2->addWidget(login_label, 1, 1, 1, 1);

    login_input = new QLineEdit(loginpage);
    login_input->setObjectName("login_input");

    gridLayout_2->addWidget(login_input, 2, 1, 1, 1);

    login_button = new QPushButton(loginpage);
    login_button->setObjectName("login_button");
    login_button->setEnabled(true);

    gridLayout_2->addWidget(login_button, 3, 1, 1, 1);

    login_space_left =
        new QSpacerItem(212, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_2->addItem(login_space_left, 4, 0, 1, 1);

    login_error = new QLabel(loginpage);
    login_error->setObjectName("login_error");

    gridLayout_2->addWidget(login_error, 4, 1, 1, 1);

    login_space_right =
        new QSpacerItem(212, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_2->addItem(login_space_right, 4, 2, 1, 1);

    login_space_bot =
        new QSpacerItem(20, 193, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(login_space_bot, 5, 1, 1, 1);

    main_view->addWidget(loginpage);

    gridLayout->addWidget(main_view, 1, 0, 1, 1);

    SocialNetworkWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(SocialNetworkWindow);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 800, 19));
    SocialNetworkWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(SocialNetworkWindow);
    statusbar->setObjectName("statusbar");
    SocialNetworkWindow->setStatusBar(statusbar);

    retranslateUi(SocialNetworkWindow);

    QMetaObject::connectSlotsByName(SocialNetworkWindow);
  } // setupUi

  void retranslateUi(QMainWindow *SocialNetworkWindow) {
    SocialNetworkWindow->setWindowTitle(QCoreApplication::translate(
        "SocialNetworkWindow", "ClickGameWindow", nullptr));
    label->setText(QCoreApplication::translate("SocialNetworkWindow",
                                               "Social Network", nullptr));
    profile_add->setText(
        QCoreApplication::translate("SocialNetworkWindow", "Add", nullptr));
    profile_home->setText(
        QCoreApplication::translate("SocialNetworkWindow", "Home", nullptr));
    login_label->setText(QCoreApplication::translate(
        "SocialNetworkWindow", "Enter Username", nullptr));
    login_input->setText(QString());
    login_button->setText(
        QCoreApplication::translate("SocialNetworkWindow", "Login", nullptr));
    login_error->setText(QCoreApplication::translate(
        "SocialNetworkWindow", "User {name} doesn't exists.", nullptr));
    profile_label->setText(QCoreApplication::translate("SocialNetworkWindow",
                                                       "My Profile", nullptr));
    label_2->setText(
        QCoreApplication::translate("SocialNetworkWindow", "Friends", nullptr));
    profile_suggested_lable->setText(QCoreApplication::translate(
        "SocialNetworkWindow", "Suggested Friends", nullptr));
  } // retranslateUi
};

QT_END_NAMESPACE

#endif // LOGINWINDOW_H_
