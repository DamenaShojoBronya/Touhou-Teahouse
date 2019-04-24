#include<algorithm>
#include <iostream>
using namespace std;

typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild; /* ������ָ� */
}BiTNode, *BiTree;

typedef int Status;
Status initBiTree(BiTree *T) {
	*T = NULL;
	return true;
}

void CreateBiTree(BiTree *T) {
	TElemType ch; cin >> ch;
	if (ch == '.') *T = NULL;//����.��ʾ�սڵ�
	else {
		*T = (BiTree)malloc(sizeof(BiTNode)); /* ���ɸ��Y�c */
		if (!*T) exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild); /* �������Ә� */
		CreateBiTree(&(*T)->rchild); /* �������Ә� */
	}
}

void DestroyBitTree(BiTNode* root) {
	if (root->lchild != NULL) DestroyBitTree(root->lchild);
	if (root->rchild != NULL) DestroyBitTree(root->rchild);
	if (root->data != NULL) free(root);//���ӽڵ㵽���ڵ�free
}

int leafNode(BiTNode* root) {//Ҷ�ӽڵ�
	static int count = 0;
	if (root != NULL) {
		if (root->lchild != NULL) leafNode(root->lchild);
		if (root->rchild != NULL) leafNode(root->rchild);
		if (root->lchild == NULL&&root->rchild == NULL) count++;
	}
	return count;
}

int depth(BiTNode* root) {//���
	int deep = 0;//�ݹ�ص����ڵ㣬������һ����·��
	if (root != NULL) {
		int left = depth(root->lchild);
		int right = depth(root->rchild);
		deep = max(left, right) + 1;
	}
	return deep;
}


int main()
{
	BiTree T;
	initBiTree(&T);
	CreateBiTree(&T);
	cout << endl << "leaf= " << leafNode(T);
	cout << endl << "depth= " << depth(T);
	DestroyBitTree(T);

	return 0;
}