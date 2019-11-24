#ifndef OPEN_HASHING
#define OPEN_HASHING

class OpenHasing : public HashTable<T> {
	public:
		void insert(K key, V value)
		{
			int index = HashFunc(key);
			// will be replace by linked_list methods
			entry[index].push_back(index);
		}
		
		int search(K key)
		{
			int index = HashFunc(key);
			for(int i = 0;i < entry[index].size();i++)
        		{
            		if(entry[index][i] == s)
            		{
                		return entry[index][I];
            		}
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