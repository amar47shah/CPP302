#include <iostream>
#include <vector>

using namespace std;

template<typename Comparable>
void printArray(vector<Comparable> & a)
{
	int i = 0;
	int length = a.size();

	if (length == 0)
	{
		cout << "[empty]";
	}
	else
	{
		cout << "[ ";
		while (i < length)
		{
			cout << a[i];
			i++;
			if (i < length)
			{
				cout << ", ";
			} // end if
		}
		cout << " ]" << endl;
	}
}

/**
 * Shellsort, using Shell's (poor) increments.
 */
template<typename Comparable>
void shellSort(vector<Comparable> & a)
{

    // Hibbard's increments
    // h = largest of 1, 3, 7, 15, 31... still smaller than a.size()
    unsigned h = 1;
    while (2 * h + 1 < a.size())
        h = 2 * h + 1;

	for (int gap = h; gap > 0; gap /= 2)
	{
		// The following loop starts at gap and increment forward
		// Until we reach the end
		for (unsigned i = gap; i < a.size(); i++)
		{
			Comparable tmp = a[i];
			unsigned switches = 0;
			int j = i;

			// The loop below is a clever way of starting at a[gap] and comparing it with
			// it's predecessors that are gap apart and doing insert sort when needed

			for (; j >= gap && tmp < a[j - gap]; j -= gap)
			{
				a[j] = a[j - gap];
				switches++;
			}
			a[j] = tmp;
			cout << "Gap = " << gap << ", " << "Switches = " << switches << " ";
			printArray(a);
		}
	}
}

void initializeV1(vector<int> & V1)
{
	for (unsigned i = 0; i < 9; i++)
	    V1[i] = 9 - i;
}

void initializeV2(vector<int> & V2)
{
}

int main()
{
	vector<int> V1(9);

	initializeV1(V1);

	printArray(V1);
	cout << "Shell is starting" << endl;
	shellSort(V1);
	cout << "Shell is done" << endl;
	printArray(V1);

	return 0;
}
