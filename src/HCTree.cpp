#include <stack>
#include <queue>

#include "HCTree.hpp"

/**
 * Destructor for HCTree
 */
HCTree::~HCTree() {
    // TODO (checkpoint) done
    deleteAll( root );

}

/** Use the Huffman algorithm to build a Huffman coding tree.
 *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is
 *  the frequency of occurrence of byte i in the message.
 *  POSTCONDITION:  root points to the root of the tree,
 *  and leaves[i] points to the leaf node containing byte i.
 */
void HCTree::build(const vector<int>& freqs) {
    // TODO (checkpoint)

    // Base case for when there already exists an HCTree 
    if( root != nullptr ) {

        deleteAll( root ); 

    }

    // Iterating through the array of frequencies
    unsigned int i;
    HCNode * tempNode;
    // Priority queue for the tempNodes created
    priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> node_queue;
    for( i = 0; i < freqs.size(); i ++ ) {

        // If the frequency isn't 0 for the i symbol
        if( freqs[i] != 0 ) {

            tempNode = new HCNode( freqs[i], (byte)i, 0, 0, 0);
            // Temp node objects pushed to the priority queue
            node_queue.push( tempNode );
            leaves[i] = tempNode;

        }

    }

    // Variables for the popping from the priority queue
    HCNode * left;
    HCNode * right;
    HCNode * top;

    // Popping from the priority queue in order to access low priority elements
    while( node_queue.size() > 1 ) {

        left = node_queue.top();
        node_queue.pop();
        right = node_queue.top();
        node_queue.pop();
        top = new HCNode( ( right -> count ) + ( left -> count ), 
                max( right -> symbol, left -> symbol ), 0, 0, 0 );
        top -> c0 = left;
        top -> c1 = right;
        right -> p = top;
        left -> p = top;
        node_queue.push( top );

    }

    // The last node to be pushed into the priority queue is top
    if( node_queue.size() == 1 ) {
        root = node_queue.top();
    }

}

/** Write to the given ostream
 *  the sequence of bits (as ASCII) coding the given symbol.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
void HCTree::encode(byte symbol, ostream& out) const {

    // TODO (checkpoint) testing
    HCNode * curr = leaves[ (int)symbol ];
    HCNode * child = curr; 
    string bitString = "";

    // While loop for looping up the tree
    while( child -> p ) {

        // Sets the new curr as the old curr's parent
        curr = curr -> p;

        // If the child is the left child
        if( child == curr -> c0 ) {

            bitString = "0" + bitString;

            // If the child is the right child
        } else if ( child == curr -> c1 ) {

            bitString = "1" + bitString;

        }

        // Sets the new child as the old parent
        child = curr;

    } // End of while loop

    out << bitString;

}

/** Return the symbol coded in the next sequence of bits (represented as 
 *  ASCII text) from the istream.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
byte HCTree::decode(istream& in) const {
    // TODO (checkpoint) needs testing

    char bit;
    HCNode * curr = root;

    // While loop stops when curr is a leaf node
    while( curr -> c0 || curr -> c1 ) {

        bit = (char)in.get();
        // If the bit is 0
        if( bit == '0' ) {

            curr = curr -> c0;

            // If the bit is 1
        } else {

            curr = curr -> c1;

        }

    }

    // Returns the symbol coded in the sequence
    return curr -> symbol;

}

/** Write to the given BitOutputStream
 *  the sequence of bits coding the given symbol.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
void HCTree::encode(byte symbol, BitOutputStream& out) const {
    // TODO (final) needs testing

    HCNode * curr = leaves[ (int)symbol ];
    HCNode * child = curr; 

    // Vector for keeping track of all the bits
    vector<bool> bits;

    // While loop for looping up the tree
    while( child -> p ) {

        // Sets the new curr as the old curr's parent
        curr = curr -> p;

        // If the child is the left child
        if( child == curr -> c0 ) {

            bits.push_back( 0 );

        // If the child is the right child
        } else if ( child == curr -> c1 ) {

            bits.push_back( 1 );

        }

        // Sets the new child as the old parent
        child = curr;

    } // End of while loop

    // Loop to write bits
    for( int i = bits.size() - 1; i >= 0; i -- ) {

        out.writeBit( bits[ i ] );

    }

}

/** Return symbol coded in the next sequence of bits from the stream.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
byte HCTree::decode(BitInputStream& in) const {
    
    bool bit = 0;
    HCNode * curr = root;

    // While loop stops when curr is a leaf node
    while( curr -> c0 || curr -> c1 ) {

        bit = in.readBit(); 

        // If the bit is 0
        if( bit == 0 ) {

            curr = curr -> c0;

            // If the bit is 1
        } else {

            curr = curr -> c1;

        }

    }

    // Returns the symbol coded in the sequence
    return curr -> symbol;

}

/**
 * Print the contents of a tree
 */
void HCTree::printTree() const {
    cout << "=== PRINT TREE BEGIN ===" << endl;
    printTreeHelper(root);
    cout << "=== PRINT TREE END =====" << endl;
}

/**
 * Recursive helper function for printTree
 */
void HCTree::printTreeHelper(HCNode * node, string indent) const {
    if (node == nullptr) {
        cout << indent << "nullptr" << endl;
        return;
    }

    cout << indent << *node << endl;
    if (node->c0 != nullptr || node->c1 != nullptr) {
        printTreeHelper(node->c0, indent + "  ");
        printTreeHelper(node->c1, indent + "  ");
    }
}

/**
 * Recursive helper function for HCTree destructor
 */
void HCTree::deleteAll( HCNode * n ) {

    // Base case
    if( n == nullptr ) {

        return;

    }

    deleteAll( n -> c0 );
    deleteAll( n -> c1 );
    delete n;

}
