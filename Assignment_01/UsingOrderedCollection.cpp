
#include <iostream>
#include "OrderedCollection.h"

using namespace std;


int main( ) {
    OrderedCollection<int> myCollection;

    cout << "Is myCollection empty? " << (myCollection.isEmpty( ) ? "yes" : "no") << endl;
    cout << "Let's add 4, 7, and 9 to the collection." << endl;
    myCollection.insert( 4 );
    myCollection.insert( 7 );
    myCollection.insert( 9 );
    cout << "Is myCollection empty now? " << (myCollection.isEmpty( ) ? "yes": "no") << endl;
    cout << "The minimum value in myCollection is " << myCollection.findMin( ) << endl;
    cout << "The maximum value in myCollection is " << myCollection.findMax( ) << endl;
    cout << "But if I remove the maximum value...";
    myCollection.remove( myCollection.findMax( ) );
    cout << "then the new maximum value is " << myCollection.findMax( ) << endl;
    cout << "I still have some things in my collection, but what if I make it empty?" << endl;
    myCollection.makeEmpty( );
    cout << "Is myCollection empty now? " << (myCollection.isEmpty( ) ? "yes" : "no" ) << endl;

    return 0;
}


