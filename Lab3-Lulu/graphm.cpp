//#include "pch.h"
#include "graphm.h"
#include <limits>
using namespace std;

// ----------------------- graphm.cpp ----------------------------------------
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

//------------------------- Constructors ---------------------------------------
// ------------------------ GraphM() ---------------------------------------------
// Description: 
//		among others that need to be initialized, the data member T is 
//		initialized to sets all dist to infinity, sets all visited to false,
//		and sets all path to 0.
// -----------------------------------------------------------------------------  
GraphM::GraphM()
{
	//initialization
	for (int i = 0; i < MAXNODES; i++)
	{
		//init C arr and T arr
		for (int j = 0; j < MAXNODES; j++)
		{
			C[i][j] = std::numeric_limits<int>::max();
			T[i][j].dist = std::numeric_limits<int>::max();
			T[i][j].path = 0;
			T[i][j].visited = false;
		}
		//init size
		size = 0;

	}
}// end of GraphM()

// ------- SplitStr(string s, vector<string>& v, char c) -----------------------
// Description: 
//		split string by specific char ' '
//		Helper function
// -----------------------------------------------------------------------------  
static void SplitStr(string s, vector<string>& v, char c)
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			v.push_back(s.substr(count, i - count));
			count = i + 1;
		}
	}
	v.push_back(s.substr(count, s.size()));
}// end of SplitStr(string s, vector<string>& v, char c)

// ----------------------- buildGraph(ifstream& infile) ------------------------
// Description: 
//		builds up graph node information and adjacency matrix of edges between 
//		each node reading from a data file.
// -----------------------------------------------------------------------------  
bool GraphM::buildGraph(ifstream& infile)
{
	//if file is empty , return false
	if (infile.eof())
	{
		return false;
	}
	string line = "";
	//first line -- size
	getline(infile, line);
	size = atoi(line.c_str());
	//store str from file into  data array
	for (int i = 1; i <= size; i++)
	{
		if (infile.eof())
		{
			return false;
		}
		//set data value from file
		data[i].setData(infile);
	}
	//store path into C arr, and save adjacent nodes into adjacent list
	while (!infile.eof())
	{
		getline(infile, line);
		vector<string> v;
		SplitStr(line, v, ' ');
		int n1 = atoi(v[0].c_str());
		int n2 = atoi(v[1].c_str());
		int dist = atoi(v[2].c_str());
		adjacentList[n1].push_back(n2);

		if (n1 == 0)
		{
			break;
		}
		C[n1][n2] = dist;
	}
	return true;
}// end of buildGraph(ifstream& infile)

// --------------- insertEdge(int n1, int n2, int dist) ------------------------
// Description: 
//		insert an edge into graph between two given nodes
// -----------------------------------------------------------------------------  	
bool GraphM::insertEdge(int n1, int n2, int dist)
{
	if (C[n1][n2] != std::numeric_limits<int>::max())
	{
		return false;
	}
	C[n1][n2] = dist;
	adjacentList[n1].push_back(n2);
	findShortestPath();
	return true;
}// end of insertEdge(int n1, int n2, int dist)

// ------------------------- removeEdge(int n1, int n2) ------------------------
// Description: 
//		remove an edge between two given nodes
// -----------------------------------------------------------------------------  
bool GraphM::removeEdge(int n1, int n2)
{
	if (C[n1][n2] == std::numeric_limits<int>::max())
	{
		return false;
	}
	C[n1][n2] = std::numeric_limits<int>::max();
	findShortestPath();
	return true;
}// end of removeEdge(int n1, int n2)

