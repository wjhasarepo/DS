#ifndef LINEAR_PROBE
#define LINEAR_PROBE

class LinearProbe : public HashTable {
	public:
		void insert(T k, T v)
		{
			int index = HashFunc(k);
			while(entry[index]!= NULL)
			{
				index = HashFunc(index+1);
			}
			entry[index] = v;
		}
		void search(int k)
		{
			int index = HashFunc(k);
			int h = 1;
			while(entry[index]!= NULL)
			{
				if(entry[index] == v) 
                	return entry[index];
				index = (index+1) % size;
			}
			
			return NULL;
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

}



endif