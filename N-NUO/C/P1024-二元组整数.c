#include <stdio.h>

int main() {
	int n;//����n������
	scanf("%d", &n);
	int a[n];//����
	int b[n];//�治�ظ�����
	int c[n];//���ظ�������ӱ�� 
	int i; 
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[i] = 0; 
	}
	//��a��������������
	int j;
	int temp;//��Ϊת��ʹ�� 
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				 temp = a[i];
				 a[i] = a[j];
				 a[j] = temp; 
			}
		}
	} 
	b[0] = a[0];//��a[0]��ֵ��b[0] 
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
