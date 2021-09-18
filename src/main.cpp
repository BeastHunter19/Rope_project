#include "Rope.h"
#include <utility>
#include <iostream>

int main()
{
	//the constructors work correctly with a string longer than the limit for a single node
	std::cout << "Test the constructor with a long string\n";
	std::string s1;
	for (int i = 0; i < 10; i++) {
		s1.append("a");
	}
	for (int i = 0; i < 10; i++) {
		s1.append("b");
	}
	for (int i = 0; i < 10; i++) {
		s1.append("c");
	}
	for (int i = 0; i < 10; i++) {
		s1.append("d");
	}
	Rope* R1 = new Rope(s1);
	std::cout << "Inorder visit of the rope:\n";
	R1->printInorder();
	std::cout << "Rope content: ";
	R1->print();
}