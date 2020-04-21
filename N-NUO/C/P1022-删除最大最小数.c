/*
题目：删除最大最小数*/ 

#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);//输入n个整数
	int a[n];
	int i, min = 0, max = n - 1;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	} 
	for (i = 0; i < n; i++) {
		if (a[min] > a[i]) {
			min = i;
		}
		if (a[max] < a[i]) {
			max = i;
		}
	} 
	int flag = 0;
	for (i = 0; i < n; i++) {
		if (i != max && i != min) {
			if (flag) {
				printf(" %d", a[i]);
			} else {
				printf("%d", a[i]);
			}
			flag = 1;	
		}
	}
	printf("\n");
	return 0;
}
