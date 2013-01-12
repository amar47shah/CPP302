#include <iostream>
#include <vector>

using namespace std;

void initializeV2(vector<int> & V2)
{
    V2[0] = 81;
    V2[1] = 94;
    V2[2] = 11;
    V2[3] = 96;
    V2[4] = 12;
    V2[5] = 35;
    V2[6] = 17;
    V2[7] = 95;
    V2[8] = 28;
    V2[9] = 58;
    V2[10] = 41;
    V2[11] = 75;
    V2[12] = 15;
}

/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template<typename Comparable>
void merge(vector<Comparable> & a, vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	// Main loop
	while (leftPos <= leftEnd && rightPos <= rightEnd)
	{
		if (a[leftPos] >= a[rightPos])
		{
			tmpArray[tmpPos++] = a[leftPos++];
		}
		else
		{
			tmpArray[tmpPos++] = a[rightPos++];
		} // end ifelse
	} // end while

	while (leftPos <= leftEnd) // Copy rest of first half
	{
		tmpArray[tmpPos++] = a[leftPos++];
	} // end while

	while (rightPos <= rightEnd) // Copy rest of right half
	{
		tmpArray[tmpPos++] = a[rightPos++];
	} // end while

	// Copy tmpArray back
	for (int i = 0; i < numElements; i++, rightEnd--)
	{
		a[rightEnd] = tmpArray[rightEnd];
	} // end for
	cout << "     "; printVector(tmpArray);
}
/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template<typename Comparable>
void mergeSort(vector<Comparable> & a, vector<Comparable> & tmpArray, int left, int right)
{
	//cout << "Left = " << left << ", Right = " << right << endl;

	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort(a, tmpArray, left, center);
		mergeSort(a, tmpArray, center + 1, right);
		merge(a, tmpArray, left, center + 1, right);
	}
}

/**
 * Mergesort algorithm (driver).
 */
template<typename Comparable>
void mergeSort(vector<Comparable> & a)
{
	vector<Comparable> tmpArray(a.size());
	mergeSort(a, tmpArray, 0, a.size() - 1);
}

void printVector(vector<int> & h)
{
	unsigned int i;
	cout << "[";
	for (i = 0; i < h.size() - 1; ++i)
	{
		cout << h[i] << ", ";
	} // end for
	cout << h[h.size()-1] << "]" << endl;
}

int main()
{
	vector<int> V2(13);

	initializeV2(V2);

	cout << "V2 = "; printVector(V2);
	mergeSort(V2);
	cout << "V2 = "; printVector(V2);
	return 0;
}
