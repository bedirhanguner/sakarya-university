hepsi: compile run

compile:
	g++ -I ./include/ -o ./lib/File.o -c ./src/File.cpp
	g++ -I ./include/ -o ./lib/Iterator.o -c ./src/Iterator.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Arrays.o -c ./src/Arrays.cpp
	g++ -I ./include/ -o ./lib/CircularDoublyLinkedList.o -c ./src/CircularDoublyLinkedList.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/File.o ./lib/CircularDoublyLinkedList.o ./lib/Node.o ./lib/Arrays.o ./lib/Iterator.o ./src/Test.cpp
	
run:
	./bin/Test.exe