#include <iostream>
#include <vector>

// Should retern index of element if it exists. -1 otherwise
int binary_search_r(const std::vector<int> &values, int element, int begin, int end) {
  if(element > values[values.size() / 2]){
    begin = values[values.size() / 2];
  }
else if(element < values[values.size() / 2]){
    end = values[values.size() / 2];
  }
  else{
    return values.size() / 2;
  }
  
  return binary_search_r(values, element, begin, end);
}

int binary_search(const std::vector<int> &values, int element) {
  
  return binary_search_r(values, element, 0, values.size());
}


int main(int argc, char **argv) {
  {
    std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << binary_search(values, 4) << " == 3" << std::endl;
  }
  {
    std::vector<int> values{1, 3, 5, 7, 9};
    std::cout << binary_search(values, 4) << " == -1" << std::endl;
  }
  return 0;
}