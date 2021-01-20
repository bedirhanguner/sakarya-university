#include "Dosya.hpp"
#include "Kisi.hpp"
#include "AVL_Agaci.hpp"

	Dosya::Dosya()
	{
		
	}
	
	AVL_Agaci *agac = new AVL_Agaci();
	
	void Dosya::oku(string& dosyaYolu)const
	{
	Kisi* kisi = new Kisi();
	
	ifstream dosya(dosyaYolu);
	string satir;
	string sutun;
		if (dosya.is_open())
		{
			while (getline(dosya,satir))
			{	
		
				int uzunluk = satir.length();
			
				char dizi[uzunluk + 1];
				strcpy(dizi, satir.c_str()); 
				
				char *token = strtok(dizi, "#"); 
				string kisiBilgileri[3];
				int i=0;
				
				while (token != NULL) 
				{ 
					kisiBilgileri[i]=token;
					token = strtok(NULL, "#"); 
					i++;
				} 
				kisi->setIsim(kisiBilgileri[0]);
			
				int yas = stoi(kisiBilgileri[1]);
				kisi->setYas(yas);
				int kilo =stoi(kisiBilgileri[2]);
				kisi->setKilo(kilo);
				
				agac->Ekle(kisi);
			}
			
			dosya.close();
			agac->postOrder();
			cout<<endl;
			agac->Temizle();
		}
	}
	
	Dosya::~Dosya()
	{
	}
	
