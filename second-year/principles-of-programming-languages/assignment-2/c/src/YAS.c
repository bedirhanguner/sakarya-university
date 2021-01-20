#include "YAS.h"


	Yas YasOlustur()
	{
		Yas this;
		this=(Yas)malloc(sizeof(struct YAS));
		
		this->olustur = &_rastgeleYasOlustur;
		this->yokEt = &_yasYokEt;
		return this;
		
	}

	void _rastgeleYasOlustur(const Yas this)
	{	
	
		srand(time(0));
		int yasDegeri = 0;

		yasDegeri = (rand() % (100 - 0 + 1));
		
		printf("%d", yasDegeri);
	}

	void _yasYokEt(Yas this)
	{
		if(this == NULL)return;
		free(this);
	}