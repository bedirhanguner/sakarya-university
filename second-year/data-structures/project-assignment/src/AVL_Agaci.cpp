#include "AVL_Agaci.hpp"

	Dugum* AVL_Agaci::AraveEkle(Dugum* anlikDugum, Kisi* kisi) 
	{
		int eklenen = kisi->getYas();
		
		if (anlikDugum == NULL) 
		{
			anlikDugum = new Dugum(eklenen, NULL, NULL,kisi->getIsim(),kisi->getYas() ,kisi->getKilo() );
			
		}
		
		else if (eklenen <= anlikDugum->veri) 
		{
			anlikDugum->sol = AraveEkle(anlikDugum->sol, kisi);
			
			if (Yukseklik(anlikDugum->sol) - Yukseklik(anlikDugum->sag) == 2) 
			{
				if (eklenen < anlikDugum->sol->veri)
				{
					anlikDugum->yigit->Push("A");
					anlikDugum->sol->yigit->Push("Y");
					
					anlikDugum = solCocukIleDegistir(anlikDugum);
				}
				
				else 
				{ 
					anlikDugum->yigit->Push("A");
					anlikDugum->sol->sag->yigit->Push("Y");
					
					if(anlikDugum->sol->sag->sag!=NULL || anlikDugum->sol->sag->sol!=NULL)
					{
						anlikDugum->sag->yigit->Push("A");
					}
					
					anlikDugum->sol = sagCocukIleDegistir(anlikDugum->sol); 
					anlikDugum = solCocukIleDegistir(anlikDugum);
				}
			}
		}
		
		else if (eklenen > anlikDugum->veri) 
		{
			anlikDugum->sag = AraveEkle(anlikDugum->sag, kisi);
			
			if (Yukseklik(anlikDugum->sag) - Yukseklik(anlikDugum->sol) == 2) 
			{
				if (eklenen > anlikDugum->sag->veri)
				{
					anlikDugum->yigit->Push("A");
					anlikDugum->sag->yigit->Push("Y");
					
					anlikDugum = sagCocukIleDegistir(anlikDugum);
				}
				
				else if(eklenen < anlikDugum->sag->veri)
				{		
					anlikDugum->yigit->Push("A");
					anlikDugum->sag->sol->yigit->Push("Y");
					
					if(anlikDugum->sag->sol->sag!=NULL || anlikDugum->sag->sol->sol!=NULL)
					{
						anlikDugum->sag->yigit->Push("A");
					}
					
					anlikDugum->sag = solCocukIleDegistir(anlikDugum->sag);
					anlikDugum = sagCocukIleDegistir(anlikDugum);
				}	
			}	
		}

		anlikDugum->yukseklik = Yukseklik(anlikDugum);

		return anlikDugum;
	}
	
	Dugum* AVL_Agaci::solCocukIleDegistir(Dugum* anlikDugum)
	{
		Dugum* tmp = anlikDugum->sol;
		anlikDugum->sol = tmp->sag;
		tmp->sag = anlikDugum;

		anlikDugum->yukseklik = Yukseklik(anlikDugum);
		tmp->yukseklik = max(Yukseklik(tmp->sol), anlikDugum->yukseklik) + 1;

		return tmp;
	}
	
	Dugum* AVL_Agaci::sagCocukIleDegistir(Dugum* anlikDugum)
	{
		Dugum* tmp = anlikDugum->sag;
		anlikDugum->sag = tmp->sol;
		tmp->sol = anlikDugum;

		anlikDugum->yukseklik = Yukseklik(anlikDugum);
		tmp->yukseklik = max(Yukseklik(tmp->sag), anlikDugum->yukseklik) + 1;

		return tmp;
	}

	void AVL_Agaci::postOrder(Dugum* anlikDugum)
	{
		if (anlikDugum != NULL) 
		{
			postOrder(anlikDugum->sol);
			postOrder(anlikDugum->sag);

			cout<<anlikDugum->isim<<", "<<anlikDugum->yas<<", "<<anlikDugum->kilo<<" "<<"Yigit: ";
			
			while(!(anlikDugum->yigit->IsEmpty()))
			{
				cout<<anlikDugum->yigit->Top()<<" ";
				anlikDugum->yigit->Pop();
			}
			cout<<endl;
		}
	}
	
	void AVL_Agaci::seviyeAyniKaldiMi(Dugum* dugum, int seviye, int yeniSeviye)
	{ 
		if (dugum == NULL)
		{
			return;
		}
		
		if (seviye == 0)
		{
			int oncekiSeviye = dugum->seviye; 
			
			dugum->seviye = yeniSeviye;	
			
			if (dugum->seviye == oncekiSeviye && oncekiSeviye != -1)
			{
				dugum->yigit->Push("D");
			}
		}
		
		else
		{
			seviyeAyniKaldiMi(dugum->sol, seviye - 1, yeniSeviye);
			seviyeAyniKaldiMi(dugum->sag, seviye - 1, yeniSeviye);
		}
	}

	int AVL_Agaci::Yukseklik(Dugum* anlikDugum) 
	{
		if (anlikDugum == NULL)
		{
			return -1; 
		}
		
			if((Yukseklik(anlikDugum->sol) > Yukseklik(anlikDugum->sag)))
			{
				return 1 + Yukseklik(anlikDugum->sol);
			}
			
			else
			{
				return 1+ Yukseklik(anlikDugum->sag);
			}
	}
	
	bool AVL_Agaci::DugumSil(Dugum*& anlikDugum)
	{
		Dugum* silinecekDugum = anlikDugum;

		if (anlikDugum->sag == NULL)
		{
			anlikDugum = anlikDugum->sol;
		}
		
		else if (anlikDugum->sol == NULL)
		{
			anlikDugum = anlikDugum->sag;
		}
		
		else 
		{
			silinecekDugum = anlikDugum->sol;
			Dugum* ebeveynDugum = anlikDugum;
			
			while (silinecekDugum->sag != NULL)
			{
				ebeveynDugum = silinecekDugum;
				silinecekDugum = silinecekDugum->sag;
			}
			anlikDugum->veri = silinecekDugum->veri;
			
			if (ebeveynDugum == anlikDugum)
			{
				anlikDugum->sol = silinecekDugum->sol;
			}
			
			else
			{
				ebeveynDugum->sag = silinecekDugum->sol;
			}
		}
		
		delete silinecekDugum;
		return true;
	}
	
	AVL_Agaci::AVL_Agaci() 
	{
		root = NULL;
	}
	
	bool AVL_Agaci::Bosmu()
	{
		return root == NULL;
	}
	
	void AVL_Agaci::Ekle(Kisi* kisi)
	{	
		root = AraveEkle(root, kisi);
		
		seviyeAyniKaldiMi();
	}
	
	void AVL_Agaci::postOrder()
	{
		postOrder(root);
	}
	
	void AVL_Agaci::seviyeAyniKaldiMi()
	{
		int yukseklik = Yukseklik();
		
		for (int yeniSeviye = 0; yeniSeviye <= yukseklik; yeniSeviye++)
		{
			seviyeAyniKaldiMi(root, yeniSeviye, yeniSeviye);
		}
	}

	void AVL_Agaci::Temizle() 
	{
		while (!Bosmu()) DugumSil(root);
	}
	
	int AVL_Agaci::Yukseklik() {
		return Yukseklik(root);
	}
	
	AVL_Agaci::~AVL_Agaci() {
		Temizle();
	}