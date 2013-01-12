#include <iostream>
#include <vector>

using namespace std;

template<typename Comparable>
void heapsort(vector<Comparable> & a)
{
    cout << endl << "Building heap." << endl;
	for (int i = (a.size() / 2) - 1; i >= 0; i--) /* buildHeap */
	{
	    prettyPrintVector(a);
		cout << "i = " << i << " ";
		cout << "h[i] = " << a[i] << " ";
		cout << "children = " << a[2*i+1];
		if (2*i+2 < a.size()) cout << ", " << a[2*i+2];
		cout << endl;

		percDown(a, i, a.size());
	}
	cout << endl;
	prettyPrintVector(a);
	cout << endl;
	cout << "Using deleteMax to sort heap." << endl;
	for (int j = a.size() - 1; j > 0; j--)
	{
		swap(a[0], a[j]); /* deleteMax */
		prettyPrintVector(a);
		percDown(a, 0, j);
		prettyPrintVector(a);
	}
}

/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline int leftChild(int i)
{
	return 2 * i + 1;
}

/**
 * Internal method for heapsort that is used in deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template<typename Comparable>
void percDown(vector<Comparable> & a, int i, int n)
{
	int child;
	Comparable tmp;

	for (tmp = a[i]; leftChild(i) < n; i = child)
	{
		child = leftChild(i);
		if (child != n - 1 && a[child] < a[child + 1])
			child++;
		if (tmp < a[child])
			a[i] = a[child];
		else
			break;
	}
	a[i] = tmp;
}

void printVector(vector<int> & h)
{
	unsigned int i;
	cout << "Start:" << endl;
	for (i = 0; i < h.size(); ++i)
	{
		cout << "h[" << i << "] = " << h[i] << endl;
	} // end for
	cout << "End." << endl;
}

void prettyPrintVector(vector<int> &h)
{
    unsigned int i;
    cout << "h = [";
    for (i = 0; i < h.size() - 1; ++i)
        cout << h[i] << ", ";
    cout << h[i] << "]" << endl;

}

int main()
{

	vector<int> h(12);

	h[0] = 142;
	h[1] = 543;
	h[2] = 123;
	h[3] = 65;
	h[4] = 453;
	h[5] = 879;
	h[6] = 572;
    h[7] = 434;
    h[8] = 111;
    h[9] = 242;
    h[10] = 811;
    h[11] = 102;

	prettyPrintVector(h);
	heapsort(h);
	prettyPrintVector(h);
	return 0;

}
