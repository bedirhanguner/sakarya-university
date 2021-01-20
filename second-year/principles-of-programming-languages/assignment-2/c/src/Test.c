#include "ADSOYAD.h"
#include "YAS.h"
#include "IMEI.h"
#include "TELEFONNO.h"
#include "TCKN.h"

#include "conio.h"

void rastgeleKisiOlustur();
void uretilmisDosyayiKontrolEt();

int main()
{
	do
    {
    	int secim;
		printf("\nYapmak istediginiz islemi seciniz: \n1)Rastgele Kisi Olustur: \n2)Olusturulan Kisiyi Kontrol Et: \n3)Cikis: \n");
        scanf("%d",&secim);

        if(secim == 1)
        {
           rastgeleKisiOlustur();
        }
        if (secim == 2)
        {
          uretilmisDosyayiKontrolEt();
        }
        if (secim == 3)
        {
        	exit(0); 
                   
        }              
        printf("\n\nBaska bir islem yapmak istiyor musunuz? (e/h)");        
    }while (getch() == 'e');
    	return getch();
    	
	return 0;	
}

	void rastgeleKisiOlustur()
	{
		Tckn tckn = TcknOlustur();
		AdSoyad adSoyad = AdSoyadOlustur();
		Yas yas = YasOlustur();
		TelefonNo telefonNo = TelefonNoOlustur();
		Imei imei = ImeiOlustur();
		
		int i;
		int *kontrolEdilecekTC;
		kontrolEdilecekTC = tckn->olustur(tckn);
		for ( i = 0; i < 11; i++ ) 
			printf("%d",*(kontrolEdilecekTC + i));
			printf(" ");
		
		adSoyad->olustur(adSoyad);printf(" ");
		
		yas->olustur(yas);printf(" ");
		
		telefonNo->olustur(telefonNo);printf(" ");
		
		int *kontrolEdilecekIMEI;
		kontrolEdilecekIMEI = imei->olustur(imei);
		printf("(");
		for ( i = 0; i < 15; i++ ) 
			printf("%d",*(kontrolEdilecekIMEI + i));
		printf(")");
		
		yas->yokEt(yas);
		tckn->yokEt(tckn);
		telefonNo->yokEt(telefonNo);
		imei->yokEt(imei);				
	}

	void uretilmisDosyayiKontrolEt() 
    {
		int i;
    	Tckn tckn = TcknOlustur();
		int *kontrolEdilecekTC;
		int tcknUzunluk = 10;
		kontrolEdilecekTC = tckn->olustur(tckn);
        printf("Kisi icin olusturulmus rastgele TC kimlik numarasi: "); 
		for ( i = 0; i <= tcknUzunluk; i++ ) 
			printf("%d",*(kontrolEdilecekTC + i));
			printf("\n");
      
        if(*(kontrolEdilecekTC + 0) == 0)
        {
           printf("Kisi icin olusturulan rastgele TC kimlik numarasi GECERSIZDIR.\n");  
        }
		
        if (((*(kontrolEdilecekTC + 0) + *(kontrolEdilecekTC + 2) + *(kontrolEdilecekTC + 4) + *(kontrolEdilecekTC + 6) + *(kontrolEdilecekTC + 8)) * 7 + (*(kontrolEdilecekTC + 1) + *(kontrolEdilecekTC + 3) + *(kontrolEdilecekTC + 5) + *(kontrolEdilecekTC + 7)) * 9) % 10 != *(kontrolEdilecekTC + 9))
        {
            printf("Kisi icin olusturulan rastgele TC kimlik numarasi GECERSIZDIR.\n");     
        }
		
        if(( *(kontrolEdilecekTC + 0) + *(kontrolEdilecekTC + 1) + *(kontrolEdilecekTC + 2) + *(kontrolEdilecekTC + 3) + *(kontrolEdilecekTC + 4) + *(kontrolEdilecekTC + 5) + *(kontrolEdilecekTC + 6) + *(kontrolEdilecekTC + 7) + *(kontrolEdilecekTC + 8) + *(kontrolEdilecekTC + 9))%10 != *(kontrolEdilecekTC + 10))
        {
            printf("Kisi icin olusturulan rastgele TC kimlik numarasi GECERSIZDIR.\n");     
        }
		
        else
        {
            printf("Kisi icin olusturulan rastgele TC kimlik numarasi GECERLIDIR.\n\n");  
        }
		tckn->yokEt(tckn);
   
        Imei imei = ImeiOlustur();
		int *kontrolEdilecekIMEI;
		int imeiUzunluk = 14;
		int tekBasamakToplami = 0;
        int ciftBasamakToplami = 0;
        int genelToplam = 0;
        int bolum = 0;
		kontrolEdilecekIMEI = imei->olustur(imei);
        printf("Kisi icin olusturulmus rastgele IMEI numarasi: "); 
		for ( i = 0; i <= imeiUzunluk; i++ ) 
			printf("%d",*(kontrolEdilecekIMEI + i));
			printf("\n");

        for (i = 0; i <imeiUzunluk; i++)
        {
           if( i%2 == 0)
		   {
               tekBasamakToplami = tekBasamakToplami + *(kontrolEdilecekIMEI + i);
		   }
        }        
        for (i = 0; i <imeiUzunluk; i++)
        {
            if( i%2 == 1)
                if(*(kontrolEdilecekIMEI + i)*2 >=10)
                {
                    ciftBasamakToplami  = ciftBasamakToplami + ((*(kontrolEdilecekIMEI + i)*2)%10)+1;
                }
                else
                {
                    ciftBasamakToplami = ciftBasamakToplami + (*(kontrolEdilecekIMEI + i)*2);
                }
        }
        genelToplam = tekBasamakToplami + ciftBasamakToplami;
        bolum = genelToplam / 10;
		
        if(genelToplam %10 == 0)
        {
            if(*(kontrolEdilecekIMEI + 14) != 0)
            {
                printf("Kisi icin olusturulan rastgele IMEI numarasi GECERSIZDIR.\n"); 
            }  
            else
            {
                printf("Kisi icin olusturulan rastgele IMEI numarasi GECERLIDIR.\n"); 
            }
        }   
		
        else
		{
            if(*(kontrolEdilecekIMEI + 14) != (10*(bolum + 1)) - genelToplam)
            {
                printf("Kisi icin olusturulan rastgele IMEI numarasi GECERSIZDIR.\n"); 
            }
            else
            {
                printf("Kisi icin olusturulan rastgele IMEI numarasi GECERLIDIR.\n"); 
            }
		}
	     
		imei->yokEt(imei);
    }