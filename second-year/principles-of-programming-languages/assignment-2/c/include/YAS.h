#ifndef YAS_H
#define YAS_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

	struct YAS
	{	
		void (*olustur)(struct YAS*);
		void (*yokEt)(struct YAS*);	
	};

typedef struct YAS* Yas;

Yas YasOlustur();
void _rastgeleYasOlustur(Yas);
void _yasYokEt(Yas);

#endif