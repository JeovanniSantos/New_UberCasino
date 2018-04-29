#include <iostream>
#include <functional>
#include <vector>
#include <string.h>


#include <boost/thread.hpp>

#include "dealer.h"
#include <mutex>

#define DEBUG

#define TIMER(SECS) \
    if ( m_timer_thread )\
    {\
       m_timer_thread->interrupt ();\
       delete ( m_timer_thread );\
       m_timer_thread = NULL;\
    }\
    m_timer_thread = new boost::thread ( delay_thread , SECS , std::bind ( &dealer::timer_expired , this ) );\

//std::mutex m;

int suite_to_string ( UberCasino::suite_t t )
{
   int retval;
   switch ( t )
   {
     case hearts:retval = 0;break;
     case diamonds:retval = 1;break;
     case clubs:retval = 2;break;
     case spades:retval = 3;break;
   }
   return retval;
}

int kind_to_string ( UberCasino::card_kind t )
{
   int retval;
   switch ( t )
   {
      case ace:retval = 0;break;
      case two:retval = 1;break;
      case three:retval = 2;break;
      case four:retval = 3;break;
      case five:retval = 4;break;
      case six:retval = 5;break;
      case seven:retval = 6;break;
      case eight:retval = 7;break;
      case nine:retval = 8;break;
      case ten:retval = 9;break;
      case jack:retval = 10;break;
      case queen:retval = 11;break;
      case king:retval = 12;break;
   }
   return retval;
}

void MainWindow::resetGame(){
      //dealer
      dealer_value->label("dealer");
      dealer_value->hide();
      card1->hide();
      card2->hide();
      card3->hide();
      card4->hide();
      card5->hide();
      card6->hide();
      card7->hide();
      card8->hide();
      card9->hide();
      card10->hide();

      //player 1
      player1_value->label("player1");
      player1_value->hide();
      card1_1->hide();
      card1_2->hide();
      card1_3->hide();
      card1_4->hide();
      card1_5->hide();
      card1_6->hide();
      card1_7->hide();
      card1_8->hide();
      card1_9->hide();
      card1_10->hide();

      //player 2
      player2_value->label("player2");
      player2_value->hide();
      card2_1->hide();
      card2_2->hide();
      card2_3->hide();
      card2_4->hide();
      card2_5->hide();
      card2_6->hide();
      card2_7->hide();
      card2_8->hide();
      card2_9->hide();
      card2_10->hide();

      //player 3
      player3_value->label("player3");
      player3_value->hide();
      card3_1->hide();
      card3_2->hide();
      card3_3->hide();
      card3_4->hide();
      card3_5->hide();
      card3_6->hide();
      card3_7->hide();
      card3_8->hide();
      card3_9->hide();
      card3_10->hide();

      //player 4
      player4_value->label("player4");
      player4_value->hide();
      card4_1->hide();
      card4_2->hide();
      card4_3->hide();
      card4_4->hide();
      card4_5->hide();
      card4_6->hide();
      card4_7->hide();
      card4_8->hide();
      card4_9->hide();
      card4_10->hide();

      //player 5
      player5_value->label("player5");
      player5_value->hide();
      card5_1->hide();
      card5_2->hide();
      card5_3->hide();
      card5_4->hide();
      card5_5->hide();
      card5_6->hide();
      card5_7->hide();
      card5_8->hide();
      card5_9->hide();
      card5_10->hide();

      //player 6
      player6_value->label("player6");
      player6_value->hide();
      card6_1->hide();
      card6_2->hide();
      card6_3->hide();
      card6_4->hide();
      card6_5->hide();
      card6_6->hide();
      card6_7->hide();
      card6_8->hide();
      card6_9->hide();
      card6_10->hide();

      //player 7
      player7_value->label("player7");
      player7_value->hide();
      card7_1->hide();
      card7_2->hide();
      card7_3->hide();
      card7_4->hide();
      card7_5->hide();
      card7_6->hide();
      card7_7->hide();
      card7_8->hide();
      card7_9->hide();
      card7_10->hide();
}

void MainWindow::card_to_string(Fl_Box** box, UberCasino::card_t c){
  int suite = suite_to_string (c.suite);
  int type = kind_to_string (c.card);

  switch(suite){
    case 0:
      switch(type){
        case 0:
          (*box)->image(AH);
        break;
        case 1:
          (*box)->image(H2);
        break;
        case 2:
          (*box)->image(H3);
        break;
        case 3:
          (*box)->image(H4);
        break;
        case 4:
          (*box)->image(H5);
        break;
        case 5:
          (*box)->image(H6);
        break;
        case 6:
          (*box)->image(H7);
        break;
        case 7:
          (*box)->image(H8);
        break;
        case 8:
          (*box)->image(H9);
        break;
        case 9:
          (*box)->image(H10);
        break;
        case 10:
          (*box)->image(JH);
        break;
        case 11:
          (*box)->image(QH);
        break;
        case 12:
          (*box)->image(KH);
        break;
      };
      break;
    case 1:
      switch(type){
        case 0:
          (*box)->image(AD);
        break;
        case 1:
          (*box)->image(D2);
        break;
        case 2:
          (*box)->image(D3);
        break;
        case 3:
          (*box)->image(D4);
        break;
        case 4:
          (*box)->image(D5);
        break;
        case 5:
          (*box)->image(D6);
        break;
        case 6:
          (*box)->image(D7);
        break;
        case 7:
          (*box)->image(D8);
        break;
        case 8:
          (*box)->image(D9);
        break;
        case 9:
          (*box)->image(D10);
        break;
        case 10:
          (*box)->image(JD);
        break;
        case 11:
          (*box)->image(QD);
        break;
        case 12:
          (*box)->image(KD);
        break;
      };
      break;
    case 2:
      switch(type){
        case 0:
          (*box)->image(AC);
        break;
        case 1:
          (*box)->image(C2);
        break;
        case 2:
          (*box)->image(C3);
        break;
        case 3:
          (*box)->image(C4);
        break;
        case 4:
          (*box)->image(C5);
        break;
        case 5:
          (*box)->image(C6);
        break;
        case 6:
          (*box)->image(C7);
        break;
        case 7:
          (*box)->image(C8);
        break;
        case 8:
          (*box)->image(C9);
        break;
        case 9:
          (*box)->image(C10);
        break;
        case 10:
          (*box)->image(JC);
        break;
        case 11:
          (*box)->image(QC);
        break;
        case 12:
          (*box)->image(KC);
        break;
      };
      break;
    case 3:
      switch(type){
        case 0:
          (*box)->image(AS);
        break;
        case 1:
          (*box)->image(S2);
        break;
        case 2:
          (*box)->image(S3);
        break;
        case 3:
          (*box)->image(S4);
        break;
        case 4:
          (*box)->image(S5);
        break;
        case 5:
          (*box)->image(S6);
        break;
        case 6:
          (*box)->image(S7);
        break;
        case 7:
          (*box)->image(S8);
        break;
        case 8:
          (*box)->image(S9);
        break;
        case 9:
          (*box)->image(S10);
        break;
        case 10:
          (*box)->image(JS);
        break;
        case 11:
          (*box)->image(QS);
        break;
        case 12:
          (*box)->image(KS);
        break;
      };
      break;
  };
  (*box)->show();
}

