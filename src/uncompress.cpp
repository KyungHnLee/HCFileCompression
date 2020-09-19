#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdint.h>

#include "HCNode.hpp"
#include "HCTree.hpp"
#include "BitInputStream.hpp"

using namespace std;

void print_usage(char ** argv) {
    cout << "Usage:" << endl;
    cout << "  " << argv[0] << " INFILE OUTFILE [-b]" << endl;
    cout << "Command-line flags:" << endl;
    cout << "  -b: switch to bitwise mode" << endl;
}

/**
 * Reads infile, constructs a Huffman coding tree based on its header,
 * and produces an uncompressed version in outfile.
 * For debugging purposes, uses ASCII '0' and '1' rather than bitwise I/O.
 */
void uncompressAscii(const string & infile, const string & outfile) {
    // TODO (checkpoint)
    
    // Opening infile
    ifstream ifs;
    ifs.open( infile, ios::binary );

    // Opening outFile
    ofstream ofs;
    ofs.open( outfile, ios::binary );

    HCTree tree;
    vector<int> freqs( 256, 0 );

    int frequency = 0;
    // For counting unique chars
    int uniqueChars = 0;

    unsigned int i;
    // Reads line by line
    for( i = 0; i < freqs.size(); i ++ ) {

        ifs >> frequency;
        freqs[i] = frequency;
        if( frequency != 0 ) {

            uniqueChars = uniqueChars + 1;

        }
    
    } // freqs is finished

    ifs.get();

    tree.build( freqs );
   
    // When empty input file
    if( uniqueChars == 0 ) {

        ifs.close();
        ofs.close();
        return;

    }

    // Creates a byte for tree decoding
    byte read = 0;

    // When ony one char
    if( uniqueChars == 1 ) {

        read = tree.decode( ifs );

        // Prints to file single char
        for( i = 0; i < (unsigned int)freqs[ read ]; i ++ ) {

            ofs << read;

        }

        ifs.close();
        ofs.close();
        return;

    }

    // Not reaching end of file
    while( 1 ) {
    
        // Decoding from the ifs stream (last line)
        read = tree.decode( ifs );

        if( ifs.eof() ) {

            break;

        }

        ofs << read;


    }

    ifs.close();
    ofs.close();

}

/**
 * Reads infile, constructs a Huffman coding tree based on its header,
 * and produces an uncompressed version in outfile.
 * Uses bitwise I/O.
 */
void uncompressBitwise(const string & infile, const string & outfile) {
    // TODO (final)

    // Opening infile
    ifstream ifs;
    ifs.open( infile, ios::binary );

    // Opening outFile
    ofstream ofs;
    ofs.open( outfile, ios::binary );

    // Creates BitInputStream
    BitInputStream bis( ifs );

    HCTree tree;
    vector<int> freqs( 256, 0 );

    int frequency = 0;
    // For counting unique chars
    int uniqueChars = 0;

    unsigned int i = 0;
    // Reads line by line
    for( i = 0; i < freqs.size(); i ++ ) {

        ifs.read( (char *)&frequency, sizeof(int) );
        freqs[i] = frequency;
        if( frequency != 0 ) {

            uniqueChars = uniqueChars + 1;

        }
    
    } // freqs is finished

    tree.build( freqs );
   
    // When empty input file
    if( uniqueChars == 0 ) {

        ifs.close();
        ofs.close();
        return;

    }

    // Creates a byte for tree decoding
    byte read = 0;

    // When ony one char
    if( uniqueChars == 1 ) {

        read = tree.decode( bis );

        // Prints to file single char
        for( i = 0; i < (unsigned int)freqs[ read ]; i ++ ) {

            ofs << read;

        }

        ifs.close();
        ofs.close();
        return;

    }

    // Not reaching end of file
    while( 1 ) {
    
        // Decoding from the ifs stream (last line)
        read = tree.decode( bis );

        if( ifs.eof() ) {

            break;

        }

        ofs << read;


    }

    ifs.close();
    ofs.close();

}

int main(int argc, char ** argv) {
    string infile = "";
    string outfile = "";
    bool bitwise = false;
    for (int i = 1; i < argc; i++) {
        string currentArg = argv[i];
        if (currentArg == "-b") {
            bitwise = true;
        } else if (infile == "") {
            infile = currentArg;
        } else {
            outfile = currentArg;
        }
    }

    if (infile == "" || outfile == "") {
        cout << "ERROR: Must provide input and output files" << endl;
        print_usage(argv);
        return 1;
    }

    if (bitwise) {
        uncompressBitwise(infile, outfile);
    } else {
        uncompressAscii(infile, outfile);
    }

    return 0;
}
