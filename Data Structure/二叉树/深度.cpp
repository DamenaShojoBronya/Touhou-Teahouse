int depth(BiTNode* root) {//���
	int deep = 0;//�ݹ�ص����ڵ㣬������һ����·��
	if (root != NULL) {
		int left = depth(root->lchild);
		int right = depth(root->rchild);
		deep = max(left, right) + 1;
	}
	return deep;
}