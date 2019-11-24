#ifndef LINEAR_PROBE
#define LINEAR_PROBE

class LinearProbe : public HashTable<K, V> {
	public:
		void insert(K key, V value)
		{
			int index = HashFunc(key);
			while(entry[index]!= NULL)
			{
				index = HashFunc(index+1);
			}
			entry[index] = v;
		}
		
		void search(K key)
		{
			int index = HashFunc(key);
			int h = 1;
			while(entry[index]!= NULL)
			{
				if(entry[index] == v) 
                	return entry[index];
				index = (index+1) % size;
			}
			
			return NULL;
		}
		
		int qudraticProbeSearch(K key)
		{
			int index = hashFunc(key);
			int h=1;
			while(entry[index] != v && entry[index] != NULL)
				index = (index+h*h)%size;
			if(entry[index] == v)
				return entry[index];
			else
				return -1;
		}

		void remove(K key)
		{
			int index = HashFunc(key);
			while(entry[h] != NULL)
			{
				if(entry[h]->key == key)
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
      	
      	HashTable *clone()
      	{
      		return new LinearProbe(*this);
      	}

}



#endif