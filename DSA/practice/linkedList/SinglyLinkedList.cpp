#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int data, Node* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};

struct SinglyLinkedList {
	Node* head;
	Node* tail;

	SinglyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	void print() const {
		Node* curr = head;
		while (curr)
		{
			std::cout << curr->data << " ";
			curr = curr->next;
		}
		std::cout << endl;
	}

	bool search(int x) {
		Node* curr = head;
		while (curr)
		{
			if (curr->data == x)
				return true;
			curr = curr->next;
		}
		return false;
	}

	void pushFront(int x) {
		Node* temp = new Node(x, head);
		head = temp;
		if (!tail)
			tail = head;
	}

	void pushBack(int x) {
		if (!head) {
			head = new Node(x);
			tail = head;
		}
		else {
			tail->next = new Node(x);
			tail = tail->next;
		}
	}

	void insert(int idx, int num) {
		Node* curr = head;
		Node* prev = nullptr;

		if (idx == 0) {
			pushFront(num);
			return;
		}

		for (size_t i = 0; i < idx; i++)
		{
			if (!curr)
				return;
			prev = curr;
			curr = curr->next;
		}
		prev->next = new Node(num, curr);
	}

	void popFront() {
		if (tail == head) {
			delete head;
			head = tail = nullptr;
			return;
		}
		Node* newHead = head->next;
		delete head;
		head = newHead;
	}

	void popBack() {
		Node* curr = head;
		Node* prev = nullptr;
		if (head == tail) {
			delete head;
			head = tail = nullptr;
			return;
		}
		while (curr)
		{
			if (curr->next == nullptr) {
				delete curr;
				prev->next = nullptr;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
	}

	void removeAt(int idx) {
		if (idx == 0) {
			popFront();
			return;
		}
		Node* curr = head;
		Node* prev = nullptr;
		for (size_t i = 0; i <= idx; i++)
		{
			if (!curr)
				return;
			prev = curr;
			curr = curr->next;
		}
		if (curr == tail) {
			prev->next = nullptr;
			delete curr;
		}

		prev->next = curr->next;
		delete curr;
	}
};


int main() {


}