#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

// Compare - функция или функтор, который используется для сравнения. По
// дефолтну это просто std::less - то же самое, что оператор <. То есть
// Compare(1, 2) == true, а Compare(2, 1) == false. Note: По дефолту с таким
// компаратором очередь должна работать как max heap
template <class T, class Compare = std::less<T>> class PriorityQueue {

  // Заполнить:
  using container_type = std::vector<T, Compare>;
  using value_compare =	Compare;
  using value_type = T;
  using size_type = std::size_t;
  using reference = T&;
  using const_reference = T;

private:
  std::vector<T> data; 

public:
  // Создает пустую очередь с приоритетом
  PriorityQueue() = default;

  // Создает новую очередь с приоритетом, являющююся глубокой копией очереди
  // other [O(n)]
  PriorityQueue(const PriorityQueue &other) = default;

  // Перезаписывает текущую очередь с приоритетом очередью other
  PriorityQueue &operator=(const PriorityQueue &other) = default;

  // Создает новую очередь с приоритетом перемещая существующую [O(1)]
  PriorityQueue(PriorityQueue &&other) = default;

  // Присваивает текущую очередь с приоритетом очередью other
  PriorityQueue &operator=(PriorityQueue &&other) = default;

  // Очищает память очереди с приоритетом
  ~PriorityQueue() = default;

  // Получает ссылку на верхний элемент очереди с приоритетом
  const_reference top() const{
    return data[0];
  };

  // Проверяет является ли контейнер пустым
  bool empty() const{
    return data.size() == 0;
  };

  // Возвращает размер очереди с приоритетом (сколько памяти уже занято)
  size_type size() const{
    return data.size();
  };

  // Добавляет элемент в очередь с приоритетом
  void push(const value_type &value){
    data.push_back(value);
    int i = data.size() - 1;
    while(i != 0) {
      int parent = (i - 1) / 2; 
      if (Compare(data[parent], data[i]) == true) {
        std::swap(data[i], data[parent]);
      }
      else{
        break;
      }
    }
  };

  // Добавляет элемент в очередь с приоритетом
  void push(value_type &&value);

  // Удаляет элемент из начала очереди с приоритетом. Возвращает удаленный
  // элемент.
  T pop(){
    T top = data[0];
    std::swap(data[0], data[data.size()-1]);
    data.pop_back();
    int index = 0;
    while(index<data.size()){
      int left = index*2 + 1;
      int right = index*2 + 2;
      if(left < data.size()-1 && right <= data.size()-1){
        if(data[left] > data[right]){
          std::swap(data[index], data[left]);
          index = left;
        }
        else{
          std::swap(data[index],data[right]);
          index = right;
        }
      }

      if(right > data.size()-1 && left < data.size()-1){
        if(data[index] < data[left]){
          std::swap(data[index], data[left]);
          index = data.size()+1;
        }
      }

      if(right > data.size()-1 && left > data.size()-1){
        index = data.size()+1;
      }
    }
    return top;
  };

  // Меняет содержимое с другой очередью с приоритетом. q1.swap(q2);
  void swap(PriorityQueue &other){
    std::swap(data, other.data);
  };
};

void test_top() {
  PriorityQueue<int> mypq;
  mypq.push(5);
  mypq.push(25);
  mypq.push(15);

  assert(mypq.top() == 25);
}

void test_empty() {
  PriorityQueue<int> mypq;
  assert(mypq.empty());

  mypq.push(42);
  assert(!mypq.empty());
}

void test_empty_after_pop() {
  PriorityQueue<int> mypq;
  int sum{};

  for (int i = 1; i <= 10; i++)
    mypq.push(i);

  while (!mypq.empty()) {
    sum += mypq.top();
    mypq.pop();
  }

  assert(sum == 55);
}

void test_size() {

  PriorityQueue<int> myints;
  assert(myints.size() == 0);
  for (int i = 0; i < 5; i++) {
    myints.push(i);
    assert(myints.size() == i + 1);
  }
}

void test_swap() {
  PriorityQueue<int> mypq, mypq_for_swap;
  mypq.push(15);
  mypq.push(30);
  mypq.push(10);
  mypq_for_swap.push(101);
  mypq_for_swap.push(202);

  mypq.swap(mypq_for_swap);
  assert(mypq.size() == 2);
  assert(mypq_for_swap.size() == 3);
}

void test_pop() {
  PriorityQueue<int> mypq;

  mypq.push(30);
  mypq.push(100);
  mypq.push(25);
  mypq.push(40);

  while (!mypq.empty()) {
    int top = mypq.top();
    assert(top == mypq.pop());
  }
}

void test_push() {
  PriorityQueue<int> mypq;

  for (int i = 0; i < 5; ++i) {
    mypq.push(i);
    assert(mypq.top() == i);
  }
}

void test_operator_assignment_l_value() {
  PriorityQueue<int> mypq, mypq_copyed;
  mypq.push(1);
  mypq.push(2);
  mypq.push(10);
  mypq.push(5);

  mypq_copyed = mypq;

  assert(mypq.size() == mypq_copyed.size());
  assert(mypq.top() == mypq_copyed.top());
}

void test_operator_assignment_r_value() {
  PriorityQueue<int> mypq, mypq_copyed;
  mypq.push(1);
  mypq.push(2);
  mypq.push(10);
  mypq.push(5);

  mypq_copyed = std::move(mypq);

  assert(mypq.size() == 0);
  assert(mypq_copyed.size() == 4);
}

void test_copy_constructor() {
  PriorityQueue<int> mypq;
  mypq.push(1);
  mypq.push(2);
  mypq.push(10);
  mypq.push(5);

  PriorityQueue<int> mypq_copyed{mypq};

  assert(mypq.size() == mypq_copyed.size());
}

void test_move_constructor() {
  PriorityQueue<int> mypq;
  mypq.push(1);
  mypq.push(2);
  mypq.push(10);
  mypq.push(5);

  auto size_of_mypq = mypq.size();
  PriorityQueue<int> mypq_copyed{std::move(mypq)};

  assert(mypq_copyed.size() == size_of_mypq);
  assert(mypq.size() == 0);
}

void test_swap_with_empty_container() {
  PriorityQueue<int> mypq, mypq_for_swap;
  mypq.push(5);
  mypq.push(25);
  mypq.push(15);

  mypq.swap(mypq_for_swap);

  assert(mypq.size() == 0);
  assert(mypq_for_swap.size() == 3);
  assert(mypq_for_swap.top() == 25);
}

int main() {

  test_top();
  test_empty();
  test_empty_after_pop();
  test_push();
  test_pop();
  test_size();
  test_swap();

  test_operator_equal_l_value();
  test_operator_equal_r_value();

  test_copy_constructor();
  test_move_constructor();

  test_swap_with_empty_container();

  return 0;
}