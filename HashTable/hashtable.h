#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include<vector>
#include<typeinfo>
#include"string.h"



template<typename K, typename, V>
struct HashEntry {
	private:
		K key;
		V value;
	public:
		HashEntry(K key, V value)
		{
			this->key = key;
			this->value = value;
		}
};


template<typename K, typename V, typename T>
class HashTable {
	protected:
		int size;
		
	public:
		HashTable(int s)
		{
			this->size = s;
		}
		
		virtual void int HashFunc(K key);
		virtual void insert(K key, V value);
		virtual V search(K key);
		
		virtual HashTable *clone() = 0;
		
		~HashTable() 
		{
			for (int i = 0; i < this->size; i++) 
			{
            	if (this->entry[i] != NULL)
               		delete this->entry[i];
               	delete[] this->entry;
         	}
      	}
		
};

#endif
