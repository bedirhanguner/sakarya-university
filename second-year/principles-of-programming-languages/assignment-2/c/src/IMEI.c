#include "IMEI.h"

	Imei ImeiOlustur()
	{
		Imei this;
		this=(Imei)malloc(sizeof(struct IMEI));
		
		this->olustur = &_rastgeleImeiOlustur;
		this->yokEt = &_imeiYokEt;
		return this;
	}

	int *_rastgeleImeiOlustur(Imei this)
	{

		srand(time(NULL));
	    static int IMEI[15];
	    int n = 0;
	    int tekBasamakToplami = 0;
	    int ciftBasamakToplami = 0;
	    int genelToplam;
	    int bolum;
		int i;
	
	    for (i = 0; i < 14; i++) 
	    {
	        IMEI[i] = (rand() % (9 - 0 + 1)) + 0;    
	    }
	    
	    for ( i = 0; i <14; i++)
	    {
	       if( i%2 == 0)
	           tekBasamakToplami = tekBasamakToplami + IMEI[i];
	    }

	
	    for (i = 0; i <14; i++)
	    {			
	        if( i%2 == 1)
	
	            if(IMEI[i]*2 >=10)
	            {
	                ciftBasamakToplami  = ciftBasamakToplami + ((IMEI[i]*2)%10)+1;
	            }
				
	            else
	            {
	                ciftBasamakToplami = ciftBasamakToplami + IMEI[i]*2;
	            }
	    }
				
	    genelToplam = tekBasamakToplami + ciftBasamakToplami;       
	    bolum = genelToplam / 10;

	    if(genelToplam%10 == 0)
	    {
	        IMEI[14] = 0;
	    }
			
	    else
	    {
	        IMEI[14] = (10*(bolum + 1)) - genelToplam;
	    }
    
		return IMEI;
	}

	void _imeiYokEt(Imei this)
	{
		if(this == NULL)return;
		free(this);
	}