void MainWindow::create_player1(){
    /*** player 1 ***/
    int x = 140;
    int y = 50;
    player1_value = new Fl_Box(x-110,y,100,50,"player1");
    player1_value->box(FL_BORDER_BOX);
    card1_1 = new Fl_Box(x,y,69,106); 
    card1_1->image(AC);
    card1_1->box(FL_BORDER_BOX);
    x=x+20;
    card1_2 = new Fl_Box(x,y,69,106);
    card1_2->box(FL_BORDER_BOX);
    x=x+20;
    card1_3 = new Fl_Box(x,y,69,106);  
    card1_3->box(FL_BORDER_BOX);
    x=x+20;
    card1_4 = new Fl_Box(x,y,69,106); 
    card1_4->box(FL_BORDER_BOX);
    x=x+20;
    card1_5 = new Fl_Box(x,y,69,106);  
    card1_5->box(FL_BORDER_BOX);
    x=150;
    y=80;
    card1_6 = new Fl_Box(x,y,69,106); 
    card1_6->image(AC); 
    card1_6->box(FL_BORDER_BOX);
    x=x+20;
    card1_7 = new Fl_Box(x,y,69,106);  
    card1_7->box(FL_BORDER_BOX);
    x=x+20;
    card1_8 = new Fl_Box(x,y,69,106); 
    card1_8->box(FL_BORDER_BOX);
    x=x+20;
    card1_9 = new Fl_Box(x,y,69,106); 
    card1_9->box(FL_BORDER_BOX);
    x=x+20;
    card1_10 = new Fl_Box(x,y,69,106); 
    card1_10->box(FL_BORDER_BOX);

    player1_value->hide();
    card1_1->hide();
    card1_2->hide();
    card1_3->hide();
    card1_4->hide();
    card1_5->hide();
    card1_6->hide();
    card1_7->hide();
    card1_8->hide();
    card1_9->hide();
    card1_10->hide();

}

void MainWindow::create_player7(){
    /*** player 7 ***/
    int x = 710;
    int y = 50;
    player7_value = new Fl_Box(x+170,y,100,50,"player7");
    player7_value->box(FL_BORDER_BOX);

    card7_1 = new Fl_Box(x,y,69,106);   
    card7_1->box(FL_BORDER_BOX);
    x=x+20;
    card7_2 = new Fl_Box(x,y,69,106);
    card7_2->box(FL_BORDER_BOX);
    x=x+20;
    card7_3 = new Fl_Box(x,y,69,106);  
    card7_3->box(FL_BORDER_BOX);
    x=x+20;
    card7_4 = new Fl_Box(x,y,69,106); 
    card7_4->box(FL_BORDER_BOX);
    x=x+20;
    card7_5 = new Fl_Box(x,y,69,106);   
    card7_5->box(FL_BORDER_BOX);
    x=720;
    y=80;
    card7_6 = new Fl_Box(x,y,69,106);  
    card7_6->box(FL_BORDER_BOX);
    x=x+20;
    card7_7 = new Fl_Box(x,y,69,106);  
    card7_7->box(FL_BORDER_BOX);
    x=x+20;
    card7_8 = new Fl_Box(x,y,69,106); 
    card7_8->box(FL_BORDER_BOX);
    x=x+20;
    card7_9 = new Fl_Box(x,y,69,106); 
    card7_9->box(FL_BORDER_BOX);
    x=x+20;
    card7_10 = new Fl_Box(x,y,69,106); 
    card7_10->box(FL_BORDER_BOX);

    player7_value->hide();
    card7_1->hide();
    card7_2->hide();
    card7_3->hide();
    card7_4->hide();
    card7_5->hide();
    card7_6->hide();
    card7_7->hide();
    card7_8->hide();
    card7_9->hide();
    card7_10->hide();

}

void MainWindow::create_player2(){
    /*** player 2 ***/
    int x = 160;
    int y = 200;
    player2_value = new Fl_Box(x-110,y,100,50,"player2");
    player2_value->box(FL_BORDER_BOX);
    card2_1 = new Fl_Box(x,y,69,106);  
    card2_1->box(FL_BORDER_BOX);
    x=x+20;
    card2_2 = new Fl_Box(x,y,69,106);  
    card2_2->box(FL_BORDER_BOX);
    x=x+20;
    card2_3 = new Fl_Box(x,y,69,106); 
    card2_3->box(FL_BORDER_BOX);
    x=x+20;
    card2_4 = new Fl_Box(x,y,69,106);  
    card2_4->box(FL_BORDER_BOX);
    x=x+20;
    card2_5 = new Fl_Box(x,y,69,106);  
    card2_5->box(FL_BORDER_BOX);
    x=170;
    y=230;
    card2_6 = new Fl_Box(x,y,69,106); 
    card2_6->box(FL_BORDER_BOX);
    x=x+20;
    card2_7 = new Fl_Box(x,y,69,106); 
    card2_7->box(FL_BORDER_BOX);
    x=x+20;
    card2_8 = new Fl_Box(x,y,69,106);  
    card2_8->box(FL_BORDER_BOX);
    x=x+20;
    card2_9 = new Fl_Box(x,y,69,106); 
    card2_9->box(FL_BORDER_BOX);
    x=x+20;
    card2_10 = new Fl_Box(x,y,69,106);  
    card2_10->box(FL_BORDER_BOX);

    player2_value->hide();
    card2_1->hide();
    card2_2->hide();
    card2_3->hide();
    card2_4->hide();
    card2_5->hide();
    card2_6->hide();
    card2_7->hide();
    card2_8->hide();
    card2_9->hide();
    card2_10->hide();
}

