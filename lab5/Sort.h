//  Sort.h

#ifndef SORT_H
#define SORT_H

#include <iterator>
#include <algorithm> 	// for std::partition
#include <functional> 	// for std::less

template<typename RandomAccessIterator, typename Order>
void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (last - first > 1)
   {
		RandomAccessIterator split = std::partition(first+1, last, std::bind2nd(order, *first));
		std::iter_swap(first, split-1);
		quicksort(first, split-1, order);
		quicksort(split, last, order);
	}
}

template<typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last)
{
   quicksort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

template <typename Iterator>
void heapsort(Iterator begin, Iterator end)
{
	std::make_heap(begin, end);
   std::sort_heap(begin, end);
}

template<typename RandomAccessIterator, typename Order>
void mergesort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
   if (last - first > 1)
   {
		RandomAccessIterator middle = first + (last - first) / 2;
		mergesort(first, middle, order);
		mergesort(middle, last, order);
		std::inplace_merge(first, middle, last, order);
   }
}

template<typename RandomAccessIterator>
void mergesort(RandomAccessIterator first, RandomAccessIterator last)
{
	mergesort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

template<typename Iter>
void insertionSort(Iter beg, Iter end)
{
	for (Iter i = beg; i != end; ++i)
   	std::rotate(std::upper_bound(beg, i, *i), i, i+1);
}

#endif
