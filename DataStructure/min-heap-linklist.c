#include<stdio.h>
#include<stdlib.h>
#define MinData -1//哨兵元素的值
typedef struct MinHeap{
    int *data;//表示堆的数组 大小要在用户输入的元素个数上+1
    int Size;//数组里已有的元素(不包含a[0]) 
    int Capacity; //数组的数量上限
}heap;//定义顶堆

//创建堆 
heap* init(int size){
    heap* h = (heap*)malloc(sizeof(heap));
    h->data = (int*)malloc(sizeof(int)*(size+1));//从a[1]开始保存数 所以数组数量要+1
    h->Size = 0;
    h->Capacity = size;
    h->data[0] = MinData;//岗哨
    return h;
}
//插入元素 
int insert(heap* h, int x){
    //判断是否满了
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
//删除最小元素 
int deleteMin(heap* h){
    int top = h->data[1];
    int last = h->data[h->Size];
    h->Size--;
    int i,child;
    for (i = 1; i * 2 <= h->Size; i = child) {
        child = i*2;
            //注意这里是存在右子节点 并且 右子节点比左子节点小    
        if (child!=h->Size && h->data[child] > h->data[child+1]) {
            child++;
    	}
		//如果比右子节点还小
        if (h->data[child]>last) {
            break;
        }else{//下滤
            h->data[i] = h->data[child];
        }
    
    }
    h->data[i] = last;
    return top;
}

//堆排序
void heap_sort(int a[], int n) {
    int i;
    heap* h = init(n);//初始化堆
    for (i = 0; i < n; i++) {//将数组的元素依次插入堆
        insert(h, a[i]);
    }
    for (i = 0; i < n; i++) {
        a[i] = deleteMin(h);
    }
}
//遍历数组
void traverse_array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

//主函数测试 
int main() {
    int a[] = {10,7,2,5,1};
    int n = sizeof(a) / sizeof(int);
    traverse_array(a, n);
    heap_sort(a, n);
    traverse_array(a, n);
}
