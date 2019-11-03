#include <iostream>
using namespace std;

class Node {

public:
	//������
	Node();

	//���� ��带 ����Ű�� ������ ������
	void setNext(Node* ptr) { next = ptr; }
	//����� ������ ����
	void setData(int data) { this->data = data; }
	//���� ��带 ����Ű�� ������ ����
	Node* getNext() { return next; }
	//����� ������ ����
	int getData() { return data; }

private:
	int data;
	Node* next;
};

Node::Node() : data(0), next(nullptr) { }

class LinearQueue {

public:
	//������
	LinearQueue();

	//data�� ť�� �� �ڿ� �߰�
	void enqueue(const int& data);
	//ť�� ������� �ʴٸ� �� �� ��Ҹ� �����ϰ� ��ȯ
	int dequeue();
	//ť�� ��� ��ҵ��� ������ ��ȯ
	int getSize();
	//���� �� ��� ������ ��ȯ
	int peekFront();
	//���� �� ��� ������ ��ȯ
	int peekRear();
	//ť�� ��� ��ҵ��� ���ٿ� 15���� ���
	void display();
	//ť�� ��������� true, �ƴϸ� false ��ȯ
	bool isEmpty();

private:
	Node* front; //��Ҹ� �����ϴ� �κ��� ����Ű�� ������
	Node* rear; //��Ҹ� �߰��ϴ� �κ��� ����Ű�� ������
	int len; //����� ����
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
		cout << "queue�� ������ϴ�.";
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
	cout << "���� �� ������: " << v.peekFront() << endl;
	cout << "���� �� ������: " << v.peekRear() << endl;
	cout << "����� ����: " << v.getSize() << endl;
	(v.isEmpty()) ? cout << "ť�� ������ϴ�." << endl : cout << "ť�� �Ⱥ�����ϴ�." << endl;
	cout << endl;

	for (int i = 0; i < 15; i++)
		v.dequeue();
	v.display();
	cout << "���� �� ������: " << v.peekFront() << endl;
	cout << "���� �� ������: " << v.peekRear() << endl;
	cout << "����� ����: " << v.getSize() << endl;
	(v.isEmpty()) ? cout << "ť�� ������ϴ�." << endl : cout << "ť�� �Ⱥ�����ϴ�." << endl;

	for (int i = 0; i < 15; i++)
		v.dequeue();
	v.display();

	cout << "����� ����: " << v.getSize() << endl;
	(v.isEmpty()) ? cout << "ť�� ������ϴ�." << endl : cout << "ť�� �Ⱥ�����ϴ�." << endl;

	return 0;
}