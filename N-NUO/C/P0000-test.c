/*���������
��Ŀ��
����һ���������������������ӡ�
����
���룺60
�����2 3 4 5 6
ע�⣺1��������*/ 
#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);//����һ������N��N<=10000��
	int factorMax = 0;
	int i, j, index;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			int cnt = 1;
			for (j = i + 1; j < n; j++) {
				if (n % j == 0) {
					cnt++;
				} else {
					break;
				}
			}
			if (cnt > factorMax) {
				index = i;
				factorMax = cnt;
			}
		}
	}
	for (i = index; i < index + factorMax; i++) {
		printf("%d ", i);
	}
	 
	return 0;
}
