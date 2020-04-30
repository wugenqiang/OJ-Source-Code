#include<stdio.h>
#include<stdlib.h>
#define MinData -1//�ڱ�Ԫ�ص�ֵ
typedef struct MinHeap{
    int *data;//��ʾ�ѵ����� ��СҪ���û������Ԫ�ظ�����+1
    int Size;//���������е�Ԫ��(������a[0]) 
    int Capacity; //�������������
}heap;//���嶥��

//������ 
heap* init(int size){
    heap* h = (heap*)malloc(sizeof(heap));
    h->data = (int*)malloc(sizeof(int)*(size+1));//��a[1]��ʼ������ ������������Ҫ+1
    h->Size = 0;
    h->Capacity = size;
    h->data[0] = MinData;//����
    return h;
}
//����Ԫ�� 
int insert(heap* h, int x){
    //�ж��Ƿ�����
    if (h->Size == h->Capacity) {
        return 0;
    }
    int i = ++h->Size;
    for (; i >= 1; i/=2) {
		if (h->data[i/2] > x) {
			h->data[i] = h->data[i/2];
		} else {
			break;
		}  
    }
    h->data[i] = x;
    return 1;
}
//ɾ����СԪ�� 
int deleteMin(heap* h){
    int top = h->data[1];
    int last = h->data[h->Size];
    h->Size--;
    int i,child;
    for (i = 1; i * 2 <= h->Size; i = child) {
        child = i*2;
            //ע�������Ǵ������ӽڵ� ���� ���ӽڵ�����ӽڵ�С    
        if (child!=h->Size && h->data[child] > h->data[child+1]) {
            child++;
    	}
		//��������ӽڵ㻹С
        if (h->data[child]>last) {
            break;
        }else{//����
            h->data[i] = h->data[child];
        }
    
    }
    h->data[i] = last;
    return top;
}

//������
void heap_sort(int a[], int n) {
    int i;
    heap* h = init(n);//��ʼ����
    for (i = 0; i < n; i++) {//�������Ԫ�����β����
        insert(h, a[i]);
    }
    for (i = 0; i < n; i++) {
        a[i] = deleteMin(h);
    }
}
//��������
void traverse_array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

//���������� 
int main() {
    int a[] = {10,7,2,5,1};
    int n = sizeof(a) / sizeof(int);
    traverse_array(a, n);
    heap_sort(a, n);
    traverse_array(a, n);
}
