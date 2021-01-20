#include "File.hpp"

int main()
{
	File* file = new File();
	string filePath = "Sayilar.txt";
	file->Read(filePath);
	
	
	delete file;

	return 0;
}