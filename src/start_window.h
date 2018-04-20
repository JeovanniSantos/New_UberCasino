#ifndef START_WINDOW_H
#define START_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Round_Button.H>
#include <iostream>
#include <FL/Fl_Group.H>



using namespace std;

//---------------------------------------------------
 
class StartWindow : public Fl_Window{
 
   public:
      StartWindow(int w, int h, const char* title,const char* uuid_in);
      ~StartWindow();
      Fl_Box * welcome;
      Fl_Button* start;
      Fl_Button* quit;
      Fl_Input* name;
      Fl_Output* uuid;
      Fl_Round_Button* test_deck;
      Fl_Round_Button* eight_deck;
      Fl_Round_Button* infinite_deck;

      const char* get_dealer_name();


   
   private:
      static void cb_start(Fl_Widget*, void*);
      inline void cb_start_i();
 
      static void cb_quit(Fl_Widget*, void*);
      inline void cb_quit_i();

      static void cb_radio(Fl_Widget* o, void* v); 
      inline void cb_radio_i(Fl_Widget *b, void *d); 

      const char* dealer_name;

};

StartWindow::StartWindow(int w, int h, const char* title, const char* uuid_in):Fl_Window(w,h,title){
   
   begin();
   
      welcome = new Fl_Box(80, 10, 100, 50, "Welcome to UberCasino!");
      welcome->labelsize(18);
  
      name = new Fl_Input(80, 80, 350, 30, "Name:");
      uuid = new Fl_Output(80, 130, 350, 30, "Uuid:");
      uuid->value(uuid_in); 

      Fl_Group* rb_group = new Fl_Group(15, 10, 300, 300);
      //rb_group->box(FL_UP_FRAME);   
      { test_deck = new Fl_Round_Button(80, 180, 70, 30, "Test");
        test_deck->type(102);
        test_deck->down_box(FL_ROUND_DOWN_BOX);
        test_deck->callback(cb_radio,(void*)1);
      } 
      { eight_deck = new Fl_Round_Button(80, 220, 70, 30, "8 Deck");
        eight_deck->type(102);
        eight_deck->down_box(FL_ROUND_DOWN_BOX);
        eight_deck->callback(cb_radio,(void*)2);
      } 
      { infinite_deck = new Fl_Round_Button(80, 260, 70, 30, "Infinite");
        infinite_deck->type(102);
        infinite_deck->down_box(FL_ROUND_DOWN_BOX);
        infinite_deck->callback(cb_radio,(void*)3);
      } 
      rb_group->end();

/*
      test_deck = new Fl_Round_Button( 80, 180, 70, 30, "Test");;
      eight_deck = new Fl_Round_Button( 80, 220, 70, 30, "8 Deck") ;
      infinite_deck = new Fl_Round_Button( 80, 260, 70, 30, "Infinite");
*/
      start = new Fl_Button( 50, 350, 70, 30, "Start");
      start->callback( cb_start, this );
    
      quit = new Fl_Button(140, 350, 70, 30, "Quit");
      quit->callback(cb_quit, this);


   end();
   resizable(this);
   show();
}

//----------------------------------------------------

StartWindow::~StartWindow(){}
#endif

