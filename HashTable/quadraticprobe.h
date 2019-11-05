#ifndef QUARDRATIC_PROBE
#define QUARDRATIC_PROBE

class QuadraticProbe : public HashTable {
	public:
		void insert(int k, int v)
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
		
		int search(int k)
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