#include "socialnetworkwindow.h"

/* ******************************************* */
QT_BEGIN_NAMESPACE

SocialNetworkWindowUi::SocialNetworkWindowUi(QMainWindow *SocialNetworkWindow,
                                             Network *network) {
  SocialNetworkWindow->resize(800, 600);

  // needed for reasons
  centralwidget = new QWidget(SocialNetworkWindow);

  /* ***************** Page Setup *************** */
  // grid is used so that items appear in center of screen
  grid = new QGridLayout(centralwidget);
  viewstack = new QStackedWidget(centralwidget);

  loginpage = new LoginPage(network, centralwidget);
  viewstack->addWidget(loginpage);

  profilepage = new ProfilePage(network, centralwidget);
  viewstack->addWidget(profilepage);

  makepostpage = new MakepostPage(centralwidget);
  viewstack->addWidget(makepostpage);

  grid->addWidget(viewstack, 0, 0);
  SocialNetworkWindow->setCentralWidget(centralwidget);
  /* ************** End Page Setup *************** */

  /* *************** Window Setup ************* */
  menubar = new QMenuBar(SocialNetworkWindow);
  menubar->setObjectName("menubar");
  menubar->setGeometry(QRect(0, 0, 800, 19));
  SocialNetworkWindow->setMenuBar(menubar);
  statusbar = new QStatusBar(SocialNetworkWindow);
  statusbar->setObjectName("statusbar");
  SocialNetworkWindow->setStatusBar(statusbar);
  /* ************* End Window Setup ************ */

  SocialNetworkWindow->setWindowTitle(QCoreApplication::translate(
      "SocialNetworkWindow", "Social Network", nullptr));
}

QT_END_NAMESPACE
/* ******************************************* */

SocialNetworkWindow::SocialNetworkWindow()
    : QMainWindow(nullptr), curr(), user() {

  int ret = network.readUsers("users.txt");
  if (ret < 0) {
    // try backup location
    ret = network.readUsers("etc/users.txt");
    if (ret < 0)
      throw;
  }

  ret = network.readPosts("posts.txt");
  if (ret < 0) {
    // try backup location
    ret = network.readPosts("etc/posts.txt");
    if (ret < 0)
      throw;
  }

  ui = new SocialNetworkWindowUi(this, &network);

  // ui->profile_friends_table->setColumnCount(1);

  // ui->profile_home->hide();
  // ui->profile_add->hide();

  // auto p = new Post();
  // auto post = new postwidget(p, &this->curr.id, ui->loginpage);
  // ui->gridLayout_2->addWidget(post);

  // login ports
  QObject::connect(ui->loginpage, &LoginPage::loggedin, this,
                   &SocialNetworkWindow::showprofile);

  // profile ports
  QObject::connect(ui->profilepage, &ProfilePage::gomakepost, this,
                   &SocialNetworkWindow::show_makepost);

  // make post connection
  QObject::connect(ui->makepostpage, &MakepostPage::submit_post, this,
                   &SocialNetworkWindow::add_post);

  // QObject::connect(ui->profile_home, &QPushButton::clicked, this,
  //                  &SocialNetworkWindow::gohome);
  // QObject::connect(ui->profile_add, &QPushButton::clicked, this,
  //                  &SocialNetworkWindow::addfriend);
  // QObject::connect(ui->profile_friends_table, &QTableWidget::cellClicked,
  // this,
  //                  &SocialNetworkWindow::gofriend);
  // QObject::connect(ui->profile_suggested_table, &QTableWidget::cellClicked,
  //                  this, &SocialNetworkWindow::addsuggestedfriend);
}

SocialNetworkWindow::~SocialNetworkWindow() { delete ui; }

void SocialNetworkWindow::show_makepost() {
  this->ui->makepostpage->load_page(this->curr.id);
  this->ui->viewstack->setCurrentIndex(2);
}

void SocialNetworkWindow::add_post(Post *p) {
  User *u = this->network.getUser(p->getOwnerId());
  if (u == nullptr) {
    printf("post is not asociated with any user\n");
    this->ui->viewstack->setCurrentIndex(1);
    return;
  }

  printf("TODO: fix post not being added by uncommenting next line\n");
  // u->addPost(p);
  this->ui->viewstack->setCurrentIndex(1);
}

