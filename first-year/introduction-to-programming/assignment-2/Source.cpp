#include <iostream>
#include<iomanip>
#include <locale.h>
#include<conio.h>

using namespace std;

int main() {

	setlocale(LC_ALL, "Turkish");

	int j, a_sayisi = 0, e_sayisi = 0, i_sayisi = 0, o_sayisi = 0, u_sayisi = 0;

	char mesaj[1000];

	cout << "Herhangi bir þey yazýnýz: ";

	cin.getline(mesaj,1000);

	for (j = 0; j < mesaj[j]; j++) {

		if (mesaj[j] == 'a' || mesaj[j] == 'A')
			a_sayisi = a_sayisi + 1;

		else if (mesaj[j] == 'e' || mesaj[j] == 'E')
			e_sayisi = e_sayisi + 1;
				
		else if (mesaj[j] == 'i' || mesaj[j] == 'I')
			i_sayisi = i_sayisi + 1;
			
		else if (mesaj[j] == 'o' || mesaj[j] == 'O')
			o_sayisi = o_sayisi + 1;
		
		else if (mesaj[j] == 'u' || mesaj[j] == 'U')
			u_sayisi = u_sayisi + 1;
	}
	cout << endl;
	cout << "Girdiðiniz mesajdaki sesli harflerin tanýmlanmasý:";
	cout << endl;	
	cout << endl << setw(3) << "H" << setw(5) << "TS" << setw(5) << "1" << setw(5) << "2" << setw(5) << "3" << setw(5) << "4" << setw(5) << "5" << setw(5) << "6" << setw(5) << "7" << setw(5) << "8" << setw(5) << "9" << setw(5) << "10" << setw(2) << "|" << endl;

	cout << setw(3) << "a" << setw(5) << a_sayisi;
	for (a_sayisi >= 0; a_sayisi--;)
		cout << setw(5) << "a";
	cout << endl;

	cout << setw(3) << "e" << setw(5) << e_sayisi;
	for (e_sayisi >= 0; e_sayisi--;)
		cout << setw(5) << "e";
	cout << endl;

	cout << setw(3) << "i" << setw(5) << i_sayisi;
	for (i_sayisi >= 0; i_sayisi--;)
		cout << setw(5) << "i";
	cout << endl;

	cout << setw(3) << "o" << setw(5) << o_sayisi;
	for (o_sayisi >= 0; o_sayisi--;)
		cout << setw(5) << "o";
	cout << endl;

	cout << setw(3) << "u" << setw(5) << u_sayisi;
	for (u_sayisi >= 0; u_sayisi--;)
		cout << setw(5) << "u";
	cout << endl << endl;

	cout << "Þeklindedir."<<endl;

	system("PAUSE");
}
