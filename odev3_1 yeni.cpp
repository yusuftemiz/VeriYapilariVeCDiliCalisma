//Samet Karavaizoðlu 16060017
//news: sil fonksiyonu her sil(x) elemanýný siliyor.
//news: sil fonksiyonu ilk eleman root ise rootu siliyor sonraki ayný eleman olanlarý da siliyor.

#include <stdio.h>
#include <stdlib.h>


struct n {
	int x;
	n* next;
};
 
typedef n node;
void bastir(node*r){
	node*iter=r;
	printf("%d\n",r->x);//Ýteri ilerletiyoruz. Aksi halde While ýn içine girmez
	iter=iter->next;
	while(iter!=r){
		printf("%d\n",iter->x);
		iter=iter->next;
	}
	printf("\n");
}

node* ekle(node*r,int x){
	node*iter=r;//iter root tan baþlatýldý
	while(iter->next!=r){
		iter=iter->next;}
		iter->next=(node*)malloc(sizeof(node));		
		iter->next->x=x;
		iter->next->next=r;
		return r;
	
}

node* ekleSirali(node*r,int x){
	if (r==NULL){//Linl list boþ ise
	r=(node*)malloc(sizeof(node));
	r->next=r;//dairesel yapýldý
	r->x=x;
	return r;
	}
	if(r->x>x){//ilk elemandan kucuk o halde root deðiþmeli
	node*temp=(node*)malloc(sizeof(node));
	temp->x=x;
	temp->next=r;
	node*iter=r;//iter root tan baþladý
	while(iter->next!=r)
	iter=iter->next;
	iter->next=temp;//yeni root baðlantýsý yapýldý. Circle yapý tamamlandý
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
			return iter->next;//root silindiði için yeni root baðl.yapýldý
	}
				while(iter->next!=r){
					if(iter->next->x == x){ // bir sonraki elemanýn x i aradýðýmýz sayý ise
            temp=iter->next; // deðeri geçiciye al
            iter->next=iter->next->next; // bir sonraki elemanla bir sonrakinin sonraki elamanýný eþleþtir
            free(temp); //tempi ram den sil
            continue; // alt kýsma geçmeden döngüye dön
            
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


