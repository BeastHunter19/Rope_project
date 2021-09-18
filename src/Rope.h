#pragma once
#include <utility>
#include <string>

class Node;

class Rope
{
public:
	Rope(std::string& s);
	Rope(const char* s);
	Rope(Node* r);
	~Rope();

	Rope* concatenate(Rope* R);
	const char index(int i) const;
	std::pair<Rope*, Rope*> split(const int i);
	Rope* insert(Rope* R, const int i);
	Rope* cancel(const int i, const int j);
	const int length() const;
	void printInorder() const;
	void print() const;
	
	const char operator[](std::size_t idx) const;
	friend std::ostream& operator<<(std::ostream& os, const Rope& obj);
	friend Rope& operator+(Rope& R1, Rope& R2);

private:
	Node* root;
	const char index(Node* p, const int i) const;
	void printInorder(Node* p) const;
	void print(Node* p, std::ostream& stream) const;
};



