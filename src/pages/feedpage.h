#ifndef FEEDPAGE_H
#define FEEDPAGE_H

#include <QMainWindow>
#include <QTableWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

#include "../network/network.h"
#include <stack>

/* 8888888888888 88888888888888888888888888888 888888888 */
QT_BEGIN_NAMESPACE

class postwidget : public QWidget {
  Q_OBJECT

public:
  QWidget *root;
  QVBoxLayout *vbox;

  /// Root of the info bar
  QWidget *winfo;
  QHBoxLayout *hinfo;

  QLabel *author_lable;
  QLabel *date_lable;

  /// Root of the info bar
  QWidget *wbody;
  QHBoxLayout *hbody;

  QLabel *text_lable;
  QPushButton *like_button;

  Post *post;

  postwidget(Post *p, QWidget *parent = nullptr) : QWidget(parent) {
    root = new QWidget(parent);
    vbox = new QVBoxLayout(root);
    {
      winfo = new QWidget(root);
      hinfo = new QHBoxLayout(winfo);

      author_lable = new QLabel(winfo);
      author_lable->setText(QString::fromStdString(p->getAuthor()));
      hinfo->addWidget(author_lable);
      date_lable = new QLabel(winfo);
      hinfo->addWidget(date_lable);

      vbox->addWidget(winfo);
    }

    {
      wbody = new QWidget(root);
      hbody = new QHBoxLayout(wbody);

      text_lable = new QLabel(wbody);
      hinfo->addWidget(text_lable);
      like_button = new QPushButton(wbody);
      hinfo->addWidget(date_lable);

      vbox->addWidget(winfo);
    }
  }

  ~postwidget() {
    // TODO
  }

  void reset();
};

class FeedPageUi {
public:
  QVBoxLayout *vbox;

  std::vector<postwidget *> posts;

  FeedPageUi(QWidget *FeedPage) {
    vbox = new QVBoxLayout(FeedPage);
    posts = {};
  }

  ~FeedPageUi() {
    delete vbox;
    // TODO: delete widgets
  }

  void add_post(postwidget *pw) {
    vbox->addWidget(pw);
    posts.push_back(pw);
  }

  void reset();
};

QT_END_NAMESPACE
/* 888888888 88888888888888888888888888888 888888888 */

class FeedPage : public QWidget {
  Q_OBJECT

public:
  FeedPage(Network *network, QWidget *parent = nullptr)
      : QWidget(parent), ui(new FeedPageUi(this)), n(network) {}

  void show_user(User *u) {
    for (auto f : u->getFriends()) {
      User *fr = n->getUser(f);
      if (fr == nullptr)
        continue;

      for (auto post : fr->getPosts()) {
        auto pw = new postwidget(post, this);
        ui->add_post(pw);
      }
    }
  }

  // qt makes this for you
  // ~FeedPage();

signals:

private:
  FeedPageUi *ui;
  Network *n;
};

#endif // FEEDPAGE_H
