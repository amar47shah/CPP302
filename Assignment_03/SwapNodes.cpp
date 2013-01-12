/*
 * SwapNodes.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: amar
 */

#include <iostream>
#include <iterator>
#include "DLList.h"
#include "SLList.h"

using namespace std;

template<typename Container>
void printCollection(const Container & c, ostream & out = cout)
{
    if (c.empty())
        out << "(empty)";
    else
    {
        typename Container::const_iterator itr = c.begin();
        out << "[ " << *itr++; // Print first item

        while (itr != c.end())
            out << ", " << *itr++;
        out << " ]" << endl;
    }
}

int main()
{
    DLList<int> myDLL;
    DLList<int>::const_iterator cIter;

    cout << "Here is my double-linked list." << endl;

    myDLL.push_front(3);
    myDLL.push_front(2);
    myDLL.push_front(1);
    myDLL.push_back(4);
    myDLL.push_back(5);
    myDLL.push_back(6);
    myDLL.push_back(7);
    myDLL.push_back(8);
    myDLL.push_back(9);

    cout << "List size = " << myDLL.size() << endl;
    cout << "List: "; printCollection(myDLL, cout);

    cout << endl;
    cout << "Swapping the first two elements:" << endl;
    myDLL.swapWithNextDLL(myDLL.begin());
    cout << "List: "; printCollection(myDLL, cout);

    cIter = myDLL.begin();
    for (int i = 0; i < 4; ++i) cIter++;
    cout << "Swapping the fourth and sixth elements:" << endl;
    myDLL.swapBeforeAndAfter(cIter);
    cout << "List: "; printCollection(myDLL, cout);

    cIter = myDLL.begin();
    for (int i = 0; i < 2; ++i) cIter++;
    cout << "Let's swap the elements before and after the 3:" << endl;
    myDLL.swapBeforeAndAfter(cIter);
    cout << "List: "; printCollection(myDLL, cout);

    cout << endl;
    cout <<"What happens if we try to swap the elements \"before\" and after the beginning?" << endl;
    myDLL.swapBeforeAndAfter(myDLL.begin());
    cout << "List: "; printCollection(myDLL, cout);
    cout << "Or before and \"after\" the end?" << endl;
    myDLL.swapBeforeAndAfter(myDLL.end());
    cout << "List: "; printCollection(myDLL, cout);
    cout << "Nothing happened either time." << endl;
    cout << endl;

    SLList mySLL;
    SLList::Iterator Iter;

    mySLL.push_front(0);
    mySLL.push_front(1);
    mySLL.push_front(0);
    mySLL.append(1);
    mySLL.append(1);
    mySLL.append(0);
    mySLL.append(0);

    cout << "Now I'll make a single-linked list." << endl;
    cout << "List: "; mySLL.display();

    cout << endl;
    cout << "Swapping the first two elements:" << endl;

    mySLL.swapTwo(mySLL.begin());
    cout << "List: "; mySLL.display();

    Iter = mySLL.begin();
    for (int i = 0; i < 4; ++i) ++Iter;
    cout << "Swapping the fourth and sixth elements:" << endl;
    mySLL.swapBeforeAndAfter(Iter);
    cout << "List: "; mySLL.display();
    Iter = mySLL.begin();
    for (int i = 0; i < 3; ++i) ++Iter;
    cout << "Now let's swap the third and fifth elements:" << endl;
    mySLL.swapBeforeAndAfter(Iter);
    cout << "List: "; mySLL.display();

    cout << endl;
    cout <<"What happens if we try to swap the elements \"before\" and after the beginning?" << endl;
    mySLL.swapBeforeAndAfter(mySLL.begin());
    cout << "List: "; mySLL.display();
    cout << "Or before and \"after\" the end?" << endl;
    mySLL.swapBeforeAndAfter(mySLL.end());
    cout << "List: "; mySLL.display();
    cout << "Nothing happened either time." << endl;
    cout << endl;


    return 0;
}





