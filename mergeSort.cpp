#include	<iostream>
#include	<cstdlib>
#include	<vector>
#include	<iterator>
#include	<algorithm>

using namespace std;

// double	gen_rand()	{ return	rand()/(double)RAND_MAX; }

// uses struct to create a function object
struct gen_rand
	{
		double	factor;

		gen_rand() :	factor( 1/(double)RAND_MAX )	{}

		double	operator()()	{
			return	rand()*factor;
		}
	};



// -------------------------------------
// merges the left and right sublists
// -------------------------------------
template	<typename	elemType>
list<elemType>	merge( list<elemType>  &left, list<elemType>  &right )
{
	list<elemType>::iterator 		left_first  = left.begin();
	list<elemType>::iterator 		right_first = right.begin();
	list<elemType>::const_iterator 	left_last   = left.end();
	list<elemType>::const_iterator 	right_first = right.end();

	list<elemType>					result;





	
}







int	main(int argc, char* argv[])
{
	int			num_items = atoi( argv[1] ); 

 
	// ----------------------------------------
	// creates a vector of random double values
	// ----------------------------------------
	vector<double>		dVec;
	dVec.reserve(num_items);
	generate_n( std::back_inserter(dVec), num_items, gen_rand() );


	// call sort function



	// print the vector
	std::ostream_iterator<double>	os( cout, "\t\t" );
	copy( dVec.begin(), dVec.end(), os );
	cout << endl;


	return	0;
}