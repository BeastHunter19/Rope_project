#include "Rope.h"
#include <utility>
#include <iostream>

int main()
{
	//the constructors work correctly with a string longer than the limit for a single node
	std::cout << "--- Testing the constructor with a long string ---\n";
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

	std::cout << "\n--- Indexing characters in R2 ---\n";
	std::cout << "Character in 4th position: " << R2->index(4) << std::endl;
	std::cout << "Character in 12th position: " << R2->index(12) << std::endl;

	//concatenation works correctly
	std::cout << "\n--- Concatenating R1 and R2 into R3 ---\n";
	Rope* R3 = R1->concatenate(R2);
	std::cout << "Inorder visit of the rope R3:\n";
	R3->printInorder(); 
	std::cout << "Rope content: ";
	R3->print();

	//splitting works correctly
	std::cout << "\n--- Splitting R3 into R4 and R5 ---\n";
	Rope *R4, *R5;
	std::pair<Rope*, Rope*> pair = R3->split(15);
	R4 = pair.first;
	R5 = pair.second;
	std::cout << "Inorder visit of the rope R4:\n";
	R4->printInorder();
	std::cout << "Rope content: ";
	R4->print();
	std::cout << "Inorder visit of the rope R5:\n";
	R5->printInorder();
	std::cout << "Rope content: ";
	R5->print();

	//insert works correctly
	std::cout << "\n--- Inserting R6 in R4 at position 5 ---\n";
	std::string s3("sssssssssstttttttttt");
	Rope* R6 = new Rope(s3);
	Rope* R7 = R4->insert(R6, 5);
	std::cout << "Inorder visit of the rope R7:\n";
	R7->printInorder();
	std::cout << "Rope content: ";
	R7->print();

	delete R1;
	delete R2;
	delete R4;
	delete R5;
	delete R7;
}