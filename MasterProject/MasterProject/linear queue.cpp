#include <iostream>
using namespace std;

class Node {

public:
	//생성자
	Node();

	//다음 노드를 가리키는 포인터 설정자
	void setNext(Node* ptr) { next = ptr; }
	//노드의 데이터 설정
	void setData(int data) { this->data = data; }
	//다음 노드를 가리키는 포인터 접근
	Node* getNext() { return next; }
	//노드의 데이터 접근
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

	//data를 큐의 맨 뒤에 추가
	void enqueue(const int& data);
	//큐가 비어있지 않다면 맨 앞 요소를 삭제하고 반환
	int dequeue();
	//큐의 모든 요소들의 개수를 반환
	int getSize();
	//제일 앞 요소 데이터 반환
	int peekFront();
	//제일 뒤 요소 데이터 반환
	int peekRear();
	//큐의 모든 요소들을 한줄에 15개씩 출력
	void display();
	//큐가 비어있으면 true, 아니면 false 반환
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

int LinearQueue::peekFront()
{
	return front->getData();
}

int LinearQueue::peekRear()
{
	return rear->getData();
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
	cout << endl;
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
	cout << "제일 앞 데이터: " << v.peekFront() << endl;
	cout << "제일 뒤 데이터: " << v.peekRear() << endl;
	cout << "요소의 개수: " << v.getSize() << endl;
	(v.isEmpty()) ? cout << "큐가 비었습니다." << endl : cout << "큐가 안비었습니다." << endl;
	cout << endl;

	for (int i = 0; i < 15; i++)
		v.dequeue();
	v.display();
	cout << "제일 앞 데이터: " << v.peekFront() << endl;
	cout << "제일 뒤 데이터: " << v.peekRear() << endl;
	cout << "요소의 개수: " << v.getSize() << endl;
	(v.isEmpty()) ? cout << "큐가 비었습니다." << endl : cout << "큐가 안비었습니다." << endl;

	for (int i = 0; i < 15; i++)
		v.dequeue();
	v.display();

	cout << "요소의 개수: " << v.getSize() << endl;
	(v.isEmpty()) ? cout << "큐가 비었습니다." << endl : cout << "큐가 안비었습니다." << endl;

	return 0;
}