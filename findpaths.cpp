//Last modified by Wei Shi 04/25/2015


#include "graph/graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;



void parse(graph<unsigned int> & g, string textfile)
{

	cout << "Reading from " << textfile << "...\n" << endl;

	string input_string;
	ifstream instream;
	instream.open(textfile);

	string size;

	getline(instream, size);

	unsigned int numVertices=0;

	istringstream convert(size);                 
	convert >> numVertices;

	unsigned int vertexCount = 0;


	string cur_str;


	while(vertexCount < numVertices)
	{

		getline(instream, cur_str, '\n');



		string cur_vertex;

		unsigned int i = 0;

		while(cur_str[i] != ' ')
		{
			cur_vertex = cur_vertex + cur_str[i];

			i++;

		}
		
		unsigned int cur_vertex_num;

		istringstream convert(cur_vertex);
		if(!(convert >> cur_vertex_num))
			cout << "Failed to convert!" << endl;


		bool isWeight = false;


		list< pair<unsigned int, double > > adjList;



		/////////////////////
		//
		// Compute Adjacent
		//
		/////////////////////
		while(cur_str[i] != '-')
		{

			//The reason why adj_vertex_num becomes zero when you get to the else if is because:
			//When else if runs, the if doesn't, but the adj_vertex_num was initialized to 0 beginning of every loop.
			//Therefore when you construct pairToInsert using adj_vertex_num, it is always 0!
			unsigned int adj_vertex_num;

			//condition for computing vertex
			if(cur_str[i] != ' ' && !isWeight)
			{

				string adj_vertex;
				while(cur_str[i] != ' ')
				{

					adj_vertex = adj_vertex + cur_str[i];
					i++;
				}


				istringstream convert(adj_vertex);
				if(!(convert >> adj_vertex_num))
					cout << "Failed to convert!" << endl;


				isWeight = true;

			}

		
			//condition for computing weight of previous vertex
			else if(cur_str[i] != ' ' && isWeight)
			{
				string weight_str;
				while(cur_str[i] != ' ')
				{

					weight_str = weight_str + cur_str[i];
					i++;
				}

				double weight;

				istringstream convert(weight_str);
				if(!(convert >> weight))
					cout << "Failed to convert!" << endl;



				//after each weight calculation, we add a pair to the list.
				pair<unsigned int, double> pairToInsert(adj_vertex_num, weight);

				adjList.push_back(pairToInsert);

				isWeight = false;
			}
		

			i++;
		}
		//cout << "End vertex: " << cur_vertex_num << endl << endl;
		//cur_str = "-1";

		g.insert(cur_vertex_num, adjList);
		vertexCount++;
	}


	instream.close();
}

 
int main(int argc, char **argv )
{
	try
	{
		if (argc != 3) 
		{
			cout << "Usage: " << argv[0] << " <GRAPH_FILE>	<STARTING_VERTEX>	 " << endl;
			cout << "The <STARTING_VERTEX> must be an unsigned integer!" << endl;

			return 0;
		}

		graph<unsigned int> DijkstraTest;

		string filename(argv[1]);

		string start_vertex_str(argv[2]);

		parse(DijkstraTest, filename);

		unsigned int start_vertex;

		istringstream convert(start_vertex_str);
				                  
		convert >> start_vertex;

		DijkstraTest.print(cout);

		DijkstraTest.DijkstraPath(start_vertex);


		unsigned int to_vertex;
		char cont;
		while(cont != 'N' && cont != 'n')
		{

			cout << "\nEnter target unsigned integer vertex for minimum weight path to it from " << start_vertex << ": ";
			cin >> to_vertex;


			DijkstraTest.printPath(cout, to_vertex);

			cout << "\ncost: " << DijkstraTest.getDistance(to_vertex) << endl;

			cout << "Try again? (Y/N) ";
			cin >> cont;

		}





	}


	catch(runtime_error & RTE)
	{

		cout << RTE.what() << endl;


	}









/*
	graph<unsigned int> g;



	g.insert(1, { {2,2}, {4,1} });
	g.insert(2, { {4,3}, {5,10} });
	g.insert(3, { {1,4}, {6,5} });
	g.insert(4, { {3,2}, {6,8}, {7,4}, {5,2} });
	g.insert(5, { {7,6} });
	g.insert(6);
	g.insert(7, { {6,1} });


	g.print(cout);



	g.DijkstraPath(1);

	g.printPath(cout, 6);
*/

	return 0;

}
