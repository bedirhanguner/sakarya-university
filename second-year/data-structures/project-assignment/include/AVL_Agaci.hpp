#ifndef AVL_AGACI_HPP
#define AVL_AGACI_HPP

#include "Dugum.hpp"
#include "Kisi.hpp"

#include <cmath>
#include <iostream>

using namespace std;

class AVL_Agaci {
private:
	Dugum* root;
	Dugum* AraveEkle(Dugum* , Kisi*);
	Dugum* solCocukIleDegistir(Dugum*);
	Dugum* sagCocukIleDegistir(Dugum*);
	void postOrder(Dugum*) ;
	void seviyeAyniKaldiMi(Dugum *alt_Dugum, int seviye, int level) ;
	int Yukseklik(Dugum*);
	bool DugumSil(Dugum*&);

public:
	Kisi* kisi;
	AVL_Agaci();
	bool Bosmu()  ;
	void Ekle(Kisi*);
	void postOrder()  ;
	void seviyeAyniKaldiMi();
	void Temizle();
	int Yukseklik();

	~AVL_Agaci();
};
#endif