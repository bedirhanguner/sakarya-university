#ifndef ADSOYAD_H
#define ADSOYAD_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct ADSOYAD
{
	void (*olustur)(struct ADSOYAD*);
	void (*yokEt)(struct ADSOYAD*);	
};

typedef struct ADSOYAD* AdSoyad;

AdSoyad AdSoyadOlustur();
void _rastgeleAdSoyadOlustur(AdSoyad);
void _adSoyadYokEt(AdSoyad);

#endif