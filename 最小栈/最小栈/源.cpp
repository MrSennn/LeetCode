#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int* date;
	int top;
} MinStack;
#define MaxSize 800
MinStack* helper;//���츨��ջ
MinStack* minStackCreate() {//��������ջ
	MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
	helper = (MinStack*)malloc(sizeof(MinStack));
	stack->date = (int*)malloc(sizeof(int) * MaxSize);
	stack->top = -1;
	helper->top = -1;
	helper->date = (int*)malloc(sizeof(int) * MaxSize);
	return stack;
}

void minStackPush(MinStack* obj, int x) {
	if (obj->top == MaxSize - 1) {
		
	}
	else {
		obj->top++;//��ջ
		obj->date[obj->top] = x;
		if (helper->top == -1) {//�븨��ջ
			helper->top++;
			helper->date[helper->top] = x;
		}
		else {
			if (helper->date[helper->top] < x) {//������ֵx�ȸ���ջ��ջ��ֵС������x��������ջ��Ԫ��ֵ
				int temp = helper->date[helper->top];
				helper->top++;
				helper->date[helper->top] = temp;
			}
			else {
				helper->top++;
				helper->date[helper->top] = x;
			}
		}

	}
}

void minStackPop(MinStack* obj) {//��ջ������ջ��Ҫ��ջ
	if (obj->top == -1) {
		
	}
	else {
		obj->top--;
		helper->top--;
	}
}

int minStackTop(MinStack* obj) {//ջ��Ԫ��ֵ
	if (obj->top == -1) {
		return -1;
	}
	else {
		return obj->date[obj->top];
	}
}

int minStackGetMin(MinStack* obj) {//��ջ�е���СԪ�أ�������ջ��ջ��Ԫ��
	if (obj->top == -1) {
		return -1;
	}
	else {
		return helper->date[helper->top];
	}
}

void minStackFree(MinStack* obj) {//free�ռ�
	free(obj->date);
	obj->date = NULL;
	free(obj);
	obj = NULL;
	free(helper->date);
	helper->date = NULL;
	free(helper);
	helper = NULL;
}
int main() {//����
	MinStack* obj = minStackCreate();
	minStackPush(obj, 1);
	minStackPush(obj, 0);
	minStackPush(obj, 3);
	minStackPop(obj);
	printf("%d", minStackGetMin(obj));
	printf("%d", minStackTop(obj));
	minStackFree(obj);
}
