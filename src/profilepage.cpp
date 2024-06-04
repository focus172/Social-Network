#include "profilepage.h"

QT_BEGIN_NAMESPACE

ProfilePageUi::ProfilePageUi(QWidget *ProfilePage) {
  profilegrid = new QGridLayout(ProfilePage);
  profilegrid->setObjectName("gridLayout");

  name_div = new QHBoxLayout();
  name_div->setObjectName("name_div");
  profile_name_pad_left =
      new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  name_div->addItem(profile_name_pad_left);

  profile_label = new QLabel(ProfilePage);
  profile_label->setObjectName("profile_label");

  name_div->addWidget(profile_label);

  profile_name_pad_right =
      new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  name_div->addItem(profile_name_pad_right);

  profilegrid->addLayout(name_div, 1, 0, 1, 1);

  verticalSpacer =
      new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

  profilegrid->addItem(verticalSpacer, 5, 0, 1, 1);

  horizontalLayout = new QHBoxLayout();
  horizontalLayout->setObjectName("horizontalLayout");
  verticalLayout = new QVBoxLayout();
  verticalLayout->setObjectName("verticalLayout");
  friends_lable = new QLabel(ProfilePage);
  friends_lable->setObjectName("label_2");

  verticalLayout->addWidget(friends_lable);

  profile_friends_table = new QTableWidget(ProfilePage);
  if (profile_friends_table->columnCount() < 1)
    profile_friends_table->setColumnCount(1);
  if (profile_friends_table->rowCount() < 12)
    profile_friends_table->setRowCount(12);
  profile_friends_table->setObjectName("profile_friends_table");
  QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(
      profile_friends_table->sizePolicy().hasHeightForWidth());
  profile_friends_table->setSizePolicy(sizePolicy);
  profile_friends_table->setAcceptDrops(false);
  profile_friends_table->setAutoFillBackground(true);
  profile_friends_table->setSizeAdjustPolicy(
      QAbstractScrollArea::AdjustToContents);
  profile_friends_table->setAutoScrollMargin(16);
  profile_friends_table->setProperty("showDropIndicator", QVariant(true));
  profile_friends_table->setDragDropOverwriteMode(false);
  profile_friends_table->setShowGrid(true);
  profile_friends_table->setGridStyle(Qt::SolidLine);
  profile_friends_table->setWordWrap(false);
  profile_friends_table->setRowCount(12);
  profile_friends_table->setColumnCount(1);

  verticalLayout->addWidget(profile_friends_table);

  profile_suggested_lable = new QLabel(ProfilePage);
  profile_suggested_lable->setObjectName("profile_suggested_lable");

  verticalLayout->addWidget(profile_suggested_lable);

  profile_suggested_table = new QTableWidget(ProfilePage);
  if (profile_suggested_table->columnCount() < 1)
    profile_suggested_table->setColumnCount(1);
  if (profile_suggested_table->rowCount() < 5)
    profile_suggested_table->setRowCount(5);
  profile_suggested_table->setObjectName("profile_suggested_table");
  QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
  sizePolicy1.setHorizontalStretch(0);
  sizePolicy1.setVerticalStretch(0);
  sizePolicy1.setHeightForWidth(
      profile_suggested_table->sizePolicy().hasHeightForWidth());
  profile_suggested_table->setSizePolicy(sizePolicy1);
  profile_suggested_table->setLineWidth(1);
  profile_suggested_table->setRowCount(5);
  profile_suggested_table->setColumnCount(1);

  verticalLayout->addWidget(profile_suggested_table);

  horizontalLayout->addLayout(verticalLayout);

  profile_post_list = new QListView(ProfilePage);
  profile_post_list->setObjectName("profile_post_list");
  QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
  sizePolicy2.setHorizontalStretch(0);
  sizePolicy2.setVerticalStretch(0);
  sizePolicy2.setHeightForWidth(
      profile_post_list->sizePolicy().hasHeightForWidth());
  profile_post_list->setSizePolicy(sizePolicy2);
  QFont font;
  font.setPointSize(17);
  profile_post_list->setFont(font);
  profile_post_list->setWordWrap(true);

  horizontalLayout->addWidget(profile_post_list);

  profilegrid->addLayout(horizontalLayout, 2, 0, 1, 1);

  reset();
}

void ProfilePageUi::reset() {
  friends_lable->setText(
      QCoreApplication::translate("SocialNetworkWindow", "Friends", nullptr));
  profile_suggested_lable->setText(QCoreApplication::translate(
      "SocialNetworkWindow", "Suggested Friends", nullptr));
}

QT_END_NAMESPACE

ProfilePage::ProfilePage(QWidget *parent) : QWidget(parent) {
  ui = new ProfilePageUi(this);
}
ProfilePage::~ProfilePage() { delete ui; }
