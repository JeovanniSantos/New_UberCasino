#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl_PNG_Image.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Round_Button.H>
#include <iostream>
#include <FL/Fl_Group.H>
#include <vector>
#include <FL/Fl_Widget.H>


using namespace std;

//---------------------------------------------------
 
class MainWindow : public Fl_Window{
 
   public:
      MainWindow(int w, int h, const char* title);
      ~MainWindow();

      Fl_PNG_Image* png;
      Fl_Box* box;   

      Fl_Box*dealer_deck;
      Fl_Box*dealer_value;
      Fl_Box* game_info;
      Fl_Box* table_count;	
      Fl_Box* player1;
      Fl_Box* player1_value;
      Fl_Box* player2;
      Fl_Box* player2_value;
      Fl_Box* player3;
      Fl_Box* player3_value;
      Fl_Box* player4;
      Fl_Box* player4_value;
      Fl_Box* player5;
      Fl_Box* player5_value;
      Fl_Box* player6;
      Fl_Box* player6_value;
      Fl_Box* player7;
      Fl_Box* player7_value;
      Fl_Button* start;
      Fl_Button* quit;
      Fl_Input* name;


   private:
      static void cb_start(Fl_Widget* o, void* v);
      inline void cb_start_i(Fl_Widget* b, void* d);
 
      static void cb_quit(Fl_Widget* o, void* v);
      inline void cb_quit_i(Fl_Widget* b, void* d);

};

#endif
