//Last modified by Wei Shi 04/25/2015

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "distType.h"
using namespace std;

int main()
{
	DistType temp{5};
	double test;

	test = temp.getDistance();

	cout << "test: " << test << endl;




	return 0;

}
