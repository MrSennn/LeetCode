#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct queue {//队列
	TreeNode* data[MaxSize];
	int front, rear;//记录队列中   第一个元素前一个的位置  和  最后一个元素的位置
};

void creat(queue* q) {//创建队列
	(*q).front = (*q).rear = 0;
}

void enqueue(queue* q, TreeNode* t) {//入队
	if (((*q).rear + 1) % MaxSize == 0) {
		printf("队列已满");
		return;
	}
	else {
		(*q).rear = ((*q).rear + 1) % MaxSize;
		(*q).data[(*q).rear] = t;
	}
}
TreeNode* dequeue(queue* q) {//出队
	TreeNode* t;
	(*q).front = ((*q).front + 1) % MaxSize;
	t = (*q).data[(*q).front];
	return t;
}

bool isEmpty(queue q) {//判定是否为空
	return q.front == q.rear;
}
TreeNode* creatTree() {
	int a;
	TreeNode* root;
	queue q;
	creat(&q);
	scanf("%d", &a);
	if (a == -1)//返回空树
		return NULL;
	else {
		root = (TreeNode*)malloc(sizeof(struct TreeNode));//建立树
		root->val = a;
		root->left = root->right = NULL;
		enqueue(&q, root);
	}
	while (!isEmpty(q)) {//如果队列不空
		TreeNode* p = dequeue(&q);//出队
		scanf("%d", &a);
		if (a == -1) {//左子树为空
			p->left = NULL;
		}
		else {
			p->left = (TreeNode*)malloc(sizeof(struct TreeNode));//建立左子树并入队 
			p->left->val = a;
			enqueue(&q, p->left);
		}

		scanf("%d", &a);
		if (a == -1) {//右子树为空
			p->right = NULL;
		}
		else {
			p->right = (TreeNode*)malloc(sizeof(struct TreeNode));//建立右子树并入队 
			p->right->val = a;
			enqueue(&q, p->right);
		}
	}
	return root;
}

bool isMirror(struct TreeNode* p,struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val != q->val)
		return false;
	return isMirror(p->left, q->right) && isMirror(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root) {
	return isMirror(root, root);
}

void Print(TreeNode* p) {
	if (p) {
		Print(p->left);
		printf("%d ", p->val);
		Print(p->right);
	}
}
int main() {
	TreeNode* p = creatTree();
	Print(p);
	if (isSymmetric(p)) {
		printf("true");
	}
	else {
		printf("false");
	}
}
