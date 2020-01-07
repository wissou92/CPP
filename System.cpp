#include "System.h"


System::System(QWidget *parent):QWidget(parent)
{

 //this ->setStyleSheet("QWidget{background-color: transparent;}");
  this -> resize (700 , 700);
  setWindowTitle("Projet CPP");
  tracer_lignes();
  creer_tanks();
  creer_buttons();

    M1 = new Moteur("M1",t,this );
    mes_moteur.push_back(M1);
    M2 = new Moteur("M2",t1,this);
    mes_moteur.push_back(M2);
    M3 = new Moteur("M3",t2 ,this);
    mes_moteur.push_back(M3);
    M1 -> move(115, 400);
    M2 -> move(305, 400);
    M3-> move(505,400);

    tracer_vannes();

  for (auto it = mes_btns.begin() ; it != mes_btns.end(); ++it)
  {
     connect(*it, SIGNAL(clicked()),SLOT(open_close()));
     connect(*it, SIGNAL(clicked()),SLOT(test_vidange()));
     connect(*it, SIGNAL(clicked()),SLOT(arret_Pompe()));
     connect(*it, SIGNAL(clicked()),SLOT(mouvement_reserv()));
  }

 //RESERVOIR

  timer1 = new QTimer(this);
  connect(timer1, SIGNAL(timeout()), t, SLOT(mise_a_jour()));


  timer2 = new QTimer(this);
  connect(timer2, SIGNAL(timeout()), t1, SLOT(mise_a_jour()));


  timer3 = new QTimer(this);
  connect(timer3, SIGNAL(timeout()), t2, SLOT(mise_a_jour()));



   //Moteur
  for (auto i = mes_moteur.begin() ;  i!= mes_moteur.end() ; ++i )
    connect(*i, SIGNAL(non_alimenter()),this, SLOT(alimentation()));


   connect(start , SIGNAL(clicked()) ,SLOT(demarer_timer()));
}

//pour eviter un constructeur trop rempli
void System::tracer_lignes()
{
    Line *l1 =  new Line(155,80,155,400,this); Q_UNUSED(l1);
    Line *l2 =  new Line(175,50,325,50,this);  Q_UNUSED(l2);
    Line *l3 =  new Line(385,50,555,50,this);  Q_UNUSED(l3);
    Line *l4 =  new Line(350,100,350,400,this);Q_UNUSED(l4);
    Line *l5 =  new Line(555,80,555,400,this); Q_UNUSED(l5);
    //pour v13
    Line *l6 =  new Line(155,150,555,150,this);Q_UNUSED(l6);
    //pour v12
    Line *l7 =  new Line(155,250,350,250,this);Q_UNUSED(l7);
    //pour v23
    Line *l8 =  new Line(350,350,555,350,this);Q_UNUSED(l8);
}

void System::tracer_vannes()
{
    vt12 = new VanneTT ("VT12",1,this,t,t1);
    vt12 -> move (240,35);
    vt23 = new VanneTT ("VT23",1,this,t1,t2);
    vt23 ->move  (445,35);
    v13 = new VanneTM ("V13",2,this,t,M3);
    v13 ->move  (240,135);
    v12 = new VanneTM ("V12",2,this,t,M2);
    v12 ->move  (240,235);
    v23 = new VanneTM ("V23",2,this,t2,M2);
    v23 ->move  (445,335);
}

