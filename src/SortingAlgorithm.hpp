#pragma once

#include <iostream>
#include <vector>

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                T tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}


template<Sortable T>
void HeapSort(std::vector<T>& v)
{
	//enqueue
    unsigned int n = v.size();
    for(unsigned int i = 1; i < n; i++)
    {
        unsigned int node = i;
        while(node > 0)
        {
            unsigned int father = 0;
			if (node%2==1)
			{
				father = (node-1)/2;
			}
			else
			{
				father = (node-2)/2;
			}
			if (v[node]>v[father])
			{
				T tmp = v[node];
                v[node] = v[father];
                v[father] = tmp;
			}
			else
			{
				break;
			}
			node = father;
		}
    }
			
	//dequeue
	for(unsigned int i = 0; i < n; i++)
	{
		T tmp = v[0];
        v[0] = v[n-1-i];
        v[n-1-i] = tmp;	
		unsigned int node = 0;
        while(true)
        {
			unsigned int left_son = 2 * node + 1;
			unsigned int right_son = 2 * node + 2;
			unsigned int maxNode = node;
			if (left_son<n-1-i && v[left_son]>=v[maxNode])
			{
				maxNode=left_son;
			}
			if (right_son<n-1-i && v[right_son]>=v[maxNode])
			{
				maxNode=right_son;
			}
			if (maxNode!=node)
			{
				T tmp = v[node];
                v[node] = v[maxNode];
                v[maxNode] = tmp;
				node=maxNode;
			}
			else
			{
				break;
			}
		}
	} 
}

