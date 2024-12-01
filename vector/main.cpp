#include <iostream>

template <class T> class Vector {
private:
std::size_t arr_size;
std::size_t arr_capacity;
T* arr;

public:
  // Создает вектор размера arr_size заполненный дефолтными значениями типа T
  Vector(std::size_t arr_size = 0)
:arr_size(arr_size)
,arr_capacity(arr_size * 2 + 1)
,arr(new T[arr_capacity]{})
{
}

  // Создает новый вектор, являющийся глубокой копией вектора other
  Vector(const Vector &other)
:arr_size(other.arr_size)
,arr_capacity(other.arr_capacity)
,arr(new T[arr_capacity])
{
  for(int i = 0 ; i < arr_size; i++)
    {
      arr[i] = other.arr[i];
    }
}

  // Перезаписывает текущий вектор вектором other
  // Vector v1{5}, v2{10};
  // v1 = v2;
  // std::cout << v1.size() == 10 << std::endl // True
  Vector &operator=(const Vector &other);

  // Очищает память вектора
  ~Vector();

  // Возвращает размер вектора (сколько памяти уже занято)
  std::size_t size();

  // Проверяет является ли контейнер пустым
  bool empty();

  // Возвращает размер выделенной памяти
  std::size_t capacity();

  // Возвращает копию элемента по индексу
  T operator[](std::size_t index) const;

  // Возвращает ссылку на элемент по индексу (позволяет менять элемент, типа
  // v[5] = 42;)
  T &operator[](std::size_t index);

  // Перевыделяет память:
  // * выделяет новый кусок памяти размером равным new_capacity,
  // * копирует столько старых элементов, сколько влезает,
  // * удаляет старый кусок памяти.
  void resize(std::size_t new_capacity);

  // Добавляет элемент в конец вектора. Если нужно перевыделяет память
  void push_back(const T &x);

  // Удаляет последний элемент вектора и возвращает его.
  T pop_back();

  // Очищает вектор (выделенная память остает выделенной)
  void clear();

  // Вставляет новый элемент value на место pos.
  // [1, 2, 3].insert(1, 42) -> [1, 42, 2, 3]
  void insert(size_t pos, T value);

  // Удаляет элемент с идексом pos. Возвращает удаленный элемент.
  // [1, 2, 3].erase(1) -> [1, 3] (return 2)
  T erase(size_t pos);
};

int main() { return 0; }
