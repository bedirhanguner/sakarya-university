#ifndef FILE_HPP
#define FILE_HPP

#include "CompanyAVLTree.hpp"
#include "EmployeeAVLTree.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class File
{
public:
	File();

	void Read(string &) const;

	~File();
};
#endif