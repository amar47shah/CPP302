/*
 * SLListMain.cpp
 *
 *  Created on: Oct 9, 2012
 *      Author: amar
 */

#include <iostream>
#include <ctime>
#include "SLList.h"
#define LARGE 1e6

using namespace std;

int main()
{
    SLList myList;
    clock_t initial, duration;

    cout << "Using the insert() method to add the value True to the beginning:" << endl;
    myList.insert(True); myList.display();

    cout << "Using the append() method to add the value False to the end:" << endl;
    myList.append(False); myList.display();

    cout << "Appending True to the end:" << endl;
    myList.append(True); myList.display();

    cout << "Using the push_front() method to add the value True to the beginning:" << endl;
    myList.push_front(True); myList.display();

    cout << "Inserting False at the beginning:" << endl;
    myList.insert(False); myList.display();

    cout << "Pushing True to the beginning:" << endl;
    myList.push_front(True); myList.display();

    cout << endl << "Removing all occurrences of the value False:" << endl;
    myList.remove(False); myList.display();

    if (myList.isPresent(True))
        cout << "The value True is present." << endl;
    else
        cout << "The value True is not present." << endl;

    if (myList.isPresent(False))
        cout << "The value False is present." << endl;
    else
        cout << "The value False is not present." << endl;

    if (myList.isEmpty())
        cout << "The list is empty." << endl;
    else
        cout << "The list is not empty" << endl;

    cout << endl << "Removing all items from the list:" << endl;
    myList.remove(); myList.display();

    if (myList.isEmpty())
        cout << "The list is empty." << endl;
    else
        cout << "The list is not empty." << endl;

    cout << endl << "Using append() to add " << LARGE << " values of True to the empty list." << endl;
    initial = clock();
    for (unsigned i = 0; i < LARGE; i++)
        myList.append(True);
    duration = clock() - initial;
    cout << "That took " << duration << " clock ticks." << endl;

    cout << endl << "Emptying the list." << endl;
    myList.remove();

    if (myList.isEmpty())
        cout << "The list is empty." << endl;
    else
        cout << "The list is not empty." << endl;

    cout << endl << "Using push_front to add " << LARGE << " values of True to the empty list." << endl;
    initial = clock();
    for (unsigned i = 0; i < LARGE; i++)
        myList.push_front(True);
    duration = clock() - initial;
    cout << "That took " << duration << " clock ticks." << endl;

    cout << endl << "Emptying the list." << endl;
    myList.remove();

    if (myList.isEmpty())
        cout << "The list is empty." << endl;
    else
        cout << "The list is not empty." << endl;

    return 0;
}


