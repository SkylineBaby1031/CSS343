#include "moviefactory.h"
//--------------------- MovieFactory()--------------------------------------------
// Return to moive object
//-------------------------------------------------------------------------
 Movie * MovieFactory::createMovie(const string& a) {

	 Movie *  movie = NULL;
	 switch (a[0])
	 {
	 case Drama::comandType:
		 movie =  (Movie*) new Drama(a);  // Drama
		 break;
	 case Comedy::comandType:
		 movie = (Movie*) new Comedy(a);  // Comedy
		 break;
	 case Classics::comandType:
		 movie = (Movie*) new Classics(a); //  Classics
		 break;
	 default:
		 movie = NULL;

		 break;
	 }
	return movie;                  
}
