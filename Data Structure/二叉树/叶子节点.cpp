int leafNode(BiTNode* root) {//р╤вс╫з╣Ц
	static int count = 0;
	if (root != NULL) {
		if (root->lchild != NULL) leafNode(root->lchild);
		if (root->rchild != NULL) leafNode(root->rchild);
		if (root->lchild == NULL&&root->rchild == NULL) count++;
	}
	return count;
}