#include "socialnetworkwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  SocialNetworkWindow w;
    srand(time(nullptr));
  w.show();
  return a.exec();
}
