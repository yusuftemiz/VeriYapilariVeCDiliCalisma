//Samet Karavaizo�lu 16060017
//news: sil fonksiyonu her sil(x) eleman�n� siliyor.
//news: sil fonksiyonu ilk eleman root ise rootu siliyor sonraki ayn� eleman olanlar� da siliyor.

#include <stdio.h>
#include <stdlib.h>


struct n {
	int x;
	n* next;
};
 
typedef n node;
void bastir(node*r){
	node*iter=r;
	printf("%d\n",r->x);//�teri ilerletiyoruz. Aksi halde While �n i�ine girmez
	iter=iter->next;
	while(iter!=r){
		printf("%d\n",iter->x);
		iter=iter->next;
	}
	printf("\n");
}

node* ekle(node*r,int x){
	node*iter=r;//iter root tan ba�lat�ld�
	while(iter->next!=r){
		iter=iter->next;}
		iter->next=(node*)malloc(sizeof(node));		
		iter->next->x=x;
		iter->next->next=r;
		return r;
	
}

node* ekleSirali(node*r,int x){
	if (r==NULL){//Linl list bo� ise
	r=(node*)malloc(sizeof(node));
	r->next=r;//dairesel yap�ld�
	r->x=x;
	return r;
	}
	if(r->x>x){//ilk elemandan kucuk o halde root de�i�meli
	node*temp=(node*)malloc(sizeof(node));
	temp->x=x;
	temp->next=r;
	node*iter=r;//iter root tan ba�lad�
	while(iter->next!=r)
	iter=iter->next;
	iter->next=temp;//yeni root ba�lant�s� yap�ld�. Circle yap� tamamland�
	return temp;
	}
	node*iter=r;//araya ekleme durumu
	while(iter->next!=r && iter->next->x<x){
		iter=iter->next;
	}
	node*temp=(node*)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->x=x;
	return r;
}
node*sil(node*r,int x){
	node*temp;
	node*iter=r;
	if(r->x==x){
		while(iter->next!=r){
			if(iter->next->x == x){
            temp=iter->next; 
            iter->next=iter->next->next;
            free(temp); 
            continue; 
        }
			iter=iter->next;}
			iter->next=r->next;
			free(r);
			return iter->next;//root silindi�i i�in yeni root ba�l.yap�ld�
	}
				while(iter->next!=r){
					if(iter->next->x == x){ // bir sonraki eleman�n x i arad���m�z say� ise
            temp=iter->next; // de�eri ge�iciye al
            iter->next=iter->next->next; // bir sonraki elemanla bir sonrakinin sonraki elaman�n� e�le�tir
            free(temp); //tempi ram den sil
            continue; // alt k�sma ge�meden d�ng�ye d�n
            
        }	
		iter=iter->next;}	
			if(iter->next==r){
		  	printf("sayi bulunamadi\n");
		  	return r;
		  	}
	//if(r->x==x){
		temp=iter->next;
		iter->next=iter->next->next;
		free(temp);
		//continue;
		//}
	return r;

}
int main()
{
	node* root;
	root=NULL;
	root=ekleSirali(root,4);
	root=ekleSirali(root,4);
	root=ekleSirali(root,4);
	root=ekleSirali(root,450);
	//root=ekle(root,-1000);
	//bastir(root);
	root=ekleSirali(root,500);
	root=ekleSirali(root,400);
	bastir(root);
	
	root=sil(root,4);
	bastir(root);
	root=sil(root,3);
	
	
	//root=sil(root,999);

	//ekle(root,-10);
	//bastir(root);
}


