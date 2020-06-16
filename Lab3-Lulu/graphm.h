#pragma once
#include "nodedata.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define MAXNODES 101
using namespace std;

// ----------------------- graphm.h ----------------------------------------
// Programmer Name: Lu Lu
// Course Section Number : CSS343 B
// Creation Date : 5/13/2019
// Date of Last Modification : 5/14/2019
// ---------------------------------------------------------------------------
// Purpose - 
//	This  project  is  to  implement  Dijkstra's  shortest  path  algorithm.  
// --------------------------------------------------------------------------- 
// Assumption :
//	-read  a  data  file  consisting  of  many  lines 
//	-be able to find the lowest cost paths  
//	-display  the  cost  and  path  from  every  node  to  every  other  node   
//	-Another display routine (display function) will output one path in detail. 
// --------------------------------------------------------------------------- 

class GraphM {
public:

	GraphM();											// data member T is initialized	
	bool buildGraph(ifstream&);						    // builds up graph node information and adjacency matrix of edges betwee
	bool insertEdge(int, int, int);						// insert an edge into graph between two given nodes	
	bool removeEdge(int, int);							// remove an edge between two given nodes	
	void findShortestPath();							// find the shortest path between every node to every other node in the graph,	
	void displayAll();									// uses couts to demonstrate that the algorithm works properly.
	void display(int, int);								// display path by nodes


private:
	struct TableType {
		bool visited;									 // whether node has been visited
		int dist;										 // shortest distance from source known so far
		int path;										 // previous node in path of min dist
	};

	NodeData data[MAXNODES];							 // data for graph nodes 
	int C[MAXNODES][MAXNODES];							 // Cost array, the adjacency matrix
	int size;										     // number of nodes in the graph
	TableType T[MAXNODES][MAXNODES];					 // stores visited, distance, path
	vector<int> adjacentList[MAXNODES];				     // the list of each node's adjacent nodes
	string getPath(int, int);							 // a recursion helper, help to retrieve path (the node's previous node)
};