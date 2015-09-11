//Created by Wei Shi 5/11/2015
#ifndef GRAPH_ADJLIST_H
#define GRAPH_ADJLIST_H

#include <vector>
#include <string>
#include <list>
#include <stdexcept>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include "../distType/distType.h"
#include "../vertex/vertex.h"
#include "../binomialQueue/BinomialQueue/BinomialQueue.h"
using namespace std;


/*
	A different implementation:
	
	still use a map

	key = vertex_type name

	value = vertex_type (no longer a list)

	class vertex_type
	{
	
		private:

			name

			list of adjacent vertices
	}


	why is this faster?

	once you find a vertex_type u. you go to its adjacent vertex_type v. If from v you want to go to one of v's adjacent vertex_type, you would have to go look up in the map the value of v and find it's adjaceny list.

	This implementation is faster because once you find v, you can access v as an object to get its list of adjacent vertices without having to do a look-up in the map again. Of course you trade data for speed again.
*/


template <typename vertex_type>
class graph
{
	private:


		//you can only insert a pair into an unordered_map.
		//we don't actually need a new hash function for vertex_type if we can assume that the vertex_type is unsigned int.
		unordered_map< vertex_type, vertex<vertex_type>* > graph_;

	public:

		graph();
		graph(const graph & rhs);
		graph(graph && rhs);

		~graph();

		void clear();

		void insert(const vertex_type & item);
		void insert(vertex_type && item);


		//void insert(const vertex_type & item, const list< vertex_type > & adjList);
		//void insert(vertex_type && item, list< vertex_type > && adjList);


		void insert(const vertex_type & item, const list< pair<vertex_type, double> > & adjList);


		void insert(vertex_type && item, list< pair<vertex_type, double> > && adjList);


		//void direct(const vertex_type & from, const pair<vertex_type, double> & to_item);
		//void direct(vertex_type && from, pair<vertex_type, double> && to_item);

		void print(ostream & out);
		void printPath(ostream & out, const vertex_type & to_v);
		void printPath(ostream & out, vertex_type && to_v);


		void printAdjFrom(const vertex_type & item);


		const list< pair<vertex<vertex_type>*, double> >  & getAdjList(vertex_type && v);
		const list< pair<vertex<vertex_type>*, double> >  & getAdjList(const vertex_type & v);

		bool pointerWorks();

		const size_t & size();

		const DistType & getDistance(const vertex_type & v); 
		const DistType & getDistance(vertex_type && v); 

		//for dijkstra, let the user clear the dijkstra vertex variables
		void clearDijkstra();

		//finds shortest path to all vertices.
		//run this repeatedly for all vertices to get shortest path from start_vertex to all vertices.
		void DijkstraPath(	const vertex_type & start_vertex	);






};


#include "graph.cpp"

#endif
