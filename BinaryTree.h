#pragma once

#include<memory>
class Node
{
	char data = '*';
	std::unique_ptr<Node> pLeft;
	std::unique_ptr<Node> pRight;
public:
	Node();
	Node(char data);

	friend class BinaryTree;
};

class BinaryTree
{
	std::unique_ptr<Node> pRoot;

public:
	BinaryTree();
	BinaryTree(char dataInTheRoot);

	void addData(char newData) const;
	void print(Node* pCurrent) const;
	Node* getPRoot() const;
};
