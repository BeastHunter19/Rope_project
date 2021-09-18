#pragma once
#include <string>

class Node
{
public:
	Node();
	~Node();
	void init(std::string& s);
	void init(Node* l, Node* r);
	
	Node* parent;
	Node* left;
	Node* right;
	int weight;
	int len;
	std::string str;

private:
	static constexpr int MAX_STR_LEN = 10;
};

