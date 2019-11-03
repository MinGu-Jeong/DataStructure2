#include <iostream>
using namespace std;

class Node {

public:
	Node();

	void setNext(Node* ptr) { next = ptr; }
	void setData(int data) { this->data = data; }
	Node* getNext() { return next; }
	int getData() { return data; }

private:
	int data;
	Node* next;
};

Node::Node() : data(0), next(nullptr) { }

class LinearQueue {

public:
	//생성자
	LinearQueue();

	void enqueue(const int& data);
	int dequeue();
	int getSize();
	void display();
	bool isEmpty();

private:
	Node* front; //요소를 삭제하는 부분을 가리키는 포인터
	Node* rear; //요소를 추가하는 부분을 가리키는 포인터
	int len; //요소의 개수
};

LinearQueue::LinearQueue() : front(nullptr), rear(nullptr), len(0) { }

void LinearQueue::enqueue(const int& data)
{
	Node* temp_ptr = new Node;

	temp_ptr->setData(data);
	temp_ptr->setNext(nullptr);

	if (isEmpty())
	{
		front = temp_ptr;
		rear = temp_ptr;
	}
	else
	{
		rear->setNext(temp_ptr);
		rear = temp_ptr;
	}

	len++;
}

int LinearQueue::dequeue()
{
	if (isEmpty())
		cout << "queue가 비었습니다.";
	else
	{
		int temp_data = front->getData();
		Node* temp_ptr = front;

		front = front->getNext();

		delete temp_ptr;
		len--;
		return temp_data;
	}
}

int LinearQueue::getSize()
{
	return len;
}

void LinearQueue::display()
{
	Node* temp_ptr = front;
	int k = 1;

	while (temp_ptr != nullptr)
	{
		printf("[%3d ] ", temp_ptr->getData());
		if (k % 15 == 0)
			printf("\n");

		k++;
		temp_ptr = temp_ptr->getNext();
	}
}

bool LinearQueue::isEmpty()
{
	if (len == 0)
		return true;
	else
		return false;
}

int main(void) {

	LinearQueue v;

	for (int i = 0; i < 30; i++)
		v.enqueue(i + 1);

	v.display();

	for (int i = 0; i < 15; i++)
		v.dequeue();

	cout << endl;

	v.display();

	return 0;
}