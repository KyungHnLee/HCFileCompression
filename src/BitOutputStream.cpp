#include "BitOutputStream.hpp"

// TODO (final) needs testing
BitOutputStream::BitOutputStream(ostream & o) : out(o), buf(0), nbits(0) {}

void BitOutputStream::writeBit(bool bit) {
    // TODO (final) needs testing
    
    // flush the bitwise buffer if it is full
    if( nbits == 8 ) {

        flush();

    }

    // set the next open bit of the bitwise buffer to 'bit' 
    buf = buf << 1; // shift buffer by 1 to left
    if( bit == 1 ) {

        buf = buf | 1;

    }

    // implement the number of bits in our bitwise buffer
    nbits ++;

}

void BitOutputStream::flush() {
    // TODO (final) needs testing
    
    if( nbits != 0 ) {
        if( nbits != 8 ) {

            buf = buf << ( 8 - nbits );
    
        }

        out.put( buf );     // write the bitwise buffer to the ostream
        buf = 0;            // clear the bitwise buffer
        nbits = 0;          // bitwise buffer is cleared, there are 0 bits in it

    }

}
