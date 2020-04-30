#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct string {
	char ch[MAX_SIZE + 1];//1给'\0' 
	int length;
} String;

//串的赋值
int StringAssign(String *s, char chs[]) {
	int flag = 1;
	if (!s) {
		flag = 0;//s为空，错误 
	} else {
		int i = 0;
		while (chs[i] != '\0') {
			if (i < MAX_SIZE) {
				s->ch[i] = chs[i];
				i++;
			} else {
				flag = 0;
			}	
		}
		s->length = i;
		s->ch[i] = '\0';
	} 	
	return flag;
} 

//串的复制：将s1复制到s 
int StringCopy(String *s, String *s1) {
	int i = 0;
	for (i = 0; i < s1->length; i++) {
		s->ch[i] = s1->ch[i]; 
	} 
	s->length = s1->length;//复制长度 
	s->ch[i] = '\0'; 
	return s->length;
} 

//串的长度
 int StringLength(String *s) {
 	return s->length;
 } 
//打印串
int PrintString(String *s) {
	if (s->length == 0) {
		printf("当前串为空！\n");
		return 0;
	}
	int i;
	for (i = 0; i < s->length; i++) {
		printf("%c", s->ch[i]);
	}
	printf("\n");
	return 0;
} 

//测试
int main() {
	String s;
	char ch[] = "Hello, String";
	//char ch[MAX _SIZE + 1];
	//gets(ch);
	//测试赋值 
	if (StringAssign(&s, ch)) {
		printf("赋值成功：");
		puts(s.ch);
	}
	//给串t赋值
	String t;
	char ch2[] = "test string copy";
	StringAssign(&t, ch2);
	//测试复制
	if (StringCopy(&s, &t)) {
		printf("复制成功：");
		puts(s.ch);
	}
	//测试串长
	printf("s串长为：%d\n",StringLength(&s)); 
	//测试打印串
	PrintString(&s); 
	return 0;
} 
