#include "TCKN.h"

	Tckn TcknOlustur()
	{
		Tckn this;
		this=(Tckn)malloc(sizeof(struct TCKN));
		
		this->olustur = &_rastgeleTcknOlustur;
		this->yokEt = &_tcknYokEt;
		return this;
	}
	
	int * _rastgeleTcknOlustur(Tckn this)
	{

		srand(time(NULL));
	    static int TCKN[11];
		int i;

		TCKN[0] = (rand() % (9 - 1 + 1)) + 1;    

		for (i = 1; i < 9; i++) 	    {
	        TCKN[i] = (rand() % (9 - 0 + 1)) + 0;    
	    }
	    
	    TCKN[9] = (7*(TCKN[0] + TCKN[2] + TCKN[4] + TCKN[6] +  TCKN[8]) + 9*( TCKN[1] + TCKN[3] + TCKN[5] + TCKN[7]))%10;
			
        TCKN[10] = ( TCKN[0] + TCKN[1] + TCKN[2] + TCKN[3] + TCKN[4] + TCKN[5] + TCKN[6] + TCKN[7] + TCKN[8] + TCKN[9])%10;

	    return TCKN;
	}

	void _tcknYokEt(Tckn this)
	{
		if(this == NULL)return;
		free(this);
	}