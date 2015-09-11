//Created by Wei Shi 5/11/2015


///////////////////////////////////////////////////////////////
//
//										BEGIN CONSTRUCTORS
//
///////////////////////////////////////////////////////////////
template <typename vertex_type>
graph<vertex_type>::graph(): graph_{ unordered_map< vertex_type, vertex<vertex_type>* >() }
{
	

}


template <typename vertex_type>
graph<vertex_type>::graph(const graph & rhs)
{
	graph_ = rhs.graph_;

}

template <typename vertex_type>
graph<vertex_type>::graph(graph && rhs)
{

	graph_ = std::move(rhs.graph_);


}

template <typename vertex_type>
graph<vertex_type>::~graph()
{
	clear();

}



///////////////////////////////////////////////////////////////
//
//										END CONSTRUCTORS
//
///////////////////////////////////////////////////////////////

template <typename vertex_type>
void graph<vertex_type>::clear()
{

	graph_.clear();


}

//////////////////////////////////////////////////////
//
//		insert(vertex_type, list_empty)
//
//////////////////////////////////////////////////////
template <typename vertex_type>
void graph<vertex_type>::insert(const vertex_type & item)
{

	typename unordered_map<vertex_type, vertex<vertex_type>* >::const_iterator lookup = graph_.find(item);

	if(lookup != graph_.end())
	{
		vertex<vertex_type>* newVertex = new vertex<vertex_type>(item);

		pair<vertex_type, vertex<vertex_type>* > newPair(item, newVertex);

		graph_.insert(newPair);

	}

}

template <typename vertex_type>
void graph<vertex_type>::insert(vertex_type && item)
{
	typename unordered_map<vertex_type, vertex<vertex_type>* >::const_iterator lookup = graph_.find(std::move(item));

	if(lookup != graph_.end())
	{
		vertex<vertex_type>* newVertex = new vertex<vertex_type>(std::move(item));

		pair<vertex_type, vertex<vertex_type>* > newPair(std::move(item), newVertex );

		graph_.insert(newPair);

	}


}

/*
template <typename vertex_type>
void graph<vertex_type>::insert(const vertex_type & item, const list< vertex_type > & adjList)
{
	typename unordered_map<vertex_type, vertex<vertex_type>* >::const_iterator lookup = graph_.find(item);

	if( lookup == graph_.end())
	{

		vertex<vertex_type>* newVertex = new vertex<vertex_type>(item);

		for(auto list_entry: adjList)
		{
			lookup = graph_.find(list_entry);

			if(lookup == graph_.end())
			{
				vertex<vertex_type>* temp_vertex = new vertex<vertex_type>{list_entry};

				newVertex.addToList(temp_vertex, 1);

			}



			else//vertex found in graph
			{
				vertex<vertex_type>* temp_vertex = lookup->second;

				newVertex.addToList(temp_vertex, 1);

			}
	
		}

		pair<vertex_type, vertex<vertex_type>* > newPair(item, newVertex);

		graph_.insert(newPair);

	}

}


template <typename vertex_type>
void graph<vertex_type>::insert(vertex_type && item, list< vertex_type > && adjList)
{
	typename unordered_map<vertex_type, vertex<vertex_type>* >::const_iterator lookup = graph_.find(item);

	if( lookup == graph_.end())
	{

		vertex<vertex_type>* newVertex = new vertex<vertex_type>(item);

		for(auto list_entry: adjList)
		{
			lookup = graph_.find(list_entry);

			if(lookup == graph_.end())
			{
				vertex<vertex_type>* temp_vertex = new vertex<vertex_type>{list_entry};

				newVertex.addToList(temp_vertex, 1);

			}



			else//vertex found in graph
			{
				vertex<vertex_type>* temp_vertex = lookup->second;

				newVertex.addToList(temp_vertex, 1);

			}
	
		}
		pair<vertex_type, vertex<vertex_type>* > newPair(std::move(item), newVertex);

		graph_.insert(newPair);

	}

 	//don't delete adjList

}
*/
//////////////////////////////////////////////////////
//
//			insert(vertex_type, list of pairs)
//
//////////////////////////////////////////////////////
template <typename vertex_type>
void graph<vertex_type>::insert(vertex_type && item, list< pair<vertex_type, double> > && adjList)
{


	typename unordered_map<vertex_type, vertex<vertex_type>* >::const_iterator lookup = graph_.find(std::move(item));


	if( lookup == graph_.end())
	{

		vertex<vertex_type>* newVertex = new vertex<vertex_type>(std::move(item));

		for(auto list_entry: adjList)
		{
			lookup = graph_.find(list_entry.first);

			if(lookup == graph_.end())
			{
				vertex<vertex_type>* temp_vertex = new vertex<vertex_type>{list_entry.first};


				pair< vertex_type, vertex<vertex_type>* > pairToInsert(list_entry.first, temp_vertex);
			
				graph_.insert(pairToInsert);


				newVertex->addToList(temp_vertex, list_entry.second);



			}


			else//vertex found in graph
			{

				newVertex->addToList(lookup->second, list_entry.second);

			}
	

		}

		pair<vertex_type, vertex<vertex_type>* > newPair(std::move(item), newVertex);

		graph_.insert(newPair);

	}

	else //item is already a vertex in the graph
	{
		vertex<vertex_type>* current_vertex = lookup->second;

		for(auto list_entry: adjList)
		{
			lookup = graph_.find(list_entry.first);

			if(lookup == graph_.end())//not found
			{
				vertex<vertex_type>* temp_vertex = new vertex<vertex_type>{list_entry.first};

				pair< vertex_type, vertex<vertex_type>* > pairToInsert(list_entry.first, temp_vertex);
			
				graph_.insert(pairToInsert);


				current_vertex->addToList(temp_vertex, list_entry.second);

			}


			else//vertex found in graph
			{

				current_vertex->addToList(lookup->second, list_entry.second);

			}
	

		}
		

	}

 	//don't delete adjList

}

