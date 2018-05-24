
#include <iostream>
inline int add(const int& a) {
  return a + 1;
}

int power(int x, int n){
  if(x == 0){
    return 0;
  }
  if(0==n){
    return 1;
  }else if(n<0){
    return 1/(x*pow(x,n+1));  
  }
  assert(n>0)
  return x * power(x,n-1);
}


int main() {
  
  int a = 10;
  int y = add(a);
  return 0;
}
