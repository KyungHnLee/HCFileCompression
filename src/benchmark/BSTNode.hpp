//
// BSTNode.hpp
//

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>
#include <iomanip>

using namespace std;

template <typename Data>
class BSTNode {
public:
    BSTNode<Data> *left;
    BSTNode<Data> *right;
    BSTNode<Data> *parent;
    Data const data;

    /** 
     * Constructor that initializes a BSTNode with the given data.
     */
    BSTNode(const Data &d) : data(d) {
        left = right = parent = nullptr;
    }

    /**
     * Find the successor this node.
     *
     * The successor of a node is the node in the BST whose data
     * value is the next in the ascending order.
     *
     * Returns:
     *     the BSTNode that is the successor of this BSTNode,
     *     or 0 if there is none (this is the last node in the BST).
     */
    // TODO testing
    BSTNode<Data> *successor() {

	// If the node has a right child
        if( right != nullptr ) {

	    BSTNode<Data> * curr = right;
	    // Continues down the tree until left child is null
	    while( curr -> left != nullptr ) {

    		curr = curr -> left;

	    }

	    return curr; 	

	// If the node does not have a right child
	} else {

  	    BSTNode<Data> * curr = this;

	    // While parent is not a nullptr and parent's left isn't curr
	    while( ( curr -> parent != nullptr ) && 
		curr -> parent -> left != curr ) {
															
    		curr = curr -> parent;

	    }	
	    
	    // if parent's left is curr
	    if( ( curr -> parent != nullptr ) && 
            ( curr -> parent) -> left == curr ) {

	    	return curr -> parent;

	    } 

	    return 0;	

	}    

    }
};

/** 
 * Overload operator<< to print a BSTNode's fields to an ostream. 
 */
template <typename Data>
ostream &operator<<(ostream &stm, const BSTNode<Data> &n) {
    stm << '[';
    stm << setw(10) << &n;                  // address of the BSTNode
    stm << "; p:" << setw(10) << n.parent;  // address of its parent
    stm << "; l:" << setw(10) << n.left;    // address of its left child
    stm << "; r:" << setw(10) << n.right;   // address of its right child
    stm << "; d:" << n.data;                // its data field
    stm << ']';
    return stm;
}

#endif  // BSTNODE_HPP