void MainWindow::create_player6(){
    /*** player 6 ***/
    int x = 690;
    int y = 200;
    player6_value = new Fl_Box(x+170,y,100,50,"player6");
    player6_value->box(FL_BORDER_BOX);

    card6_1 = new Fl_Box(x,y,69,106); 
    card6_1->box(FL_BORDER_BOX);
    x=x+20;
    card6_2 = new Fl_Box(x,y,69,106);   
    card6_2->box(FL_BORDER_BOX);
    x=x+20;
    card6_3 = new Fl_Box(x,y,69,106);  
    card6_3->box(FL_BORDER_BOX);
    x=x+20;
    card6_4 = new Fl_Box(x,y,69,106); 
    card6_4->box(FL_BORDER_BOX);
    x=x+20;
    card6_5 = new Fl_Box(x,y,69,106);  
    card6_5->box(FL_BORDER_BOX);
    x=700;
    y=230;
    card6_6 = new Fl_Box(x,y,69,106);  
    card6_6->box(FL_BORDER_BOX);
    x=x+20;
    card6_7 = new Fl_Box(x,y,69,106); 
    card6_7->box(FL_BORDER_BOX);
    x=x+20;
    card6_8 = new Fl_Box(x,y,69,106); 
    card6_8->box(FL_BORDER_BOX);
    x=x+20;
    card6_9 = new Fl_Box(x,y,69,106);  
    card6_9->box(FL_BORDER_BOX);
    x=x+20;
    card6_10 = new Fl_Box(x,y,69,106); 
    card6_10->box(FL_BORDER_BOX);

    player6_value->hide();
    card6_1->hide();
    card6_2->hide();
    card6_3->hide();
    card6_4->hide();
    card6_5->hide();
    card6_6->hide();
    card6_7->hide();
    card6_8->hide();
    card6_9->hide();
    card6_10->hide();
}


void MainWindow::create_player3(){
    /*** player 3***/
    int x = 180;
    int y = 350;
    player3_value = new Fl_Box(x-110,y,100,50,"player3");
    player3_value->box(FL_BORDER_BOX);
    card3_1 = new Fl_Box(x,y,69,106); 
    card3_1->box(FL_BORDER_BOX);
    x=x+20;
    card3_2 = new Fl_Box(x,y,69,106);  
    card3_2->box(FL_BORDER_BOX);
    x=x+20;
    card3_3 = new Fl_Box(x,y,69,106); 
    card3_3->box(FL_BORDER_BOX);
    x=x+20;
    card3_4 = new Fl_Box(x,y,69,106); 
    card3_4->box(FL_BORDER_BOX);
    x=x+20;
    card3_5 = new Fl_Box(x,y,69,106); 
    card3_5->box(FL_BORDER_BOX);
    x=190;
    y=380;
    card3_6 = new Fl_Box(x,y,69,106);  
    card3_6->box(FL_BORDER_BOX);
    x=x+20;
    card3_7 = new Fl_Box(x,y,69,106); 
    card3_7->box(FL_BORDER_BOX);
    x=x+20;
    card3_8 = new Fl_Box(x,y,69,106);  
    card3_8->box(FL_BORDER_BOX);
    x=x+20;
    card3_9 = new Fl_Box(x,y,69,106);  
    card3_9->box(FL_BORDER_BOX);
    x=x+20;
    card3_10 = new Fl_Box(x,y,69,106); 
    card3_10->box(FL_BORDER_BOX);

    player3_value->hide();
    card3_1->hide();
    card3_2->hide();
    card3_3->hide();
    card3_4->hide();
    card3_5->hide();
    card3_6->hide();
    card3_7->hide();
    card3_8->hide();
    card3_9->hide();
    card3_10->hide();  
}

void MainWindow::create_player5(){
    /*** player 5***/
    int x = 670;
    int y = 350;
    player5_value = new Fl_Box(x+170,y,100,50,"player5");
    player5_value->box(FL_BORDER_BOX);

    card5_1 = new Fl_Box(x,y,69,106);   
    card5_1->box(FL_BORDER_BOX);
    x=x+20;
    card5_2 = new Fl_Box(x,y,69,106);   
    card5_2->box(FL_BORDER_BOX);
    x=x+20;
    card5_3 = new Fl_Box(x,y,69,106); 
    card5_3->box(FL_BORDER_BOX);
    x=x+20;
    card5_4 = new Fl_Box(x,y,69,106); 
    card5_4->box(FL_BORDER_BOX);
    x=x+20;
    card5_5 = new Fl_Box(x,y,69,106);   
    card5_5->box(FL_BORDER_BOX);
    x=680;
    y=380;
    card5_6 = new Fl_Box(x,y,69,106);  
    card5_6->box(FL_BORDER_BOX);
    x=x+20;
    card5_7 = new Fl_Box(x,y,69,106); 
    card5_7->box(FL_BORDER_BOX);
    x=x+20;
    card5_8 = new Fl_Box(x,y,69,106);   
    card5_8->box(FL_BORDER_BOX);
    x=x+20;
    card5_9 = new Fl_Box(x,y,69,106);  
    card5_9->box(FL_BORDER_BOX);
    x=x+20;
    card5_10 = new Fl_Box(x,y,69,106);   
    card5_10->box(FL_BORDER_BOX);

    player5_value->hide();
    card5_1->hide();
    card5_2->hide();
    card5_3->hide();
    card5_4->hide();
    card5_5->hide();
    card5_6->hide();
    card5_7->hide();
    card5_8->hide();
    card5_9->hide();
    card5_10->hide();
}

