#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "HCNode.hpp"
#include "HCTree.hpp"
#include "BitOutputStream.hpp"

using namespace std;

void print_usage(char ** argv) {
    cout << "Usage:" << endl;
    cout << "  " << argv[0] << " INFILE OUTFILE [-b]" << endl;
    cout << "Command-line flags:" << endl;
    cout << "  -b: switch to bitwise mode" << endl;
}

/**
 * Reads infile, constructs a Huffman coding tree based on its contents,
 * and produces a compressed version in outfile.
 * For debugging purposes, uses ASCII '0' and '1' rather than bitwise I/O.
 */
void compressAscii(const string & infile, const string & outfile) { 
    // Opening infile
    ifstream ifs;
    ifs.open( infile, ios::binary );
    // Opening outfile
    ofstream ofs;
    ofs.open( outfile, ios::binary );
    // For reading in the byte
    int nByte = 0;
    byte nChar = 0;
    // Array for the chars that were read
    vector<byte> chars;
    // Declare tree and vector of ints
    HCTree tree;
    vector<int> freqs(256, 0);
    // Loop to get the infile bytes
    while( ( nByte = ifs.get() ) != EOF ) {
        nChar = (byte)nByte;
        // Once byte is found, index it
        freqs[ nChar ] += 1;
        chars.push_back( nChar );
    } // At this point, freqs is finished
    tree.build( freqs );
    unsigned int i = 0;
    // Loop through the freqs to construct the header of file
    for( i = 0; i < freqs.size(); i ++ ) {
        ofs << freqs[i] << endl;
    }
    // Loop through the chars to construct lastline
    for( i = 0; i < chars.size(); i ++ ) {
        tree.encode( chars[i], ofs );
    }
    // Closes the files
    ifs.close();
    ofs.close();
}

/**
 * Reads infile, constructs a Huffman coding tree based on its contents,
 * and produces a compressed version in outfile.
 * Uses bitwise I/O.
 */
void compressBitwise(const string & infile, const string & outfile) {
    // TODO (final)

    // Opening infile
    ifstream ifs;
    ifs.open( infile, ios::binary );

    // Opening outfile
    ofstream ofs;
    ofs.open( outfile, ios::binary );

    // BitOutStream for outfie
    BitOutputStream bos( ofs );

    // For reading in the byte
    int nByte;
    unsigned char nChar;

    // Array for the chars that were read
    vector<unsigned char> chars;

    // Declare tree and vector of ints
    HCTree tree;
    vector<int> freqs(256, 0);

    // Loop to get the infile bytes
    while( ( nByte = ifs.get() ) != EOF ) {

        nChar = (unsigned char)nByte;

        // Once byte is found, index it
        freqs[ nChar ] += 1;
        chars.push_back( nChar );

    } // At this point, freqs is finished

    tree.build( freqs );
   
    unsigned int i;
    // Loop through the freqs to construct the header of file
    for( i = 0; i < freqs.size(); i ++ ) {

        ofs.write( (char *) &freqs[i], sizeof( int ) );

    }

    // Loop through the chars to construct lastline
    for( i = 0; i < chars.size(); i ++ ) {

        tree.encode( chars[i], bos );

    }

    bos.flush();

    // Closes the files
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
        compressBitwise(infile, outfile);
    } else {
        compressAscii(infile, outfile);
    }

    return 0;
}
