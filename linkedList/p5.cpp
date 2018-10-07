#include<iostream>
#include<string>
using namespace std;

int main()
{
string a,b,c;
int f;
cout<<"Enter the plaintext :  ";
cin>>a;
int r=0;
for(int x=0;x<a.length();x++)
{ if(r%2==0)
{
	b.push_back(a[x]);
}
else
{
	c.push_back(a[x]);
}
	r++;
	}	
	cout<<"\nCipher text is  : "<<b<<c<<"\n";
	
	cout<<"\nEnter the text for decryption  : ";
	cin>>a;
	cout<<"\nPlaintext must be  : ";
	int l=a.length();
	int o=0;
	if(l%2==0)
	 f=l/2;

	else
	f=l/2+1;
	for(int x=0;x<(a.length())/2;x++)
	{
	 cout<<a[x];
	cout<<a[f+x];
	o++;      }       
 }