void MainWindow::create_player4(){
    /*** player 4***/
    int x = 420;
    int y = 350;
    player4_value = new Fl_Box(x+45,y+145,100,50,"player4");
    player4_value->box(FL_BORDER_BOX);

    card4_1 = new Fl_Box(x,y,69,106);  
    card4_1->box(FL_BORDER_BOX);
    x=x+20;
    card4_2 = new Fl_Box(x,y,69,106); 
    card4_2->box(FL_BORDER_BOX);
    x=x+20;
    card4_3 = new Fl_Box(x,y,69,106); 
    card4_3->box(FL_BORDER_BOX);
    x=x+20;
    card4_4 = new Fl_Box(x,y,69,106);  
    card4_4->box(FL_BORDER_BOX);
    x=x+20;
    card4_5 = new Fl_Box(x,y,69,106);  
    card4_5->box(FL_BORDER_BOX);
    x=430;
    y=380;
    card4_6 = new Fl_Box(x,y,69,106);   
    card4_6->box(FL_BORDER_BOX);
    x=x+20;
    card4_7 = new Fl_Box(x,y,69,106); 
    card4_7->box(FL_BORDER_BOX);
    x=x+20;
    card4_8 = new Fl_Box(x,y,69,106);  
    card4_8->box(FL_BORDER_BOX);
    x=x+20;
    card4_9 = new Fl_Box(x,y,69,106);
    card4_9->box(FL_BORDER_BOX);
    x=x+20;
    card4_10 = new Fl_Box(x,y,69,106); 
    card4_10->box(FL_BORDER_BOX);

    player4_value->hide();
    card4_1->hide();
    card4_2->hide();
    card4_3->hide();
    card4_4->hide();
    card4_5->hide();
    card4_6->hide();
    card4_7->hide();
    card4_8->hide();
    card4_9->hide();
    card4_10->hide();

}

void MainWindow::create_dealer_group(){ 
    /*** player 4***/
    int x = 420;
    int y = 100;
    dealer_value = new Fl_Box(x+45,y+145,100,50,"Dealer Value");
    dealer_value->box(FL_BORDER_BOX);

    card1 = new Fl_Box(x,y,69,106); 
    card1->box(FL_BORDER_BOX);
    x=x+20;
    card2 = new Fl_Box(x,y,69,106); 
    card2->box(FL_BORDER_BOX);
    x=x+20;
    card3 = new Fl_Box(x,y,69,106);  
    card3->box(FL_BORDER_BOX);
    x=x+20;
    card4 = new Fl_Box(x,y,69,106); 
    card4->box(FL_BORDER_BOX);
    x=x+20;
    card5 = new Fl_Box(x,y,69,106); 
    card5->box(FL_BORDER_BOX);
    x=430;
    y=130;
    card6 = new Fl_Box(x,y,69,106); 
    card6->box(FL_BORDER_BOX);
    x=x+20;
    card7 = new Fl_Box(x,y,69,106);  
    card7->box(FL_BORDER_BOX);
    x=x+20;
    card8 = new Fl_Box(x,y,69,106); 
    card8->box(FL_BORDER_BOX);
    x=x+20;
    card9 = new Fl_Box(x,y,69,106); 
    card9->box(FL_BORDER_BOX);
    x=x+20;
    card10 = new Fl_Box(x,y,69,106); 
    card10->box(FL_BORDER_BOX);

    dealer_value->hide();
    card1->hide();
    card2->hide();
    card3->hide();
    card4->hide();
    card5->hide();
    card6->hide();
    card7->hide();
    card8->hide();
    card9->hide();
    card10->hide();
}

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

MainWindow::MainWindow(int w, int h, const char* title, const char* dealer_Name, const char* dealer_Uid, const char* deck_Type):Fl_Window(w,h,title){
   
   begin();
   
      box=new Fl_Box(0, 0, 1020,700);   
      png = new Fl_PNG_Image("src/background.png");      
      box->image(png);  
      box->box(FL_BORDER_BOX);
 
      //create group for dealer
      create_player1();
      create_player2();
      create_player3();
      create_player4();
      create_player5();
      create_player6();
      create_player7();
      create_dealer_group();

      game_info= new Fl_Box(20, 550, 480,120,""); 
      game_info->box(FL_BORDER_BOX);

      dealerName = new Fl_Output(140, 560, 350, 20, "Dealer Name: ");
      dealerName->value(dealer_Name);

      dealerUid = new Fl_Output(140, 590, 350, 20, "Dealer UUID: ");
      dealerUid->value(dealer_Uid);

      deckType = new Fl_Output(140, 620, 350, 20, "Deck Type: ");
      deckType->value(deck_Type);

      numPlayers = new Fl_Output(170, 640, 50, 20, "Number of Players: ");
      numPlayers->value("0");
      
      //hide player slots until player is active

      table_count= new Fl_Box(150, 50, 100, 50, "Table Count");
      table_count->box(FL_BORDER_BOX);	
      table_count->hide();

      start = new Fl_Button(900, 550, 80, 50, "&Start");
      start->callback( cb_start, this );
    
      quit = new Fl_Button(900, 630, 80, 50, "&Quit");
      quit->callback(cb_quit, this);


   end();
   resizable(this);
}

//----------------------------------------------------

MainWindow::~MainWindow(){}

/*** Function to Setup Deck ***/
void dealer::SetDeck(int option){
  deck.SetDeckType(option);
}

/*** Function to Setup Main Window ***/
void dealer::setMainWindow(const char* dealer_Name, const char* dealer_Uid, const char* deck_Type){
  mw = new MainWindow(1020,700,"UberCasino", dealer_Name, dealer_Uid, deck_Type);
  mw->show();
}

/*** Function to Setup Start Window ***/
void dealer::setStartWindow(const char* value){
  sw = new StartWindow(500,600,"StartWindow",value);
  sw->show();
}

/*** Function to check if player already exists in a Game ***/
bool dealer::playerExists(char * uid){
  bool found = false;
  for (unsigned int i=0;i<UberCasino::MAX_PLAYERS_IN_A_GAME;i++)
  {
    if(strcmp(m_G_pub.p[ i ].uid, uid) == 0){
      found = true;
#ifdef DEBUG
      std::cout << "Player already exists!" << std::endl;
#endif
      return found;
    }
  }
  return found;
}

/*** Function to Return a card from deck ***/
UberCasino::card_t dealer::dealCard(){
  return deck.deal_a_card();
}

