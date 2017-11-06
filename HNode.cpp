// hnode.cpp -- heap node class
// c. 2015 A. Deeter

#include "HNode.hpp"

/**
 * @brief constructor to initialise HNode
 * @param s the character
 * @param t the weight/ frequency of the character
 */
HNode::HNode(const char& s, const int& t) {
	value = s;
	weight = t;
}

/**
 * @brief  constructor for HNode, weight is the sum of left and right HNodes
 * @param l the left node 
 * @param r the right node
 */
HNode::HNode(HNode* l, HNode* r) {
	
	//weight is sum of left and right children nodes
	weight = l->weight + r->weight;
	
	//assign left and right children
	left = l;
	right = r;
}

