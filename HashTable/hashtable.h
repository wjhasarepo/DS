#ifndef HASH_TABLE_H
#define HASH_TABLE_H

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
			entry = new HastTableEntry* [this->size];
			for(int i = 0; i<s; i++)
			{
				entry[i]= NULL;
			}
		}
		int HashFunc(int k)
		{
			return (k%this->size);
		}
		void insert(int k, int v)
		{
			int h = HashFunc(k);
			while(entry[h]!=NULL && entry[h]->k != k)
			{
				h = HashFunc(h+1);
			}
			entry[h] = new HashTableEntry(k, v);
		}
		int searchKey(int k)
		{
			int h = HashFunc(k);
			while(entry[h] != NULL && entry[h]->k != k)
			{
				h = HashFunc(h+1);
			}
			if(entry[h] == NULL)
				return -1;
			else
				return entry[h]->v;
		}
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
      	~HashMapTable() {
         	for (int i = 0; i < this->size; i++) {
            	if (entry[i] != NULL)
               		delete t[i];
               	delete[] t;
         	}
      	}

	private:
		HashTableEntry **entry;
}



endif
