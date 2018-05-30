#include <implementation.hpp>
#include <iostream>
#include <fstream>
#include <cassert>

#define number_of_ships 4

const unsigned int size = 10;
/*
int ships_1[4] = {1, 1, 1, 1};
int ships_2[4] = {1, 1, 1, 1};

void put_test_ship(int** sea, int length, int ships_array_index) 
{
	assert(sea);
	int x = generate_random_number(size, 0);
	int y = generate_random_number(size, 0);
	int direction = generate_random_number(2, 0);
	int is_putted = (0 == direction) ? put_vertical(sea, x, y, length): put_horizontal(sea, x, y, length);
	if (0 == is_putted) {
		if (1 == ships_array_index) {
			--ships_1[length - 1];
		} else {
			--ships_2[length - 1];
		}

	}
}

int** generate_ships_layout (int** sea, int ships_array_index)
{
	assert(sea);
	for (int i = (number_of_ships - 1); i >= 0; --i) {
		assert(*(sea + i));
		if (1 == ships_array_index) {
			while (ships_1[i] > 0) {   
				put_test_ship(sea, i + 1, ships_array_index);
			}
		} else {
			while (ships_2[i] > 0) {   
				put_test_ship(sea, i + 1, ships_array_index);
			}
		}
	}	
	show_sea(sea);	
	return sea;
}

*/
int check_playing_areas_random_states (int** sea_1, int** sea_2)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (*(*(sea_1 + i) + j) == *(*(sea_2 + i) + j)) {
				continue;			
			}
			return 1;
		}	
	}
	return 0;
}

void write_test_result (char test_index, int test_result)
{
	const char *path="./test_results.txt";
	std::ofstream myfile;
	myfile.open (path);
	if (1 == test_result) {
		myfile << "test_" << test_index << " : " << "Pass\n";
	} else {
		myfile << "test_" << test_index << " : " << "Fail\n";
	}
	myfile.close();
}

extern int ships[4];

int main(int argc, char *argv[]) 
{
	int ships_copy[4];
	for(int i = 0; i<4; ++i){
	    ships_copy[i] = ships[i];
	    std::cout << ships_copy[i] << std::endl;
	}
//	int** sea_1 = create_sea();
//	sea_1 = fill_sea(sea_1);
//	ships = ships_copy;
//	int** sea_2 = create_sea();
//	sea_2 = fill_sea(sea_2);
//	int test_result = check_playing_areas_random_states(sea_1, sea_2);
//	write_test_result('1', test_result);	
	std::cout<< "hello";
	return 0;
}



