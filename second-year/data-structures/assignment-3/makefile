everything: compile run

compile:
	g++ -I ./include/ -o ./lib/CompanyAVLTree.o -c ./src/CompanyAVLTree.cpp
	g++ -I ./include/ -o ./lib/EmployeeAVLTree.o -c ./src/EmployeeAVLTree.cpp
	g++ -I ./include/ -o ./lib/EmployeeNode.o -c ./src/EmployeeNode.cpp
	g++ -I ./include/ -o ./lib/CompanyNode.o -c ./src/CompanyNode.cpp
	g++ -I ./include/ -o ./lib/Employee.o -c ./src/Employee.cpp
	g++ -I ./include/ -o ./lib/File.o -c ./src/File.cpp
	g++ -I ./include/ -o ./lib/Company.o -c ./src/Company.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/CompanyAVLTree.o ./lib/EmployeeAVLTree.o ./lib/EmployeeNode.o  ./lib/CompanyNode.o ./lib/File.o ./lib/Employee.o ./lib/Company.o ./src/Test.cpp
	
run:
	./bin/Test.exe