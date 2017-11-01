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
	 HNode* root = elements[index]; 
	 int lastIndex = elements.size() - 1;
	 
	 // Promote children of removed root while they are larger than last 
	 //int index = 1; 
	 boolean more = true;
	 while (more) 
		 {
			 int childIndex = 2 * index;
			 if (childIndex <= lastIndex) 
				{ // Get smaller child,  left child first
				 HNode* child = elements[2 * index];
				 // Use right child instead if it is smaller
				 if ((2 * index + 1 <= lastIndex) && (elements[2 * index + 1] < child)) 
					{
						 childIndex = 2 * index + 1; 
						 child = elements[2 * index + 1];
					}
					// Check if larger child is smaller than root; if so promote child
					if (child < root) 
					{ 
						elements[index] = child; 
						index = childIndex; 
					}
					else 
					{ 
						more = false; // Root is smaller than both children 
					}      
						
				}
				else  
				{ 
					more = false; // No children
				}        
				
						
		}
		
		elements[index] = root;       

}


HNode* Heap::dequeue()
{
	HNode* min = tree[1];
	
	//Remove last element
	int lastIndex = tree.size() - 1;
	HNode* last = tree.pop_back();
	
	if(lastIndex > 1)
	{
		tree[1] = last;
		fix_up(1);
	}
	
	return min;
	
}


void Heap::fix_down(const int& index)
{

}

void Heap::clear()
{
	tree.clear();
}
