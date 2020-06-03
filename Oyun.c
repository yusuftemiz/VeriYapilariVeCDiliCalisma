#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

srand(time(NULL));

int s[4];
int t[4];

for(int sayac1=0; sayac1<10; sayac1++){
	printf("\nYENI OYUN!! Yeni sayi uretildi.\n");
	for(int sayac2=0; sayac2<10; sayac2++){
		int rastgele=rand()%10000;     
		s[0]=(rastgele/1000);
		s[1]=(rastgele/100)%10;    
		s[2]=(rastgele/10)%10;     
		s[3]=rastgele%10;     
		if(s[0]!=s[1] && s[0]!=s[2] && s[0]!=s[3] && s[1]!=s[2] && s[1]!=s[3] && s[2]!=s[3]){
				break;
        }
    }
    
	int toplameksi=0;
   	int toplamarti=0;
    for(int sayac3=1;sayac3<11;sayac3++){
    	int tahmin;
        printf("\n%d.Tahmininizi giriniz=",sayac3);
     	scanf("%d",&tahmin);     
		
		t[0]=tahmin/1000;                           
		t[1]=(tahmin/100)%10;    
		t[2]=(tahmin/10)%10;     
		t[3]=tahmin%10;     
			
		int eksi=0;
		int arti=0;
		for (int sayac4=0;sayac4<4;sayac4++){
			if(s[sayac4]==t[sayac4]){
				arti+=1;
			}
			else{
				for(int sayac5=0;sayac5<4;sayac5++){
					if(sayac4!=sayac5){
						if(s[sayac4]==t[sayac5]){
							eksi -=1;
						}
					}
				}
			}
		}
			
		printf("%d , +%d",eksi, arti);
		toplameksi += eksi;
		toplamarti += arti;

		if(s[0]==t[0] && s[1]==t[1] && s[2]==t[2] && s[3]==t[3]){
			printf("\n\nSayiyi buldunuz.");                                                  
			printf("\n\nSayi %d%d%d%d",s[0],s[1],s[2],s[3]);
			printf("\n\nSayiyi %d tahminde buldunuz",sayac3);
			int puan=((10*toplamarti)+(5*toplameksi)+((1/sayac3)*1000)-((toplamarti*toplameksi)/(toplamarti+toplameksi)));
			printf("\n\nPuaniniz:%d\n\n\n",puan);
			break;
		}
			
		if(sayac3>9){
			printf("\n\nSayiyi bulamadiniz.");
			printf("\n\nSayi %d%d%d%d\n\n\n",s[0],s[1],s[2],s[3]);
			break;
		}		
	}
}
return 0;
}