void SocialNetworkWindow::showprofile(int newuser) {
  User *u = network.getUser(newuser);

  if (ui->viewstack->currentIndex() == 0) {
    // if we are comming here from a new the login page we need to update this
    ui->viewstack->setCurrentIndex(1);
    ui->profilepage->login(u);
  }

  this->user.select(u, this->curr.id);

  // if (newuser == this->curr.id) {
  //   // this user
  //   ui->profile_label->setText(QString("My Profile"));
  //   ui->profile_home->hide();

  //   ui->profile_add->hide();

  //   ui->profile_suggested_lable->show();
  //   ui->profile_suggested_table->show();
  //   int score;
  //   auto suggestions = this->network.suggestFriends(newuser, score);
  //   ui->profile_suggested_table->setRowCount(suggestions.size());

  //   int index = 0;
  //   for (auto f : suggestions) {
  //     User *uf = this->network.getUser(f);
  //     auto it = new QTableWidgetItem(QString::fromStdString(uf->getName()));
  //     ui->profile_suggested_table->setItem(index, 0, it);
  //     index += 1;
  //   }

  // } else {
  //   // other user
  //   ui->profile_label->setText(
  //       QString::asprintf("%s's Profile", u->getName().c_str()));
  //   ui->profile_home->show();

  //   ui->profile_suggested_lable->hide();
  //   ui->profile_suggested_table->hide();

  //   auto me = this->network.getUser(this->curr.id);
  //   auto myfr = me->getFriends();
  //   if (myfr.find(newuser) == myfr.end()) {
  //     ui->profile_add->show();
  //   } else {
  //     ui->profile_add->hide();
  //   }
  // }

  // ui->profile_friends_table->clear();

  // auto fr = u->getFriends();
  // ui->profile_friends_table->setRowCount(fr.size());

  // int index = 0;
  // for (auto f : fr) {
  //   // printf("thing %d\n", index);
  //   User *uf = this->network.getUser(f);

  //   // this call takes owevership of the object
  //   auto it = new QTableWidgetItem(QString::fromStdString(uf->getName()));
  //   ui->profile_friends_table->setItem(index, 0, it);
  //   index += 1;
  // }

  // ui->profile_post_list->setModel(user.model);
}

void SocialNetworkWindow::gohome() {
  // SocialNetworkWindow::showprofile(this->curr.id);
}

void SocialNetworkWindow::gofriend(int row, int col) {
  (void)row;
  (void)col;

  // assert(col == 0);

  // User *u = this->network.getUser(this->user.id);
  // auto fr = u->getFriends();

  // int show = -1;
  // int index = 0;
  // for (int f : fr) {
  //   if (index == row) {
  //     show = f;
  //     break;
  //   }
  //   index += 1;
  // }
  // if (show < 0)
  //   return;

  // SocialNetworkWindow::showprofile(show);
}

void SocialNetworkWindow::addsuggestedfriend(int row, int col) {
  (void)row;
  (void)col;
  // User *u = this->network.getUser(this->user.id);
  // thrownull(u);

  // auto it = ui->profile_suggested_table->item(row, col);
  // auto text = it->text();
  // int s = this->network.getId(text.toStdString());

  // User *f = this->network.getUser(s);
  // thrownull(u);

  // u->addFriend(s);
  // f->addFriend(u->getId());

  // this->network.writeUsers("users.txt");

  // SocialNetworkWindow::showprofile(this->user.id);
}

void SocialNetworkWindow::addfriend() {
  // User *u = this->network.getUser(this->curr.id);
  // thrownull(u);
  // User *f = this->network.getUser(this->user.id);
  // thrownull(f);

  // u->addFriend(this->user.id);
  // f->addFriend(this->curr.id);

  // this->network.writeUsers("users.txt");

  // this->ui->profile_add->hide();

  // SocialNetworkWindow::showprofile(this->user.id);
}
