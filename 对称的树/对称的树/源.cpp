#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct queue {//����
	TreeNode* data[MaxSize];
	int front, rear;//��¼������   ��һ��Ԫ��ǰһ����λ��  ��  ���һ��Ԫ�ص�λ��
};

void creat(queue* q) {//��������
	(*q).front = (*q).rear = 0;
}

void enqueue(queue* q, TreeNode* t) {//���
	if (((*q).rear + 1) % MaxSize == 0) {
		printf("��������");
		return;
	}
	else {
		(*q).rear = ((*q).rear + 1) % MaxSize;
		(*q).data[(*q).rear] = t;
	}
}
TreeNode* dequeue(queue* q) {//����
	TreeNode* t;
	(*q).front = ((*q).front + 1) % MaxSize;
	t = (*q).data[(*q).front];
	return t;
}

bool isEmpty(queue q) {//�ж��Ƿ�Ϊ��
	return q.front == q.rear;
}
TreeNode* creatTree() {
	int a;
	TreeNode* root;
	queue q;
	creat(&q);
	scanf("%d", &a);
	if (a == -1)//���ؿ���
		return NULL;
	else {
		root = (TreeNode*)malloc(sizeof(struct TreeNode));//������
		root->val = a;
		root->left = root->right = NULL;
		enqueue(&q, root);
	}
	while (!isEmpty(q)) {//������в���
		TreeNode* p = dequeue(&q);//����
		scanf("%d", &a);
		if (a == -1) {//������Ϊ��
			p->left = NULL;
		}
		else {
			p->left = (TreeNode*)malloc(sizeof(struct TreeNode));//��������������� 
			p->left->val = a;
			enqueue(&q, p->left);
		}

		scanf("%d", &a);
		if (a == -1) {//������Ϊ��
			p->right = NULL;
		}
		else {
			p->right = (TreeNode*)malloc(sizeof(struct TreeNode));//��������������� 
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
