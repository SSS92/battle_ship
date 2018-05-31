#include <shot_test.hpp>
#include <implementation.hpp>
#include <iostream>
#include <new>

/**
 * @brief Creates a two dimenssional array (sea), fills it with ships and run
 * tests for shooting.
 *@return 0 - if succes, 1 - if system can't allocate memory for sea.
 */
int main(){
	int ** sea = NULL;
	try {
		sea = create_sea();
		fill_sea(sea);
	}
	catch(std::bad_alloc& e)
	{
		std::cout<< e.what() << std::endl;
		return 1;
	}
	if(!shot_test(sea)) {
		prepare_for_repetition(sea);
	}
	shot_test(sea,true);
	return 0;
}
