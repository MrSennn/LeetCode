#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int* date;
	int top;
} MinStack;
#define MaxSize 800
MinStack* helper;//构造辅助栈
MinStack* minStackCreate() {//构造两个栈
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
		obj->top++;//入栈
		obj->date[obj->top] = x;
		if (helper->top == -1) {//入辅助栈
			helper->top++;
			helper->date[helper->top] = x;
		}
		else {
			if (helper->date[helper->top] < x) {//如果入的值x比辅助栈的栈顶值小，则入x，否则入栈顶元素值
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

void minStackPop(MinStack* obj) {//出栈，两个栈都要出栈
	if (obj->top == -1) {
		
	}
	else {
		obj->top--;
		helper->top--;
	}
}

int minStackTop(MinStack* obj) {//栈顶元素值
	if (obj->top == -1) {
		return -1;
	}
	else {
		return obj->date[obj->top];
	}
}

int minStackGetMin(MinStack* obj) {//找栈中的最小元素，即辅助栈的栈顶元素
	if (obj->top == -1) {
		return -1;
	}
	else {
		return helper->date[helper->top];
	}
}

void minStackFree(MinStack* obj) {//free空间
	free(obj->date);
	obj->date = NULL;
	free(obj);
	obj = NULL;
	free(helper->date);
	helper->date = NULL;
	free(helper);
	helper = NULL;
}
int main() {//测试
	MinStack* obj = minStackCreate();
	minStackPush(obj, 1);
	minStackPush(obj, 0);
	minStackPush(obj, 3);
	minStackPop(obj);
	printf("%d", minStackGetMin(obj));
	printf("%d", minStackTop(obj));
	minStackFree(obj);
}
