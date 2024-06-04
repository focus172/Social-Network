#ifndef PROFILEPAGE_H_
#define PROFILEPAGE_H_

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

class ProfilePageUi {
public:
  QGridLayout *profilegrid;
  QHBoxLayout *name_div;
  QSpacerItem *profile_name_pad_left;
  QLabel *profile_label;
  QSpacerItem *profile_name_pad_right;
  QSpacerItem *verticalSpacer;
  QHBoxLayout *horizontalLayout;
  QVBoxLayout *verticalLayout;
  QLabel *friends_lable;
  QTableWidget *profile_friends_table;
  QLabel *profile_suggested_lable;
  QTableWidget *profile_suggested_table;
  QListView *profile_post_list;

  ProfilePageUi(QWidget *ProfilePage);

  void reset();
};

QT_END_NAMESPACE

class ProfilePage : public QWidget {
public:
  ProfilePage(QWidget *parent = nullptr);
  ~ProfilePage();

private:
  ProfilePageUi *ui;
};

#endif // PROFILEPAGE_H_
