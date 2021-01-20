#include "Dugum.hpp"

	Dugum::Dugum(const int& veri, Dugum* sol, Dugum* sag,const string& isim,const int& yas,const int& kilo) 
	{
		yigit = new Yigit();
		
		yigit->Push("O");	
		this->isim = isim;
		this->yas = yas;
		this->kilo = kilo;
		this->veri = veri;
		this->sol = sol;
		this->sag = sag;
		this->yukseklik = 0;
		
		this->seviye = -1;
	}
	
	Dugum::~Dugum(){}
