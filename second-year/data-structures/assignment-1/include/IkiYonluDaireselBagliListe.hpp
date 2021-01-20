#ifndef ITETATOR_HPP
#define ITERATOR_HPP

#include"Node.hpp"
#include "Ebob.hpp"

class IkiYonluDaireselBagliListe
{
	private:
		Node* dosyaElemani;
		Node* degistirici;
		
		int obeb;
		int mod;
		
		int boyut;
		int siraSayisi;
		int yazdirilanSiraSayisi;
		
		Ebob EBOB;
		
	public:
		IkiYonluDaireselBagliListe();

		void ekle(int);
		void ekle(int, Node*);
		void yazdir(Node*);
		void yazdir();
		
		~IkiYonluDaireselBagliListe();
};

#endif