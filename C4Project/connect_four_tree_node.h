#ifndef __ConnectFour__TreeNode__
#define __ConnectFour__TreeNode__

class TreeNode {
public:
	TreeNode();
	~TreeNode();

	TreeNode *parent_Node;
	int depth_;
	bool is_gameover_;
};

#endif