void System::creer_buttons()
{
    V12 = new QPushButton ("V12");
    mes_btns.push_back(V12);
    V13 = new QPushButton ("V13");
    mes_btns.push_back(V13);
    V23 = new QPushButton ("V23");
    mes_btns.push_back(V23);
    VT12 = new QPushButton ("VT12");
    mes_btns.push_back(VT12);
    VT23 = new QPushButton ("VT23");
    mes_btns.push_back(VT23);
    P32 = new QPushButton ("P32");
    mes_btns.push_back(P32);
    P12 = new QPushButton ("P12");
    mes_btns.push_back(P12);
    P22 = new QPushButton ("P22");
    mes_btns.push_back(P22);
    res1 = new QPushButton ("VidangeT1");
    mes_btns.push_back(res1);
    res2 = new QPushButton ("VidangeT2");
    mes_btns.push_back(res2);
    res3 = new QPushButton ("VidangeT3");
    mes_btns.push_back(res3);
    PP11= new QPushButton ("PP11");
    mes_btns.push_back(PP11);
    PP21 = new QPushButton ("PP21");
    mes_btns.push_back(PP21);
    PP31 =new QPushButton ("PP31");
    mes_btns.push_back(PP31);

    Menu =new QPushButton ("Menu",this);
    mes_btns.push_back(Menu);

    start = new QPushButton ("Start",this);
    start -> move (0,22);
    start -> setStyleSheet(
                "border-style: outset;"
                "border-width: 2px;"
                "border-radius: 10px;"
                "border-color: steelblue;"
                 "color: steelblue;"
                "font: bold 10px;"
                "min-width: 5em;"
                " padding: 3px;" );

    QGroupBox *gb2 = new QGroupBox(this);
    QGroupBox *gb1 = new QGroupBox(this);
    QGroupBox *gb = new QGroupBox(this);

    QHBoxLayout *layout = new QHBoxLayout();
    QHBoxLayout *layout1 = new QHBoxLayout();
    QHBoxLayout *layout2 = new QHBoxLayout();


   layout1 -> addWidget(P12);
   layout1 -> addWidget(P22);
   layout1 -> addWidget(P32);


   layout -> addWidget(V12);
   layout -> addWidget(V13);
   layout -> addWidget(V23);
   layout -> addWidget(VT12);
   layout -> addWidget(VT23);

   layout2 ->addWidget(res1);
   layout2 ->addWidget(res2);
   layout2 ->addWidget(res3);
   layout2 ->addWidget(PP11);
   layout2 ->addWidget(PP21);
   layout2 ->addWidget(PP31);

   gb2 ->setLayout(layout2);

   gb2 -> move(50,645);
   gb2-> resize (600 ,55);
   gb1 -> setLayout(layout);
   gb2 ->setStyleSheet("QWidget{background-color: transparent;}");
   gb1 -> move(50,545);
   gb1 -> resize (600 ,55);
   gb1 ->setStyleSheet("QWidget{background-color: transparent;}");

   gb -> setLayout(layout1);
   gb -> move(50,595);
   gb -> resize (600 ,55);
   gb ->setStyleSheet("QWidget{background-color: transparent;}");

   for (auto it = mes_btns.begin() ; it !=mes_btns.end(); ++it)
   (*it) -> setStyleSheet(
                  "border-style: outset;"
                  "border-width: 2px;"
                  "border-radius: 10px;"
                  "border-color: steelblue;"
                   "color: steelblue;"
                  "font: bold 10px;"
                  "min-width: 5em;"
                  " padding: 3px;" );


}

void System::creer_tanks()
{

    t = new Tank(this,500);
    mes_tank.push_back(t);

    t1 = new Tank(this,300);
    mes_tank.push_back(t1);

    t2 = new Tank(this,500) ;
    mes_tank.push_back(t2);
    t -> move(100, 5);
    t2-> move(500,5);
    t1 -> move(300,20);
}


System::~System(){}

//slot qui detecte le clic des buttons tank
//et qui lance le signal pannetank
//et renvoie vers le slot du vidange plus bas
void System:: test_vidange(){
      tmp = (QPushButton*)sender() ;
      emit Panne_Tank() ;
      connect(this, SIGNAL(Panne_Tank()), this, SLOT(accelerer_timer()));
}

//pour la vidange j'accelere le timer
//pour actualiser la valeur du res plus vite
void System::accelerer_timer()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(vider_T()));
    timer->start(25);
 }

//slot pour le vidange
void System ::vider_T()
{
    if(res1 == tmp)
    {
        t-> Panne_Reservoir();
        t ->  mise_a_jour();
        t  -> update();
    }
    if(res2 == tmp)
    {
         t1-> Panne_Reservoir();
         t1 -> mise_a_jour();
         t1 -> update();
    }
    if(res3 == tmp)
    {
       t2-> Panne_Reservoir();
       t2 -> mise_a_jour();
       t2 -> update();
    }
}


//non fini
//il manque  un siganl pour changer la couleur
// du moteur quand le reservoir est arrete
void System ::mouvement_reserv()
{

    //gestion du timer du tank1
 if ((QPushButton*)sender() == PP11  && t->secondaire->get_etat()==OFF)
    { timer1->stop();}

 if ((QPushButton*)sender() == P12 && t->primaire->get_etat()==OFF && t->secondaire->get_etat()==ON)
     {
     timer1->start(700);
     }
  else if((QPushButton*)sender() == P12 && t->primaire->get_etat()==OFF && t->secondaire->get_etat()==OFF)
  {
     timer1->stop();
   }
    //gestion du timer du tank2
 if ((QPushButton*)sender() == PP21 && t1->secondaire->get_etat()==OFF)
    {
     timer2->stop();
    }
 else if((QPushButton*)sender() == P22 && t1->primaire->get_etat()==OFF && t1->secondaire->get_etat()==OFF)
 {
    timer2->stop();
  }

 if ((QPushButton*)sender() == P22 && t1->primaire->get_etat()==OFF && t1->secondaire->get_etat()==ON)
    {
     timer2->start(600);
    }

    //gestion du timer du tank2
 if ((QPushButton*)sender() == PP31 && t2->secondaire->get_etat()==OFF)
    {
     timer3->stop();
    }

 else if((QPushButton*)sender() == PP31 && t2->primaire->get_etat()==OFF && t2->secondaire->get_etat()==OFF)
 {
     timer3->stop();
 }

 if ((QPushButton*)sender() == P32 && t2->primaire->get_etat()==OFF && t2->secondaire->get_etat()==ON)
    {
     timer3->start(700);
    }

 }


