
/*����˳����У���ν���������*/

#include <iostream>
#include<stack>;
using namespace std;
#define MAXSIZE 100

struct tnode   //�������ݽṹ
{
	int data;
	tnode* lchild, * rchild;
};

struct queue  //���е����ݽṹ
{
	tnode* data[MAXSIZE];
	int front, rear;
};

void creat(queue& q);   //����һ���ն���
void enqueue(queue& q, tnode* t);   //��t���
tnode* dequeue(queue& q);   //���ӣ������ض�ͷԪ��
bool isempty(queue& q);    //�ж϶����Ƿ�Ϊ��
tnode* creatbintree();    //�����˳�򴴽�һ�ö������������ظ��ڵ�
void showbintree(tnode* root);  //��α���������
class Solution1 {
public:
	int maxDepth(struct tnode* root) {
		if (root == NULL)
			return 0;
		stack<pair<struct tnode*, int>> s;
		int deep = 0, MaxDeep = 0;
		tnode* p = root;
		while (p != NULL || !s.empty()) {
			while (p) {
				s.push(pair<tnode*,int>(p, ++deep));
				p = p->lchild;
			}
			p = s.top().first;
			deep = s.top().second;
			if (deep > MaxDeep)
				MaxDeep = deep;
			s.pop();
			p = p->rchild;
		}
		return MaxDeep;
	}
};
class Solution2 {
public:
	int maxDepth(tnode* root) {
		if (root == NULL) return 0;
		deque<tnode*> q;
		q.push_back(root);
		int deep = 0;
		while (!q.empty())
		{
			deep++;
			int num = q.size();
			for (int i = 1; i <= num; i++)
			{
				tnode* p = q.front();
				q.pop_front();
				if (p->lchild) q.push_back(p->lchild);
				if (p->rchild) q.push_back(p->rchild);
			}
		}
		return deep;
	}
};

int main()
{
	tnode* root = NULL;
	root = creatbintree();
	Solution1 s1 = Solution1();
	Solution2 s2 = Solution2();
	cout << s1.maxDepth(root)<<endl;
	cout << s2.maxDepth(root) << endl;
	//showbintree(root);
	//system("pause");
	return 0;
}

void creat(queue& q)
{
	q.front = q.rear = 0;
}

void enqueue(queue& q, tnode* t)
{
	if ((q.rear + 1) % MAXSIZE == q.front)
	{
		cout << "ջ�������ܽ�ջ" << endl;
		return;
	}
	q.rear = (q.rear + 1) % MAXSIZE;
	q.data[q.rear] = t;
}

tnode* dequeue(queue& q)
{
	tnode* t;
	q.front = (q.front + 1) % MAXSIZE;
	t = q.data[q.front];
	return t;
}

bool isempty(queue& q)
{
	return (q.front == q.rear);
}

tnode* creatbintree()
{
	//1.�Ƚ����ڵ���ӣ������в�Ϊ��ʱ��ѭ��ִ�����²�����
	//2.������������ֵ����Ϊ�գ��������
	//3.������������ֵ����Ϊ�գ��������
	int a;
	tnode* root;
	queue Q;
	creat(Q);
	cout << "������ڵ�ֵ��-1��ʾ�սڵ㣺" << endl;
	cin >> a;
	if (a == -1)    //�����һ���ڵ�Ϊ�գ���ֱ�ӷ��ؿ���
		return NULL;
	else
	{
		root = new tnode;
		root->data = a;
		enqueue(Q, root);  //���ڵ����
	}
	while (!isempty(Q))   //�����в�Ϊ��
	{
		//���������ӵ�ֵ���������Һ��ӵ�ֵ
		tnode* p = dequeue(Q);
		cin >> a;
		if (a == -1)   //����Ϊ��
			p->lchild = NULL;
		else
		{
			p->lchild = new tnode;
			p->lchild->data = a;
			enqueue(Q, p->lchild);  //�������
		}
		cin >> a;
		if (a == -1)   //�Һ���Ϊ��
			p->rchild = NULL;
		else
		{
			p->rchild = new tnode;
			p->rchild->data = a;
			enqueue(Q, p->rchild);   //�Һ������
		}

	}
	return root;
}

void showbintree(tnode* root)
{
	//1.�Ƚ����ڵ���ӣ������в�Ϊ��ʱ��ѭ��ִ�����²�����
	//2.����һ��Ԫ�أ�������
	//3.����������Ϊ�գ��������
	//4.����������Ϊ�գ��������
	queue Q;
	tnode* p;
	creat(Q);
	if (root == NULL)
		return;
	enqueue(Q, root);
	while (!isempty(Q))
	{
		p = dequeue(Q);
		cout << p->data << ' ';
		if (p->lchild)
			enqueue(Q, p->lchild);
		if (p->rchild)
			enqueue(Q, p->rchild);
	}
	cout << endl;
}