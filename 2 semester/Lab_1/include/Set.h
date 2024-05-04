#ifndef LAB_1_INCLUDE_SET_H
#define LAB_1_INCLUDE_SET_H

#include <iostream>
#include <set>
#include <stack>

class Set {
	struct Node {
		int value;
		Node* left, * right;

		Node(int value) : value(value), left(nullptr), right(nullptr) {}
	};

	Node* _root;
	size_t _size;

public:
	class Iterator {
		std::stack<Node*> node_stack;
		Node* current;
	public:
		Iterator(Node* root);

		int operator*();

		void operator++();

		bool operator==(const Iterator& other);

		bool operator!=(const Iterator& other);
	};

	Set() : _root(nullptr), _size(0) {}

	Set(const Set& other);

	~Set();

	Set& operator=(const Set& other);

	void print() const;

	bool contains(int value) const;

	Node* find(int value) const;

	Node* findNode(Node* node, int value) const;

	bool insert(int value);

	bool erase(int value);

	size_t size() const;

	Node* root() const;

	Iterator begin();

	Iterator end();

private:
	void deleteNode(Node* node);

	void printNode(Node* node) const;

	Node* clone(Node* node);

	bool containsNode(Node* node, int value) const;

	Node* insertNode(Node* node, int value);

	Node* eraseNode(Node* node, int value);

	Node* findMinNode(Node* node) const;
};

#endif