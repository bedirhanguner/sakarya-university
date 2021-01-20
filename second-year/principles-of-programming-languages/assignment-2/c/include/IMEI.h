#ifndef IMEI_H
#define IMEI_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

	struct IMEI
	{
		int * (*olustur)(struct IMEI*);
		void (*yokEt)(struct IMEI*);	
	};

typedef struct IMEI* Imei;

Imei ImeiOlustur();
int * _rastgeleImeiOlustur(Imei);
void _imeiYokEt(Imei);

#endif