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

	//after concatenation deletion of starting ropes should be avoided
	Rope* concatenate(Rope* R);
	char index(int i);
	std::pair<Rope*, Rope*> split(int i);
	Rope* insert(Rope* R, int i);
	Rope* cancel(int i, int j);
	int length();
	void printInorder();
	void print();

private:
	Node* root;
	char index(Node* p, int i);
	void printInorder(Node* p);
	void print(Node* p);
};

