#include <iostream>
#include <vector>

std::vector<int> merge(
  const std::vector<int>& v1, 
  const std::vector<int>& v2
) {
  int i = 0;
  int j = 0;

  std::vector<int> result;
  result.reserve(v1.size() + v2.size());
  while(i < v1.size() && j < v2.size()) {
    if(v1[i] < v2[j]) {
      result.push_back(v1[i]);
      ++i;
    } else {
      result.push_back(v2[j]);
      ++j;
    }
  }
  while(i < v1.size()) {
    result.push_back(v1[i]);
    ++i;
  }
  while(j < v2.size()) {
    result.push_back(v2[j]);
    ++j;
  }
  return result;
}

void mergeSort(std::vector<int>& v) {
  if(v.size() <= 1) {
    return;
  }
  
  std::vector<int> v1(v.begin(), v.begin() + v.size() / 2);
  std::vector<int> v2(v.begin() + v.size() / 2, v.end());

  mergeSort(v1);
  mergeSort(v2);
  v = merge(v1, v2);
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> v(n);
  for(int i = 0 ; i < n; ++i) {
    std::cin >> v[i];
  }
  mergeSort(v);

  for(int i = 0; i < n; ++i) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}