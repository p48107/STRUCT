#pragma once
#include<iostream>
using namespace std;
template<class tipo> 
class Bucky
{
private:
	tipo first, second;
public:
	Bucky(tipo f, tipo s);
	tipo bigger();
};

