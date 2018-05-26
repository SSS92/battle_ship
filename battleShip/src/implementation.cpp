#include <iostream>
#include <new>
#include <ios>
#include <limits>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cassert>

/**
 * The number of ships for the game
 */
#define number_of_ships 4
/**
 *The label for the damaged unit
 */
#define shot_in_the_ship 6
/**
 *The label for the lost shot
 */
#define shot_at_sea 8

//const unsigned int N = std::numeric_limits<unsigned int>::max();
/**
 * The size of the square sea
 */
const unsigned int N = 10;

/**
 * Array of ships. The value of ships i is the count of a ship with length i+1
 */
int ships[4] = {2, 1, 1, 1};

/**
 *@brief Reset input stream when the user has entered wrong type value
 *@return return type is void
 */
void reset_input_stream()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	std::cin.get();
	std::cout << "Please insert a digital number!" << std::endl ;
}

/**
 *@brief Generates a random integer in  [min, max)  interval  and returns it
 *@param maximum number
 *@param minimum number
 *@return a random integer in [min , max) interval
 */
int generate_random_number(int max, int min)
{
	if (min >= max) {
		min = max - 1;
	}
	srand(time(0));
	int rand_number = (rand()%(max - min)) + min;
	return rand_number;
}

/**
 *@brief Creates a two dimensional dynamic  array,
 initializes every element with 0-s and returns a int** pointer to the array,
 if there is no enough  space throws bad_alloc() exception.
 *@return returns a pointer to the created array
 */
int** create_sea()
{
	int** sea = new int* [N];
	if (!sea) {
		throw std::bad_alloc();
	}
	for (int i = 0; i < N; ++i) {
		*(sea + i) = new int [N]();
		if (!(sea + i)) {
			throw std::bad_alloc();
		}
	}
	return sea;
}

/**
 *@brief Deletes the created two dimensional array.
 *@param pointer to the two dimensional array (int **)
 */
void delete_sea(int** sea)
{
	assert(sea);
	for (int i = 0; i < N; ++i) {
		delete [] *(sea + i);
	}				 
	delete [] sea;
	return;
}

/**
 *@brief Print the given two dimensional array.
 *@param pointer to a two dimensional array (int**)
 */
