  #include <iostream>

struct Node {
	int value;
	Node* next;
};

class ForwardList {
private:
	Node* root;
public:
	ForwardList() : root{nullptr} {}

	~ForwardList() {
    while(root != nullptr) {
      pop_front();
    }
  }

	void push_front(int value) {
		root = new Node{value, root};
	}

	void pop_front() {
		if (root == nullptr) {
			throw std::runtime_error{"empty list"};
		}
		Node* tmp = root->next;
		delete root;
		root = tmp;
	}


	int operator[] (std::size_t index) const {
		Node* current = root;
		std::size_t count{};
		while(current != nullptr && count != index) {
			current = current->next;
			count++;
		}
		if (current == nullptr) {
			throw std::runtime_error{"index > size"};	
		}
		return current->value;
	}

};



int main() {
	ForwardList list;
	list.push_front(42);
	list.push_front(5);
	list.push_front(10);
	std::cout << list[1] << std::endl;
}