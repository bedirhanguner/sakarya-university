#include "Dosya.hpp"

int main()
{
	Dosya* dosya = new Dosya();
	string dosyaAdi = "Kisiler.txt";
	dosya->oku(dosyaAdi);
	
	return 0;
}