//return total value of the cards with the value of ace count as 1 
//smallest total value
unsigned int Hand_Value ( UberCasino::card_t cards[] )
{
   // given an array of cards, returns the point value
   unsigned int total=0;
   for (unsigned int i=0; i< UberCasino::MAX_CARDS_PER_PLAYER;i++)
   {
      if ( cards[i].valid )
      {
         switch ( cards[i].card )
         {
            case ace: total=total+1;break;
            case two: total=total+2;break;
            case three: total=total+3;break;
            case four: total=total+4;break;
            case five: total=total+5;break;
            case six: total=total+6;break;
            case seven: total=total+7;break;
            case eight: total=total+8;break;
            case nine: total=total+9;break;
            case ten: total=total+10;break;
            case jack: total=total+10;break;
            case queen: total=total+10;break;
            case king: total=total+10;break;
         }
      }
   }
   return total;
}

//return total value of the cards 
unsigned int card_value(UberCasino::card_t cards[]){
  unsigned int number_of_ace=0;
  unsigned int card_value=0;
  for (unsigned int i=0; i< UberCasino::MAX_CARDS_PER_PLAYER;i++)
   {
      if ( cards[i].valid )
      {
         if (cards[i].card==ace){
            number_of_ace++;
         }
       }
    }
  
   card_value = Hand_Value ( cards);// card_value now is smallest value

   if(card_value>=21) return card_value;

   while(number_of_ace>0)
   {
     if(card_value + 10 > 21){     //check to see if the count 1 ace as 11 will go over 21
       return card_value;          //if it is bigger than 21, do not increment it 
     }
     else{
       card_value += 10;           //if it is less than 21, increment card_value, decrement the number_of_ace
       number_of_ace--;
     }
   }
   return card_value;
}

UberCasino::card_t dealer::Next_Card ()
{
   // this function returns the next card to be dealt
   UberCasino::card_t retval;
   //retrieve a card from the deck 
   retval = this->dealCard();
   retval.valid = true;
   return retval;
}

void delay_thread ( int seconds, std::function <void(void)> callback)
{
  // this routine is created as a posix thread.
  boost::this_thread::sleep_for(boost::chrono::seconds(seconds));
  callback ();
}

void dealer::lock ()
{
  std::cout << "****************************************" << std::endl;
  // pthread mutex works well
  // suggest you put it in if needed
  //m.lock();
}

void dealer::unlock ()
{
  // see remarks under lock(), above
  //m.unlock();
}

std::string dealer::to_string ( dealer_state_t d )
{
   std::string retval;
   switch ( d )
   {
    case Init:
         retval = "Init";
         break; 
    case Waiting:
         retval = "Waiting";
         break;
    case WaitingForOthers:
         retval = "WaitingForOthers";
         break;
    case StartHand:
         retval = "StartHand";
         break;
    case Deal:
         retval = "Deal";
         break;
    case EndHand:
         retval = "EndHand";
         break;
    case Done:
         retval = "Done";
   }
   return retval;
}

