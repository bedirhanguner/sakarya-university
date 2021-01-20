#include "IkiYonluDaireselBagliListe.hpp"
#include<iostream>
using namespace std;

	IkiYonluDaireselBagliListe::IkiYonluDaireselBagliListe()
	{
		this->dosyaElemani= NULL;
		this->degistirici= NULL;
		this->boyut = 0;
		this->mod = 0;
		this->obeb = 0;
		this->siraSayisi = 1;
		this->yazdirilanSiraSayisi = 0;
		
	}

	void IkiYonluDaireselBagliListe::ekle(int deger)
	{
		this->ekle(deger, dosyaElemani);
	}

	void IkiYonluDaireselBagliListe::ekle(int deger,Node* gosterici)
	{
		
		Node* nextNode = new Node(deger);
		Node* tutucu = new Node(0);
		
		if (dosyaElemani == NULL)
		{
			this->dosyaElemani = nextNode;
			
			this->dosyaElemani->setSagdaki(nextNode);
			this->dosyaElemani->setSoldaki(nextNode);
			
			this->obeb = 0;
			this->degistirici = this->dosyaElemani;
			
			this->boyut++;
			
		}
		
		else
		{
			if (this->obeb > EBOB.ebobAl(nextNode->getDeger(), gosterici->getDeger())&& siraSayisi < boyut)
			{
				this->siraSayisi++;
				this->ekle(nextNode->getDeger(), gosterici->getSagdaki());
			}
			
			else
			{
				if (nextNode->getDeger()< gosterici->getDeger())
				{
					this->mod = gosterici->getDeger() % nextNode->getDeger();
				}
				
				else
				{
					this->mod = nextNode->getDeger() % gosterici->getDeger();
				}
				
				this->degistirici = gosterici;
				
				if (mod == 0)
				{
					nextNode->setSoldaki(degistirici);
					nextNode->setSagdaki(degistirici->getSagdaki());
					degistirici->getSagdaki()->setSoldaki(nextNode);
					degistirici->setSagdaki(nextNode);
					boyut++;			
				}
				
				else
				{			
					for (int i = 0; i < mod; i++)
					{				
						this->degistirici = degistirici->getSoldaki();							
					}
					
					if (degistirici!=dosyaElemani)
					{	
						nextNode->setSoldaki(degistirici);
						nextNode->setSagdaki(degistirici->getSagdaki());
						degistirici->getSagdaki()->setSoldaki(nextNode);
						degistirici->setSagdaki(nextNode);											
					}
					
					else
					{
						nextNode->setSagdaki(degistirici);
						nextNode->setSoldaki(degistirici->getSoldaki());
						degistirici->getSoldaki()->setSagdaki(nextNode);
						degistirici->setSoldaki(nextNode);
						dosyaElemani = nextNode;								
					}
					
					boyut++;
				}
					
				if (this->obeb < EBOB.ebobAl(nextNode->getDeger(), gosterici->getDeger()))
				{
					this->obeb = EBOB.ebobAl(nextNode->getDeger(), gosterici->getDeger());
				}
				siraSayisi = 1;
			}		
		}
	}

	void IkiYonluDaireselBagliListe::yazdir(Node* yazdirilan)
	{
		yazdirilanSiraSayisi++;
		if ((boyut+1 ) > yazdirilanSiraSayisi)
		{
			char karakter = yazdirilan->getDeger();
			cout << karakter;
			yazdir(yazdirilan->getSagdaki());
		}
	}

	void IkiYonluDaireselBagliListe::yazdir()
	{
		yazdir(dosyaElemani);
	}

	IkiYonluDaireselBagliListe::~IkiYonluDaireselBagliListe()
	{
		
	}
