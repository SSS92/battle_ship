#include <implementation.hpp>
#include <iostream>
#include <new>
/**
 *@brief The main function for battleship program
 * 
 * The fucntion creates a playing area, fills it with random layout of ships, and profides the user to play.
 *@return return 0 - success, return 1 - fail with message "cant allocate memory..." 
 *@authors Galust Betkhemyan, Sevak Sahakyan
 *@date 25.05.2018
 */
int main(){
	try {
		int** sea = create_sea();
		int number_of_units = fill_sea(sea);
		play(sea, number_of_units);
		return 0;
	}
	catch (std::bad_alloc& e) {
		std::cout << "The system can not allocate memory for your program" << std::endl;
		return 1;
	}
}
