#include "Dosya.hpp"

using namespace std;
int main()
{
	Dosya dosya;
	string dosyaAdi("sayilar.txt");
	dosya.oku(dosyaAdi);

	return 0;
}