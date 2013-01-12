#define HIGH 1000000000
#define LOW -1 * HIGH
#define PRECISION 20

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

double randomDouble();
int printDigit(int);
int printDigit(char);
int printDouble(double);
int printWhole(int);
int printDecimal(double);

int main () {

    cout << "Generating a random double." << endl;
    double anyDouble = randomDouble();

    cout << "Output using cout: \t\t";
    cout.precision(PRECISION + 9);
    cout << anyDouble << endl;

    cout << "Output using only printDigit: \t";
    printDouble(anyDouble);

    return 0;
}

double randomDouble() {
// generate random double in range(HIGH, LOW)

    srand( time(NULL));
    double f = (double) rand() / RAND_MAX;
    return (double) LOW + f * (HIGH - LOW);
}

int printDigit(int d) {
// Prints an integer in the range 0...9

    if (d >= 0 && d <= 9) {
	    putchar(48 + d);
	    return 0;
	}
    return 1;
}

int printDigit(char c) {
// Prints the character '-' or '.'

    if (c == '-' || c == '.') {
        putchar(c);
        return 0;
    }
    return 1;
}

int printDouble(double d) {

    if (d < 0) {
        printDigit('-');
        d *= -1;
    }
    // now d is positive.

    // break d into whole and decimal parts
    int wholePart = (int) d;
    double decimalPart = d - wholePart;

    printWhole(wholePart);
    printDecimal(decimalPart);

    return 0;
}

int printWhole(int w) {

    int placeCount = (int) log10(w);

    for (int i = placeCount; i >= 0; i--) {

        int powerOf10 = (int) pow(10.0, i);
        int leadDigit = w / powerOf10;

        printDigit(leadDigit);
        w -= leadDigit * powerOf10;
    }

    return 0;
}

int printDecimal(double d) {

    if (d) {
        printDigit('.');

        for (int i = 0; i < PRECISION; i++) {

            d *= 10;
            int leadDigit = (int) d;

            printDigit(leadDigit);
            d -= leadDigit;
        }

        return 0;
    }

    return 1;
}
