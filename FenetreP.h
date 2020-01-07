#ifndef FentreP_H
#define FentreP_H
#include <QStackedWidget>
#include <QMainWindow>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QList>
#include <QPalette>
#include <QGridLayout>
#include "System.h"
#include "Menu.h"
#include "Connexion.h"

class FenetreP : public QMainWindow {

    Q_OBJECT
  private:
      QStackedWidget *stack;
      System *s ;
      Connexion *c;
      Menu * menu ;
  public:
   FenetreP(QWidget *parent = 0);

  public slots:
   void changement_Fenetre();


};
#endif // MENU_H
