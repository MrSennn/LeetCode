#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<deque>
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

int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	int maxl = maxDepth(root->left);
	int maxr = maxDepth(root->right);
	return (maxl>maxr ? maxl:maxr)+ 1;
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
//	Print(p);
	printf("%d", maxDepth(p));
}



//C++�汾 
//������ȣ��ݹ��
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l=maxDepth(root->left)+1;
        int r=maxDepth(root->right)+1;
        return l>r?l:r;   
    }
};
//������ȣ���ջ��ѭ����
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        stack<pair<TreeNode*,int>> s;
        TreeNode* p=root;
        int Maxdeep=0;
        int deep=0;
        while(!s.empty()||p!=NULL)//��ջ�ǿգ���˵������һЩ�ڵ����������δ̽������p�ǿգ���ζ�Ż���һЩ�ڵ����������δ̽��
        {
            while(p!=NULL)//�����������
            {
                s.push(pair<TreeNode*,int>(p,++deep));
                p=p->left;
            }
            p=s.top().first;//�������·����Ԥ���ҹա��ҹ�֮ǰ����¼�ҹյ�Ļ�����Ϣ
            deep=s.top().second;
            if(Maxdeep<deep) Maxdeep=deep;//Ԥ���ҹ�ʱ���Ƚϵ�ǰ�ڵ���Ⱥ�֮ǰ�洢��������
            s.pop();//���ҹյ��ջ����ʱջ��Ϊ�ҹյ��ǰһ����㡣���ҹյ��������ȫ��������󣬻�Ԥ��������ڵ��ҹ�
            p=p->right;
        }
        return Maxdeep;
    }
};
//������ȣ�ʹ�ö���
class Solution3 {
public:
    int maxDepth(TreeNode* root) {
         if(root==NULL) return 0;
         deque<TreeNode*> q;
         q.push_back(root);
         int deep=0;
         while(!q.empty())
         {
             deep++;
             int num=q.size();
             for(int i=1;i<=num;i++)
             {
                TreeNode* p=q.front();
                q.pop_front();
                if(p->left) q.push_back(p->left);
                if(p->right) q.push_back(p->right);
             }
         }
         return deep;         
    }
};

