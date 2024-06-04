#include "loginpage.h"

QT_BEGIN_NAMESPACE

LoginPageUi::LoginPageUi(QWidget *loginpage) {
  // LoginPage->setObjectName("LoginPage");

  centergrid = new QGridLayout(loginpage);

  // first two numbers are x y
  // so these items are order vertically in row 1

  /* ********** Login Items *********** */
  login_label = new QLabel(loginpage);
  centergrid->addWidget(login_label, 1, 1, 1, 1);

  login_input = new QLineEdit(loginpage);
  centergrid->addWidget(login_input, 2, 1, 1, 1);

  login_button = new QPushButton(loginpage);
  login_button->setEnabled(true);
  centergrid->addWidget(login_button, 3, 1, 1, 1);

  login_error = new QLabel(loginpage);
  login_error->setObjectName("login_error");
  centergrid->addWidget(login_error, 4, 1, 1, 1);
  /* ******* End Login Items ********** */

  /* ********** Spacers *********** */
  spacer_top =
      new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
  centergrid->addItem(spacer_top, 0, 1, 1, 1);
  spacer_bot =
      new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
  centergrid->addItem(spacer_bot, 5, 1, 1, 1);

  spacer_left =
      new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
  centergrid->addItem(spacer_left, 4, 0, 1, 1);
  spacer_right =
      new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
  centergrid->addItem(spacer_right, 4, 2, 1, 1);
  /* ************* End ************ */

  reset();
}

void LoginPageUi::reset() {
  login_label->setText(QCoreApplication::translate("SocialNetworkWindow",
                                                   "Enter Username", nullptr));
  login_input->setText(QString());
  login_button->setText(
      QCoreApplication::translate("SocialNetworkWindow", "Login", nullptr));
  login_error->setText(QCoreApplication::translate(
      "SocialNetworkWindow", "User {name} doesn't exists.", nullptr));
}

QT_END_NAMESPACE

LoginPage::LoginPage(QWidget *parent) : QWidget(parent) {
  ui = new LoginPageUi(this);
}

LoginPage::~LoginPage() { delete ui; }

void LoginPage::login() {}
