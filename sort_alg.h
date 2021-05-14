#pragma once

class quick_sort
{
public:
	quick_sort();
	~quick_sort();
	template< typename T, typename Obj >
	void sort( T &list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) );
	template< typename T, typename Obj >
	void sort_rev( T& list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) );
private:
	
	template< typename T, typename Obj >
	void sort_recur( T &list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) );

	template< typename T, typename Obj >
	void sort_recur_rev( T& list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) );

	template< typename T, typename Obj >
	void swap( T &list, int a, int b, Obj temp ) ;


};

quick_sort::quick_sort()
{
}

quick_sort::~quick_sort()
{
}

template< typename T, typename Obj >
void quick_sort::sort( T &list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) )
{
	// T list is template list(array/vector).
	// int ( *cmp_ptr )( ) is function pointer. # < is return -1, == is return 0, > is return 1
	// This function is quick sort the list (implemented by recursion).
	// This is unstable and internal sort.
	if ( front < end && front >= 0 ) {
		sort_recur( list, front, end, cmp_ptr );
	} // if
	
} // sort

template< typename T, typename Obj >
void quick_sort::sort_rev( T& list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) )
{
	// T list is template list(array/vector).
	// int ( *cmp_ptr )( ) is function pointer. # < is return -1, == is return 0, > is return 1
	// This function is quick sort the list (implemented by recursion) #reverse version.
	// This is unstable and internal sort.

	if ( front < end && front >= 0 ) {
		sort_recur_rev( list, front, end, cmp_ptr );
	} // if

} // sort_rev

template<typename T, typename Obj>
void quick_sort::sort_recur( T &list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) )
{
	if ( front < end && front >= 0 ) {

		int pivot = end;
		int j = front - 1;
		for ( int i = front  ; i < end ; i++ ) {

			if ( cmp_ptr( list[ i ], list[ pivot ] ) <= 0 ) {
				j++;
				swap( list, i, j, list[ 0 ] );
			} // if

		} // for

		j++;
		swap( list, pivot, j, list[ 0 ] );

		sort_recur( list, front, j - 1, cmp_ptr ); // left
		sort_recur( list, j + 1, end, cmp_ptr ); // right
	} // if

} // sort_recur

template<typename T, typename Obj>
void quick_sort::sort_recur_rev( T& list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) )
{
	if ( front < end && front >= 0 ) {

		int pivot = end;
		int j = front - 1;
		for ( int i = front ; i < end ; i++ ) {

			if ( cmp_ptr( list[ i ], list[ pivot ] ) >= 0 ) {
				j++;
				swap( list, i, j, list[ 0 ] );
			} // if

		} // for

		j++;
		swap( list, pivot, j, list[ 0 ] );

		sort_recur_rev( list, front, j - 1, cmp_ptr ); // left
		sort_recur_rev( list, j + 1, end, cmp_ptr ); // right
	} // if

} // sort_recur_rev

template< typename T, typename Obj >
void quick_sort::swap( T &list, int a, int b, Obj ref ) {
	Obj temp = list[ b ];
	list[ b ] = list[ a ];
	list[ a ] = temp;
} // swap



class merge_sort
{
public:
	merge_sort();
	~merge_sort();

	template< typename T, typename Obj >
	void sort( T& list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) );

private:

	template< typename T, typename Obj >
	void merge( T& list, int front, int mid, int end, int ( *cmp_ptr )( Obj, Obj ) );

};

merge_sort::merge_sort()
{
}

merge_sort::~merge_sort()
{
}

template< typename T, typename Obj >
void merge_sort::sort( T& list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) )
{
	// T list is template list(array/vector).
	// int ( *cmp_ptr )( ) is function pointer. # < is return -1, == is return 0, > is return 1
	// This function is merge sort the list (implemented by recursion).
	// This is stable and external sort.

	if ( front < end && front >= 0 ) {
		int mid = ( front + end ) / 2;

		sort( list, front, mid, cmp_ptr ); // left
		sort( list, mid + 1, end, cmp_ptr ); // right
		merge( list, front, mid, end, cmp_ptr );

	} // if

} // sort

template<typename T, typename Obj>
void merge_sort::merge( T& list, int front, int mid, int end, int ( *cmp_ptr )( Obj, Obj ) )
{
	if ( front < end && front >= 0 ) {
		// front ~ mid is left.
		// mid + 1 ~ end is right.

		Obj *left_subarray_ptr = new Obj [ mid - front + 1 ];
		Obj *right_subarray_ptr = new Obj[ end - ( mid + 1 ) + 1 ];

		int j = 0;
		for ( int i = front ; i <= mid ; i++ ) {
			// push left list to left_subarray
			left_subarray_ptr[ j ] = list[ i ];
			j++;
		} // for

		j = 0;
		for ( int i = mid + 1 ; i <= end ; i++ ) {
			// push right list to right_subarray
			right_subarray_ptr[ j ] = list[ i ];
			j++;
		} // for


		int left_index = 0;
		int right_index = 0;
		int left_end = mid - front;
		int right_end = end - ( mid + 1 );

		for ( int i = front ; i <= end ; i++ ) {

			if ( left_index > left_end ) {
				list[ i ] = right_subarray_ptr[ right_index ];
				right_index++;
			} // if
			else if ( right_index > right_end ) {
				list[ i ] = left_subarray_ptr[ left_index ];
				left_index++;
			} // else if
			else {
				if ( cmp_ptr( left_subarray_ptr[ left_index ], right_subarray_ptr[ right_index ] ) <= 0 ) {
					list[ i ] = left_subarray_ptr[ left_index ];
					left_index++;
				} // if
				else {
					list[ i ] = right_subarray_ptr[ right_index ];
					right_index++;
				} // else
			} // else

		} // for
		

		// release memloc.
		delete[] left_subarray_ptr;
		left_subarray_ptr = nullptr;
		delete[] right_subarray_ptr;
		right_subarray_ptr = nullptr;

	} // if

} // merge

class insertion_sort
{
public:
	insertion_sort();
	~insertion_sort();

	template< typename T, typename Obj >
	void sort( T& list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) );

private:

};

insertion_sort::insertion_sort()
{
}

insertion_sort::~insertion_sort()
{
}

template< typename T, typename Obj >
void insertion_sort::sort( T& list, int front, int end, int ( *cmp_ptr )( Obj, Obj ) ) {
	// T list is template list(array/vector).
	// int ( *cmp_ptr )( ) is function pointer. # < is return -1, == is return 0, > is return 1
	// This is stable and internal sort.
	// If the list is close sorted the method would be prefered. 

	for ( int i = front + 1; i <= end; i++ ) {
		Obj key = list[ i ];
		int j = i - 1;
		while ( j >= 0 && cmp_ptr( key, list[ j ] ) < 0 ) {
			list[ j + 1 ] = list[ j ];
			j--;
		} // while
		list[ j + 1 ] = key;
	} // for
} // sort