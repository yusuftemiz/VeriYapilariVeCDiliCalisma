#include <stdio.h>
//4 secenekli liste editoru.. ekleme cikarma listeleme yapar.

int array[100], n;
void display(int n)
{
    int i;
    if (n == 0)
    {
        printf("Heap bos \n ");
        return;
    }
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
void insert(int num, int location)
{
    int parentnode;
    while (location > 0)
    {
        parentnode =(location-1)/2;
        if (num <= array[parentnode])
        {
            array[location] = num;
            return;
        }
        array[location] = array[parentnode];
        location = parentnode;
    } 
    array[0] = num;  
	}
void delet(int num)
{
int left, right, i, temp, parentnode;
    for (i = 0; i < num; i++) {
        if (num == array[i])
            break;
    }
    if (num != array[i])
    {
        printf("%d sayisi heap listesinde yok\n", num);
        return;
    }
    array[i] = array[n - 1];
    n = n - 1;
    parentnode =(i-1) / 2; 
    if (array[i] > array[parentnode])
    {
        insert(array[i], i);
        return;
    }
    left = 2 * i + 1; 
    right = 2 * i + 2;
    while (right < n)
    {
        if (array[i] >= array[left] && array[i] >= array[right])
            return;
        if (array[right] <= array[left])
        {
            temp = array[i];
            array[i] = array[left];
            array[left] = temp;
            i = left;
        }
        else
        {
            temp = array[i];
            array[i] = array[right];
            array[right] = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    if (left == n - 1 && array[i])    {
        temp = array[i];
        array[i] = array[left];
        array[left] = temp;
    }
}

int main()
{
    int choice, num,m;
    n = 0; 
    int kosul = 1;
    while(kosul)
    {
        printf("1.Listeye eleman ekler \n");
        printf("2.Listeden eleman siler \n");
        printf("3.Listeyi gösterir \n");
        printf("4.Programdan cikar \n");
        printf("1-4 arasinda seciminizi yapin : ");
        scanf("%d", &choice);
      
	  	switch(choice){
        case 1:
            printf("Listeye eklenecek eleman sayisini gir : ");
            scanf("%d",&m);
			for ( int i=0; i < m ; i++){
        		printf("%d. elemanini gir:" , i+1 );
        		scanf( "%d" , &num );
        		insert(num,n);
        		n=n+1;
            }
		    break;
        case 2:
            printf("Listeden silinecek elamani gir: ");
            scanf("%d", &num);
            delet(num);
            break;
        case 3:
            display(n);
            break;
        case 4:
        	kosul = 0;
        	break;
        default:
            printf("Yalnis Secim \n");
    }
  }
}

