#ifndef VERTEX_HASH
#define VERTEX_HASH

#include "../vertex/vertex.h"

using namespace std;


class hashVertex
{
	public:

	size_t operator()( const vertex<unsigned int> & key )
	{

		static hash<unsigned int> hf;

		size_t hash_value = hf( key.getName() );

		return hash_value;


	}
};

#endif

