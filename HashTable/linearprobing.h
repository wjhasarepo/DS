#ifndef LINEAR_PROBE
#define LINEAR_PROBE

#include<iostream>
using namespace std;

template<typename K, typename V, typename T>
class LinearProbe : public HashTable<T> {
	public:
		void insert(K key, V value)
		{
			int index = this->HashFunc(key);
			while(this->entry[index]!= NULL)
			{
				index = this->HashFunc(index+1);
			}
			this->entry[index] = value;
		}
		
		V search(K key)
		{
			int index = this->HashFunc(key);
			int h = 1;
			while(this->entry[index]!= NULL)
			{
				if(this->entry[index] == key) 
                	return this->entry[index];
				index = (index+1) % this->size;
			}
			
			return NULL;
		}

		void remove(K key)
		{
			int index = this->HashFunc(key);
			while( this->entry[index] != NULL)
			{
				if(this->entry[index]->key == key)
					break;
				index = this->HashFunc(index+1);
			}
				
			if (this->entry[index] == NULL) 
			{
            	cout<<"No Element found at key "<<index<<endl;
            	return;
         	} 
         	else 
         	{
            	delete this->entry[index];
         	}
         		
         	cout<<"Element Deleted";
      	}
      	
      	HashTable<T> *clone()
      	{
      		return new LinearProbe(*this);
      	}

};



#endif