#ifndef LINEAR_PROBE
#define LINEAR_PROBE

#include<iostream>
using namespace std;

template<typename K, typename V, typename T>
class LinearProbe : public HashTable<K, V, T> {
	public:
		int hashFunc(K key)
		{
			return key % size;
		}

		void insert(K key, V value)
		{
			HashEntry<K, V> *temp = new HashEntry<K, V>(key, value);

			int index = HashFunc(key);
			
			while(entry[index]!= NULL && entry[index]->key!=key)
			{
				index = this->HashFunc(index+1);
				index %= size;
			}

			entry[index] = temp;
		}
		
		V search(K key)
		{
			int index = this->HashFunc(key);
			int h = 1;
			
			while(entry[index]!= NULL)
			{
				if(h++ > size)
					return NULL;
				if(entry[index]->key == key)
                	return entry[index];
  				
				index ++;
				index %= size;
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
