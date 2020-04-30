#include <stdio.h>

int main() {
	int n;//定义n个整数
	scanf("%d", &n);
	int a[n];//存数
	int b[n];//存不重复的数
	int c[n];//给重复的数添加标记 
	int i; 
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[i] = 0; 
	}
	//给a数组中数字排序
	int j;
	int temp;//作为转换使用 
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				 temp = a[i];
				 a[i] = a[j];
				 a[j] = temp; 
			}
		}
	} 
	b[0] = a[0];//把a[0]赋值给b[0] 
	int len = 0;
	for (i = 1; i < n; i++) {
		if (a[i] != b[len]) {
			b[++len] = a[i];
		} else {
			c[len] = 1;
		}
	}
	for (i = 0; i <= len; i++) {
		for (j = 0; j <= len; j++) {
			if (i != j) {
				printf("(%d,%d)\n", b[i], b[j]);
			} else if (c[i]) {
				printf("(%d,%d)\n", b[i], b[i]);
			}
		}
	}
	
	return 0;
} 
