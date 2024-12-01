#include <iostream>
#include <vector>

template <class T>
class Stack {
private:
  std::vector<T> vec;

public:
  // Создает пустой стэк
  Stack()=default;

  // Создает новый стэк, являющийся глубокой копией списка other [O(n)]
  Stack(const Stack& other)=default;

  // Перезаписывает текущий стэк стэком other
  Stack& operator=(const Stack& other)//=default;
  {
    vec = other.vec;
  }

  // Очищает память стэка
  ~Stack()  //= default
  {
    vec.clear();
  }

  // Возвращает размер стэка (сколько памяти уже занято)
  std::size_t size(){
    return vec.size();
  }

  // Проверяет является ли контейнер пустым
  bool empty(){
    return vec.empty();
  }

  // Добавляет элемент на верх стэка.
  void push(const T& x){
    vec.push_back(x);
  }

  // Получает элемент на верху стэка
  T& top(){
    return vec.back();
  };

  // Удаляет последний элемент стэка. Возвращает удаленный элемент.
  T pop()
  {
    T temp = vec.back();
    vec.pop_back();
    return temp;
  }

  // Меняет содержимое с другим стэком. s1.swap(s2);
  void swap(Stack& other)
  {
    std::vector<T> temp = vec;
    vec.clear();
    vec = other.vec;
    other.vec = temp;
  }
};

int main() {
  Stack<int> st;

  std::cout << st.empty() << std::endl;
  
  st.push(10);
  st.push(9);
  st.push(8);
  st.push(7);
  st.push(6);
  st.push(5);
  
  std::cout << st.empty() << std::endl;
  std::cout << st.size() << std::endl;
  
  Stack<int> st1 = st;
  
  std::cout << st1.size() << std::endl;
  std::cout << st.top() << std::endl;
  std::cout << st.pop() << std::endl;
  std::cout << st.top() << std::endl;
  st.swap(st1);
  std::cout << st1.size() << std::endl;
  std::cout << st.size() << std::endl;
  
  return 0;
}