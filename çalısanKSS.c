#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
        //STRUCT
typedef struct 
{
	char isim[15];
	char soyisim[15];
	char gorev[20];
	char telefon[20];
	char adres[20];
	int yas;
	int id;
	int maas;

}calisanBilgileri;
//FONKSIYONLAR 
void dosyayazdir(void);
void dosyaoku(void);
void calisanekleme(void);
void calisangoruntuleme(void);
void calisanguncelleme(void);
void yoneticigiris(void);
static void yonetici_calisan_ucreti(void);
static void yonetici_gorev_guncelleme(void);
static void yonetici_toplam_ucret(void);
static void yonetici_toplam_calisan(void);
static void yonetici_calisan_silme(void);

//DEGÝSKENLER
int toplamucret=0;
calisanBilgileri calisanlar[100];
const char yoneticiad[15]="Admin";
int calisansayisi;
const int yoneticisifre=1234;
int kullanicisecim;

//MAÝN
int main(int argc, char *argv[]) {
      dosyayazdir();
      dosyaoku();
	do
	{
		printf("--------Calisan Kayit ve Sorgulama Sistemi--------\n");
		printf("1-Calisan ekleme\n");
		printf("2-Calisan bilgileri goruntuleme\n");
		printf("3-calisan bilgileri gucelleme\n");
		printf("4-Yonetici girisi\n");
		printf("5-Cikis\n");
		printf("\ntercihiniz:");
		scanf("%d",&kullanicisecim);
		system("cls");
		
		switch(kullanicisecim)
		{
			case 1:
				calisanekleme();
				break;
			case 2:
				calisangoruntuleme();
			    break;
			case 3:
				calisanguncelleme();
				break;
			case 4:
				 yoneticigiris();
			    break;
					
		}
        
	}
	while(kullanicisecim!=5);
	 dosyaoku();
     dosyayazdir();
     dosyaoku();

  return 0;	
}
//CALISAN BÝLGÝLERÝNÝ DOSYAYA YAZAN FONK.
void dosyayazdir(void)
{   
    int i;
	FILE *dosya=fopen("Calisanlar.txt","w");
	if(dosya==NULL)
	{
		printf("Dosya olusturulamadi");
		return;
	}
	for(i=0; i<calisansayisi; i++)
	{
		calisanBilgileri m=calisanlar[i];
		fprintf(dosya,"%s%s%s%d%s%s%d%d",m.isim,m.soyisim,m.gorev,m.maas,m.telefon,m.adres,m.yas,m.id);
		
	}
	fclose(dosya);
}
//CALISAN BÝLGÝLERÝNÝN DOSYADAN OKUYAN FONK.
void dosyaoku()
{
 FILE *dosya=fopen("Calisanlar.txt","r");
 if(dosya==NULL)
 {
 	printf("Dosya acilamadi");
 	return;
 }
 while(!feof(dosya))
 {
 	calisanBilgileri m;
    fscanf(dosya,"%14s %14s %19s %19s %19s %d %d %d", m.isim, m.soyisim, m.gorev, m.telefon, m.adres, &m.id, &m.maas, &m.yas);
 	if(strlen(m.isim)>0)
 	{
 		calisanlar[calisansayisi]=m;
 		
    }
     
     
 }
	 fclose(dosya);
}
//CALISAN EKLEME FONKSIYONU
void calisanekleme()
{
	calisanBilgileri m;
	printf("adi:");
	scanf("%s",m.isim);
	printf("soyisim:");
	scanf("%s",m.soyisim);
	printf("gorev:");
	scanf("%s",m.gorev);
	printf("Adres:");
	scanf("%s",m.adres);
	printf("Telefon no:");
	scanf("%s",m.telefon);
	printf("yas:");
	scanf("%d",&m.yas);
	printf("id:");
	scanf("%d",&m.id);
	printf("maas:");
	scanf("%d",&m.maas);
		calisanlar[calisansayisi]=m;
		calisansayisi++;
		printf("Calisan ekleme basarili");
		sleep(1);
		system("cls");
}
//ÇALIÞAN GORUNTULEME FONKSIYONU
void calisangoruntuleme()
{    
    //
    char bosluk[10];
	int gelenid=0;
	int index=-1;
	int i;
	//
	printf("Calisan id:");
	scanf("%d",&gelenid);
	for(i=0;i<calisansayisi;i++)
	{
		if(gelenid==calisanlar[i].id)
		 {
		 	index=1;
		 	printf("-----Calisan bilgileri-----\n");
		 	printf("adi:%s\n",calisanlar[i].isim);
		 	printf("soyadi:%s\n",calisanlar[i].soyisim);
		 	printf("adres:%s\n",calisanlar[i].adres);
		 	printf("telefon:%s\n",calisanlar[i].telefon);
		 	printf("id:%d\n",calisanlar[i].id);
		 	printf("maas:%d\n",calisanlar[i].maas);
		 	printf("gorev:%s\n",calisanlar[i].gorev);
		 	printf("yas:%d\n",calisanlar[i].yas);
		 	printf("Ana menuye donmek icin '1' tusunu seciniz:");
            scanf("%s",&bosluk);
            system("cls");
		 }
	}
	if(index==-1)
	{
		printf("Calisan bulunamadi!!!");
	}
	
	
}
//CALIÞAN GUNCELLEME FONKSIYONU
void calisanguncelleme()
{ 
  char ilerleme=NULL;
  int index=-1;
  int i=0;
  int gelenid;
  printf("Calisan id:");
  scanf("%d",&gelenid);
  system("cls");
  
  for(i=0;i<calisansayisi;i++)
  {
  	if(calisanlar[i].id==gelenid)
  	{
  		printf("Bulunan kullanici:%s %s\n",calisanlar[i].isim,calisanlar[i].soyisim);
  		printf("\nkullanicinin bilgilerini guncellemeye devam etmek istiyor musunuz [E/H]:");
  		scanf("%s",&ilerleme);
        
        if(ilerleme=='E');
        {
            system("cls");
            printf("yeni isim:");
            scanf("%s",calisanlar[i].isim);
            printf("yeni soyisim:");
            scanf("%s",calisanlar[i].soyisim);
            printf("yeni yas:");
            scanf("%d",&calisanlar[i].yas);
            printf("yeni telefon:");
            scanf("%s",calisanlar[i].telefon);
            printf("yeni adres:");
            scanf("%s",calisanlar[i].adres);
            system("cls");
            printf("Guncelleme basarili...");
            sleep(2);
            system("cls");
            printf("Menuye donmek icin '1' tusuna basin:");
            scanf("%d",&ilerleme);
        }
       
  
  	}
  }  
}
//YONETÝCÝ GÝRÝS FONKSIYONU
	void yoneticigiris()
	{
		//fonksiyon icin
        
        int kullanicitercih;
		int gelensifre=0;
		char gelenad[15];
		//  degýskenler
		printf("\nYonetici kullanici adi:");
		scanf("%s",gelenad);
		printf("\nYonetici sifre:");
		scanf("%d",&gelensifre);
		system("cls");
		if(strcmp(gelenad,yoneticiad)==0 && gelensifre==yoneticisifre)
		{
			do{
				printf("----Yonetim sistemine hosgeldiniz----\n");
			    sleep(1);
			    printf("1-calisan ucreti guncelleme\n");
			    printf("2-calisan gorevi guncelleme\n");
			    printf("3-calisanlara odenen tutar\n");
			    printf("4-toplam calisan sayisi\n");
			    printf("5-calisan silme\n");
			    printf("6-cikis\n");
			    printf("\ntercihiniz:");
			    scanf("%d",&kullanicitercih);
                system("cls");
			    switch(kullanicitercih)
			    {
			    	case 1:
			    		yonetici_calisan_ucreti();
			    		break;
                    case 2:
                       yonetici_gorev_guncelleme();
                        break;
                    case 3:
                    	yonetici_toplam_ucret();
                    	break;
                    case 4:
                    	yonetici_toplam_calisan();
                    	break;
                    case 5:
                    	yonetici_calisan_silme();
                    	break;
                    	
				}
			    
			}while(kullanicitercih!=6);
			
		}
		else
		{
			printf("Girilen bilgiler yanlis!!");
		}
		
	}
