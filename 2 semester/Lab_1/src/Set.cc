#include "../include/Set.h"

Set::Set(const Set& other) {
	_root = clone(other._root);
	_size = other._size;
}

Set::~Set() {
	deleteNode(_root);
	_size = 0;
}

Set& Set::operator=(const Set& other) {
	if (this != &other) {
		deleteNode(_root);
		_root = clone(other._root);
		_size = other._size;
	}
	return *this;
}

void Set::print() const {
	printNode(_root);
	std::cout << std::endl;
}

bool Set::contains(int value) const {
	return containsNode(_root, value);
}

bool Set::insert(int value) {
	if (contains(value))
		return false;
	_root = insertNode(_root, value);
	_size++;
	return true;
}

bool Set::erase(int value) {
	if (!contains(value))
		return false;
	_root = eraseNode(_root, value);
	_size--;
	return true;
}

size_t Set::size() const {
	return _size;
}

Set::Node* Set::root() const {
	return _root;
}

void Set::deleteNode(Node* node) {
	if (node) {
		deleteNode(node->left);
		deleteNode(node->right);
		delete node;
	}
}

void Set::printNode(Node* node) const {
	if (node) {
		printNode(node->left);
		std::cout << node->value << " ";
		printNode(node->right);
	}
}

Set::Node* Set::clone(Node* node) {
	if (!node)
		return nullptr;
	Node* clone_node = new Node(node->value);
	clone_node->left = clone(node->left);
	clone_node->right = clone(node->right);
	return clone_node;
}

bool Set::containsNode(Node* node, int value) const {
	if (!node)
		return false;
	if (node->value == value)
		return true;
	if (node->value > value)
		return containsNode(node->left, value);
	return containsNode(node->right, value);
}

Set::Node* Set::find(int value) const {
	return findNode(_root, value);
}

Set::Node* Set::findNode(Node* node, int value) const {
	if (!node)
		return nullptr;
	if (node->value == value)
		return node;
	if (node->value > value)
		return findNode(node->left, value);
	return findNode(node->right, value);
}

Set::Node* Set::insertNode(Node* node, int value) {
	if (!node)
		return new Node(value);
	if (value < node->value) {
		node->left = insertNode(node->left, value);
	}
	else if (value > node->value) {
		node->right = insertNode(node->right, value);
	}
	return node;
}

Set::Node* Set::findMinNode(Node* node) const {
	while (!node->left)
		node = node->left;
	return node;
}

Set::Node* Set::eraseNode(Node* node, int value) {
	if (!node) {
		return nullptr;
	}
	if (value < node->value) {
		node->left = eraseNode(node->left, value);
	}
	else if (value > node->value) {
		node->right = eraseNode(node->right, value);
	}
	else {
		if (!node->left && !node->right) {
			delete node;
			return nullptr;
		}
		else if (!node->left) {
			Node* tmp = node->right;
			delete node;
			return tmp;
		}
		else if (!node->right) {
			Node* tmp = node->left;
			delete node;
			return tmp;
		}
		else {
			Node* tmp = findMinNode(node->right);
			node->value = tmp->value;
			node->right = eraseNode(node->right, tmp->value);
		}
	}
	return node;
}

Set::Iterator::Iterator(Node* root) {
	current = root;
	while (current) {
		node_stack.push(current);
		current = current->left;
	}
}

int Set::Iterator::operator*() {
	return node_stack.top()->value;
}

void Set::Iterator::operator++() {
	Node* node = node_stack.top();
	node_stack.pop();
	if (node->right) {
		current = node->right;
		while (current) {
			node_stack.push(current);
			current = current->left;
		}
	}
}

Set::Iterator Set::begin() {
	return Iterator(_root); 
}

Set::Iterator Set::end() { 
	return Iterator(nullptr); 
}

bool Set::Iterator::operator==(const Iterator& other) {
	return (node_stack == other.node_stack);
}

bool Set::Iterator::operator!=(const Iterator& other) {
	return (!node_stack.empty()) || (!other.node_stack.empty());
}
