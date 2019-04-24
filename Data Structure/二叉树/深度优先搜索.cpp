void PreOrderTraversal(BiTNode* root) {//�����������_ǰ�����
	if (root->data != NULL) cout << root->data;
	if (root->lchild != NULL) PreOrderTraversal(root->lchild);
	if (root->rchild != NULL) PreOrderTraversal(root->rchild);
}

void InOrderTraversal(BiTNode* root) {//�����������_�������
	if (root->lchild != NULL) InOrderTraversal(root->lchild);
	if (root->data != NULL) cout << root->data;
	if (root->rchild != NULL) InOrderTraversal(root->rchild);
}

void PostOrderTraversal(BiTNode* root) {//�����������_�������
	if (root->lchild != NULL) PostOrderTraversal(root->lchild);
	if (root->data != NULL) cout << root->data;
	if (root->rchild != NULL) PostOrderTraversal(root->rchild);
}

void DestroyBitTree(BiTNode* root) {
	if (root->lchild != NULL) DestroyBitTree(root->lchild);
	if (root->rchild != NULL) DestroyBitTree(root->rchild);
	if (root->data != NULL) free(root);//���ӽڵ㵽���ڵ�free
}