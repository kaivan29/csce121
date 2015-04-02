#include "std_lib_facilities_3.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
try {
  	 if(H112 != 201206L)error("Error: incorrect std_lib_facilities_3.h version ",
		  	   H112);
         Simple_window win1(Point(100,200),600,400,"Initials" ) ; //A window with the name Initials

 	 Lines k ; //A lines object k for the first initial
 	 Lines s ; //A lines object s for the second initial
	 //150 pixels high
	 //First initial K  
	 k.add(Point(225,50),Point(150,125));  
	 k.add(Point(225,200),Point(150,125));
	 k.add(Point(150,50),Point(150,200));  
	 k.set_style(Line_style(Line_style::solid, 3)); //To make the lines of the object thick

	 //Second initial S
	 s.add(Point(275,50),Point(350,50));
	 s.add(Point(275,125),Point(350,125));
	 s.add(Point(275,200),Point(350,200));
	 s.add(Point(275,50),Point(275,125));
	 s.add(Point(350,125),Point(350,200));
	 s.set_style(Line_style(Line_style::solid, 3));	//To make the lines of the object thick

	 win1.attach(k); //Connect object k to the window
	 win1.attach(s); //connect object s to the window

	 k.set_color(Color::white); //The colour of the first initial is set to white
	 s.set_color(Color::black); //The colour of secod initial is set to black

	 win1.wait_for_button(); //Give control to the display engine
	 return 0;
    }

catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Some exception\n";
	return 2;
}
