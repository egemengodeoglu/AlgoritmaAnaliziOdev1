#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void LocksSirala(int*,int*,int,int,int);
void KeysSirala(int*,int,int,int);

int main(){
	srand(time(NULL));														//Random de�er �retebilmek i�in
	int *locks, *keys;
	int i,size;
	printf("Keys Locks dizilerinin boyutunu giriniz=");						//Dinamic dizilerin boyutlar� al�n�yor
	scanf("%d",&size);
	locks=(int*)calloc(size,sizeof(int));									//Dinamik diziler a��l�yor
	keys=(int*)calloc(size,sizeof(int));
	printf("->Rastgele olusturulmus dizi elemanlari\n");
	printf("Locks dizisi siralanmamis hali\n");
		for(i=0;i<size;i++){												//Diziler rastgele elemanlarla dolduruluyor
			locks[i]=1+rand()%500;
			keys[(size-i)-1]=locks[i];
			printf("%d \t",locks[i]);										//Locks dizisinin ilk hali ekrana yazd�r�l�yor
		}
	printf("\nKeys dizisi siralanmamis hali\n");							//Keys dizisinin ilk hali ekrana yazd�r�l�yor
	for(i=0;i<size;i++)
	printf("%d \t",keys[i]);	

	LocksSirala(locks,keys,0,size-1,size);									//Diziler s�ralanmas� i�in fonksiyona g�nderiliyor
	printf("\nLocks dizisi siralanmis hali\n-----------------------------\n");
	for(i=0;i<size;i++){													//S�ralanm�� Locks dizisi ekrana yazd�r�l�yor
		printf("%d \t",locks[i]);
	}
	printf("\nKeys dizisi siralanmis hali\n------------------------------\n");
	for(i=0;i<size;i++){													//S�ralanm�� Keys dizisi ekrana yazd�r�l�yor
		printf("%d \t",keys[i]);
	}

	return 0;
}
void KeysSirala(int* dizi, int sol, int sag, int pivot)						//Keys dizisi s�ralamak i�in kullan�lan fonksiyon	
       {
            int tmp,i,j,kx=0,ex=0,bx=0;
			int kucuk[sag-sol],esit[sag-sol],buyuk[sag-sol];				//Se�ilen pivottan b�y�k e�it ve k���k elemanlar� tutmak i�in diziler a��l�yor
			for(i=sol;i<=sag;i++){
				if(dizi[i]<pivot)											//Dizinin eleman� pivottan k���kse k���k dizisine kaydediliyor
					kucuk[++kx]=dizi[i];
				else if(dizi[i]==pivot)										//Dizinin eleman� pivota e�itse e�it dizisine kaydediliyor
					esit[++ex]=dizi[i];
				else														//Dizinin eleman� pivottan b�y�kse b�y�k dizisine kaydediliyor
					buyuk[++bx]=dizi[i];
					
			}
			i=sol;
				for(j=kx;j>0;j--)											//�nce k���k olan elemanlar diziye yerle�tiriliyor
					dizi[i++]=kucuk[j];
				for(j=ex;j>0;j--)											//Ard�ndan e�it olan elemanlar yerle�tiriliyor
					dizi[i++]=esit[j];
				for(j=bx;j>0;j--)											//Ard�ndan b�y�k olan elemanlar yerle�tiriliyor
					dizi[i++]=buyuk[j];	
       }     
 

void LocksSirala(int* dizi, int* dizi2 ,int sol, int sag,int size)			//Locks dizisinin elemanlar�n� s�ralamak i�in fonksiyon
       {
       		 static int count=1;
             int pivot, tmp, i,j,x;
             i=sol;
             j=sag;           
             pivot=dizi[(sol+sag)/2];  
          
             do {
                    while(dizi[i]<pivot&& i<sag )							//Pivottan k���k olduk�a i g�stergesi sa�a kay�yor
                           i++;
                    while(pivot<dizi[j]&&j>sol )							//Pivottan b�y�k olduk�a j g�stergesi sola kay�yor
                           j--;
                    if(i<=j){                        						//E�er i ve j ters y�nde birbirini ge�mediyse elemanlar yer de�i�tiriliyor
                           tmp=dizi[i];
                           dizi[i]=dizi[j];
                           dizi[j]=tmp;
                           i++;
                           j--;  
                    }    		                               
             } while (i<=j);												//i jyi ge�inceye kadar devam ediyor
             printf("\n%d. adim locks pivot=%d\n---------------------------\n",count,pivot);
             for(x=0;x<size;x++)											//Bu ad�mda locks dizisinin g�ncel durumu yazd�r�l�yor
             printf("%d\t",dizi[x]);
             x=0;
             printf("\n%d. adim keys\n",count);							
			 
			 KeysSirala(dizi2,sol,sag,pivot);								//Keys dizisi locks dizisinin pivotuna g�re s�ralan�yor
			 for(x=0;x<size;x++)
			 printf("%d\t",dizi2[x]);										//Bu ad�mda Keys dizisinin g�ncel durumu yazd�r�l�yor
			 count++;
             if (sol<j) 
			 LocksSirala(dizi,dizi2, sol, j,size);							//Recursive �ekilde tekrar LocksS�rala fonksiyonu �a��r�l�yor 
             if (i<sag) 
			 LocksSirala(dizi,dizi2, i, sag,size);							//Recursive �ekilde tekrar LocksS�rala fonksiyonu �a��r�l�yor 
                 
       }     
 

