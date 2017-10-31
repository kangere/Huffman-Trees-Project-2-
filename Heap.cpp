#include "Heap.hpp"

void Heap::enqueue(HNode* newElement)
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
	
	//update position of last item added
	position = index;
	
	//increment count of elements in heap
	count++;
	

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
	if(count < 1)
		return;
	else
		tree.clear();
}
