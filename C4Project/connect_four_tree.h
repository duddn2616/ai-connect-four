#ifndef __ConnectFour__Tree__
#define __ConnectFour__Tree__

#include <vector>
#include "connect_four.h"
#include "connect_four_tree_node.h"

class Tree {
public:
	Tree();
	~Tree();

	TreeNode *GetMaxNodes();

	TreeNode *root_node_;
	TreeNode *child_nodes[kRow];
	int next_node_index_;
};

#endif