#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void LocksSirala(int*,int*,int,int,int);
void KeysSirala(int*,int,int,int);

int main(){
	srand(time(NULL));														//Random deðer üretebilmek için
	int *locks, *keys;
	int i,size;
	printf("Keys Locks dizilerinin boyutunu giriniz=");						//Dinamic dizilerin boyutlarý alýnýyor
	scanf("%d",&size);
	locks=(int*)calloc(size,sizeof(int));									//Dinamik diziler açýlýyor
	keys=(int*)calloc(size,sizeof(int));
	printf("->Rastgele olusturulmus dizi elemanlari\n");
	printf("Locks dizisi siralanmamis hali\n");
		for(i=0;i<size;i++){												//Diziler rastgele elemanlarla dolduruluyor
			locks[i]=1+rand()%500;
			keys[(size-i)-1]=locks[i];
			printf("%d \t",locks[i]);										//Locks dizisinin ilk hali ekrana yazdýrýlýyor
		}
	printf("\nKeys dizisi siralanmamis hali\n");							//Keys dizisinin ilk hali ekrana yazdýrýlýyor
	for(i=0;i<size;i++)
	printf("%d \t",keys[i]);	

	LocksSirala(locks,keys,0,size-1,size);									//Diziler sýralanmasý için fonksiyona gönderiliyor
	printf("\nLocks dizisi siralanmis hali\n-----------------------------\n");
	for(i=0;i<size;i++){													//Sýralanmýþ Locks dizisi ekrana yazdýrýlýyor
		printf("%d \t",locks[i]);
	}
	printf("\nKeys dizisi siralanmis hali\n------------------------------\n");
	for(i=0;i<size;i++){													//Sýralanmýþ Keys dizisi ekrana yazdýrýlýyor
		printf("%d \t",keys[i]);
	}

	return 0;
}
void KeysSirala(int* dizi, int sol, int sag, int pivot)						//Keys dizisi sýralamak için kullanýlan fonksiyon	
       {
            int tmp,i,j,kx=0,ex=0,bx=0;
			int kucuk[sag-sol],esit[sag-sol],buyuk[sag-sol];				//Seçilen pivottan büyük eþit ve küçük elemanlarý tutmak için diziler açýlýyor
			for(i=sol;i<=sag;i++){
				if(dizi[i]<pivot)											//Dizinin elemaný pivottan küçükse küçük dizisine kaydediliyor
					kucuk[++kx]=dizi[i];
				else if(dizi[i]==pivot)										//Dizinin elemaný pivota eþitse eþit dizisine kaydediliyor
					esit[++ex]=dizi[i];
				else														//Dizinin elemaný pivottan büyükse büyük dizisine kaydediliyor
					buyuk[++bx]=dizi[i];
					
			}
			i=sol;
				for(j=kx;j>0;j--)											//Önce küçük olan elemanlar diziye yerleþtiriliyor
					dizi[i++]=kucuk[j];
				for(j=ex;j>0;j--)											//Ardýndan eþit olan elemanlar yerleþtiriliyor
					dizi[i++]=esit[j];
				for(j=bx;j>0;j--)											//Ardýndan büyük olan elemanlar yerleþtiriliyor
					dizi[i++]=buyuk[j];	
       }     
 

void LocksSirala(int* dizi, int* dizi2 ,int sol, int sag,int size)			//Locks dizisinin elemanlarýný sýralamak için fonksiyon
       {
       		 static int count=1;
             int pivot, tmp, i,j,x;
             i=sol;
             j=sag;           
             pivot=dizi[(sol+sag)/2];  
          
             do {
                    while(dizi[i]<pivot&& i<sag )							//Pivottan küçük oldukça i göstergesi saða kayýyor
                           i++;
                    while(pivot<dizi[j]&&j>sol )							//Pivottan büyük oldukça j göstergesi sola kayýyor
                           j--;
                    if(i<=j){                        						//Eðer i ve j ters yönde birbirini geçmediyse elemanlar yer deðiþtiriliyor
                           tmp=dizi[i];
                           dizi[i]=dizi[j];
                           dizi[j]=tmp;
                           i++;
                           j--;  
                    }    		                               
             } while (i<=j);												//i jyi geçinceye kadar devam ediyor
             printf("\n%d. adim locks pivot=%d\n---------------------------\n",count,pivot);
             for(x=0;x<size;x++)											//Bu adýmda locks dizisinin güncel durumu yazdýrýlýyor
             printf("%d\t",dizi[x]);
             x=0;
             printf("\n%d. adim keys\n",count);							
			 
			 KeysSirala(dizi2,sol,sag,pivot);								//Keys dizisi locks dizisinin pivotuna göre sýralanýyor
			 for(x=0;x<size;x++)
			 printf("%d\t",dizi2[x]);										//Bu adýmda Keys dizisinin güncel durumu yazdýrýlýyor
			 count++;
             if (sol<j) 
			 LocksSirala(dizi,dizi2, sol, j,size);							//Recursive þekilde tekrar LocksSýrala fonksiyonu çaðýrýlýyor 
             if (i<sag) 
			 LocksSirala(dizi,dizi2, i, sag,size);							//Recursive þekilde tekrar LocksSýrala fonksiyonu çaðýrýlýyor 
                 
       }     
 

