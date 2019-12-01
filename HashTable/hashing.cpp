#include "hashtable.h"
#include "linearprobing.h"
//#include "openhashing.h"
//#include "quadraticprobe.h"

int main()
{
	HashTable< HashTableEntry<int, string> > h_a(10);
	LinearProbe< int, string, HashTableEntry<int, string> > lp = &h_a;
	//OpenHashing oh = & h_b;
	//QuadraticProbe qp = & h_c;
	
	int c = 65;
	for(int i = 0; i<5; i++)
	{
		string str(char(++c));
		lp.insert(i, str);
	}
	
	cout<<lp.search(2)<<endl;
	
	//LinearProbe lp_cp = h_a.clone();
	
	return 0;
}