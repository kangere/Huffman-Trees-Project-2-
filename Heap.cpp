#include "Heap.hpp"

Heap::~Heap()
{
	
}

void Heap::enqueue( HNode* newElement)
{
	//add a new leaf
	HNode* temp = nullptr;
	tree.push_back(temp);
	int index = tree.size() - 1;

	//demote parents that are larger than new element
	while((index > 1) && (*newElement < *tree[index / 2]))
	{
		tree[index] = tree[index / 2];
		index = index / 2;
	}	
	
	//store new element into the vacant slot
	tree[index] = newElement;

}

void  Heap::fix_up(const int& index)
{


}


HNode* Heap::dequeue()
{

}


void Heap::fix_down(const int& index)
{

}

void Heap::clear()
{

}
