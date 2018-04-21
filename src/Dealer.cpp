#include <iostream>
#include <string.h>


#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include "dealer.h"

#define DEBUG

static dealer* PTR;

#include "callback.h" // uses the PTR var
//----------------------------------------------------

const char* StartWindow::get_dealer_name(){
    return dealer_name;
}

//----------------------------------------------------
void StartWindow::cb_start(Fl_Widget* o, void* v) {
 
    ( (StartWindow*)v )->cb_start_i(o,v);
}

void StartWindow::cb_start_i(Fl_Widget* b, void* d) {
    dealer_name = name->value();
    strncpy ( (*PTR).m_D_pub.name,dealer_name,sizeof ( (*PTR).m_D_pub.name ) );
    
    //start Next Window && Game
    (*PTR).user_input ("start");
    (*PTR).setMainWindow();
   
#ifdef DEBUG    
    cout << endl << dealer_name << endl; // test
#endif
    b->parent()->hide();
    b->parent()->redraw();
}

//----------------------------------------------------

void StartWindow::cb_radio(Fl_Widget* o, void* v) {
 
    ( (StartWindow*)v )->cb_radio_i(o,v);
}

void StartWindow::cb_radio_i(Fl_Widget *b, void *d) {
    

    Fl_Round_Button* rb = ((Fl_Round_Button*)b);
    if(rb->value() == 1)
    {
      int h = *(int *)(&d);
      (*PTR).SetDeck(h);
#ifdef DEBUG
      cout << endl << h << endl;
#endif
    }
}

//----------------------------------------------------

void StartWindow::cb_quit(Fl_Widget* o, void* v) {

   ( (StartWindow*)v )->cb_quit_i(o,v);
}


void StartWindow::cb_quit_i(Fl_Widget* b, void* d) {

    (*PTR).user_input ("quit");
    hide();
}

//----------------------------------------------------
void MainWindow::cb_start(Fl_Widget* o, void* v) {
 
    ( (MainWindow*)v )->cb_start_i(o,v);
}

void MainWindow::cb_start_i(Fl_Widget* b, void* d) {
    //dealer_name = name->value();
    //cout << endl << dealer_name << endl; // test
    (*PTR).user_input ("startGame");
    //hide();
}


//----------------------------------------------------

void MainWindow::cb_quit(Fl_Widget* o, void* v) {

   ( (MainWindow*)v )->cb_quit_i(o,v);
}


void MainWindow::cb_quit_i(Fl_Widget* b, void* d) {

    (*PTR).user_input ("quit");
    hide();
}


int main ( int argc, char* argv[] )
{
   // create the dealer object
   dealer D = dealer ();
   PTR = &D;
   // dealer unique ID
   boost::uuids::uuid uuid = boost::uuids::random_generator()();
   memcpy ( D.m_D_pub.uid, &uuid, sizeof ( D.m_D_pub.uid ) );
   // game unique ID
   boost::uuids::uuid game_uuid = boost::uuids::random_generator()();
   memcpy ( D.m_D_pub.game_uid, &game_uuid, sizeof ( D.m_D_pub.game_uid ) );

   const std::string tmp = boost::uuids::to_string(uuid);
   const char* value = tmp.c_str();

   (*PTR).setStartWindow(value);
   return Fl::run();

   //return 0;
}

