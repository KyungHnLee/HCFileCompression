#include "BitInputStream.hpp"

// TODO (final) needs testing
BitInputStream::BitInputStream(istream & i) : in(i), buf(0), nbits(8) {}

void BitInputStream::fill() {

    buf = in.get(); // Read one byte from istream to bitwise buffer
    nbits = 0;      // no nbits have been read from bitwise buffer

}

// The bitwise number that is going to be used for the operation in readBit
int BitInputStream::bitWiseNum() {

    // the number to return to use for the bitwise operation
    int bitWiseNum = 1;
    // for loop to multiply by necessary amount of 2's
    for( int i = 1; i <= (7 - nbits); i ++ ) {

        bitWiseNum = bitWiseNum * 2;

    }

    return bitWiseNum;

}

bool BitInputStream::readBit() {
//TODO (final) needs testing

    if( nbits == 8 ) {

        fill();

    }

    int bitWiseNum = BitInputStream::bitWiseNum();

    unsigned int nextBit = buf & bitWiseNum;

    nextBit = nextBit >> ( 7 - nbits );

    // increment the num of bits we read from the bitwise buffer
    nbits ++;

    // return false if 0, true if 1
    if( nextBit == 0 ) {

        return false;

    } else {

        return true;

    }

}
