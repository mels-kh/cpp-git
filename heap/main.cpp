#include <iostream>
#include <vector>
class heap {
private:
  std::vector<int> data{};

public:
  void push(int value) {
    data.push_back(value);
    int i = data.size() - 1;
    while (i != 0) {
      int parent = (i - 1) / 2;
      if (data[i] > data[parent]) {
        std::swap(data[i], data[parent]);
        i = parent;
      }
      else {
        break;
      }
    }
  }

  void pop() {
    int current = 0;
    int biggest;
    std::swap(data[0], data[data.size()-1]);
    while(true){
      int left = 2*current+1;
      int right = 2*current+2;


      if (left < data.size() && right < data.size()) {
        if (data[left] > data[right]) {
          biggest = left;
        }        
        else {
          biggest = right;
        }
      }
      else if (left < data.size() && right >= data.size()) {
        biggest = left;
      }
      else {
        break;
      }

      
      if (data[biggest] <= data[current]) {
        break;
      }

      std::swap(data[biggest], data[current]);

      current = biggest;
     
      if(left>=data.size() && right>=data.size()){
        break;
      }
      if(left<data.size() && data[left] > data[right]){
        biggest = left;
      }
      if(data[left] < data[right]){
        biggest = right;
      }
      if(data[current]<data[biggest])
      {
        std::swap(current,biggest);
        current = biggest;
      }
      else{
        break;
      }
      
    }
  }
};

int main() { return 0; }