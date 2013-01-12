//============================================================================
// Name        : Problem_06.cpp
// Author      : Mark Weiss
// Version     :
// Copyright   :
// Description :This code was written by Mark Weiss, the textbook author.
//              It is not the original work of this student, Amar Shah.
//============================================================================
#include <iostream>
#include <list>
#include <ctime>

using namespace std;

int main()
{

 char again;
 do {
    int i, j, n, m, mPrime, numLeft;
    clock_t initial, final;

    list<int> L;
    list<int>::iterator iter;

    //Initialization
    cout << "enter N (# of people) & M (# of passes before elimination): ";
    cin >> n >> m;
    numLeft = n;
    mPrime = m % n;
    for (i = 1; i <= n; i++)
    {
        L.push_back(i);
    }
    iter = L.begin();
    /*for (i = 0; i < n; i++)
    {
        cout << *iter++ << " ";
    }
    cout << endl;*/

    iter = L.begin();

    initial = clock();

    // Pass the potato
    for (i = 0; i < n; i++)
    {
        mPrime = mPrime % numLeft;

        if (mPrime <= numLeft / 2) // pass forward
        {
            for (j = 0; j < mPrime; j++)
            {
                iter++;
                if (iter == L.end())
                    iter = L.begin();
            }
        }
        else
        { // pass backward
            for (j = 0; j < mPrime; j++)
            {
                if (iter == L.begin())
                    iter = --L.end();
                else
                    iter--;
            }
        }
        //cout << *iter << " ";
        iter = L.erase(iter);
        if (iter == L.end())
            iter = L.begin();
    }
    //cout << endl;

    final = clock();
    cout << "That took " << final - initial << " clock ticks." << endl;

    cout << "Again (Y/N)? ";
    cin >> again;
 } while (again == 'Y' || again == 'y');

    return 0;
}
