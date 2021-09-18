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
	return nullptr;
}

char Rope::index(int i)
{
	return 0;
}

char Rope::index(Node* p, int i)
{
	return 0;
}

std::pair<Rope*, Rope*> Rope::split(int i)
{
	return std::pair<Rope*, Rope*>();
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
