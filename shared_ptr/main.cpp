#include <iostream>

class WeakPtr;
class SharedPtr {
  friend WeakPtr;
  int* data;
  int* shared_counter;
  int* weak_counter;

public:
SharedPtr(): data(nullptr), shared_counter(nullptr), weak_counter(nullptr){}

SharedPtr(int* Data): data(Data), shared_counter(new int(1)), weak_counter(new int(0)){}

SharedPtr(const SharedPtr& other): data(other.data), shared_counter(other.shared_counter), weak_counter(other.weak_counter){
  (*shared_counter) ++;
      
}
SharedPtr(const WeakPtr& other):data(other.data), shared_counter(other.shared_counter), weak_counter(other.weak_counter){
  (*shared_counter) ++;
}

  ~SharedPtr() {
    (*shared_counter) --;
    if(*shared_counter == 0)
    {
      ptr->data
      delete data;
    }
    if(*weak_counter == 0 && *shared_counter == 0){
      delete shared_counter;
      delete weak_counter;
    }
  }


  int &operator* (){
    return *data;
  }
  int *operator-> (){
    return data;
  }
};

class WeakPtr {

  int* data;
  int* shared_counter;
  int* weak_counter;
public:
WeakPtr(const SharedPtr &shared): data(shared.data), shared_counter(shared.shared_counter), weak_counter(shared.weak_counter){
  (*weak_counter) ++;
  }
  ~WeakPtr() {
    (*weak_counter) --;
    if(*shared_counter == 0 || *weak_counter == 0)
    {
      delete shared_counter;
      delete weak_counter;
    }
    
  }
  SharedPtr lock(){
    if(*shared_counter != 0)
    {
      return SharedPtr (*this);
    }
    return SharedPtr();
  }
};

int main() {
  SharedPtr s(new int {42});
  WeakPtr w(s);
  SharedPtr s1 = w.lock();
  *s1;
  
 return 0;
}