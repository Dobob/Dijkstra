//Last Modified Wei Shi 5/14/2015

#ifndef VERTEX_H
#define VERTEX_H

#include "../distType/distType.h"
#include <list>

template<typename vertex_type>
class vertex
{
	private:

	vertex_type name;
	list< pair <vertex<vertex_type>*, double> > adj; // Adjacency list of pointers to vertices and corresponding weight to reach those vertices.

	

	//////used in dijkstra//////
	bool known;
	DistType dist;
	vertex<vertex_type>* path; // For recording shortest edge to current node.
	//////used in dijkstra//////

	public:
	vertex();

	//the two methods below sets the names
	vertex(const vertex_type & item);
	vertex(vertex_type && item);

	vertex(const vertex_type & item, const double & d);
	vertex(vertex_type && item, double && d);

	vertex(const vertex_type & item, list< pair<vertex<vertex_type>, double> > && l );
	vertex(vertex_type && item, list< pair<vertex<vertex_type>, double> > && l );

	~vertex();


	vertex & operator= (const vertex<vertex_type> & item);
	//vertex & operator= (vertex<vertex_type> && item);

	DistType & operator= (const DistType & d);
	DistType & operator= (DistType && d);

	double & operator= (const double & d);
	double & operator= (double && d);

	bool operator< (vertex<vertex_type> & item);
	bool operator< (vertex<vertex_type> && item);

	bool operator!= (const vertex<vertex_type> & item) const;
	bool operator!= (vertex<vertex_type> && item) const;

	bool isDistInfinity();

	//adds copies of v if v is already exists in the adj list.
	//The graph ADT decides whether to allow duplicates or not.
	void addToList(vertex<vertex_type>* v, const double & w);

	const bool noAdjacency() const;

	void setDist(const DistType & d);
	const DistType & getDistance() const;
	const vertex_type& getName() const;
	const vertex_type getPath() const;

	void print() const;


	void clear();
	void clearDijkstra();

	template<typename friendtype>
	friend class graph;


};

#include "vertex.cpp"

#endif
