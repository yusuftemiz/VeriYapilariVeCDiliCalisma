#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//rastgele dizi olusturup otomatik siralama,en kucuk en buyuk elemanlari ve ortalamayi belirleme..

int main(){
    srand(time(NULL));
    int dizi[20];
    
    printf("%s","Dizi:\n");
    int i;
    for(i=0; i<20; i++){
        dizi[i] = 1 + rand()%19;
        printf("%d ",dizi[i]);
    }

    int gecici,j;
    for (i=0; i<(20-1); i++){
        for (j=0; j<20-i-1; j++){
            if (dizi[j]>dizi[j+1]){
                gecici = dizi[j]; 
                dizi[j] = dizi[j+1];
                dizi[j+1] = gecici;
            }
        }
    }

    printf("\n\nKucukten buyuge siralama:\n");    
    for(i=0; i<20; i++){
        printf("%d ",dizi[i]);
    }
    printf("%s%d ","\n\nDizinin en kucuk elemani: ",dizi[0]);
    printf("%s%d ","\n\nDizinin en buyuk elemani: ",dizi[19]);

    int toplam = 0;
    for(i=0; i<20; i++){
     toplam += dizi[i];
	}
    printf("%s%f","\n\nDizi ortalamasi:\n",toplam/20.0);
    
return 0;
}
