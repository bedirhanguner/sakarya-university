#include "ADSOYAD.h"


	AdSoyad AdSoyadOlustur()
	{
		AdSoyad this;
		this=(AdSoyad)malloc(sizeof(struct ADSOYAD));
		
		this->olustur = &_rastgeleAdSoyadOlustur;
		this->yokEt = &_adSoyadYokEt;
		return this;
	}

	void _rastgeleAdSoyadOlustur(AdSoyad this)
	{
		struct Kisiler
		{
			char ad[100];
			char soyad[100];	    
		};

		struct Kisiler kisiBilgisi[3000];
	
		srand(time(NULL));

		FILE *dosya = fopen("random_isimler.txt", "r");
		if (dosya == NULL) {
			printf("Dosya açılamadı.\n");
			exit(0);
		}
		else 
		{
			char ch;
			int satirSayisi = 0;		
			do
			{
				ch = fgetc(dosya);
				if (ch == '\n') satirSayisi++;
			} while (ch != EOF);
			
			rewind(dosya);
			int satir;
			for (satir = 0; satir < satirSayisi+1; satir++) 
			{
				fscanf(dosya, "%s %s\n", kisiBilgisi[satir].ad, kisiBilgisi[satir].soyad);
			}

			int rastgele = (rand() % (3000 - 0 + 1)) + 0;
			printf("%s %s", kisiBilgisi[rastgele].ad, kisiBilgisi[rastgele].soyad);
		}
	}
	
	void _adSoyadYokEt(AdSoyad this)
	{
		if(this == NULL)return;
		free(this);
	}