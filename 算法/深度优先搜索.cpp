#include<algorithm>
#include <iostream>
using namespace std;

typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild; /* 左右子指針 */
}BiTNode, *BiTree;

typedef int Status;
Status initBiTree(BiTree *T) {
	*T = NULL;
	return true;
}

void CreateBiTree(BiTree *T) {
	TElemType ch; cin >> ch;
	if (ch == '.') *T = NULL;//输入.表示空节点
	else {
		*T = (BiTree)malloc(sizeof(BiTNode)); /* 生成根結點 */
		if (!*T) exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild); /* 構造左子樹 */
		CreateBiTree(&(*T)->rchild); /* 構造右子樹 */
	}
}

void DestroyBitTree(BiTNode* root) {
	if (root->lchild != NULL) DestroyBitTree(root->lchild);
	if (root->rchild != NULL) DestroyBitTree(root->rchild);
	if (root->data != NULL) free(root);//从子节点到父节点free
}

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