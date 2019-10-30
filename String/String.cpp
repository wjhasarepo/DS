#include "String.h"
#include <iostream>
using namespace std;

int main()
{
	String s1("First String");
	String s2("Second String");;
	String s3("Test String");
	String s4=s3;
	cout<<(s1==s2);
	cout<<"\n";
	cout<<(s2<=s3);
	cout<<"\n";
	cout<<(s2>=s4);
	cout<<"\n";
	cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4;
	cout<<"\n";

	return 0;
}
