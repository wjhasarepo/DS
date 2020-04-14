#ifndef OPEN_HASHING
#define OPEN_HASHING

class OpenHasing : public HashTable<K, V, T> {
	private:
		int BUCKET;
		list<HashEntry> *table;
	public:
		OpenHasing(K key): HashTable(key)
		{
			table = new list<HashEntry>[BUCKET];
		}
			
		void insert(HashEntry *entry)
		{
			int index = HashFunc(entry->key);
			// will be replace by linked_list methods
			table[index].push_back(entry);
		}
		
		V search(K key)
		{
			int index = HashFunc(key);

			for(list<HashEntry>::iterator i = table[index].begin(); i != table[index].end(); i++)
        	{
            	if(*i == key)
            	{
                	return table[index][i];
        		}
        		
			return -1;
		}
		
		void remove(K key)
		{
			int index = HashFunc(key);
			
			// find the key in (inex)th list 
  			list <int> :: iterator i; 
  			for (list <int> :: iterator i = table[index].begin(); i != table[index].end(); i++) { 
    			if (*i == key) 
      				break; 
  			}
  			
			// if key is found in hash table, remove it 
  			if (i != table[index].end()) 
    			table[index].erase(i); 
      	}
}



endif
