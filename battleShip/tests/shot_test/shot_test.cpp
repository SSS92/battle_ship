#include <implementation.hpp>
#include <iostream>
#include <fstream>
#include <cassert>
#include <ios>
#define empty_unit 0
#define full_unit 1
#define killed_unit 6
#define lost_unit 8
#define shot_pass "shot test passed"
#define shot_fail "shot test failed"
#define repetition_pass "repetition test passed"
#define repetition_fail "repetition test failed"


extern int const  size = 10;
const char* log_path = "../../test_results.txt";

void write_log (const char* message)
{
        std::ofstream log_file;
        log_file.open(log_path, std::ios_base::app);
        log_file << message << std::endl;
        log_file.close();
        return;
}

bool check_change(int previus_state, int current_state)
{
        if (empty_unit == previus_state && lost_unit != current_state) {
                return false;
        } else if (full_unit == previus_state && killed_unit != current_state) {
                return false;
        } else if (full_unit != previus_state && empty_unit != previus_state &&  previus_state != current_state) {
                return false;
        }
        return true;
};



bool shot_test (int** sea, bool repetition = false)
{
        assert(sea);
        bool result = true;
        int* current_unit;
        for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                        current_unit = (*(sea + j) + i);
                        int previus_state = *current_unit;
                        kill_ship(sea, i, j);
                        int current_state = *current_unit;          
                        if (!check_change(previus_state, current_state)) {
                                result = false;
                                break;
                        }
                } 
                if (!result) {
                        break;
                }
        }
        if (result) {
                repetition ? write_log(repetition_pass) : write_log(shot_pass);
        }else {
                repetition ? write_log(repetition_fail) : write_log(shot_fail);
        }
        return result;
}

void prepare_for_repetition(int** sea)
{
        assert(sea);
        for(int i = 0; i < 10; ++i) {
                for(int j = 0; j < 10; ++j) {
                        if( 0 == j%2) {
                                *(*(sea + i) + j) = killed_unit;
                                break;
                        }
                        *(*(sea + i) + j) = lost_unit;
                }
        }
}
