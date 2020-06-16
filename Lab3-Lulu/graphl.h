#pragma once
#include "nodedata.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define MAXNODES 101

using namespace std;

// ----------------------- graphl.h ----------------------------------------
// Programmer Name: Lu Lu
// Course Section Number : CSS343 B
// Creation Date : 5/13/2019
// Date of Last Modification : 5/14/2019
// ---------------------------------------------------------------------------
// Purpose - 
//	This  project  is  to  display  the  graph  information  and  implement  
//  depth-first
// --------------------------------------------------------------------------- 
// Assumption :
//	-the first line tells the number of nodes,
//	-A zero for the first  integer  signifies  the  end  of  the  data  for  
//   that  one  graph.   
//	-allows to display each node info and edge in the graph
//	-Assume the source node is always 1
// --------------------------------------------------------------------------- 
class GraphL {

public:
	GraphL();
	~GraphL();
	bool buildGraph(ifstream&);	    // builds up graph node information and adjacency list of edges between each node reading from a data file.
	void displayGraph();			// Displays each node information and edge in the graph(e.g., the top portion of Figure 1 (c))
	void depthFirstSearch();		// Makes a depth - first search and displays each node in depth - first order


private:

	struct EdgeNode;                // forward reference for the compiler
	struct GraphNode {              // structs used for simplicity, use classes if desired
		EdgeNode* edgeHead;         // head of the list of edges
		NodeData* data;             // data information about each node
		bool visited;
	};

	struct EdgeNode {
		int adjGraphNode;            // subscript of the adjacent graph node
		EdgeNode* nextEdge;
	};

	GraphNode gNodes[MAXNODES];		 // array of GraphNodes
	void dfsHelper(int i);			 //depthFirstSearch helper Method
};