/*
��Ŀ����������д��A+Bi����ʽ������A��ʵ����B���鲿��
�Ӽ��������������������ӷ���˷�����������*/ 

#include <stdio.h>
int main() {
	double a1, b1, a2, b2;
	double res1, res2;
	char c;//����+*
	scanf("%lf %lf %lf %lf %c", &a1, &b1, &a2, &b2, &c);
	switch(c) {
		case '+':
			res1 = a1 + a2;
			res2 = b1 + b2;
			break;
		case '*':
			res1 = a1 * a2 - b1 * b2;
			res2 = a1 * b2 + b1 * a2;
			break;				
	} 
	printf("%.1lf %.1lf\n", res1, res2);
	return 0;
}
