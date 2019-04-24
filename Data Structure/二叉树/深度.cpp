int depth(BiTNode* root) {//深度
	int deep = 0;//递归回到根节点，即走完一个简单路径
	if (root != NULL) {
		int left = depth(root->lchild);
		int right = depth(root->rchild);
		deep = max(left, right) + 1;
	}
	return deep;
}