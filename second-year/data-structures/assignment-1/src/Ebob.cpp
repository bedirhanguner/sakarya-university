#include "Ebob.hpp"
#include<iostream>

Ebob::Ebob() 
{
	
}

	int Ebob::ebobAl(int sayi1, int sayi2)
	{
		int bolumdenKalan = 0;
		
		if (sayi1 == 0)
			return sayi1;
		
		if (sayi1 != 0)
			bolumdenKalan = sayi1 % sayi2;
		
		if (bolumdenKalan == 0)
			return sayi2;
		
		return ebobAl(sayi2, bolumdenKalan);
	}

Ebob::~Ebob()
{
	
}