void show_sea(int** sea) 
{
	assert(sea);
	for (int i = 0; i < N ; ++i) {
		for (int j = 0; j < N ; ++j) {
			assert(*(sea + i) + j);
			std::cout << *(*(sea + i) + j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/**
 *@brief Checks whether there is free space from start  (x, y) with the given offset in the 
 *@param axis
 *@param ordinate
 *@param offset - (1 if we check point, and the ship length when we check ship position)
 *@return true if out of the sea, false otherwise
 */
bool is_out_of_sea(int x, int y, int offset = 1)
{
	if ((y + offset - 1) >= N || x >= N || x < 0 || y < 0) {
		return true;    
	}
	return false;
}

/**
 *@brief Checks if the given point is on the ship, or the distance between them is 1.
 *@param x is the start axis of the ship
 *@param y is the start ordinate of the ship
 *@param offset is the length of the ship
 *@param i is the axis of the given point
 *@param j is the ordinate of the given point
 *@return false if on a single distance or on the ship, true otherwise
 */
bool is_not_around_of_ship(int x, int y, int offset, int i, int j) 
{
	if ((j != x) && ((i == (y - 1)) || (i == y + offset))) {
		return true;
	}
	return false;
}
/**
 *@brief Checks if the given start point is valid for vertical  putting a ship with the given length
 *@param sea is two dimensional array
 *@param x is the start axis of the ship
 *@param y is the start ordinate of the ship
 *@param length is the length of the ship
 *@return returns true if the position is not valid, 0 otherwise
 */
bool is_invalid_vertical_position(int** sea, int x, int y, int length)
{
	assert(sea);
	for (int i = y - 1; i < y + length + 1; ++i) {
		for (int j = x - 1; j < x + 2; ++j) {
			if ((is_out_of_sea(i, j)) || is_not_around_of_ship(x, y, length, i, j)) {
				continue;
			}
			assert(*(sea + i) + j);
			if (1 == *(*(sea + i) + j)) {
				return true;
			}
		}
	} 
	return false;
}
/**
 *@brief Chekes if the given start point is valid for horizontal  putting a ship with the given length
 *@param sea is two dimensional array
 *@param x is the start axis of the ship
 *@param y is the start ordinate of the ship
 *@param length is the length of the ship
 *@return returns true if the position is not valid, 0 otherwise
 */
bool is_invalid_horizontal_position(int** sea, int x, int y, int length)
{
	assert(sea);
	for (int i = y - 1; i < y + 2; ++i) {
		for (int j = x - 1; j < x + length  + 1; ++j) {
			if ((is_out_of_sea(i, j)) || is_not_around_of_ship(x, y, length, j, i)) {
				continue;
			}
			assert(*(sea + i) + j);
			if (1 == *(*(sea + i) + j)) {
				return true;
			}
		}
	} 
	return false;
}
/**
 *@brief Puts a ship with a given length horizontally on the sea at the given start point
 *@param the sea, where  the ship will be put
 *@param start X coordinate 
 *@param start Y coordinate
 *@param length of the ship, which we will be put with the  (start_x, start_y) start point
 *@return 1 if the given position is not valid, 2 if a part of the ship out of sea, 0 if the ship is put 
 */
int put_horizontal(int** sea, int start_x, int start_y, int length)
{
	assert(sea);
	if (is_out_of_sea(start_y, start_x, length)) {
		return 2;
	}
	if (is_invalid_horizontal_position(sea, start_x, start_y, length)) {
		return 1;
	}
	for (int i = start_x; i< start_x + length; ++i) {
		assert(*(sea + start_y) + i);
		*(*(sea + start_y) + i) = 1;
	}
	return 0;
}

/**
 *@brief Puts a ship with a given length vertically on the sea at the given start point
 *@param the sea, where  the ship will be put
 *@param start X coordinate 
 *@param start Y coordinate
 *@param length of the ship, which we will be put with the  (start_x, start_y) start point
 *@return 1 if the given position is not valid, 2 if a part of the ship out of sea, 0 if the ship is put 
 */
int put_vertical(int** sea, int start_x, int start_y, int length)
{
	assert(sea);
	if (is_out_of_sea(start_x, start_y, length)) {
		return 2;
	} 
	if (is_invalid_vertical_position(sea, start_x, start_y, length)) {
		return 1;
	}
	for (int i = start_y; i< (start_y + length); ++i) {
		assert(*(sea + i) + start_x);
		*(*(sea + i) + start_x) = 1;
	}
	return 0;
}

/**
 *@brief Generates a random start point  and direction, puts the given ship on the sea with the generated coordinates.
 *@param The sea where the ship will be put
 *@param The length of the ship
 */
void put_ship(int** sea, int length) {
	assert(sea);
	int x = generate_random_number(N, 0);
	int y = generate_random_number(N, 0);
	int direction = generate_random_number(2, 0);
	int is_putted = (0 == direction) ? put_vertical(sea, x, y, length): put_horizontal(sea, x, y, length);
	if (0 == is_putted) {
		--ships[length - 1];
	}
}

/**
 *@brief Puts all ships on the sea with random principle
 *@param Sea where we have to put ships
 *@return return number of units
 */
int fill_sea(int** sea)
{
	assert(sea);
	std::cout << "Please wait ..." << std::endl;
	int number_of_units = 0;
	for (int i = 0; i < number_of_ships; ++i ) {
		assert(*(sea + i));
		number_of_units += ships[i] * (i + 1);	
	}
	for (int i = (number_of_ships - 1); i >= 0; --i) {
		assert(*(sea + i));
		while (ships[i] > 0) {   
			put_ship(sea, i + 1);
		}
	}
	show_sea(sea);		
	return number_of_units;
}

/**
 *@brief Prints the shot result message.
 *@param Shot result value
 */
void show_shot_result(int shot_result)
{
	if (2 == shot_result) {
		std::cout << "Out of the sea!" << std::endl ;
	} else if (1 == shot_result) {
		std::cout << "Didn't hit!" << std::endl ;
	} else if (0 == shot_result) {
		std::cout << "You kill!" << std::endl ;
	} else if (3 == shot_result) {
		std::cout << "You have already shot here!" << std::endl ;
	}
}

/**
 *@brief Shots at the point with the  given coordinates.
 *@param Playing area
 *@param axis of the point
 *@param ordinate of the point
 *@return shot result, returns 0, if the shot is on target, 1 if there is no ship unit at the given point, 2, if the given point is out of the sea, 3 if the given point was already shot       
 */
int kill_ship(int** sea, int x, int y)
{
	assert(sea);
	if (is_out_of_sea(x, y)) {
		return 2;
	}
	int* sea_cell_ptr = (*(sea + y) + x);
	assert(sea_cell_ptr);
	if (*sea_cell_ptr == 0) {
		*sea_cell_ptr = shot_at_sea;
		return 1;
	}else if (*sea_cell_ptr == 1) {
		*sea_cell_ptr = shot_in_the_ship;
		return 0;
	}else {
		return 3;
	}
}

/**
 *@brief Reads the x and y coordinates of the target point from the terminal.
 *@param x axis
 *@param y ordinate
 */
void insert_shot_coordinates(int& x, int& y)
{
	std::cout << "Please insert axis" << std::endl ;
	std::cin >> x;
	while (std::cin.fail()) {
		reset_input_stream();
		std::cin >> x;
	}
	std::cout << "Please insert ordinate" << std::endl ;
	std::cin >> y;
	while (std::cin.fail()) {
		reset_input_stream();
		std::cin >> y;
	}
	std::cout << std::endl ;
}

/**
 *@brief The function provides the cycle where a shot at the sea will be performed along the entered coordinates and the output of the corresponding result.
 *@param The sea which will be shot.
 *@param The count of the  cells of the ships.
 */
void play(int** sea, int number_of_units) {
	assert(sea);
	int x = 0;
	int y = 0;
	int shot_result = 0;
	std::cout << "The Game is Started. " << std::endl ;
	while (number_of_units > 0) {
		insert_shot_coordinates(x, y);
		shot_result = kill_ship(sea, x - 1 ,y - 1);
		if (0 == shot_result) {
			number_of_units--;
		}
		show_shot_result(shot_result);
		show_sea(sea);
	}
	std::cout << "Your opponent won" << std::endl ;
	delete_sea(sea);    
}
