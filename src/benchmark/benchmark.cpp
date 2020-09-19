#include <iostream>
#include <set>
#include <random>
#include <cmath>
#include <vector>
#include <set>

#include "util.hpp"
#include "BST.hpp"

using namespace std;

int main() {
    // This is an example of runtime benchmarking
    // TODO (final): Replace the following with a benchmarking comparison
    // of two data structures, as described in the project instructions

    int numTrials = 100;
    int dataSize = 5;
    int maxSteps = 30;
    int stepSize = 500;
    int findSize = dataSize;

    vector<long long> times(numTrials, 0);

    Timer t;

    default_random_engine generator;
    uniform_real_distribution<double> distribution(-1.0, 1.0);

/*
    // For BST average case for find
    for( int step = 0; step < maxSteps; step ++ ) {

        // Declare BST
        BST<double> BSTree;

        // Declare array of the elements in the BST
        vector<double> elements( dataSize );

        generator.seed( 1 + step );
    
        // Adding random doubles to the BST
        for( int dataIndex = 0; dataIndex < dataSize; dataIndex ++ ) {

            double currRandom = distribution( generator );
            BSTree.insert( currRandom );
            elements[dataIndex] = currRandom;

        }

        // Run benchmarks and time each trial
        for( int trialIndex = 0; trialIndex < numTrials; trialIndex ++ ) {
        
            t.begin_timer();

           for( int toFind = 0; toFind < findSize; toFind ++ ) {

               BSTree.find( elements[ toFind ]); 

           }
          
            times[trialIndex] = t.end_timer();

        }

        // Compute statistics from trial times
        double totalTime = 0.0;
        for( int i = 0; i < numTrials; i ++ ) {

            totalTime += times[i];
        
        }

        double meanTime = totalTime / ( (double) numTrials );
        cout << dataSize << "\t" << meanTime << endl;
        dataSize += stepSize;

    }

*/

/*
    // For BST worst case for find
    for( int step = 0; step < maxSteps; step ++ ) {

        // Declare BST
        BST<double> BSTree;

        for( int i = 0; i < dataSize; i ++ ) {

            BSTree.insert( i );

        }

        // Run benchmarks and time each trial
        for( int trialIndex = 0; trialIndex < numTrials; trialIndex ++ ) {
        
            t.begin_timer();

            BSTree.find( dataSize - 1 );

            times[trialIndex] = t.end_timer();

        }

        // Compute statistics from trial times
        double totalTime = 0.0;
        for( int i = 0; i < numTrials; i ++ ) {

            totalTime += times[i];
        
        }

        double meanTime = totalTime / ( (double) numTrials );
        cout << dataSize << "\t" << meanTime << endl;
        dataSize += stepSize;

    }
*/

/*
    // For RBTree average case for find
    for( int step = 0; step < maxSteps; step ++ ) {

        // Declare BST
        set<double> RBTree;

        // Declare array of the elements in the BST
        vector<double> elements( dataSize );

        generator.seed( 1 + step );
    
        // Adding random doubles to the BST
        for( int dataIndex = 0; dataIndex < dataSize; dataIndex ++ ) {

            double currRandom = distribution( generator );
            RBTree.insert( currRandom );
            elements[dataIndex] = currRandom;

        }

        // Run benchmarks and time each trial
        for( int trialIndex = 0; trialIndex < numTrials; trialIndex ++ ) {
        
            t.begin_timer();

           for( int toFind = 0; toFind < findSize; toFind ++ ) {

               RBTree.find( elements[ toFind ]); 

           }
          
            times[trialIndex] = t.end_timer();

        }

        // Compute statistics from trial times
        double totalTime = 0.0;
        for( int i = 0; i < numTrials; i ++ ) {

            totalTime += times[i];
        
        }

        double meanTime = totalTime / ( (double) numTrials );
        cout << dataSize << "\t" << meanTime << endl;
        dataSize += stepSize;

    }
*/

/*
    // For RBTree worst case for find
    for( int step = 0; step < maxSteps; step ++ ) {

        // Declare BST
        set<double> RBTree;

        for( int i = 0; i < dataSize; i ++ ) {

            RBTree.insert( i );

        }

        // Run benchmarks and time each trial
        for( int trialIndex = 0; trialIndex < numTrials; trialIndex ++ ) {
        
            t.begin_timer();

            RBTree.find( dataSize - 1 );

            times[trialIndex] = t.end_timer();

        }

        // Compute statistics from trial times
        double totalTime = 0.0;
        for( int i = 0; i < numTrials; i ++ ) {

            totalTime += times[i];
        
        }

        double meanTime = totalTime / ( (double) numTrials );
        cout << dataSize << "\t" << meanTime << endl;
        dataSize += stepSize;

    }
*/

/*
    // For BST average case for insert
    for( int step = 0; step < maxSteps; step ++ ) {

        generator.seed( 1 + step );

        // Run benchmarks and time each trial
        for( int trialIndex = 0; trialIndex < numTrials; trialIndex ++ ) {
        
            // Declare BST
            BST<double> BSTree;

            // Adding random doubles to the BST
            for( int dataIndex = 0; dataIndex < dataSize; dataIndex ++ ) {

                double currRandom = distribution( generator );
                BSTree.insert( currRandom );

            }

            double currRandom = distribution( generator );
            // start timer and then insert when there are n elements
            t.begin_timer();
            BSTree.insert( currRandom );
            times[trialIndex] = t.end_timer();

        }

        // Compute statistics from trial times
        double totalTime = 0.0;
        for( int i = 0; i < numTrials; i ++ ) {

            totalTime += times[i];
        
        }

        double meanTime = totalTime / ( (double) numTrials );
        cout << dataSize << "\t" << meanTime << endl;
        dataSize += stepSize;

    }
*/

/*
    // For RBT average case for insert
    for( int step = 0; step < maxSteps; step ++ ) {

        generator.seed( 1 + step );

        // Run benchmarks and time each trial
        for( int trialIndex = 0; trialIndex < numTrials; trialIndex ++ ) {
        
            // Declare RBT
            set<double> RBTree;

            // Adding random doubles to the RBT
            for( int dataIndex = 0; dataIndex < dataSize; dataIndex ++ ) {

                double currRandom = distribution( generator );
                RBTree.insert( currRandom );

            }

            double currRandom = distribution( generator );
            // start timer and then insert when there are n elements
            t.begin_timer();
            RBTree.insert( currRandom );
            times[trialIndex] = t.end_timer();

        }

        // Compute statistics from trial times
        double totalTime = 0.0;
        for( int i = 0; i < numTrials; i ++ ) {

            totalTime += times[i];
        
        }

        double meanTime = totalTime / ( (double) numTrials );
        cout << dataSize << "\t" << meanTime << endl;
        dataSize += stepSize;

    }
*/

/*
    // For BST worst case for insert
    for( int step = 0; step < maxSteps; step ++ ) {

        // Run benchmarks and time each trial
        for( int trialIndex = 0; trialIndex < numTrials; trialIndex ++ ) {
        
            // Declare BST
            BST<double> BSTree;

            // Adding increasing value to the BST
            for( int dataIndex = 0; dataIndex < dataSize; dataIndex ++ ) {

                BSTree.insert( dataIndex );

            }

            // start timer and then insert when there are n elements
            t.begin_timer();
            BSTree.insert( dataSize );
            times[trialIndex] = t.end_timer();

        }

        // Compute statistics from trial times
        double totalTime = 0.0;
        for( int i = 0; i < numTrials; i ++ ) {

            totalTime += times[i];
        
        }

        double meanTime = totalTime / ( (double) numTrials );
        cout << dataSize << "\t" << meanTime << endl;
        dataSize += stepSize;

    }
*/

/*
    // For RBT worst case for insert
    for( int step = 0; step < maxSteps; step ++ ) {

        // Run benchmarks and time each trial
        for( int trialIndex = 0; trialIndex < numTrials; trialIndex ++ ) {
        
            // Declare RBT
            set<double> RBTree;

            // Adding increasing value to the RBT
            for( int dataIndex = 0; dataIndex < dataSize; dataIndex ++ ) {

                RBTree.insert( dataIndex );

            }

            // start timer and then insert when there are n elements
            t.begin_timer();
            RBTree.insert( dataSize );
            times[trialIndex] = t.end_timer();

        }

        // Compute statistics from trial times
        double totalTime = 0.0;
        for( int i = 0; i < numTrials; i ++ ) {

            totalTime += times[i];
        
        }

        double meanTime = totalTime / ( (double) numTrials );
        cout << dataSize << "\t" << meanTime << endl;
        dataSize += stepSize;

    }
*/
    return 0;
}