//generer  les pannnes des pompes primaires
//je genere une panne de la premiere pompe jarret le reservoir (timer)
//voir mouvement reserv
void System::arret_Pompe(){

    if ((QPushButton*)sender() == PP11 && t-> primaire->get_etat() == ON){
       t-> primaire->generer_Panne_Pompe();//genere la panne
       t->primaire ->start_stop();//je desactive la pompe
       connect(PP11, SIGNAL(clicked()),this,SLOT(mouvement_reserv()));
     }
   if ((QPushButton*)sender() == PP21 && t1-> primaire->get_etat() == ON){
       connect(PP21, SIGNAL(clicked()),this,SLOT(mouvement_reserv()));
        t1-> primaire->generer_Panne_Pompe();
        t1->primaire ->start_stop();

     }
    if ((QPushButton*)sender() == PP31 && t2-> primaire->get_etat() == ON){
        connect(PP31, SIGNAL(clicked()),this,SLOT(mouvement_reserv()));
        t2-> primaire->generer_Panne_Pompe();
        t2->primaire ->start_stop();

     }
   //si jactive la pompe 2
   //je restart le timer voir mouvvement_reserv
    if ((QPushButton*)sender() == P12)
                      {t->secondaire->start_stop();}

    if ((QPushButton*)sender() == P22)
                      {t1->secondaire->start_stop();}

    if ((QPushButton*)sender() == P32)
                      {t2->secondaire->start_stop();}
}

//ici il reste le cas des tank tank
//ouverture et fermeture des vanne
//les vannes cest dans les deux sens donc c bourbier :)
// juste attention les tank sont t , t1 , t2
// je sais jai merdé  mais flemme frere dsl

void System :: open_close(){
  if (VT12 ==(QPushButton*)sender()){
      /*int val = t -> progressBar->value();
      QTimer *tt = new QTimer(); tt->start (700);
     if (t1 ->progressBar->value() == t->progressBar->value())
         qDebug()<<(val > 0 &&  t1 -> progressBar->value() < val) <<endl;
     if (val > 0 &&  t1 -> progressBar->value() < val){
            // connect(t1, SIGNAL(timeout()), t, SLOT(mise_a_jour()));
             connect(tt, SIGNAL(timeout()), t1, SLOT(augmenter_Value()));
         }*/

           vt12 -> open_close();
           vt12 ->update();
    }

  if (VT23 ==(QPushButton*)sender())
    {
           vt23 -> open_close();
           vt23 ->update();
    }

  if (V12  ==(QPushButton*)sender())
   {
       if (t -> progressBar-> value() > 0){
              if (M2 -> get_Tank() != t1){ M2->changer_Reservoir(t1);}
              else{ M2 -> changer_Reservoir(t);}
        }
       else{
               if (M1 -> get_Tank() != t){ M1->changer_Reservoir(t);}
               else{ M1 -> changer_Reservoir(t1);}
           }
          v12 ->open_close();
          v12  ->update();
    }

  if (V13  ==(QPushButton*)sender()){
     if (t -> progressBar-> value() > 0){
              if (M3 -> get_Tank() != t2){ M3->changer_Reservoir(t2);}
              else{ M3 -> changer_Reservoir(t);}
      }else{
             if (M1 -> get_Tank() != t){ M1->changer_Reservoir(t);}
             else{ M1 -> changer_Reservoir(t2);}
         }
          v13 ->open_close();
          v13 -> update();
     }

  if (V23  ==(QPushButton*)sender()){
       if (t2 -> progressBar-> value() > 0){
          if (M2 -> get_Tank() != t1){ M2->changer_Reservoir(t1);}
          else{ M2 -> changer_Reservoir(t2);}
       }else{
               if (M3 -> get_Tank() != t2){ M3->changer_Reservoir(t2);}
               else{ M3 -> changer_Reservoir(t1);}
       }
          v23 -> open_close();  v23 -> update();
    }
}

//permet de deminuer le carburant de 10 a chaque fois
void System::mise_a_jour_tank()
 {
    t->mise_a_jour();
    t1->mise_a_jour();
    t2->mise_a_jour();
    t->update();
    t1->update();
    t2->update();
 }

//regarde si le reservoir
//du moteur contient du carburant
// et si les pompes de ce moteur sont fonctionnelles
//jai un poiteur tank dans chaque moteur
//pour check ca
void System::alimentation()
{
    if( M1 ==(Moteur*)sender()){M1->changer_Couleur();M1-> update();}
    if( M2 ==(Moteur*)sender()){M2->changer_Couleur();M2-> update();}
    if( M3 ==(Moteur*)sender()){M3->changer_Couleur();M3-> update();}
}


void System::demarer_timer()
{
     timer1->start(800);
     timer2->start(800);
     timer3->start(800);
}

