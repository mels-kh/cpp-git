#include <iostream>
#include <string>
#include <vector>

using Seq = std::string;
using Matrix = std::vector<std::vector<int>>;

// largest common subsequence
int lcs(const Seq &a, const Seq &b) {
  const int n = a.size();
  const int m = b.size();
  Matrix subsets (n, std::vector<int>(m));
  bool exist = false;
  for(int j = 0;j < n; ++j){
    if(b[0] == a[j]) exist=true;
    subsets[j][0] = exist;
  }
  for(int i = 0;i < n; ++i){
    if(a[0] == b[i]) exist=true;
    subsets[0][i] = exist;
  }
  for(int i = 1;i < n; ++i){
    for(int j = 1;j < m; ++j){
      if(a[i] == b[j]){
        subsets[i][j] = 1 + subsets[i-1][j-1];
      }
      else{
        subsets[i][j] = std::max(subsets[i-1][j], subsets[i][j-1]);
      }
    }
  }
  
  return subsets[n - 1][m - 1]; 
}

int main(int argc, char **argv) {

  std::string a = "abcdef";
  std::string b = "b";
	std::cout << lcs(a ,b );
	return 0;
}