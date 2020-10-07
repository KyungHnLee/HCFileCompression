//
// BSTIterator.hpp
//

#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP

#include <iterator>
#include <list>

#include "BSTNode.hpp"

using namespace std;

template <typename Data>
class BSTIterator : public iterator<input_iterator_tag, Data> {
private:
    BSTNode<Data> *curr;

public:
    /** 
     * Constructor that initializes a BSTIterator pointing to curr. 
     */
    // TODO testing
    BSTIterator(BSTNode<Data>* curr) {
    
        BSTIterator::curr = curr;

    }

    /** 
     * Dereference operator. 
     */
    Data operator*() const { 
        return curr->data; 
    }

    /** 
     * Pre-increment operator. 
     */
    BSTIterator<Data>& operator++() {
        curr = curr->successor();
        return *this;
    }

    /** 
     * Post-increment operator. 
     */
    BSTIterator<Data> operator++(int) {
        BSTIterator before = BSTIterator(curr);
        ++(*this);
        return before;
    }

    /** 
     * Equality test operator. 
     */  
    // TODO testing
    bool operator==(BSTIterator<Data> const& other) const {

        return ( curr == other.curr );

    }

    /** 
     * Inequality test operator. 
     */  
    // TODO testing
    bool operator!=(BSTIterator<Data> const& other) const {

        return ( curr != other.curr );

    }
};

#endif  // BSTITERATOR_HPP
