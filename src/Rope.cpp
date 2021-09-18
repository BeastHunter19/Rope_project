#include "Rope.h"
#include "Node.h"
#include <iostream>

Rope::Rope(std::string& s)
{
	this->root = new Node;
	this->root->init(s);
}

Rope::Rope(char* s)
{
	std::string str(s);
	this->root = new Node;
	this->root->init(str);
}

Rope::Rope(Node* r): root(r)
{}

Rope::~Rope()
{
	if(this->root) delete this->root;
}

Rope* Rope::concatenate(Rope* R)
{
	if(R->root == nullptr) return this;
	if(this->root == nullptr) return R;
	Node* newRoot = new Node;
	newRoot->init(this->root, R->root);
	return new Rope(newRoot);
}

char Rope::index(int i)
{
	if(this->root == nullptr) return '\0';
	return index(this->root, i);
}

char Rope::index(Node* p, int i)
{
	if(i < 0 || i > length()) return '\0';
	if (i < p->weight && p->left) {
		return index(p->left, i);
	}
	if (i >= p->weight && p->right) {
		return index(p->right, i - p->weight);
	}
	return p->str.at(i);
}

std::pair<Rope*, Rope*> Rope::split(int i)
{
	if (this->root == nullptr || i < 0 || i > length()) 
		return std::make_pair(nullptr, nullptr);

	//searching for the node containing the split point
	Node* iter = this->root;
	int index = i + 1;
	while (iter->left || iter->right) {
		if (index < iter->weight && iter->left) {
			iter = iter->left;
		}
		else if (index >= iter->weight && iter->right) {
			iter = iter->right;
			index -= iter->weight;
		}
	}

	//handle case where the split point is not at the start of a leaf node
	if (index != 0) {
		Node *s1, *s2, *p;
		std::string str1 = iter->str.substr(0, index);
		std::string str2 = iter->str.substr(index);
		s1 = new Node;
		s1->init(str1);
		s2 = new Node;
		s2->init(str2);
		p = new Node;
		p->init(s1, s2);
		p->parent = iter->parent;
		//fix root pointer if necessary
		if (iter == this->root) this->root = p;
		else if (iter == iter->parent->left) p->parent->left = p;
		else p->parent->right = p;
		delete iter;
		iter = p->right;
	}

	//delete right links to leaves past the split point
	Rope *S2 = nullptr, *tmp;
	//subtractCount stores the total number of characters that have been split at any given point
	int subtractCount = 0;
	//fromLeft is true by default so we can delete the first node
	bool fromLeft = true;

	//first deletion happens when going up from a right child for the first time
	while (iter->parent && iter == iter->parent->left) {
		iter = iter->parent;
	}
	while (iter->parent) {
		iter = iter->parent;
		//delete right links if there are any and we are coming from a left child
		if (fromLeft) {
			iter->weight -= subtractCount;
			if (iter->right) {
				tmp = new Rope(iter->right);
				iter->len -= iter->right->len;
				subtractCount += iter->right->len;
				iter->right->parent = nullptr;
				iter->right = nullptr;
				if (S2 == nullptr) S2 = tmp;
				else S2 = S2->concatenate(tmp);
			}
		}

		//if iter is pointing to the root exit from the loop
		if (iter->parent == nullptr) break;
		//check wether we're going up from a left child
		if(iter == iter->parent->left) fromLeft = true;
		else fromLeft = false;
	}

	return std::make_pair(this, S2);
}

Rope* Rope::insert(Rope* R, int i)
{
	return nullptr;
}

Rope* Rope::cancel(int i, int j)
{
	return nullptr;
}

int Rope::length()
{
	return this->root->len;
}

void Rope::printInorder()
{
	printInorder(this->root);
	std::cout << std::endl;
}

void Rope::printInorder(Node* p)
{
	if (p) {
		printInorder(p->left);
		if(p->str == "") std::cout << p->weight << " ";
		else std::cout << p->str << " ";
		printInorder(p->right);
	}
}

void Rope::print()
{
	print(this->root);
	std::cout << std::endl;
}

void Rope::print(Node* p)
{
	if (p) {
		print(p->left);
		std::cout << p->str;
		print(p->right);
	}
}
