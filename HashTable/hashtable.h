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
		void openHashInsert(int k, int v)
		{
			int index = HashFunc(k);
			// will be replace by linked_list methods
			entry[index].push_back(index);
		}
		void linerProbeInsert(int k, int v)
		{
			int index = HashFunc(k);
			while(entry[index]!= NULL)
			{
				index = HashFunc(index+1);
			}
			entry[index] = v;
		}
		void quadraticProbeInsert(int k, int v)
		{
			int index = HashFunc(k);
			int h = 1;
			while(entry[index]!= NULL)
			{
				index = (index+h*h) % size;
				h++;
			}
			entry[index] = v;
		}
		int openHashSearch(int k)
		{
			int index = HashFunc(k);
			for(int i = 0;i < entry[index].size();i++)
        		{
            		if(entry[index][i] == s)
            		{
                		return entry[index][I];
            		}
        		}
        		
			return -1;
		}
		int qudraticProbeSearch(int k)
		{
			int index = hashFunc(k);
			int h=1;
			while(entry[index] != v && entry[index] != NULL)
				index = (index+h*h)%size;
			if(entry[index] == v)
				return entry[index];
			else
				return -1;
		}
/*
		int doubleHashSearchI(int k)
		{
        		int index = hashFunc1(s);
        		int indexH = hashFunc2(s);
         			
        		while(hashTable[index] != s and hashTable[index] != "")
            		index = (index + indexH) % hashTableSize;
        	
        		if(entry[index] == s)
            		return entry[index];
        		else
            		return -1;
		}
*/
		void remove(int k)
		{
			int h= HashFunc(k);
			while(entry[h] != NULL)
			{
				if(entry[h]->k == k)
					break;
				h = HashFunc(h+1);
			}
			if (t[h] == NULL) {
            		cout<<"No Element found at key "<<k<<endl;
            		return;
         		} else {
            		delete t[h];
         		}
         		cout<<"Element Deleted"<<endl;
      	}
      	~HashMapTable() 
		{
         		for (int i = 0; i < this->size; i++) {
            		if (entry[i] != NULL)
               			delete t[i];
               		delete[] t;
         		}
      	}

	private:
		HashTableEntry *entry;
}



endif
