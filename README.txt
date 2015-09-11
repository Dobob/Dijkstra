IMPORTANT: This program allows no duplicates vertices.
								 This program works only as intended as a solution for the homework. Using it to solve unrelated problems may result in errors.


			1. Open terminal and type make clean(to delete old object files) just in case.
			2. Type make all.
			3. For reading simple input and displaying adjacent vertices, depending on IDE, type:

				 ./adjListTest.exe 

					or 

				./adjListTest

			4. For dijkstra's algorithm, depending on IDE, type:

			 	./findpaths.exe <GRAPH_FILE> <STARTING_VERTEX>

				or 

				./findpaths <GRAPH_FILE> <STARTING_VERTEX> 

			5. Follow the prompts.




			NOTE:

			This graph ADT allows for rvalue list initializations, e.g., 

				graph<unsigned int> g;
				g.insert(1, { {2,9.9}, {3,9.9}, {4,9.9} });

			The first parameter is the vertex name, and the second is the list of pairs {to vertex, weight}.

			For the purpose of this homework, I have only verfied the ADT's compatibility with unsigned integers as names of vertices(negative names incompatible).




Input: "resource/Graph1.txt" or "resource/Graph2.txt"
			
			no ouput files

