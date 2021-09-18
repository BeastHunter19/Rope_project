#include "Node.h"

Node::Node(): len(0), weight(0), left(nullptr), right(nullptr), 
 parent(nullptr), str("")
{}

Node::~Node()
{
	if(this->left) delete this->left;
	if(this->right) delete this->right;
}

void Node::init(std::string& s)
{
	this->parent = nullptr;
	if (s.length() <= MAX_STR_LEN) {
		this->left = this->right = nullptr;
		this->weight = this->len = s.length();
		this->str = s;
	}
	else {
		std::string l = s.substr(0, s.length()/2);
		std::string r = s.substr(s.length()/2);
		this->left = new Node;
		this->left->init(l);
		this->left->parent = this;
		this->right = new Node;
		this->right->init(r);
		this->right->parent = this;
		this->weight = this->left->len;
		this->len = s.length();
		this->str = "";
	}
}

void Node::init(Node* l, Node* r)
{
	this->left = l;
	this->left->parent = this;
	this->right = r;
	this->right->parent = this;
	this->weight = this->left->len;
	this->len = this->left->len + this->right->len;
	this->str = "";
}
