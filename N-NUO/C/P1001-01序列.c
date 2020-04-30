#include <stdio.h>

int main(){
	int i,temp,j;
	int a[6];
	for(i=0;i<64;i++){
		temp = i;
		for(j=0;j<6;j++){
			a[j] = temp%2;
			temp /= 2;
		}
		for(j=5;j>=0;j--){
			printf("%d",a[j]);
		}
		printf("\n");
	}
	return 0;
} 
