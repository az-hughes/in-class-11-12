#include "BinaryTree.h"
#include <iostream>
Node::Node() = default;

Node::Node(char data)
	:
	data(data),
	pLeft(nullptr),
	pRight(nullptr)
{
}

BinaryTree::BinaryTree() = default;

BinaryTree::BinaryTree(char dataInTheRoot)
{
	pRoot = std::make_unique<Node>(dataInTheRoot);
}

void BinaryTree::addData(char newData) const
{
	std::unique_ptr<Node> pNew = std::make_unique<Node>(newData);
	if (pRoot->pLeft == nullptr)
	{
		pRoot->pLeft = std::move(pNew);
	}

	else if (pRoot->pRight == nullptr)
	{
		pRoot->pRight = std::move(pNew);
	}

	else if (pRoot->pLeft->pLeft == nullptr)
	{
		pRoot->pLeft->pLeft = std::move(pNew);
	}

	else if (pRoot->pLeft->pRight == nullptr)
	{
		pRoot->pLeft->pRight = std::move(pNew);
	}
}

void BinaryTree::print(Node* pCurrent) const
{
	if (pCurrent == nullptr)
	{
		return;
	}

	std::cout << pCurrent->data << std::endl;
	print(pCurrent->pLeft.get());
	print(pCurrent->pRight.get());
}

Node* BinaryTree::getPRoot() const
{
	return pRoot.get();
}
