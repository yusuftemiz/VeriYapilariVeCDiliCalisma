#include<stdio.h>
//girdileri sirali sekilde yazdirir..

int heap[100], heapSize;

void Init() {
    heapSize=0;
	heap[0]=-10000;
}

void Insert(int element) {
    heapSize++;
    heap[heapSize] = element; 
    
    int now = heapSize;
    while (heap[now / 2] > element) {
        heap[now] = heap[now / 2];
        now /= 2;
}
heap[now]=element;
}
int MinHeapfy() {
	
    int minElement, lastElement, child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    
    for (now = 1; now * 2 <= heapSize; now = child) {
    	
        child = now * 2;
        
        
        if (child != heapSize && heap[child + 1] < heap[child]) {
            child++;
        }
        
        if (lastElement > heap[child]) {
            heap[now] = heap[child];
        } else 
        {
            break;
        }
    }
    heap[now] = lastElement;
	return minElement;
}
int main(){
	int number_of_elements;
    printf("Program to demonstrate Heap.\nListenin eleman sayisini gir:");
    scanf("%d", &number_of_elements);
    int iter, element;
    Init();
    
    for (iter = 0; iter < number_of_elements; iter++) {
        printf("%d.eleman: ",iter+1);
		scanf("%d", &element);
        Insert(element);
    }
    for (iter = 0; iter < number_of_elements; iter++) {
        printf("%d ",MinHeapfy());
    }
    printf("\n");
    return 0;
}
