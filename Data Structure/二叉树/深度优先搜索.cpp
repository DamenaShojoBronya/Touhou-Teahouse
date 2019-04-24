void PreOrderTraversal(BiTNode* root) {//深度优先搜索_前序遍历
	if (root->data != NULL) cout << root->data;
	if (root->lchild != NULL) PreOrderTraversal(root->lchild);
	if (root->rchild != NULL) PreOrderTraversal(root->rchild);
}

void InOrderTraversal(BiTNode* root) {//深度优先搜索_中序遍历
	if (root->lchild != NULL) InOrderTraversal(root->lchild);
	if (root->data != NULL) cout << root->data;
	if (root->rchild != NULL) InOrderTraversal(root->rchild);
}

void PostOrderTraversal(BiTNode* root) {//深度优先搜索_后序遍历
	if (root->lchild != NULL) PostOrderTraversal(root->lchild);
	if (root->data != NULL) cout << root->data;
	if (root->rchild != NULL) PostOrderTraversal(root->rchild);
}

void DestroyBitTree(BiTNode* root) {
	if (root->lchild != NULL) DestroyBitTree(root->lchild);
	if (root->rchild != NULL) DestroyBitTree(root->rchild);
	if (root->data != NULL) free(root);//从子节点到父节点free
}