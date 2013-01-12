#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// Generic findMax, with a function object, C++ style.
// Precondition: a.size( ) > 0.
template <typename Object, typename Comparator>
const Object & findMax( const vector<Object> & arr, Comparator isLessThan )
{
    int maxIndex = 0;

    for( unsigned int i = 1; i < arr.size( ); i++ )
        if( isLessThan( arr[ maxIndex ], arr[ i ] ) )
            maxIndex = i;

    return arr[ maxIndex ];
}

// Generic findMax, using default ordering.
#include <functional>
template <typename Object>
const Object & findMax( const vector<Object> & arr )
{
    return findMax( arr, less<Object>( ) );
}

class Employee
{
  public:
    void setValue( const string & n, double s )
      { name = n; salary = s; }

    void print( ostream & out ) const
      { out << name << " (" << salary << ")"; }
    bool operator< ( const Employee & rhs ) const
      { return strcasecmp( name.c_str( ), rhs.name.c_str( ) ) < 0; }

 // Other general accessors and mutators, not shown
  private:
    string name;
    double salary;
};

// Define an output operator for Employee
ostream & operator<< ( ostream & out, const Employee & rhs )
{
    rhs.print( out );
    return out;
}


int main( )
{
    vector<Employee> v( 5 );

    v[ 0 ].setValue( "Rihanna", 300000 );
    v[ 1 ].setValue( "Kanye", 500000 );
    v[ 2 ].setValue( "TUPAC", 0 );
    v[ 3 ].setValue( "Jay-Z", 800000 );
    v[ 4 ].setValue( "Beyonce", 1000000 );

    cout << "These are the employees: " << endl;
    for ( unsigned int i = 0; i < v.size( ); i++ ) {
        cout << v[ i ] << endl;
    }

    cout << "The alphabetically last employee, ignoring case distinctions, is " << findMax( v ) << endl;

    return 0;
}
