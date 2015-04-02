/*
   Simple_window.cpp
   Minimally revised for C++11 features of GCC 4.6.3 or later
   Walter C. Daugherity		June 10, 2012
*/

//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"
#include "Browse_window.h"
#include "My_randint_window.h"


using namespace Graph_lib;

//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
	
	add_button(Point(90,240), 180, 40, "Add an Image", cb_add),
    add_pushed(false),
	
	browse_button(Point(90,320),180,40,"Browse Images", cb_browse), 
	browse_pushed(false),   
	
	search_button(Point(90,400),180,40,"Search Images by Tag", cb_search), 
	search_pushed(false)
	
{

	attach(add_button);
    attach(browse_button);
	attach(search_button);
	
}



//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when browse_pushed becomes true
// this allows graphics without control inversion
{
    show();
    browse_pushed = false;
	
#if 1
    // Simpler handler
    while (!browse_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return browse_pushed;
}

//------------------------------------------------------------------------------

void Simple_window::cb_browse(Address, Address pw)
// call Simple_window::next() for the window located at pw
{  
    reference_to<Simple_window>(pw).browse();    
}

void Simple_window::cb_add(Address, Address pw)
// call Simple_window::next() for the window located at pw
{  
    reference_to<Simple_window>(pw).add();  
    // change to anext() AFTER ADDING ADD WINDOW	
}

void Simple_window::cb_search(Address, Address pw)
// call Simple_window::next() for the window located at pw
{  
    reference_to<Simple_window>(pw).search();  
    // change to snext() AFTER ADDING ADD WINDOW	
}



//------------------------------------------------------------------------------

void Simple_window::browse()
{
	Browse_window w2(Point(120,200),400,550,"Browse");
	w2.wait_for_button();
    /*browse_pushed = true;
    hide();*/
}

void Simple_window::add()
{
	My_randint_window win1(Point(100,200),800,600,"Random Digit" ) ; //A window with the name Initials
    browse_pushed = true;
    hide();
}

void Simple_window::search()
{
    browse_pushed = true;
    hide();
}

//------------------------------------------------------------------------------
