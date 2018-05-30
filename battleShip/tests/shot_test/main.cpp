#include <shot_test.hpp>
#include <implementation.hpp>
int main(){
 int** sea = create_sea();
 fill_sea(sea);
 repetition_test (sea);
 shot_test (sea);
 return 0;
}
