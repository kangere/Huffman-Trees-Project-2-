// hnode.cpp -- heap node class
// c. 2015 A. Deeter

#include "HNode.hpp"

// constructor for leaf nodes
HNode::HNode(const char& s, const int& t) {
	value = s;
	weight = t;
}

// constructor for internal nodes
HNode::HNode(HNode* l, HNode* r) {
	
	//weight is sum of left and right children nodes
	weight = l->weight + r->weight;
	
	//assign left and right children
	left = l;
	right = r;
}

