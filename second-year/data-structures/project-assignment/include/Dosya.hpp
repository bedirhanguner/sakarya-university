#ifndef DOSYA_HPP
#define DOSYA_HPP

#include "Dosya.hpp"
#include "AVL_Agaci.hpp"

#include <iostream>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std;

class Dosya 
{
	public:
		Dosya();
	
	void oku(string&)const;
	
	~Dosya();
};
#endif