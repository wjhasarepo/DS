#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include "UniformRandom.h"
using namespace std;

template <typename AnyType>
class HashFamily
{
public:
    size_t hash(const AnyType &x, int which) const;
    int getNumberOfFunctions();
    void generateNewFunctions();
};

template <int count>
class StringHashFamily
{
public:
    StringHashFamily(): MULTIPIERS(count)
    {
        gnenrateNewFunctions();
    }

    int getNumberOfFunctions() const
    {
        return count;
    }

    void generateNewFunctions()
    {
        for(auto & mult : MULTIPLERS)
            mult = r.nextInt();
    }
    
    size_t hash(const string &x, int which) const
    {
        const int multiplier = MULTIPLIERS[which];
        size_t hashVal = 0;
        
        for(auto ch : x)
            hashVal = multiplier * hashVal + ch;

        return hashVal;
    }

private:
    vector<int> MULTIPLIERS;
    UniformRandom r;
};

int nextPrime( int n );


#define MAX_LOAD 0.40  /* g++ 4.6 does not support static const double */

template <typename AnyType, typename HashFamily>
class HashTable
{
public:
    explicit HashTable(int size = 101) : array( nextPrime(size) )
    {
        numHashFunctions = hashFunctions.getNumberOfFunctions();
        rehashes = 0;
        makeEmpty();
    }
   
    bool contains(const AnyType &x) const
    {
        return findPox(x) != -1;
    }

    void makeEmpty()
    {
        currentSize = 0;
        for(auto & entry : array)
            entry.isActive = false;
    }

    bool insert( const AnyType & x )
    {
        if( contains( x ) ) 
            return false;
        
        if( currentSize >= array.size( ) * MAX_LOAD )
            expand( );
        
        return insertHelper1( x );
    }
    
    bool insert( AnyType && x )
    {
        if( contains( x ) ) 
            return false;
        
        if( currentSize >= array.size( ) * MAX_LOAD )
            expand( );
        
        return insertHelper1( std::move( x ) );
    }

    int size( ) const
    {
        return currentSize;
    }
    
    int capacity( ) const
    {
        return array.size( );
    }
    
    bool remove( const AnyType & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].isActive = false;
        return true;
    }
};

#endif
