#include "TELEFONNO.h"

	TelefonNo TelefonNoOlustur()
	{
		TelefonNo this;
		this=(TelefonNo)malloc(sizeof(struct TELEFONNO));
		
		this->olustur = &_rastgeleTelefonNoOlustur;
		this->yokEt = &_telefonNoYokEt;
		return this;
	}

	void _rastgeleTelefonNoOlustur(TelefonNo this)
	{
		
		srand(time(0));
		char telefonNumarasi[12];
		char telefonNoDizi[12] = {0};
		int n = 0;

		telefonNumarasi[0] = 9;
		telefonNumarasi[1] = 0;
				
		telefonNumarasi[2] = 5;
		telefonNumarasi[3] = 0 + (rand() % (5 - 0 + 1)) + 0;  

		int i;
		for (i = 4; i < 12; i++) 
		{
			telefonNumarasi[i] = (rand() % (9 - 0 + 1)) + 0;   
		}
	
		for ( i = 0; i < 12; i++) {
			n += sprintf (&telefonNoDizi[n], "%d", telefonNumarasi[i]);
		}
		
		printf("%s",telefonNoDizi);
	}
	
	void _telefonNoYokEt(TelefonNo this)
	{
		if(this == NULL)return;
		free(this);
	}