//YÖNETÝCÝ SÝSTEMÝ ÝCÝN UCRET GUNCELLEME FONKSIYONU
 static void yonetici_calisan_ucreti()
 { 
     int paravan=0;
   char gelenkarar;
    int i;
 	int index=-1;
 	int gelenid;
 	
 	printf("guncellemek istediginiz calisanin id'sini giriniz\n");
 	printf("\nCalisan id:");
 	scanf("%d",&gelenid);
    system("cls");
 	
 	for(i=0; i<calisansayisi; i++)
 	{
 		if(gelenid==calisanlar[i].id)
 		{
 			printf("Calisan %s %s\n",calisanlar[i].isim,calisanlar[i].soyisim);
 			printf("aldigi ucret=%d\n",calisanlar[i].maas);
 			printf("\nguncellemek istiyor musunuz ?[E/H]:");
 			scanf(" %c",&gelenkarar);
            system("cls");
 		    if(gelenkarar=='E')
 		    {
 		      	printf("\n%s %s icin yeni belirlediginiz ucret:",calisanlar[i].isim,calisanlar[i].soyisim);
                scanf("%d",&calisanlar[i].maas);
                system("cls");
                printf("Guncelleme basarili..\n");
                printf("Menuye donmek icin '1':");
                scanf("%d",&paravan);
                system("cls");
 		      	
			}
            index=0;
		}
		if(index==-1)
        {
            printf("Calisan bulunamadi");
        }
	}
	
 	
 }
 //YONETÝCÝ GOREV GUNCELLEME
 static void yonetici_gorev_guncelleme()
{
    int gelen_id;
	int i;
    char cevap;

    printf("Guncellenecek calisanin ID'sini girin: ");
    scanf("%d", &gelen_id);

    for (i = 0; i < calisansayisi; i++)
    {
        if (calisanlar[i].id == gelen_id)
        {
            printf("Calisan bilgileri:\n");
            printf("Isim: %s\n", calisanlar[i].isim);
            printf("Soyisim: %s\n", calisanlar[i].soyisim);
            printf("Gorev: %s\n", calisanlar[i].gorev);

            printf("Guncellemek istiyor musunuz? [E/H]: ");
            scanf(" %c", &cevap);

            if (toupper(cevap) == 'E')
            {
                printf("Yen	i gorev: ");
                scanf("%s", calisanlar[i].gorev);
                printf("Guncelleme basarili!\n");
            }

            return;
        }
    }

    printf("ID bulunamadi!\n");
}
//YONETÝCÝ TOPLAM CALISAN UCRETÝ
static void yonetici_toplam_ucret(void){
    setlocale(LC_NUMERIC,"");
    int paravan=0;
    int i;
    toplamucret = 0; 
    for (i=0; i<calisansayisi; i++) {
        if(calisanlar[i].id==calisanlar[i].id)
        {
            toplamucret+=calisanlar[i].maas;
        }
    }
    printf("calisanlara odenen toplam ucret:%'d TL\n",toplamucret);//bu kýsýmda mantýksal bir hata alýnýyorsa ide'den kaynaklý hata alýnýyodur(setlocale ide tanýmýyodur)
    printf("\nMenuye donmek icin '1':");
    scanf("%d",&paravan);
    system("cls");
}
static void yonetici_toplam_calisan()
{
	int paravan;
	printf("Toplam calisan sayisi:%d\n",calisansayisi);
	printf("\nMenuye donmek icin '1':");
	scanf("%d",&paravan);
}
static void yonetici_calisan_silme()
{
	int paravan;
	int index=-1;
	int i;
	int gelenid=0;
	printf("\nsilmek istediginiz calisan id:");
	scanf("%d",&gelenid);
	for(i=0;i<calisansayisi;i++)
	{
		if(calisanlar[i].id==gelenid)
		{
			index=i;
			break;
		}
	}
	if(index==-1)
	{
		printf("Calisan bulunamadi!!");
		return;
	}
	for(i=index;i<calisansayisi-1;i++)
	{
		calisanlar[i]=calisanlar[i+1];
	}
	calisansayisi--;
	("printf calisan silme basarili..\n");
	printf("\nMenuye donmek icin '1':");
	scanf("%d",&paravan);
}


