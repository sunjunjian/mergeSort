#include	<iostream>
#include	<cstdlib>
#include	<ctime>
#include	<vector>
#include	<vector>
#include	<iterator>
#include	<algorithm>

using namespace std;


int		gen_rand()	{ return	rand() % 10000; }



// -------------------------------------
// merges the left and right subvectors
// -------------------------------------
template		<typename	 IterType>
vector<int>		my_merge(  	IterType  left_first,  const IterType   left_last,
							IterType  right_first, const IterType  	right_last )
{
	vector<int>		result;


	while ( (left_first < left_last) || (right_first < right_last) )
	{
		if ( (left_first < left_last) && (right_first < right_last) )
		{
			if ( *(left_first) <= *(right_first) )
			{
				result.push_back( *left_first );
				++left_first;
			}
			else
			{
				result.push_back( *right_first );
				++right_first;				
			}
		}
		else	if ( left_first < left_last )
		{
			for ( ; left_first < left_last; ++left_first )
			{
				result.push_back( *left_first );				
			}
		}
		else	if ( right_first < right_last )
		{
			for ( ; right_first < right_last; ++right_first )
			{
				result.push_back( *right_first );			
			}
		}		
	}

	return	result;
}





// -------------------------------------
//             merge sort
// -------------------------------------
template		< typename		IterType>
vector<int>		merge_sort( IterType  first, IterType  last )
{
	int 				middle = ( last - first )/2;
	vector<int>	left, right;

	// size is one
	if ( middle < 1 )
	{
		left.push_back( *first );
		return	left;
	}

	// recursion
	left  = merge_sort( first, first + middle );
	right = merge_sort( first + middle, last );

	return	( my_merge( left.begin(), left.end(), right.begin(), right.end() ) );
}






int	main(int argc, char* argv[])
{
	int			num_items = atoi( argv[1] ); 

 	// Seed the RNG - Ramdon Number Generator
	srand( time( NULL ) );

	// ----------------------------------------
	// creates a vector of random int values
	// ----------------------------------------
	vector<int>		iVec;
	iVec.reserve(num_items);
	generate_n( std::back_inserter(iVec), num_items, gen_rand );


	// call sort function
	iVec = merge_sort( iVec.begin(), iVec.end() );


	// print the vector
	std::ostream_iterator<int>	os( cout, "\t\t" );
	copy( iVec.begin(), iVec.end(), os );
	cout << endl;

	return	0;
}