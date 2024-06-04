#include "socialnetworkwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Please input both the users and posts files\n");
    return 1;
  }

  char *users = argv[1];
  char *posts = argv[2];

  QApplication a(argc, argv);
  SocialNetworkWindow w;
  w.show();
  return a.exec();
}
