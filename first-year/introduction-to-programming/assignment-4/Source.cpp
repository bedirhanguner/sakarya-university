#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
using namespace std;

	int		AlfabeUzunlugu = 0;
	int		MesajUzunlugu = 0;
	int		SifreUzunlugu = 0;
	int		AlfabeSayaci = 0;
	int		MesajSayaci = 0;
	int		SifreSayaci = 0;
	int		a = 0, b = 0;
	int MesajKontrol = 0, SifreKontrol = 0;

class Islem {
private:
	char* alfabe;
	char* sifre;
	
public:
	char	Alfabe[100] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char	Sifre[100];
	char	YeniSifre[100];
	char	Mesaj[100];
	char	SifrelenmisMesaj[100];
	char	DesifreMesaj[100];


	void DegerleriIste() {
		cout << "ALFABE" << setw(15) << ": "; cin.getline(Alfabe, 100);
		cout << "SIFRE" << setw(16) << ": ";	cin.getline(Sifre, 100);
		cout << "MESAJ" << setw(16) << ": "; cin.getline(Mesaj, 100);
	}

	void UzunlukBul(char Alfabe[], char Mesaj[], char Sifre[]) {

		while (Alfabe[AlfabeSayaci]!= '\0') {
			AlfabeUzunlugu++;
			AlfabeSayaci++;
		}
		while (Mesaj[MesajSayaci] != '\0') {
			MesajUzunlugu++;
			MesajSayaci++;
		}
		while (Sifre[SifreSayaci] != '\0') {
			SifreUzunlugu++;
			SifreSayaci++;
		}

	}
	
	int YeniSifreyiOlustur(int MesajUzunlugu, int SifreUzunlugu, char Sifre[]) {
		for (a = 0, b = 0; a < MesajUzunlugu; a++, b++) {

			if (b == SifreUzunlugu)
				b = 0;
			YeniSifre[a] = Sifre[b];
		}

		return YeniSifre[MesajUzunlugu];
	}

	void MesajiSifrele(int MesajUzunlugu, int AlfabeUzunlugu, char Mesaj[], char YeniSifre[]) {

		for (a = 0; a < MesajUzunlugu; a++) {
			SifrelenmisMesaj[a] = ((Mesaj[a] + YeniSifre[a]) % AlfabeUzunlugu) + 'A' ;
			if (SifrelenmisMesaj[a] == 91) {
				SifrelenmisMesaj[a] = 'A';
			}
		}

		cout << "SIFRELENMIS METIN" << setw(4) << ": ";
		for (a = 0; a < MesajUzunlugu; a++) {
		cout<<SifrelenmisMesaj[a];	
		}
		cout << endl;
	}

	void SifrelenmisMesajiDesifreEt(int MesajUzunlugu, int AlfabeUzunlugu, char SifrelenmisMesaj[], char YeniSifre[]) {

	for (a = 0; a < MesajUzunlugu; a++) {
			DesifreMesaj[a] = (((SifrelenmisMesaj[a] - YeniSifre[a]) + AlfabeUzunlugu) % AlfabeUzunlugu) + 65;
			if (DesifreMesaj[a] < 65) {
				DesifreMesaj[a] = DesifreMesaj[a] + AlfabeUzunlugu;
			}
		}

		cout << "DESIFRE METIN" << setw(8) << ": ";
		for (a = 0; a < MesajUzunlugu; a++) {
			cout << DesifreMesaj[a];
		}
		cout << endl;
	}
};

int main() {
	Islem Sifrele;

	Sifrele.DegerleriIste ();
	Sifrele.UzunlukBul (Sifrele.Alfabe, Sifrele.Mesaj, Sifrele.Sifre);
	Sifrele.YeniSifreyiOlustur (MesajUzunlugu, SifreUzunlugu, Sifrele.Sifre);
	Sifrele.MesajiSifrele (MesajUzunlugu, AlfabeUzunlugu, Sifrele.Mesaj, Sifrele.YeniSifre);
	Sifrele.SifrelenmisMesajiDesifreEt (MesajUzunlugu, AlfabeUzunlugu, Sifrele.SifrelenmisMesaj, Sifrele.YeniSifre);

	system("pause");
	return 0;
}
