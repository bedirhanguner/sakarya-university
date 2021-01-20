#ifndef TCKN_H
#define TCKN_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

	struct TCKN
	{
		int * (*olustur)(struct TCKN*);
		void (*yokEt)(struct TCKN*);	
	};

typedef struct TCKN* Tckn;

Tckn TcknOlustur();
int * _rastgeleTcknOlustur(Tckn);
void _tcknYokEt(Tckn);

#endif