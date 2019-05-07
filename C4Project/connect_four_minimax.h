#ifndef __ConnectFour__Minimax__
#define __ConnectFour__Minimax__

#include "connect_four_tree.h"

class Minimax {
public:
	Minimax();
	~Minimax();

	int GetInput(int last_put);
	void Propagate();

	Tree *current_tree;
	int max_depth_;
	int node_count_;
};

#endif