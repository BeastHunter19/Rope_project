#pragma once
#include <utility>
#include <string>

class Node;

class Rope
{
public:
	Rope(std::string& s);
	Rope(char* s);
	Rope(Node* r);
	~Rope();

	Rope* concatenate(Rope* R);
	char index(int i);
	char index(Node* p, int i);
	std::pair<Rope*, Rope*> split(int i);
	Rope* insert(Rope* R, int i);
	Rope* cancel(int i, int j);
	int length();
	void printInorder();
	void printInorder(Node* p);
	void print();
	void print(Node* p);
private:
	Node* root;
};

