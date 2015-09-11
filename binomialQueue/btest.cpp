//Last Modified Wei Shi 5/14/2015

#include "BinomialQueue/BinomialQueue.h"
#include "../graph/graph.h"
#include "../distType/distType.h"
#include "../vertex/vertex.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	BinomialQueue< vertex<unsigned int> > bq;

	vertex<unsigned int> a{4, 15.1};
	vertex<unsigned int> b{1, 13.2};
	vertex<unsigned int> c{7, 35.3};
	vertex<unsigned int> d{6, 2.4};
	vertex<unsigned int> e{5, 77.5};

	cout << "a.getDist(): " << a.getDist() << endl;
	cout << "b.getDist(): " << b.getDist() << endl;
	cout << "c.getDist(): " << c.getDist() << endl;
	cout << "d.getDist(): " << d.getDist() << endl;
	cout << "e.getDist(): " << e.getDist() << endl;

	cout << "a < c : " << (a<c) << endl;

	bq.insert(a);
	bq.insert(b);
	bq.insert(c);
	bq.insert(d);
	bq.insert(e);

	for(int i=0; i< 5; i++)
	{
		vertex<unsigned int> temp;
	
		bq.deleteMin(temp);

		temp.print();
	
		cout << endl;
	}
/*
	BinomialQueue< unsigned int > bq1;

	unsigned int f= 18,g= 17,h=23 ,i= 64,j=77;

	bq1.insert(f);
	bq1.insert(g);
	bq1.insert(h);
	bq1.insert(i);
	bq1.insert(j);


	for(int i=0; i< 5; i++)
	{
		unsigned int temp;
	
		bq1.deleteMin(temp);
	
		cout << temp << ' ';
	}
*/
	return 0;

}
