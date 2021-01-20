hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/ADSOYAD.o -c ./src/ADSOYAD.c
	gcc -I ./include/ -o ./lib/YAS.o -c ./src/YAS.c
	gcc -I ./include/ -o ./lib/TCKN.o -c ./src/TCKN.c
	gcc -I ./include/ -o ./lib/TELEFONNO.o -c ./src/TELEFONNO.c
	gcc -I ./include/ -o ./lib/IMEI.o -c ./src/IMEI.c
	
	
	
	gcc -I ./include/ -o ./bin/Test ./lib/ADSOYAD.o ./lib/YAS.o ./lib/TCKN.o ./lib/TELEFONNO.o ./lib/IMEI.o ./src/Test.c
	
calistir:
	./bin/Test