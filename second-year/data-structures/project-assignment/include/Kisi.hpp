#ifndef KISI_HPP
#define KISI_HPP

#include "Kisi.hpp"

#include <iostream>
#include <string.h>

using namespace std;

class Kisi {
	private:
		
	
	public:
		string isim;
		int yas;
		int kilo;
	
		Kisi();
		
		void setIsim(string&);
		string getIsim();
		
		int yasHesapla(int);
		
		void setYas(int&);
		int getYas();
		
		void setKilo(int& );
		int getKilo();
		
		~Kisi();
};
#endif