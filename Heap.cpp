#include "Heap.hpp"
#include <iostream>
/**
 * @brief function adds element to heap
 * @param newElement element to be added
 */
void Heap::enqueue(HNode* newElement)
{
	//if heap is empty
	if(tree.size() == 0)
	{ //resize tree
		HNode* temp = nullptr;
		tree.push_back(temp);
	}
	
	//add new leaf
	HNode* temp = nullptr;
	tree.push_back(temp);
	
	//get index of empty slot
	int index = tree.size() - 1;

	//demote parents that are larger than new element
	while((index > 1) && (*newElement < *tree[index / 2]))
	{
		tree[index] = tree[index / 2];
		index = index / 2;
	}
	
	//store new element into the vacant slot
	tree[index] = newElement;
	
	//fix heap
	//fix_up(index);
	
	
	//update position of last item added
	position = index;
	
	//increment count of tree in heap
	count++;
	
	
}
/**
 * @brief function fixes the heap from the bottom  up
 * @param index the index to fix the heap from
 * 
 */

void  Heap::fix_up(const int& index)
{
	//if first element skip fix_up
	if(index <= 1)
		return;
		
		
	//temp variable
	int tempIndex = index;
	
	bool notFixed = true;
	
	//loop through heap
	while(notFixed)
	{
		
		HNode* child = tree[tempIndex];
		
		//check if it's a leaf
		if((tempIndex % 2) != 0 )
		{
			//check if right child is smaller
			if(tree[tempIndex] < tree[tempIndex - 1])
			{
				//swap left child with right child
				tree[tempIndex] = tree[tempIndex - 1];
				tree[tempIndex - 1] = child;
			}
		}
		
		//check if right child is smaller than parent
		if(child < tree[tempIndex / 2])
		{
			//swap child with parent
			tree[tempIndex] = tree[tempIndex / 2];
			tree[tempIndex / 2] = child;
			
			//change index to parent index
			tempIndex /= 2;
		}
		else
		{
			notFixed = false;
		}
	}
	
}

/**
 * @brief function removes element from the heap
 * @return rthe root element in the heap
 */
HNode* Heap::dequeue()
{
	HNode* min = tree[1];
	
	//Remove last element
	int lastIndex = tree.size() - 1;
	HNode* last = tree.back();
	
	//remove last element
	tree.pop_back();
	
	if(lastIndex > 1)
	{
		//put last element in root
		tree[1] = last;
		
		//fix heap
		fix_down(1);
	}
	//display();
	--count;
	return min;
	
}

/**
 * @brief function fixes the heap from the top down
 * @param index the index to start fixing from
 */
void Heap::fix_down(const int& index)
{
	int tempIndex = index;
	HNode* root = tree[tempIndex]; 
	int lastIndex = tree.size() - 1;
	 
	// Promote children of removed root while they are larger than last 
	//int tempIndex = 1; 
	bool more = true;
	while (more) 
		 {
			 int childIndex = 2 * tempIndex;
			 if (childIndex <= lastIndex) 
				{ // Get smaller child,  left child first
				 HNode* child = tree[2 * tempIndex];
				 // Use right child instead if it is smaller
				 if ((2 * tempIndex + 1 <= lastIndex) && (tree[2 * tempIndex + 1] < child)) 
					{
						 childIndex = 2 * tempIndex + 1; 
						 child = tree[2 * tempIndex + 1];
					}
					// Check if larger child is smaller than root; if so promote child
					if (child < root) 
					{ 
						tree[tempIndex] = child; 
						tempIndex = childIndex; 
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
		
		tree[tempIndex] = root;       

}

/**
 * @brief functions clears the heap and removes all HNodes
 */
void Heap::clear()
{
	tree.clear();
	
}
