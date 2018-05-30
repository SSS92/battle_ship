#include <implementation.hpp>
#include <iostream>
#include <fstream>
#include <cassert>
#include <ios>
#define empty_unit 0
#define full_unit 1
#define killed_unit 6
#define lost_unit 8

extern int const  size = 10;
const char* log_path = "../test_results.txt";

void write_log (char* message)
{
        std::ofstream log_file;
        log_file.open(log_path, std::ios_base::ate);
        log_file << message << std::endl;
        log_file.close();
        return;
}

bool check_change(int previus_state, int current_state)
{
        if (empty_unit == previus_state && lost_unit != current_state) {
                return false;
        } else if(full_unit == previus_state && full_unit != current_state) {
                return false;
        } else if(full_unit != previus_state && lost_unit != previus_state &&  previus_state != current_state) {
                return false;
        }
        return true;
};

bool repetition_test (int** sea)
{
        assert(sea);
        bool result = true;
        for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                        int previus_state = *(*(sea + i) + j);
                        kill_ship(sea, i, j);
                        int current_state =  *(*(sea + i) + j);          
                        if(check_change(previus_state, current_state)) {
                                result = false;
                                break;
                        }
                } 
                if(!result) {
                        break;
                }
        }
        
        if(result) {
                write_log("repetition test passed");
        }else {
                write_log("repetition test failed");
        }
        return result;
}

bool shot_test (int** sea)
{
        assert(sea);
        bool result = true;
        for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                        int previus_state = *(*(sea + i) + j);
                        kill_ship(sea, i, j);
                        int current_state =  *(*(sea + i) + j);          
                        std::cout << previus_state << "ev" << current_state
                                <<std::endl;
                        
                        if(check_change(previus_state, current_state)) {
                                result = false;
                                break;
                        }
                } 
                if(!result) {
                        break;
                }
        }
        if(result) {
                write_log("shot test passed");
        }else {
                write_log("shot test failed");
        }
        return result;
}
