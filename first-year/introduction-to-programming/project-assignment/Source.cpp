#include	<iostream>
#include	<Windows.h>
#include	<time.h>
using namespace std;

struct Hucre {
	int			x;
	int			y;
	char		karakter;
};

const int	EkranGenisligi = 80;
const int	EkranYuksekligi = 25;
int			UcakGovdesi = 2;
int			Sayac = 0;
int			Sayac1 = 0;
int			Sayac2 = 0;
char		ekran[100][100];
char		tuslar[256];

Hucre		Mermi[10000];
Hucre		Ucak[50];
Hucre		Dusman[100];

void KoordinataGit(int x, int y) {
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}

void KlavyeOku(char tuslar[]) {
	for (int i = 0; i <= 256; i++) {
		tuslar[i] = (char)(GetAsyncKeyState(i) >> 8);
	}
}

void FareGostergesiniGizle() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void EkraniCiz() {
	for (int y = 0; y < EkranYuksekligi; y++) {
		for (int x = 0; x < EkranGenisligi; x++) {
			cout << ekran[x][y];
		}
		cout << endl;
	}
}

void EkraniTemizle() {
	for (int y = 0; y < EkranYuksekligi; y++) {
		for (int x = 0; x < EkranGenisligi; x++) {
			ekran[x][y] = 32;
		}
	}
}

void SinirlariOlustur() {

	for (int x = 0; x < EkranGenisligi; x++) {
		ekran[x][0] = 219;
		ekran[x][EkranYuksekligi - 1] = 219;
	}
	for (int y = 0; y < EkranYuksekligi; y++) {
		ekran[0][y] = 219;
		ekran[EkranGenisligi - 1][y] = 219;
	}
}

void UcagiOlustur() {
	Ucak[0].x = 4;
	Ucak[0].y = 11;
	Ucak[0].karakter = 219;
}

void UcagiHareketEttir() {
	for (int i = 0; i < UcakGovdesi; i++) {
		if (Ucak[i].y == 2) {
			for (int i = 0; i < UcakGovdesi; i++) {
				Ucak[i].y++;
			}
		}
		if (Ucak[i].y == EkranYuksekligi-2 ) {
			for (int i = 0; i < UcakGovdesi; i++) {
				Ucak[i].y--;
			}
		}	
	}
}

void UcagiEkranaYerlestir() {

	for (int i = 0; i < UcakGovdesi; i++) {
		int x = Ucak[i].x;
		int y = Ucak[i].y;
		ekran[x][y] = 219;
		ekran[x - 1][y-1] = 219;
		ekran[x -2][y -2] = 220;
		ekran[x-1][y+1] = 219;
		ekran[x-2][y+2] = 223;
	}
}

void MermiyiOlustur() {
	Mermi[Sayac].x = Ucak[0].x+1;
	Mermi[Sayac].y = Ucak[0].y;
	Mermi[Sayac].karakter = '*';
	Sayac++;
}

void MermiyiHareketEttir() {

	for (int i = 0; i < 1000; i++) {
		if (Mermi[i].x < 80) {
			Mermi[i].x += 1;
		}

		if (Mermi[i].x == 79) {
			Mermi[i].x = 81;	
		}
	}

}

void MermiyiEkranaYerlestir(){
	for (int i = 1; i <Sayac; i++){
		int x = Mermi[i].x;
		int y = Mermi[i].y;
		ekran[x][y] = Mermi[i].karakter;	
	}
}

void DusmaniOlustur() {

	if (Sayac1 % 25 == 0) {

		int a = 1 + rand() % (EkranYuksekligi - 5);

		Dusman[Sayac2].x = 80;
		Dusman[Sayac2].y = a;
		Dusman[Sayac2].karakter = 178;
		Sayac2++;
	}
}

void DusmaniEkranaYerlestir() {

	for (int i = 1; i < Sayac2; i++){
		for (int j = 0; j < Sayac; j++){
			if (Mermi[j].x == Dusman[i].x && Mermi[j].y == Dusman[i].y || Mermi[j].x == Dusman[i].x && Mermi[j].y == Dusman[i].y+1 || Mermi[j].x == Dusman[i].x && Mermi[j].y == Dusman[i].y+2|| Mermi[j].x == Dusman[i].x+1 && Mermi[j].y == Dusman[i].y || Mermi[j].x == Dusman[i].x+1 && Mermi[j].y == Dusman[i].y + 1 || Mermi[j].x == Dusman[i].x+1 && Mermi[j].y == Dusman[i].y + 2) {
				Dusman[i].x = 86;
			}
		}
	}

	for (int i = 1; i < Sayac2; i++){
	int x = Dusman[i].x;
	int y = Dusman[i].y;
	ekran[x][y] = 178;
	ekran[x][y + 1] = 178;
	ekran[x][y + 2] = 178;
	ekran[x + 1][y] = 178;
	ekran[x + 1][y + 2] = 178;
	ekran[x + 2][y] = 178;
	ekran[x + 2][y + 1] = 178;
	ekran[x + 2][y + 2] = 178;
	}
}

void DusmaniHareketEttir() {
	
	for (int i = 0; i < 1000; i++) {

		if (Dusman[i].x > 0 && Dusman[i].x <85) {
			Dusman[i].x -= 1;
		}

		if (Dusman[i].x == 1) {
			Dusman[i].x = 90;
		}
	}
	Sayac1++;
}

void KlavyeKontrol() {

		KlavyeOku(tuslar);
		if (tuslar[38] != 0 || tuslar[87] != 0) {
			Ucak[0].y--;
		}

		if (tuslar[40] != 0 || tuslar[83] != 0) {
			Ucak[0].y++;
		}

		if (tuslar[32] != 0) {
			MermiyiOlustur();
		}
}

int main() {

	srand(time(NULL));

	FareGostergesiniGizle();
	KoordinataGit(0, 0);
	UcagiOlustur();

	while (true) {

		EkraniTemizle();

		SinirlariOlustur();
		DusmaniOlustur();
		DusmaniHareketEttir();
		DusmaniEkranaYerlestir();
		KlavyeKontrol();
		UcagiHareketEttir();
		UcagiEkranaYerlestir();
		MermiyiHareketEttir();
		MermiyiEkranaYerlestir();

		KoordinataGit(0, 0);
		EkraniCiz();

		Sleep(0);
	}
	
	return 0;
}
