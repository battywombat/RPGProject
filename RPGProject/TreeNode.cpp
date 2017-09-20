#include "TreeNode.h"

TreeNode::TreeNode() : _parent(nullptr)
{
}

TreeNode::TreeNode(const TreeNode * obj)
{
	if (obj == nullptr) {
		_parent = nullptr;
	}
	else {
		_parent = obj->_parent;
	}
}

TreeNode::~TreeNode()
{
}

TreeNode *TreeNode::GetParent()
{
	return _parent;
}

void TreeNode::SetParent(TreeNode *newParent)
{
	_parent = newParent;
}
