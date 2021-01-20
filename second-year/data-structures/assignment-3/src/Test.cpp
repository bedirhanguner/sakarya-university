#include "File.hpp"

int main()
{
	File *file = new File();
	string filePath = "Veri.txt";
	file->Read(filePath);

	return 0;
}