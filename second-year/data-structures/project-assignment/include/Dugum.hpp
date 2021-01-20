#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Yigit.hpp"

#include <cmath>
#include <iostream>

class Dugum 
{
	private:
	
	public:
		Dugum(const int&, Dugum*, Dugum*,const string&, const int&,const int&);
		int veri;
		Yigit* yigit;
		string isim;
		int yas;
		int kilo;
		Dugum* sol;
		Dugum* sag;
		int yukseklik;
		int seviye; 
		
		~Dugum();
};
#endif