/*最长连续因子
题目：
输入一个整数，输出其最长连续因子。
例如
输入：60
输出：2 3 4 5 6
注意：1不算因子*/ 
#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);//输入一个整数N，N<=10000。
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
