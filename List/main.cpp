#include <iostream>

template <class T>
class List {
struct Node{
Node* next;
int value;
};
Node* head = nullptr;


public:
  class Iterator;
  // Создает список размера count заполненный дефолтными значениями типа T
  List(std::size_t count)
{ 
  for(int i = 0;i < count;i ++){
  push_front(T{});
  }
}

  // Создает новый список, являющийся глубокой копией списка other [O(n)]
  List(const List& other)
{
  Node* other_node = new Node;
  
}

  // Перезаписывает текущий список списком other
  // List l1{5}, l2{10};
  // l1 = l2;
  // std::cout << l1.size() == 10 << std::endl // True
  List& operator=(const List& other);

  // Очищает память списка [O(n)]
  ~List();

  // Возвращает размер списка (сколько памяти уже занято)
  std::size_t size(){
    int count = 0;
    Node* current = head;
    while(current != nullptr)
      {
        current = current -> next;
        count ++;
      }
  }

  // Проверяет является ли контейнер пустым
  bool empty()
{
  return size() == 0;
}

  // Возвращает итератор на первый элемент
  // https://en.cppreference.com/w/cpp/container/list/begin
  Iterator begin();

  // Возвращает итератор обозначающий конец контейнера
  Iterator end();

  // Возвращает копию элемента по индексу
  T operator[](std::size_t index) const;

  // Возвращает ссылку на элемент по индексу (позволяет менять элемент, типа
  // v[5] = 42;)
  T& operator[](std::size_t index);

  // Добавляет элемент в конец списока.
  void push_back(const T& x);

  // Добавляет элемент в начало списока.
  void push_front(const T& x)
{
  Node* node = new Node;
  node -> value = x;
  node -> next = head;
  head -> next = node;
}

  // Удаляет последний элемент списока.
  T pop_back();

  // Удаляет первый элемент списока.
  T pop_front(){
    Node* tmp = head -> next;
    head  = head -> next;
    delete tmp;
    
  }

  // Вставляет новый элемент value перед элементом, на который указывает it.
  //     it
  //     v
  // [1, 2, 3].insert(it, 42) -> [1, 42, 2, 3]
  void insert(Iterator it, T value);

  //     it
  //     v
  // [1, 2, 3].erase(it) -> [1, 3] (return 2)
  T erase(Iterator it);

  // Класс, который позволяет итерироваться по контейнеру.
  // Я указал минимальный набор операций
  class Iterator {
    // Инкремент. Движение к следующему элементу. ++it
    Iterator& operator++();

    // Декремент. Движение к предыдущему элементу. --it
    Iterator& operator--();

    // Проверка на неравенство двух итераторов. Обычно используется it !=
    // container.end().
    bool operator!=(const Iterator& other);

    // разыменование (как с указателями): *it = 42; или std::cout << *it;
    T& operator*();
  };
};

int main() {

  return 0;
}
