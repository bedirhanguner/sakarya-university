hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/AVL_Agaci.o -c ./src/AVL_Agaci.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Yigit.o -c ./src/Yigit.cpp
	g++ -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.cpp
	g++ -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/AVL_Agaci.o ./lib/Dugum.o ./lib/Dosya.o ./lib/Yigit.o ./lib/Kisi.o ./src/Test.cpp
	
calistir:
	./bin/Test.exe