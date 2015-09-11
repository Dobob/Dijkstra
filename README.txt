Uploading from gedit text program has caused some spacing and tabbing issues in the code, but shouldn't stop the code from running.

DISCLAIMER:
This is created as a college homework exercise.
The priority binomial queue used in these codes are based on the binomial queue and hashtable code taken from Mark Allen Weiss' Data Structures and Algorithm Analysis in C++ textbook. I rewrote and added methods and data, and combined the two programs to create the priority binomial queue. And with the priority binomial queue, I created an algorithm for Dijkstra's shortest path solution for a graph, read from a text file(see below for an example).

Weiss' original codes can be found at: http://users.cis.fiu.edu/~weiss/dsaa_c++3/code/



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



Graph File:


Vertices		
5
0 					1 0.2 3 10.1 4 0.5 -1
1 					0 1.5 -1
2 					1 100.0 3 50.2 -1
3 					-1
4 					1 10.5 2 13.9 -1

The first line contains the number of nodes. The group of numbers on the right alternates between node and distance to that node from the node on the vertices column. E.g., from node 0 to node 1 requires 0.2 work or has a weight of 0.2. The -1 are used as delimiters to tell the program to stop reading.