// ------------------------- findShortestPath() --------------------------------
// Description: 
//		find  the  shortest  path  between  every  node  to  every  other  
//		node  in  the graph, i.e., TableType T is updated with shortest path 
//		information
// -----------------------------------------------------------------------------  
void GraphM::findShortestPath()
{
	//reinit if T has data
	if (T[0][0].path == 1)
	{
		for (int i = 0; i <= size; i++)
		{
			//remove data of T
			for (int j = 0; j <= size; j++)
			{
				T[i][j].dist = std::numeric_limits<int>::max();
				T[i][j].path = 0;
				T[i][j].visited = false;
			}
		}
	}
	for (int source = 1; source <= size; source++)
	{
		T[source][source].dist = 0;
		int preIndex = 0;
		// finds the shortest distance from source to all other nodes
		for (int i = 1; i <= size; i++)
		{
			// find v,  which is not visited, shortest distance at this point

			int vIndex = -1;
			int shortestDist = std::numeric_limits<int>::max();
			for (int j = 1; j <= size; j++)
			{
				if (!T[source][j].visited)
				{
					bool vReplace = T[source][j].dist < shortestDist;
					vIndex = (vReplace) ? j : vIndex;
					shortestDist = vReplace ? T[source][j].dist : shortestDist;
				}
			}

			if (vIndex == -1)
				continue;
			//mark v visited
			T[source][vIndex].visited = true;
			//retrieve the node's number from the adjacentlist, and use it as an index for the table
			for (int w : adjacentList[vIndex])
			{
				if (!T[source][w].visited)
				{
					if (T[source][vIndex].dist + C[vIndex][w] < T[source][w].dist)
					{
						T[source][w].dist = T[source][vIndex].dist + C[vIndex][w];
						T[source][w].path = vIndex;
					}
				}
			}

		}
	}
	T[0][0].path = 1;

}// end of findShortestPath()

// ------------------------------ displayAll() --------------------------------
// Description: 
//		uses  couts  to  demonstrate  that  the  algorithm  works  properly. 
// -----------------------------------------------------------------------------  
void GraphM::displayAll()
{
	cout << "Description         From node   To node   Dijkstra's     Path      " << endl;
	for (int i = 1; i <= size; i++)
	{
		cout << data[i] << endl;
		for (int j = 1; j <= size; j++)
		{
			if (j != i)
			{
				cout << setw(25) << i << setw(10) << j << setw(13);
				int  dist = T[i][j].dist;
				if (dist == std::numeric_limits<int>::max())
				{
					cout << "----";
				}
				else
				{
					cout << dist;
				}
				string path = getPath(i, j);
				string fPath;
				if (path != "")
				{
					fPath = path + " ";
					fPath += to_string(j);
				}
				cout << "        " << fPath << endl;
			}
		}
	}
	cout << endl;
}// end of displayAll()

// ------------------------ display(int i, int j) ------------------------------
// Description: 
//		uses couts to display the shortest distance with path info between 
//		the fromNode to toNode.
// -----------------------------------------------------------------------------  
void GraphM::display(int i, int j)
{
	string path = getPath(i, j);
	string fPath;
	if (j != i)
	{
		cout << setw(2) << i << setw(10) << j << setw(13);
		int  dist = T[i][j].dist;
		if (dist == std::numeric_limits<int>::max())
		{
			cout << "----";
		}
		else
		{
			cout << dist;
		}
		if (path != "")
		{
			fPath = path + " ";
			fPath += to_string(j);
		}
		cout << "        " << fPath << endl;
	}
	if (path != "")
	{
		vector<string> v;
		SplitStr(fPath, v, ' ');
		for (int i = 1; i < v.size(); i++)
		{
			int index = atoi(v[i].c_str());
			cout << data[index] << endl;
		}
	}
	cout << endl;
}// end of display(int i, int j)

// -------------------- getPath(int fNode, int tNode) --------------------------
// Description: 
//		return path between nodes.
// -----------------------------------------------------------------------------  
string GraphM::getPath(int fNode, int tNode)
{
	int path = T[fNode][tNode].path;
	if (path == 0)
	{
		return "";
	}
	return getPath(fNode, path) + " " + to_string(path);
}// end of getPath(int fNode, int tNode)