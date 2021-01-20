#include "Dosya.hpp"
#include "IkiYonluDaireselBagliListe.hpp"

#include<sstream>
#include<iostream>
#include<fstream>
#include<string>

	Dosya::Dosya() 
	{
		
	}

	void Dosya::oku(string dosyaAdi)
	{
		ifstream dosya(dosyaAdi);
	
		string satirElemani="";
		int listeElemani = 0;
	
		while (getline(dosya, satirElemani))
		{
			IkiYonluDaireselBagliListe* yeniListe = new IkiYonluDaireselBagliListe();
			
			stringstream ayir(satirElemani);
			while (ayir>>listeElemani)
			{
				yeniListe->ekle(listeElemani);
			}
			cout<<"Sifre: ";
			yeniListe->yazdir();
			delete yeniListe;
			cout << endl;
		}

	}

	Dosya::~Dosya()
	{
		
	}
