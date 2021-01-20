#include "Kisi.hpp"
	Kisi::Kisi()
	{
		this->isim=isim;
		this->yas=yas;
		this->kilo=kilo;
	}
	
    void Kisi::setIsim(string& isim)
	{
		this->isim = isim;
    }
	
    string Kisi::getIsim()
	{
		return isim;
    }
	
	int Kisi::yasHesapla(int dogumYili)
	{
		return 2020-dogumYili;
	}
	
	void Kisi::setYas(int& dogumYili)
	{
		int yasDegeri = yasHesapla(dogumYili);
		this->yas = yasDegeri;
    }
	
    int Kisi::getYas()
	{
		return yas;
    }
	
	void Kisi::setKilo(int& kiloDegeri)
	{
		this->kilo = kiloDegeri;
    }
	
    int Kisi::getKilo()
	{
		return kilo;
    }
	
	Kisi::~Kisi(){}