//
// BST.hpp
// CSE 100 Project 1
//
// Last modified by Heitor Schueroff on 01/10/2019
//

#ifndef BST_HPP
#define BST_HPP

#include <iostream>

#include "BSTIterator.hpp"
#include "BSTNode.hpp"

using namespace std;

template <typename Data>
class BST {
    protected:
        // Pointer to the root of this BST, or 0 if the BST is empty.
        BSTNode<Data> *root;

        // Number of elements stored in this BST.
        unsigned int isize;

        // Height of this BST.
        unsigned int iheight;

    public:
        // Define iterator as an aliased typename for BSTIterator<Data>.
        typedef BSTIterator<Data> iterator;

        /** 
         * Default constructor. Initializes an empty BST.
         */
        BST() : root(0), isize(0), iheight(0) {}

        /** 
         * Default destiructor. Frees all memory allocated by this BST.
         */
        // TODO testing
        virtual ~BST() {

            deleteAll( root );

        }

        /** 
         * Inserts the given item into this BST.
         *
         * This function should use only the '<' operator when comparing
         * Data items. (do not use ==, >, <=, >=). For the reasoning
         * behind this, see the assignment writeup.
         *
         * Parameters:
         *     item Data item to insert into this BST
         *
         * Returns:
         *     true if the item was inserted as a consequence of calling
         *     this function, false otherwise (e.g. item is a duplicate).
         */
        // TODO testing
        virtual bool insert(const Data &item) {

            BSTNode<Data> * ptr = root;
            BSTNode<Data> * prev = nullptr;
            BSTNode<Data> * newNode;
            unsigned int nheight = 0;

            // First checks if the item exists in BST, returning false if found
            while( ptr ) {

                nheight = nheight + 1;
                if( item < ptr -> data ) {

                    prev = ptr;
                    ptr = ptr -> left;

                } else if( ptr -> data < item ) { 

                    prev = ptr;
                    ptr = ptr -> right;

                    // If the item is neither less than or greater than, than = to
                } else {

                    return false;    

                }

            }

            // Sets the new inserted data
            if( prev != nullptr && item < prev -> data ) {

                newNode = new BSTNode<Data>( item );   
                prev -> left = newNode;
                newNode -> parent = prev;

            } else if( prev != nullptr && prev -> data < item ) {

                newNode = new BSTNode<Data>( item );
                prev -> right = newNode;
                newNode -> parent = prev;

            } else {

                newNode = new BSTNode<Data>( item );
                root = newNode; 

            }

            isize = isize + 1;
            nheight = nheight + 1;
            if( nheight > iheight ) {
                iheight = nheight;
            }
            return true;

        }

        /**
         * Searches for the given item in this BST.
         *
         * This function should use only the '<' operator when comparing
         * Data items. (should not use ==, >, <=, >=). For the reasoning
         * behind this, see the assignment writeup.
         *
         * Parameters:
         *     item Data item to search for in this BST.
         *
         * Returns:
         *     An iterator pointing to the item if found, or pointing 
         *     past the last node in this BST if item is not found.
         */
        // TODO testing
        virtual iterator find(const Data &item) const {

            BSTNode<Data> * ptr = root;
            while( ptr ) {

                if( item < ptr -> data ) {

                    ptr = ptr -> left;

                } else if( ptr -> data < item ) { 

                    ptr = ptr -> right;

                // If the item is neither less than or greater than, than = to
                } else {

                    return typename BST<Data>::iterator( ptr );    

                }

            }

            return typename BST<Data>::iterator( 0 );

        }

        /** 
         * Returns the number of items currently in the BST.
         */
        // TODO testing
        unsigned int size() const {

            return isize; 

        }

        /** 
         * Returns the height of this BST.
         */
        // TODO testing
        unsigned int height() const {

            return iheight;

        }

        /** 
         * Returns true if this BST is empty, false otherwise.
         */
        // TODO testing
        bool empty() const {

            return ( root == 0 );

        }

        /** 
         * Returns an iterator pointing to the first item in the BST (not 
         * the root).
         */
        // TODO testing
        iterator begin() const {

            return typename BST<Data>::iterator( first( root ) );

        }

        /** 
         * Returns an iterator pointing past the last item in the BST.
         */
        iterator end() const { 
            return typename BST<Data>::iterator(0); 
        }

        /** 
         * Prints the elements in this BST in ascending order.
         */
        void inorder() const { 
            inorder(root); 
        }

    private:
        /*
         * Find the first node in the given subtree with root curr.
         */
        static BSTNode<Data>* first(BSTNode<Data> *curr) {
            if (!curr) return 0;
            while (curr->left) {
                curr = curr->left;
            }
            return curr;
        }

        /* 
         * Do an inorder traversal, printing the data in ascending order.
         *
         * You can achieve an inorder traversal recursively by following 
         * the order below.
         *
         *     recurse left - print node data - recurse right
         */
        // TODO testing
        static void inorder(BSTNode<Data> *n) {

            // Base case
            if( n == nullptr ) {

                return;

            }

            inorder( n -> left );
            cout << ( n -> data );
            inorder( n -> right );

        }

        /* 
         * Do a postorder traversal, deleting nodes.
         *
         * You can achieve a postorder traversal recursively by following 
         * the order below.
         *
         *     recurse left - recurse right - delete node
         */
        // TODO testing
        static void deleteAll(BSTNode<Data> *n) {

            // Base case
            if( n == nullptr ) {

                return;

            }

            deleteAll( n -> left );
            deleteAll( n -> right );
            delete n;

        }

};

#endif  // BST_HPP
