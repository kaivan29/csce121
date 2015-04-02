//My_randint_window.h
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef GET_IMAGE_WINDOW_GUARD
#define GET_IMAGE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"


using namespace Graph_lib;

//------------------------------------------------------------------------------
//My_randint_window class
struct get_image_window : Graph_lib::Window {
    get_image_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop

private:
    Button save_button; //the "run again" button
    Button discard_button;     // the "next" button

    bool button_pushed;     // implementation detail

    static void cb_save(Address, Address); // callback for next_button
    static void cb_discard(Address, Address); //callback for runagain_button
    

    void save();            // action to be done when next_button is pressed
    void discard();	   //action to be done when runagain_button is presses
    };

//------------------------------------------------------------------------------

#endif // SIMPLE_WINDOW_GUARD
