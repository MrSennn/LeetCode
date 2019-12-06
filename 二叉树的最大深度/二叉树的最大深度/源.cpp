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



//C++版本 
//深度优先：递归版
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l=maxDepth(root->left)+1;
        int r=maxDepth(root->right)+1;
        return l>r?l:r;   
    }
};
//深度优先：用栈的循环版
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        stack<pair<TreeNode*,int>> s;
        TreeNode* p=root;
        int Maxdeep=0;
        int deep=0;
        while(!s.empty()||p!=NULL)//若栈非空，则说明还有一些节点的右子树尚未探索；若p非空，意味着还有一些节点的左子树尚未探索
        {
            while(p!=NULL)//优先往左边走
            {
                s.push(pair<TreeNode*,int>(p,++deep));
                p=p->left;
            }
            p=s.top().first;//若左边无路，就预备右拐。右拐之前，记录右拐点的基本信息
            deep=s.top().second;
            if(Maxdeep<deep) Maxdeep=deep;//预备右拐时，比较当前节点深度和之前存储的最大深度
            s.pop();//将右拐点出栈；此时栈顶为右拐点的前一个结点。在右拐点的右子树全被遍历完后，会预备在这个节点右拐
            p=p->right;
        }
        return Maxdeep;
    }
};
//广度优先：使用队列
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

