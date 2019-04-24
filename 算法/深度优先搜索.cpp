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
	if (root->rchild != NULL) PostOrderTraversal(root->rchild);
	if (root->data != NULL) cout << root->data;
}

int main()
{
	BiTree T;
	initBiTree(&T);
	CreateBiTree(&T);
	cout << endl << "Pre: ";
	PreOrderTraversal(T);
	cout << endl << "In: ";
	InOrderTraversal(T);
	cout << endl << "Post: ";
	PostOrderTraversal(T);
	DestroyBitTree(T);

	return 0;
}