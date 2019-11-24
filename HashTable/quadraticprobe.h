#ifndef QUARDRATIC_PROBE
#define QUARDRATIC_PROBE

class QuadraticProbe : public HashTable<T> {
	public:
		void insert(K key, V value)
		{
			int index = HashFunc(key);
			int h = 1;
			
			while(entry[index]!= NULL)
			{
				index = (index+h*h) % size;
				h++;
			}
			
			entry[index] = value;
		}
		
		int search(K key)
		{
			int index = hashFunc(key);
			int h=1;
			while(entry[index] != key && entry[index] != NULL)
			{
				index = (index+h*h)%size;
			}
				
			if(entry[index] == key)
				return entry[index];
			else
				return -1;
		}

		void remove(K key)
		{
			int h= HashFunc(key);
			
			while(entry[h] != NULL)
			{
				if(entry[h]->key == key)
					break;
				h = HashFunc(h+1);
			}
			
			if (t[h] == NULL) {
            	cout<<"No Element found at key "<<k<<endl;
            	return;
         	} 
         	else 
         	{
            	delete t[h];
         	}
         		
         	cout<<"Element Deleted"<<endl;
      	}
      	
}



endif