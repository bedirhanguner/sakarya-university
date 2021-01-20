hepsi: derle calistir

derle:
	g++ -I ./include -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include -o ./lib/Ebob.o -c ./src/Ebob.cpp
	g++ -I ./include -o ./lib/Dosya.o -c ./src/Dosya.cpp
	g++ -I ./include -o ./lib/IkiYonluDaireselBagliListe.o -c ./src/IkiYonluDaireselBagliListe.cpp
	g++ -I ./include -o ./bin/main.exe ./lib/Node.o ./lib/Ebob.o ./lib/Dosya.o ./lib/IkiYonluDaireselBagliListe.o ./src./Main.cpp

calistir:
	./bin/main.exe