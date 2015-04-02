/*
   My_randint_window.cpp
 */

#include "get_image_window.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

get_image_window::get_image_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    save_button(Point(x_max()-250,500),70,20,"Save",cb_save), //run again butto at the bottom centre of the screen
    discard_button(Point(x_max()-550,500), 70, 20, "Discard", cb_discard),
    button_pushed(false)
{
    attach(save_button);
    attach(discard_button);
}

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
bool get_image_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;
#if 1
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void get_image_window::cb_save(Address, Address pw)
// call My_randint_window::next() for the window located at pw
{  
    reference_to<get_image_window>(pw).save();    
}
 
void get_image_window::cb_discard(Address, Address pw)
// call My_randint_window::runagain() for the window located at pw
{
    reference_to<get_image_window>(pw).discard();
}


//------------------------------------------------------------------------------

void get_image_window::save()
{
    button_pushed = true;
    exit(0); //To exit when the user presses quit
}

//Run Again function
void get_image_window::discard()
{
    button_pushed = true;
	redraw();
}

//------------------------------------------------------------------------------
