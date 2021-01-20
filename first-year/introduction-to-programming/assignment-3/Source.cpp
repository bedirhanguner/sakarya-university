#include <iostream>
#include <math.h>
using namespace std;

const int girissatir = 5, girissutun = 5;

int satirkontrol = 0, sutunkontrol = 0, a = 0, b = 0, toplam = 0, cikiselemani = 0, dizileneleman = 0;;

struct Islem {
	int giris[100][100] = { {3,2,5,1,4},
						  {6,2,1,0,7},
						  {3,0,0,2,0},
						  {1,1,3,2,2,},
						  {0,3,1,0,0} };

	int cekirdek[100][100];
	int cikismatris[100][100];
};

void matrisiyaz(int satirkontrol, int sutunkontrol, int cekirdeksatir, int cekirdeksutun, int cikissatir, int kaymamiktari, int cekirdek[][100]) {

	Islem matris;

	matris.giris[100][100];

	while (satirkontrol < cikissatir + kaymamiktari - 1) {

		for (int i = satirkontrol, a = 0; a < cekirdeksatir, i < cekirdeksatir + satirkontrol; a++, i++) {
			for (int j = sutunkontrol, b = 0; b < cekirdeksatir, j < cekirdeksutun + sutunkontrol; b++, j++) {
				//Her seferinde belirlenen matris değerlerini çarparak toplam değerine eşitle.
				toplam += matris.giris[i][j] * cekirdek[a][b];
			}
		}
		sutunkontrol += kaymamiktari;

		cout << toplam << "\t";
		dizileneleman++;

		if (dizileneleman == cikissatir) {
			cout << endl;
			dizileneleman = 0;
		}
		toplam = 0;

		if (sutunkontrol >= cikissatir + kaymamiktari - 1) {
			sutunkontrol = 0;
			satirkontrol += kaymamiktari;
		}
	}
}

int main() {

	Islem matris;

	int girisboyut = sizeof(matris.giris) / sizeof(matris.giris[0][0]);
	girisboyut = sqrt(girisboyut);

	int cekirdeksatir, cekirdeksutun, kaymamiktari;
	cout << "Cekirdek matrisinin satir sayisini giriniz: "; cin >> cekirdeksatir;
	cout << "Cekirdek matrisinin sutun sayisini giriniz: "; cin >> cekirdeksutun;
	cout << "Kayma miktarini giriniz: "; cin >> kaymamiktari;

	if (kaymamiktari >= cekirdeksatir || kaymamiktari >= cekirdeksutun || kaymamiktari == 0) {
		cout << "Bu islem yapilamaz." << endl;
		return 0;
	}

	int cekirdek[100][100];
	for (int i = 0; i < cekirdeksatir; i++) {
		for (int j = 0; j < cekirdeksutun; j++) {
			cout << "cekirdek [" << i + 1 << "][" << j + 1 << "] = "; cin >> cekirdek[i][j];
		}
	}

	int cikissatir, cikissutun;
	cikissatir = ((girissatir - cekirdeksatir) / kaymamiktari) + 1;
	cikissutun = ((girissutun - cekirdeksutun) / kaymamiktari) + 1;

	cout << endl << endl;
	matrisiyaz(satirkontrol, sutunkontrol, cekirdeksatir, cekirdeksutun, cikissatir, kaymamiktari, cekirdek);

	cout << endl;
	system("pause");
	return 0;
}
