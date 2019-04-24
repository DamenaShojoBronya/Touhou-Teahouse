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

int main()
{
	BiTree T;
	initBiTree(&T);
	CreateBiTree(&T);
	DestroyBitTree(&T);

	return 0;
}