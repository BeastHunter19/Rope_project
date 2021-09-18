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
	std::cout << "Inorder visit of the rope R1:\n";
	R1->printInorder();
	std::cout << "Rope content: ";
	R1->print();

	//the indexing works correctly
	std::string s2("Hello, world!");
	Rope* R2 = new Rope(s2);
	std::cout << "Inorder visit of the rope R2:\n";
	R2->printInorder();
	std::cout << "Rope content: ";
	R2->print();
	std::cout << "Character in 4th position: " << R2->index(4) << std::endl;
	std::cout << "Character in 12th position: " << R2->index(12) << std::endl;

	//concatenation works correctly and starting ropes remain unchanged
	std::cout << "Concatenazione tra R1 e R2\n";
	Rope* R3 = R1->concatenate(R2);
	std::cout << "Inorder visit of the rope R3:\n";
	R3->printInorder();
	std::cout << "Rope content: ";
	R3->print();
	std::cout << "Inorder visit of the rope R1:\n";
	R1->printInorder();
	std::cout << "Rope content: ";
	R1->print();
	std::cout << "Inorder visit of the rope R2:\n";
	R2->printInorder();
	std::cout << "Rope content: ";
	R2->print();

	delete R3;
}