#include <iostream>
#include <string.h>


#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include "dealer.h"
#include "start_window.h"

static dealer* PTR;

#include "callback.h" // uses the PTR var

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
   StartWindow win(500,600,"StartWindow",value);
   return Fl::run();
/*
   if ( argc == 1 ) // meaning there are none
   {
      strncpy ( D.m_D_pub.name,"Dealer",sizeof ( D.m_D_pub.name ) );
   }
   else
   {
      strncpy ( D.m_D_pub.name,argv[1],sizeof ( D.m_D_pub.name ) );
   }
*/
/*

   std::cout << "Welcome to UberCasino.  The fast paced, command line BlackJack system." << std::endl;
   std::cout << "-------------------------------------------" << std::endl;

   std::cout << "The dealers name is " << D.m_D_pub.name << "." << std::endl;
   std::cout <<  "With a UUID of " << uuid << std::endl;
   std::cout << "-------------------------------------------" << std::endl;

   std::cout << "Enter 'start' to begin the game" << std::endl;
   std::cout << "Enter 'q' to exit" << std::endl;
   std::cout << "-------------------------------------------" << std::endl;

   char line[100]; // how large to make it? who knows.
   while (std::cin.getline(line, sizeof(line)))
   {
     if (line[0] == 'q' ) break;
     D.user_input ( std::string (line) );
   }
*/

   return 0;
}

