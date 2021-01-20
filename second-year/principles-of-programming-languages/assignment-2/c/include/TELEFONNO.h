#ifndef TELEFONNO_H
#define TELEFONNO_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

	struct TELEFONNO
	{
		void (*olustur)(struct TELEFONNO*);
		void (*yokEt)(struct TELEFONNO*);	
	};

typedef struct TELEFONNO* TelefonNo;

TelefonNo TelefonNoOlustur();
void _rastgeleTelefonNoOlustur(TelefonNo);
void _telefonNoYokEt(TelefonNo);

#endif