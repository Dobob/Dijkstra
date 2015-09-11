//Last Modified Wei Shi 5/14/2015

template<typename vertex_type>
vertex<vertex_type>::vertex(): name{vertex_type()}, dist{ DistType() }, known{false}, adj{ list< pair<vertex<vertex_type>*, double> >() }, path(nullptr)
{
	


}


template<typename vertex_type>
vertex<vertex_type>::vertex(const vertex_type & item): name{item}, dist{ DistType() }, known{false}, adj{ list< pair<vertex<vertex_type>*, double> >() }, path(nullptr)
{

}

template<typename vertex_type>
vertex<vertex_type>::vertex(vertex_type && item): name{std::move(item)}, dist{ DistType() }, known{false}, adj{ list< pair<vertex<vertex_type>*, double> >() }, path(nullptr)
{

}

template<typename vertex_type>
vertex<vertex_type>::vertex(const vertex_type & item, const double & d): name{std::move(item)}, dist{d}, known{false}, adj{ list< pair<vertex<vertex_type>*, double> >() }, path(nullptr)
{



}

template<typename vertex_type>
vertex<vertex_type>::vertex(vertex_type && item, double && d): name{std::move(item)}, dist{std::move(d)}, known{false}, adj{ list< pair<vertex<vertex_type>*, double> >() }, path(nullptr)
{

}






template<typename vertex_type>
vertex<vertex_type>::vertex(const vertex_type & item, list< pair<vertex<vertex_type>, double> > && l ): name{item}, dist{ DistType() }, known{false}, path(nullptr)
{

	name = item;



	for(auto list_entry: l)
	{
		vertex<vertex_type>* temp_vertex = new vertex<vertex_type>( list_entry->first );

		pair< vertex<vertex_type>*, double > pairToInsert(temp_vertex, list_entry->second);

		adj.push_back(pairToInsert);

	}

	


}

template<typename vertex_type>
vertex<vertex_type>::	vertex(vertex_type && item, list< pair<vertex<vertex_type>, double> > && l ): name{item}, dist{ DistType() }, known{false}, path(nullptr)
{

	name = std::move(item);

	for(auto list_entry: l)
	{
		vertex<vertex_type>* temp_vertex = new vertex<vertex_type>( list_entry->first );

		pair< vertex<vertex_type>*, double > pairToInsert(temp_vertex, list_entry->second);

		adj.push_back(pairToInsert);

	}

}

template<typename vertex_type>
vertex<vertex_type>::~vertex()
{
	clear();

}



template<typename vertex_type>
vertex<vertex_type> & vertex<vertex_type>::operator= (const vertex<vertex_type> & item)
{
	name = item.name;
	adj = item.adj;
	known = item.known;
	dist = item.dist;
	path = item.path; 

	return *this;

}


/*
template<typename vertex_type>
vertex<vertex_type> & vertex<vertex_type>::operator= (vertex<vertex_type> && item)
{
	name = std::move(item.name);
	adj = std::move(item.adj);
	known = std::move(item.known);
	dist = std::move(item.dist);
	path = std::move(item.path); 

	return *this;
}
*/
template<typename vertex_type>
DistType & vertex<vertex_type>::operator= (const DistType & d)
{
	dist = d;

	return dist;

}


template<typename vertex_type>
DistType & vertex<vertex_type>::operator= (DistType && d)
{
	dist = d;

	return dist;
}

template<typename vertex_type>
double & vertex<vertex_type>::operator= (const double & d)
{
	dist = d;

	return d;

}


template<typename vertex_type>
double & vertex<vertex_type>::operator= (double && d)
{


	dist = d;

	return d;

}


template<typename vertex_type>
bool vertex<vertex_type>::operator!= (const vertex<vertex_type> & item) const
{
	return (dist != item.dist);


}


template<typename vertex_type>
bool vertex<vertex_type>::operator!= (vertex<vertex_type> && item) const
{
	return (dist != std::move(item.dist));


}

template<typename vertex_type>
bool vertex<vertex_type>::operator< ( vertex<vertex_type> & item)
{
/*
	if(dist.isInfinity() || item.isDistInfinity())
		return false;
*/


	return (dist < item.dist);
	

}



template<typename vertex_type>
bool vertex<vertex_type>::operator< (vertex<vertex_type> && item)
{
/*
	if(dist.isInfinity() || item.isDistInfinity())
		return false;
*/

	return (dist < std::move(item).dist);




}


template<typename vertex_type>
void vertex<vertex_type>::clear()
{

/*
	vertex_type name;
	list< vertex<vertex_type>* > adj;
	bool known;
	DistType dist;
	vertex* path;
*/
	name = vertex_type();
	adj = list< pair<vertex<vertex_type>*, double> >();
	known = false;
	dist = DistType();
	path = nullptr;

}
template<typename vertex_type>
void vertex<vertex_type>::clearDijkstra()
{

	known = false;
	dist = DistType();
	path = nullptr;

}


template<typename vertex_type>
void vertex<vertex_type>::addToList(vertex<vertex_type>* v, const double & w)
{
/*
	bool found = false;

	for(auto & pair: adj)
	{
		if(v == pair.first)
		{
			pair.second = w;

			found = true;
		}

	}

	if(!found)
	{
*/
		pair<vertex<vertex_type>*, double> pairToInsert(v, w);

		adj.push_back(pairToInsert);


	//}
}


template<typename vertex_type>
const bool vertex<vertex_type>::noAdjacency() const
{



	return adj.empty();



}


template<typename vertex_type>
void vertex<vertex_type>::setDist(const DistType & d)
{

	dist = d;


}



template<typename vertex_type>
void vertex<vertex_type>::print() const
{

	cout << name << ": " << dist << ' ';

}

template<typename vertex_type>
const vertex_type& vertex<vertex_type>::getName() const
{

	return name;

}




template<typename vertex_type>
bool vertex<vertex_type>::isDistInfinity()
{
	return dist.isInfinity();



}

template<typename vertex_type>
const DistType & vertex<vertex_type>::getDistance() const
{

	return dist;


}


template<typename vertex_type>
const vertex_type vertex<vertex_type>:: getPath() const
{

	if(path != nullptr)
		return path->name;

	return (vertex_type());

}









