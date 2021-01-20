#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std;

class File 
{
	public:
		File();
	
	void Read(string&)const;

	
	~File();
};
#endif