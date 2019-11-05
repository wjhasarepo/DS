#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include<list>

class HashTableEntry {
	public:
		int k;
		int v;
		HashTableEntry(int k, int v)
		{
			this->k = k;
			this->v = v;
		}
};

class HashTable {
	public:
		HashTable(int s)
		{
			this->size = s;
			entry = new list<HastTableEntry>(this->size);
		}
		int HashFunc(int k)
		{
			return (k%this->size);
		}
		
		virtual insert(T k, T v);
		virtual search(T k);
		
		virtual HashTable *clone() = 0;
		
		~HashMapTable() 
		{
         	for (int i = 0; i < this->size; i++) {
            	if (entry[i] != NULL)
               		delete t[i];
               	delete[] t;
         	}
      	}
		
}

#endif
