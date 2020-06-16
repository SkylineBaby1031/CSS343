#pragma once
#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classics.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
//--------------------------  class MovieFactory ----------------------------
//  MovieFactory class factory function
//---------------------------------------------------------------------------
class MovieFactory {
public:
	static Movie* createMovie(const string&); // create
};