void dealer::manage_state ()
{
   bool transition = false;
   dealer_state_t next_state = m_dealer_state;

   // determine if we have a state transition
   switch (m_dealer_state)
   {
      case Init:
         if( m_user_event && (m_user_event_mask == "start")) //FLTK Event Handling goes here
         {
            next_state = Waiting;
            transition = true;
         }
         break;
      case Waiting:
         if ( m_Player_recv )
         {
            next_state = WaitingForOthers;
            transition = true;
         }
         break;
      case WaitingForOthers:
         if ( m_Player_recv )
         {
            next_state = WaitingForOthers;
            transition = true;
         }
         if( m_user_event && m_user_event_mask == "startGame") //FLTK Event Handling goes here
         {
            next_state = StartHand;
            transition = true;
         }
         break;
      case StartHand:
         if ( m_timer_event )
         {
            next_state = Deal;
            transition = true;
         }
         break;
      case Deal:
         if ( m_timer_event )
         {
            next_state = EndHand;
            transition = true;
         }
         if ( m_Player_recv )
         {
            next_state = Deal;
            transition = true;
         }
         break;
      case EndHand:
         if( m_user_event && m_user_event_mask == "startGame") //Dealer can start another game
         {                                                 //FLTK Event Handling goes here  
            next_state = Waiting; // wait for new players
            transition = true;
            new_game();
         }
         if( m_user_event && m_user_event_mask == "quit") //Dealer can start another game
         {                                                     //FLTK Event Handling goes here  
            next_state = Done; // wait for new players
            transition = true;
         }
         break;
      case Done:
         {
#ifdef DEBUG
           std::cout << "THE GAME IS OVER" << std::endl;
#endif
         }
   }

   // if there is a transition, then we have to run the exit 
   // and entrance processing
   if (transition)
   {
#ifdef DEBUG_STATES
      std::cout << "State change from " << to_string ( m_dealer_state ) 
                << " to " << to_string ( next_state ) << std::endl;
#endif
      // on exit
      switch (m_dealer_state)
      {
       case Init:
          {
#ifdef DEBUG_STATES
             std::cout << "Init: Exit" << std::endl;
#endif
             // this tells everyone listening, "i am starting a game"
             d_io->publish ( m_D_pub );
          }
          break;
       case Waiting:
          {
#ifdef DEBUG_STATES
             std::cout << "Waiting: Exit" << std::endl;
#endif
          }
          break;
       case WaitingForOthers:
          {
#ifdef DEBUG_STATES
            std::cout << "WaitingForOthers: Exit" << std::endl;
#endif
            // send out the game as it is
            m_G_pub.gstate = waiting;
            g_io->publish ( m_G_pub );
          }
          break;
       case StartHand:
          {
#ifdef DEBUG_STATES
            std::cout << "StartHand: Exit" << std::endl;
#endif
          }
          break;
       case Deal:
          {
#ifdef DEBUG_STATES
            std::cout << "Deal: Exit" << std::endl;
#endif
          }
          break;
       case EndHand:
          {
#ifdef DEBUG_STATES
            std::cout << "EndHand: Exit" << std::endl;
#endif
          }
          break;
       case Done:
          {
#ifdef DEBUG_STATES
            std::cout << "Done: Exit" << std::endl;
#endif
          }
          break;
      }

      // on entrance
      switch (next_state)
      {
       case Init:
          {
#ifdef DEBUG_STATES
            std::cout << "Init: Entry" << std::endl;
#endif
          }
          break;
       case Waiting:
          {
#ifdef DEBUG_STATES
            std::cout << "Waiting: Entry" << std::endl;
#endif
          }
          break;
       case WaitingForOthers:
          {
#ifdef DEBUG_STATES
             std::cout << "WaitingForOther: Entry" << std::endl;
#endif
             // if there is room and the player does not already exist, need to accept the 
             // new player.
             // need to update window as well with player cards and count values
             if (  ( m_Player_recv ) && 
                   ( m_P_sub.A == idle ) && 
                   ( m_number_of_players<UberCasino::MAX_PLAYERS_IN_A_GAME ) &&
                   (!playerExists(m_P_sub.uid) ))
             {
                 m_G_pub.gstate = waiting_to_join;
                 // the UID's don't change, so they can be copied again
                 memcpy ( m_G_pub.game_uid,  
                          m_D_pub.game_uid, 
                          sizeof (m_G_pub.game_uid) );
                 memcpy ( m_G_pub.dealer_uid,  
                          m_D_pub.uid, 
                          sizeof (m_G_pub.dealer_uid) );
                 memcpy ( m_G_pub.p[m_number_of_players].uid, 
                          m_P_sub.uid, 
                          sizeof ( m_G_pub.p[m_number_of_players].uid ) );

                 for (unsigned int i=0;i<UberCasino::MAX_CARDS_PER_PLAYER;i++)
                 {
                   m_G_pub.p[ m_number_of_players ].cards[ i ].valid  = false;
                 }
                 for (unsigned int i=0;i<UberCasino::MAX_CARDS_PER_PLAYER;i++)
                 {
                   m_G_pub.dealer_cards[i].valid = false;
                 }
            
                 m_number_of_players++;
#ifdef DEBUG
                 std::cout << "There are " << m_number_of_players << " in the game." << std::endl;
#endif
                 std::string n = std::to_string(m_number_of_players);
                 mw->numPlayers->value(n.c_str());
                 switch(m_number_of_players){
                   case 1:
                     mw->player1_value->show();
                     break;
                   case 2:
                     mw->player2_value->show();
                     break;
                   case 3:
                     mw->player3_value->show();
                     break;
                   case 4:
                     mw->player4_value->show();
                     break;
                   case 5:
                     mw->player5_value->show();
                     break;
                   case 6:
                     mw->player6_value->show();
                     break;
                   case 7:
                     mw->player7_value->show();
                     break;
                 }

                 g_io->publish ( m_G_pub );
             }
          }
          break;
        case StartHand:
          {
#ifdef DEBUG_STATES
             std::cout << "StartHand: Entry" << std::endl;
#endif
             mw->start->deactivate();
             // start a 3 second timer
             TIMER(3);
             m_G_pub.gstate = playing;
             //  one for the dealer : display card on GUI
             m_G_pub.dealer_cards[0] = Next_Card ();
             mw->dealer_value->show();
             std::string d = std::to_string(card_value(m_G_pub.dealer_cards));
             mw->dealer_value->label(d.c_str());
             mw->card_to_string((&mw->card1), m_G_pub.dealer_cards[0]);
             
             //  one for each player
             for (unsigned int i=0;i<m_number_of_players;i++)
             {
               m_G_pub.p[ i ].cards[ 0 ] = Next_Card ();
               playerValues[i] = card_value ( m_G_pub.p[ i ].cards);
               std::string p_1 = std::to_string(playerValues[i]);

               switch(i+1){
                   case 1:
                     mw->card_to_string((&mw->card1_1), m_G_pub.p[ i ].cards[ 0 ]);
                     mw->player1_value->label(p_1.c_str());
                     break;
                   case 2:
                     mw->card_to_string((&mw->card2_1), m_G_pub.p[ i ].cards[ 0 ]);
                     mw->player2_value->label(p_1.c_str());
                     break;
                   case 3:
                     mw->card_to_string((&mw->card3_1), m_G_pub.p[ i ].cards[ 0 ]);
                     mw->player3_value->label(p_1.c_str());
                     break;
                   case 4:
                     mw->card_to_string((&mw->card4_1), m_G_pub.p[ i ].cards[ 0 ]);
                     mw->player4_value->label(p_1.c_str());
                     break;
                   case 5:
                     mw->card_to_string((&mw->card5_1), m_G_pub.p[ i ].cards[ 0 ]);
                     mw->player5_value->label(p_1.c_str());
                     break;
                   case 6:
                     mw->card_to_string((&mw->card6_1), m_G_pub.p[ i ].cards[ 0 ]);
                     mw->player6_value->label(p_1.c_str());
                     break;
                   case 7:
                     mw->card_to_string((&mw->card7_1), m_G_pub.p[ i ].cards[ 0 ]);
                     mw->player7_value->label(p_1.c_str());
                     break;
                 }
             }
             // and the second card to the first player
             m_G_pub.p [ 0 ]. cards [1] = Next_Card ();
             playerValues[0] = card_value ( m_G_pub.p[ 0 ].cards);
             std::string pvalue = std::to_string(playerValues[0]);

             mw->card_to_string((&mw->card1_2), m_G_pub.p [ 0 ]. cards [1]);
             mw->player1_value->label(pvalue.c_str());

             // set to the player
             m_G_pub.active_player = 0;
             g_io->publish ( m_G_pub );
          }
          break;
       case Deal:
          {
#ifdef DEBUG_STATES
             std::cout << "Deal: Entry" << std::endl;
#endif
             if ( m_P_sub.A == standing )
             {
#ifdef DEBUG
                 std::cout << "The player is standing with " 
                           << card_value ( m_G_pub.p[ m_G_pub.active_player ].cards) // changed Hand_Value() to card_value()
                           << std::endl;
#endif
                 // go to next player
                 if ( (int) m_G_pub.active_player+1 < (int) m_number_of_players )
                 {
#ifdef DEBUG
                    std::cout << "Going to the next player" << std::endl;
#endif
                    m_G_pub.active_player++;
                    g_io->publish ( m_G_pub );
                 }
                 else
                 {
#ifdef DEBUG
                     std::cout << "Next, the dealers cards." << std::endl;
#endif
                     TIMER(1);
                 }
             }
             else if ( m_P_sub.A == hitting )
             {
                unsigned int i=0;
                while (m_G_pub.p[ m_G_pub.active_player ].cards[i].valid)
                {
                   i++;
                }
                m_G_pub.p[ m_G_pub.active_player ].cards[ i ] = Next_Card ();
                g_io->publish ( m_G_pub );
                playerValues[m_G_pub.active_player] = card_value ( m_G_pub.p[ m_G_pub.active_player ].cards);
                std::string pvalue = std::to_string(playerValues[m_G_pub.active_player]);

                switch(m_G_pub.active_player){
                   case 1:
                     mw->player1_value->label(pvalue.c_str());
                     switch(i){
                       case 0:
                         mw->card_to_string((&mw->card1_1), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 1:
                         mw->card_to_string((&mw->card1_2), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 2:
                         mw->card_to_string((&mw->card1_3), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 3:
                         mw->card_to_string((&mw->card1_4), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 4:
                         mw->card_to_string((&mw->card1_5), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 5:
                         mw->card_to_string((&mw->card1_6), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 6:
                         mw->card_to_string((&mw->card1_7), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 7:
                         mw->card_to_string((&mw->card1_8), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 8:
                         mw->card_to_string((&mw->card1_9), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 9:
                         mw->card_to_string((&mw->card1_10), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                     };
                     break;
                   case 2:
                     mw->player2_value->label(pvalue.c_str());
                     switch(i){
                       case 0:
                         mw->card_to_string((&mw->card2_1), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 1:
                         mw->card_to_string((&mw->card2_2), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 2:
                         mw->card_to_string((&mw->card2_3), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 3:
                         mw->card_to_string((&mw->card2_4), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 4:
                         mw->card_to_string((&mw->card2_5), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 5:
                         mw->card_to_string((&mw->card2_6), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 6:
                         mw->card_to_string((&mw->card2_7), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 7:
                         mw->card_to_string((&mw->card2_8), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 8:
                         mw->card_to_string((&mw->card2_9), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 9:
                         mw->card_to_string((&mw->card2_10), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                     };
                     break;
                   case 3:
                     mw->player3_value->label(pvalue.c_str());
                     switch(i){
                       case 0:
                         mw->card_to_string((&mw->card3_1), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 1:
                         mw->card_to_string((&mw->card3_2), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 2:
                         mw->card_to_string((&mw->card3_3), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 3:
                         mw->card_to_string((&mw->card3_4), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 4:
                         mw->card_to_string((&mw->card3_5), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 5:
                         mw->card_to_string((&mw->card3_6), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 6:
                         mw->card_to_string((&mw->card3_7), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 7:
                         mw->card_to_string((&mw->card3_8), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 8:
                         mw->card_to_string((&mw->card3_9), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 9:
                         mw->card_to_string((&mw->card3_10), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                     };
                     break;
                   case 4:
                     mw->player4_value->label(pvalue.c_str());
                     switch(i){
                       case 0:
                         mw->card_to_string((&mw->card4_1), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 1:
                         mw->card_to_string((&mw->card4_2), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 2:
                         mw->card_to_string((&mw->card4_3), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 3:
                         mw->card_to_string((&mw->card4_4), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 4:
                         mw->card_to_string((&mw->card4_5), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 5:
                         mw->card_to_string((&mw->card4_6), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 6:
                         mw->card_to_string((&mw->card4_7), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 7:
                         mw->card_to_string((&mw->card4_8), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 8:
                         mw->card_to_string((&mw->card4_9), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 9:
                         mw->card_to_string((&mw->card4_10), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                     };
                     break;
                   case 5:
                     mw->player5_value->label(pvalue.c_str());
                     switch(i){
                       case 0:
                         mw->card_to_string((&mw->card5_1), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 1:
                         mw->card_to_string((&mw->card5_2), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 2:
                         mw->card_to_string((&mw->card5_3), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 3:
                         mw->card_to_string((&mw->card5_4), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 4:
                         mw->card_to_string((&mw->card5_5), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 5:
                         mw->card_to_string((&mw->card5_6), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 6:
                         mw->card_to_string((&mw->card5_7), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 7:
                         mw->card_to_string((&mw->card5_8), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 8:
                         mw->card_to_string((&mw->card5_9), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 9:
                         mw->card_to_string((&mw->card5_10), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                     };
                     break;
                   case 6:
                     mw->player6_value->label(pvalue.c_str());
                     switch(i){
                       case 0:
                         mw->card_to_string((&mw->card6_1), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 1:
                         mw->card_to_string((&mw->card6_2), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 2:
                         mw->card_to_string((&mw->card6_3), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 3:
                         mw->card_to_string((&mw->card6_4), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 4:
                         mw->card_to_string((&mw->card6_5), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 5:
                         mw->card_to_string((&mw->card6_6), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 6:
                         mw->card_to_string((&mw->card6_7), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 7:
                         mw->card_to_string((&mw->card6_8), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 8:
                         mw->card_to_string((&mw->card6_9), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 9:
                         mw->card_to_string((&mw->card6_10), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                     };
                     break;
                   case 7:
                     mw->player7_value->label(pvalue.c_str());
                     switch(i){
                       case 0:
                         mw->card_to_string((&mw->card7_1), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 1:
                         mw->card_to_string((&mw->card7_2), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 2:
                         mw->card_to_string((&mw->card7_3), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 3:
                         mw->card_to_string((&mw->card7_4), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 4:
                         mw->card_to_string((&mw->card7_5), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 5:
                         mw->card_to_string((&mw->card7_6), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 6:
                         mw->card_to_string((&mw->card7_7), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 7:
                         mw->card_to_string((&mw->card7_8), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 8:
                         mw->card_to_string((&mw->card7_9), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                       case 9:
                         mw->card_to_string((&mw->card7_10), m_G_pub.p[ m_G_pub.active_player ].cards[ i ]);
                         break;
                     };
                     break;
                 }
             }
          }
          break;
       case EndHand:
          {
#ifdef DEBUG_STATES
            std::cout << "EndHand: Entry" << std::endl;
#endif
            // deal the dealers card
            // note: except for purists, dealing a card face down or
            // waiting to deal it now makes no difference.
            unsigned int i=1;
            while ( card_value ( m_G_pub.dealer_cards ) < 17 ) //changed Hand_Value to card_value
            {
               m_G_pub.dealer_cards[i] = Next_Card ();
               std::string s = std::to_string(card_value( m_G_pub.dealer_cards ));
               const char *dvalue = s.c_str();
               mw->dealer_value->label(dvalue);
               switch(i){
                 case 1:
                   mw->card_to_string((&mw->card2), m_G_pub.dealer_cards[i]);
                   break;
                 case 2:
                   mw->card_to_string((&mw->card3), m_G_pub.dealer_cards[i]);
                   break;
                 case 3:
                   mw->card_to_string((&mw->card4), m_G_pub.dealer_cards[i]);
                   break;
                 case 4:
                   mw->card_to_string((&mw->card5), m_G_pub.dealer_cards[i]);
                   break;
                 case 5:
                   mw->card_to_string((&mw->card6), m_G_pub.dealer_cards[i]);
                   break;
                 case 6:
                   mw->card_to_string((&mw->card7), m_G_pub.dealer_cards[i]);
                   break;
                 case 7:
                   mw->card_to_string((&mw->card8), m_G_pub.dealer_cards[i]);
                   break;
                 case 8:
                   mw->card_to_string((&mw->card9), m_G_pub.dealer_cards[i]);
                   break;
                 case 9:
                   mw->card_to_string((&mw->card10), m_G_pub.dealer_cards[i]);
                   break;
               };
               i++;
            }
            m_G_pub.gstate = end_hand;
            g_io->publish ( m_G_pub );
            
            int dealer_points = card_value ( m_G_pub.dealer_cards );

            int player_points = card_value ( m_G_pub.p[m_G_pub.active_player].cards );
#ifdef DEBUG
            std::cout << "Dealer has " << dealer_points << " Player has " << player_points << std::endl;
#endif
            if ( dealer_points > 21 || ( (player_points > dealer_points) && (player_points < 21) ) )
            {
#ifdef DEBUG
               std::cout << "Player Wins" << std::endl;
#endif
            }
            else
            {
#ifdef DEBUG
               std::cout << "Dealer Wins" << std::endl;
#endif
            }
            mw->start->activate();
          }
          break;
       case Done:
          {
#ifdef DEBUG_STATES
            std::cout << "Done: Entry" << std::endl;
#endif
            end_game ();
          }
          break;
      }
      // make the transition
      m_dealer_state = next_state;
   }
   // clear all event flags
   m_timer_event = false;
   m_user_event = false;
   m_Player_recv = false;
   m_Game_recv = false;
   m_Dealer_recv = false;
}

void dealer::new_game ()
{
   // member variables
   m_number_of_players = 0;
   m_G_pub.active_player = 0;

  // reset playerState p[] uid and card deck
  for (unsigned int i=0;i<UberCasino::MAX_PLAYERS_IN_A_GAME;i++)
  {
      memcpy ( m_G_pub.p[ i ].uid, 
      "", 
      sizeof ( m_G_pub.p[ i ].uid ) ); 
      
      playerValues[i] = 0;

      for (unsigned int j=0;j<UberCasino::MAX_CARDS_PER_PLAYER;j++)
      {
        m_G_pub.p[i].cards[ i ].valid  = false;
      }
  }

  for (unsigned int i=0;i<UberCasino::MAX_CARDS_PER_PLAYER;i++)
  {
      m_G_pub.dealer_cards[i].valid = false;
  }
 
  mw->resetGame();
  mw->numPlayers->value("0");
}

void dealer::next_player ()
{

}

void dealer::end_game ()
{
  exit(0);
}

void dealer::deal_to_dealer ()
{
}


void dealer::timer_expired ()
{
   // this is called by the timer thread callback when the delay has expired
   // note: only one timer can be active at a time
   lock ();
   m_timer_event = true;
   manage_state ();
   unlock ();
}

void dealer::external_data (Player P)
{
   lock ();
   // this is called when data is received
   m_P_sub = P;
   m_Player_recv = true;
   manage_state ();
   unlock ();
}

void dealer::external_data (Dealer D)
{
   lock ();
   // this is called when data is received
   m_D_sub = D;
   m_Dealer_recv = true;
   manage_state ();
   unlock ();
}

void dealer::external_data (Game G)
{
   lock ();
   // this is called when data is received
   m_G_sub = G;
   m_Game_recv = true;
   manage_state ();
   unlock ();
}

void dealer::user_input ( std::string I)
{
   // this is called when the user types in input
   // from the console.  any / all input is accepted
   lock ();
   m_user_event_mask = I;
   if (m_user_event_mask == "start")
   {
      m_user_event = true;
      manage_state ();
   }
   else if (m_user_event_mask == "quit")
   {
      m_user_event = true;
      manage_state ();
   }
   else if (m_user_event_mask == "startGame")
   {
      m_user_event = true;
      manage_state ();
   }
   unlock ();
}

dealer::dealer ()
{
   // member variables
   m_timer_thread = NULL;
   m_dealer_state = Init;
   m_user_event_mask = "";  // this is the event that Dealer will be looking for
   m_number_of_players = 0;
   m_G_pub.active_player = 0;
   // member objects
   p_io = new dds_io<Player,PlayerSeq,PlayerTypeSupport_var,PlayerTypeSupport,PlayerDataWriter_var,
                     PlayerDataWriter,PlayerDataReader_var,PlayerDataReader>
                ( (char*) "player", false, true );
                       // topic name, publish, subscribe

   d_io = new dds_io<Dealer,DealerSeq,DealerTypeSupport_var,DealerTypeSupport,DealerDataWriter_var,
                     DealerDataWriter,DealerDataReader_var,DealerDataReader>
                ( (char*) "dealer", true, false );

   g_io = new dds_io<Game,GameSeq,GameTypeSupport_var,GameTypeSupport,GameDataWriter_var,
                     GameDataWriter,GameDataReader_var,GameDataReader>
                ( (char*) "game", true, false );
   // event flags
   m_timer_event = false;
   m_user_event = false;
   m_Dealer_recv = false;
   m_Game_recv = false;
   m_Player_recv = false;

   m_hands_dealt = 0;
}

dealer::~dealer ()
{
}