template <typename vertex_type>
void graph<vertex_type>::insert(const vertex_type & item, const list< pair<vertex_type, double> > & adjList)
{

	typename unordered_map<vertex_type, vertex<vertex_type>* >::const_iterator lookup = graph_.find(item);


	if( lookup == graph_.end())
	{

		vertex<vertex_type>* newVertex = new vertex<vertex_type>(item);

		for(auto list_entry: adjList)
		{
			lookup = graph_.find(list_entry.first);

			if(lookup == graph_.end())
			{
				vertex<vertex_type>* temp_vertex = new vertex<vertex_type>{list_entry.first};


				pair< vertex_type, vertex<vertex_type>* > pairToInsert(list_entry.first, temp_vertex);
			
				graph_.insert(pairToInsert);


				newVertex->addToList(temp_vertex, list_entry.second);



			}


			else//vertex found in graph
			{

				newVertex->addToList(lookup->second, list_entry.second);

			}
	

		}

		pair<vertex_type, vertex<vertex_type>* > newPair(item, newVertex);

		graph_.insert(newPair);

	}

	else //item is already a vertex in the graph
	{
		vertex<vertex_type>* current_vertex = lookup->second;

		for(auto list_entry: adjList)
		{
			lookup = graph_.find(list_entry.first);

			if(lookup == graph_.end())//not found
			{
				vertex<vertex_type>* temp_vertex = new vertex<vertex_type>{list_entry.first};

				pair< vertex_type, vertex<vertex_type>* > pairToInsert(list_entry.first, temp_vertex);
			
				graph_.insert(pairToInsert);


				current_vertex->addToList(temp_vertex, list_entry.second);

			}


			else//vertex found in graph
			{

				current_vertex->addToList(lookup->second, list_entry.second);

			}
	

		}
		

	}
 

}

//////////////////////////////////////////////////////
//
//		direct(from vertex, to vertex)
//
//////////////////////////////////////////////////////
/*
template <typename vertex_type>
void graph<vertex_type>::direct(const vertex_type & from, const pair<vertex_type, double> & to_item)
{
	if(!find(from))
	{
		cout << "\"from\" vertex_type not found! " << endl;

		return;

	}

	graph_[from].push_back(to_item);


}

template <typename vertex_type>
void graph<vertex_type>::direct(vertex_type && from, pair<vertex_type, double> && to_item)
{

	if(!find(from))
	{
		cout << "\"from\" vertex_type not found! " << endl;

		return;

	}

	graph_[from].push_back(std::move( to_item ));





}
*/
//////////////////////////////////////////////////////
//
//										getAdjList
//
//////////////////////////////////////////////////////

