#include <iostream>
#include <vector>

int fib(int n){
  std::vector<unsigned> F(n + 1);
  F[0] = 0;
  F[1] = 1;
  for(int i = 2; i <= n; ++i){
    F[i] = F[i - 1] + F[i - 2];
  }
  return F[n];
}

int main() {
  std::cout << fib(4);
}