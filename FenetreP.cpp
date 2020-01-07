#include "FenetreP.h"

FenetreP ::FenetreP(QWidget * parent) : QMainWindow(parent)
{
    setWindowTitle("Projet CPP");
    this -> resize(700,700);
    stack = new QStackedWidget(this);
    stack -> resize(700,700);
    c=  new Connexion(this);
     s = new System(this);
    menu = new Menu(this);

    stack->addWidget(menu);//0
    stack->addWidget(s);//1
    stack->addWidget(c);//2

    //stack->addWidget(fen3);
    //stack->addWidget(fen4);
    stack->setCurrentIndex(0);

    for (auto it = menu ->btns.begin(); it != menu ->btns.end(); ++it )
    {
       connect(*it, SIGNAL(clicked()),SLOT(changement_Fenetre()));
    }
       connect(s->Menu, SIGNAL(clicked()),SLOT(changement_Fenetre()));
       connect(c->btn, SIGNAL(clicked()),SLOT(changement_Fenetre()));
}




void FenetreP::changement_Fenetre()
{
        if( menu ->Test ==(QPushButton*)sender())
        {
            //stack -> insertWidget(1,s);
            stack->setCurrentIndex(1);
        }
        if( c->btn  ==(QPushButton*)sender()){stack->setCurrentIndex(0);}
        if( s ->Menu ==(QPushButton*)sender()){stack->setCurrentIndex(0);}
        if( menu ->Connexion ==(QPushButton*)sender()){stack->setCurrentIndex(2);}

}


