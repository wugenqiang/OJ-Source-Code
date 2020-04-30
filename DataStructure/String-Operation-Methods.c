#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct string {
	char ch[MAX_SIZE + 1];//1��'\0' 
	int length;
} String;

//���ĸ�ֵ
int StringAssign(String *s, char chs[]) {
	int flag = 1;
	if (!s) {
		flag = 0;//sΪ�գ����� 
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

//���ĸ��ƣ���s1���Ƶ�s 
int StringCopy(String *s, String *s1) {
	int i = 0;
	for (i = 0; i < s1->length; i++) {
		s->ch[i] = s1->ch[i]; 
	} 
	s->length = s1->length;//���Ƴ��� 
	s->ch[i] = '\0'; 
	return s->length;
} 

//���ĳ���
 int StringLength(String *s) {
 	return s->length;
 } 
//��ӡ��
int PrintString(String *s) {
	if (s->length == 0) {
		printf("��ǰ��Ϊ�գ�\n");
		return 0;
	}
	int i;
	for (i = 0; i < s->length; i++) {
		printf("%c", s->ch[i]);
	}
	printf("\n");
	return 0;
} 

//����
int main() {
	String s;
	char ch[] = "Hello, String";
	//char ch[MAX _SIZE + 1];
	//gets(ch);
	//���Ը�ֵ 
	if (StringAssign(&s, ch)) {
		printf("��ֵ�ɹ���");
		puts(s.ch);
	}
	//����t��ֵ
	String t;
	char ch2[] = "test string copy";
	StringAssign(&t, ch2);
	//���Ը���
	if (StringCopy(&s, &t)) {
		printf("���Ƴɹ���");
		puts(s.ch);
	}
	//���Դ���
	printf("s����Ϊ��%d\n",StringLength(&s)); 
	//���Դ�ӡ��
	PrintString(&s); 
	return 0;
} 
