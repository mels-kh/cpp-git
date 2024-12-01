#include <iostream>

template <class T> class Vector {
private:
	std::size_t arr_size;
	std::size_t arr_capacity;
	T* arr;
public:
  // Создает вектор размера arr_size заполненный дефолтными значениями типа T
  Vector(std::size_t arr_size = 0)
    : arr_size(arr_size)
    		, arr_capacity(arr_size * 2 + 1)
    		, arr(new T[arr_capacity]{})
    	{
    	}

  // Создает новый вектор, являющийся глубокой копией вектора other
  Vector(const Vector &other): arr_size(other.arr_size) 
  ,arr_capacity (other.arr_capacity)
  ,arr  (new T[arr_capacity])
    {
		for (int i = 0; i < other.arr_size; ++i) {
			arr[i] = other.arr[i];
		}
	}

  // Перезаписывает текущий вектор вектором other
  // Vector v1{5}, v2{10};                        
  // v1 = v2;
  // std::cout << v1.size() == 10 << std::endl // True
  Vector &operator=(const Vector &other){
    arr_size = other.arr_size;
    arr_capacity = other.arr_capacity;
    delete [] arr;
    arr = new T[arr_capacity];
    for(int i = 0;i < other.arr_size;i ++)
      {
        arr[i] = other.arr[i];
      }
    return *this;
  }
    
  // Очищает память вектора
  ~Vector()
  {
  		delete[] arr;
  }
  // Возвращает размер вектора (сколько памяти уже занято)
    std::size_t size() const
	{
		return arr_size;
	}
  // Проверяет является ли контейнер пустым
  bool empty()
  {
    return arr_size == 0;
  }  
    
  // Возвращает размер выделенной памяти
  std::size_t capacity()
  {
    return arr_capacity;      
  }

  // Возвращает копию элемента по индексу
  T operator[](std::size_t index) const
  {
		return arr[index];
	}

  // Возвращает ссылку на элемент по индексу (позволяет менять элемент, типа
  // v[5] = 42;)
  T &operator[](std::size_t index) 
  {
		return arr[index];
	}

  // Перевыделяет память:
  // * выделяет новый кусок памяти размером равным new_capacity,
  // * копирует столько старых элементов, сколько влезает,
  // * удаляет старый кусок памяти.
  void resize(std::size_t new_capacity)
  {
    T* new_arr = new T[new_capacity];
    for(std::size_t i = 0;i < new_capacity;i++)
      {
        new_arr[i] = arr[i];
      }
    delete[] arr;
    arr = new_arr;
    arr_capacity = new_capacity;
  }

  // Добавляет элемент в конец вектора. Если нужно перевыделяет память
  void push_back(const T& x)
	{   
		if (arr_size == arr_capacity)
		{
			resize(2 * arr_capacity);
		}
		arr[arr_size++] = x;
	}

  // Удаляет последний элемент вектора и возвращает его.
  T pop_back(){
    T tmp = arr[arr_size - 1];
    arr_size--;
    return tmp;
  }
  // Очищает вектор (выделенная память остает выделенной)
  void clear()
  {
    arr_size = 0;
  }

  // Вставляет новый элемент value на место pos.
  // [1, 2, 3].insert(1, 42) -> [1, 42, 2, 3]
 void insert(size_t pos, const T& value) {
		push_back(value);
		for (int i = arr_size; i > pos; --i) {
			std::swap(arr[i], arr[i-1]);
		}
	}

  // Удаляет элемент с идексом pos. Возвращает удаленный элемент.
  // [1, 2, 3].erase(1) -> [1, 3] (return 2)
  T erase(size_t pos)
  {
    T temp = arr[pos];
    for(int i = pos;i < arr_size - 1; i++)
      {
        arr[i] = arr[i+1];
      }
    arr_size --;
    return temp;
  }
};

int main()
{ 
  Vector<int> vec{};
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);

  std::cout << "my arr is \n";
  for(int i = 0; i < vec.size(); i++)
    {
      std:: cout << vec[i] << " ";
    }
  std::cout << "\n";
  std::cout << vec.pop_back();
  std::cout << "\n size is" << vec.size() << "\n capacity is" << vec.capacity();
  vec.resize(vec.capacity() * 2);
  std::cout << "\n new_capacity is " << vec.capacity();

  Vector<int> vec_copy{vec};
  std::cout << "\n copy constructor\n"  ;
  for (std::size_t i = 0;i < vec_copy.size(); ++i)
    {
      std::cout << vec_copy[i];
    }
  
  std::cout << "\n is empty = " << vec_copy.empty();

  vec_copy.insert(6, 7);
  std:: cout << "\n insert mode \n";
  for(std::size_t i = 0;i < vec_copy.size();i++)
    {
      std::cout << vec_copy[i] << " ";
    }

  vec_copy.erase(2);
    std:: cout << "\n erase \n";
    for(std::size_t i = 0;i < vec_copy.size();i++)
    {
      std::cout << vec_copy[i] << " ";
    }

  vec_copy.clear();
  std::cout << "\nis empty " << vec_copy.empty() << "\n";
  
  return 0; 
}