template <typename vertex_type>
const list< pair<vertex<vertex_type>*, double> >  & graph<vertex_type>::getAdjList(vertex_type && v)
{

	return graph_[std::move(v)]->adj;




}
template <typename vertex_type>
const list< pair<vertex<vertex_type>*, double> >  & graph<vertex_type>::getAdjList(const vertex_type & v)
{

	return graph_[v]->adj;




}


template <typename vertex_type>
void graph<vertex_type>::print(ostream & out)
{
	//graph_ contains pairs, which requires getting either the key or value before printing.
	for(auto & entry_key: graph_)
	{
		out << get<0>(entry_key) << ": ";
		
		//entry_value is vertex*
		for(auto & entry_list: graph_[get<0>(entry_key)]->adj)
		{

			out << entry_list.first->name; 
			out << '(' << entry_list.second << ") ";


		}

		out << endl;
	}

}

template <typename vertex_type>
void graph<vertex_type>::printAdjFrom(const vertex_type & item)
{
	list< pair<vertex<vertex_type>*, double> > l = getAdjList(item);

	cout << "\n" << item << ": ";

	for(auto list_entry: l)
	{
		cout << list_entry.first->name << '(' << list_entry.second << ") ";

	}


}
template <typename vertex_type>
const size_t & graph<vertex_type>::size()
{
	return graph_.size();



}

template <typename vertex_type>
bool graph<vertex_type>::pointerWorks()
{


	return ( graph_[2]->adj.front().first == graph_[1]->adj.front().first);



}



template <typename vertex_type>
void graph<vertex_type>::clearDijkstra()
{

	for(auto pair: graph_)
	{
		
		//pair is an iterator to the ith element in graph_
		pair.second->clearDijkstra();


	}

}


template <typename vertex_type>
const DistType & graph<vertex_type>::getDistance(const vertex_type & v)
{
	
	return (graph_[v]->dist);

}
template <typename vertex_type>
const DistType & graph<vertex_type>::getDistance(vertex_type && v)
{

	return (graph_[v]->dist);

}

template <typename vertex_type>
void graph<vertex_type>::printPath(ostream & out, const vertex_type & to_v)
{
	typename unordered_map< vertex_type, vertex<vertex_type>* >::const_iterator lookup = graph_.find(to_v);

	if( (lookup != graph_.end() ) && (graph_[to_v]->path != nullptr) )
	{


		printPath(out, graph_[to_v]->path->name);


		cout << " to ";
	}

	cout << to_v;
}


template <typename vertex_type>
void graph<vertex_type>::printPath(ostream & out, vertex_type && to_v)
{
	typename unordered_map< vertex_type, vertex<vertex_type>* >::const_iterator lookup = graph_.find(to_v);

	if( (lookup != graph_.end() ) && (graph_[to_v]->path != nullptr) )
	{

		printPath(out, graph_[to_v]->path->name);

		cout << " to ";
	}

	cout << to_v;
}

template <typename vertex_type>
void graph<vertex_type>::DijkstraPath(	const vertex_type & start_vertex	)
{

	BinomialQueue< vertex<vertex_type> > q;

	for(auto pair: graph_)
	{
		pair.second->clearDijkstra();
	}




	vertex<vertex_type>* s = (graph_[start_vertex]);

	s->dist = 0;


	q.insert(*s);


	while( !q.isEmpty() )
	{
   	vertex<vertex_type> v;

		q.deleteMin(v);

		graph_[v.name]->known = true;

		//cout << "\n@@@@@@@@@@@DEQUEUED: graph_[v.name]: " << graph_[v.name]->name << " @@@@@@@@@@@" << endl;


		for(auto w : v.adj) //adj is: list< pair <vertex<vertex_type>*, double> > adj
			if( !(w.first)->known )
			{
				//cout << "\ngraph_[w.first->name] " << graph_[w.first->name]->name << endl;

				DistType cost_v_to_w = w.second;
				

				if( v.dist + cost_v_to_w < (w.first)->dist )
				{
					//cout << " w: " << (w.first->name) << endl;

					q.decreaseKey( *(w.first), (v.dist + cost_v_to_w) );
					w.first->dist = (v.dist + cost_v_to_w);

					w.first->path = graph_[v.name];

					if(!q.contains( *(w.first) ) )
						q.insert( *(w.first) );

				}



			}


		

		//cout << "q.isEmpty() : " << q.isEmpty() << endl;


	}




}










