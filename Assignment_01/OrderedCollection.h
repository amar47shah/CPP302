#ifndef OrderedCollection_h
#define OrderedCollection_h

template <typename Comparable>
class OrderedCollection
{
    public:
        OrderedCollection( ) : storedValues( ), size( 0 ) { }
        ~OrderedCollection( )
        {
            makeEmpty( );
        }
        bool isEmpty( ) const { return !size; }
        void makeEmpty( )
        {
            if ( !isEmpty( ) )
            {
                delete [ ] storedValues;
                storedValues = NULL;
                size = 0;
            }
        }
        void insert( const Comparable & newValue )
        {
            if ( isEmpty( ) )
            {
                storedValues = new Comparable[ 1 ];
                storedValues[ 0 ] = newValue;
                size = 1;
            }
            else
            {
                Comparable *tempStorage = new Comparable[ size + 1 ];
                for ( int i = 0; i < size; i++ )
                {
                    tempStorage[ i ] = storedValues[ i ];
                }
                delete [ ] storedValues;
                storedValues = tempStorage;
                storedValues[ size ] = newValue;
                size++;
            }
        }
        void remove( const Comparable & notWanted )
        {
            bool valueFound = false;
            int valueIndex = -1;
            while ( !valueFound && valueIndex < size )
            {
                valueIndex++;
                valueFound = storedValues[ valueIndex ] == notWanted;
            }
            if ( valueFound )
            {
                Comparable *tempStorage = new Comparable[ size - 1 ];
                for ( int i = 0; i < valueIndex; i++ )
                {
                    tempStorage[ i ] = storedValues[ i ];
                }
                for ( int i = valueIndex + 1; i < size; i++ )
                {
                    tempStorage[ i - 1 ] = storedValues[ i ];
                }
                delete [ ] storedValues;
                storedValues = tempStorage;
                size--;
            }
        }
        const Comparable & findMin( ) const
        {
            if ( isEmpty( ) )
            {
                return 999;
            }
            int minIndex = 0;
            for ( int i = 1; i < size; i++ )
            {
                if ( storedValues[ i ] < storedValues[ minIndex ] )
                {
                    minIndex = i;
                }
            }
            return storedValues[ minIndex ];
        }
        const Comparable & findMax( ) const
        {
            if ( isEmpty( ) )
            {
                return -999;
            }
            int maxIndex = 0;
            for ( int i = 1; i < size; i++ )
            {
                if ( storedValues[ i ] > storedValues[ maxIndex ] )
                {
                    maxIndex = i;
                }
            }
            return storedValues[ maxIndex ];
        }

private:
    Comparable *storedValues;
    int size;
};

#endif

