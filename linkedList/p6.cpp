#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main()
{   
    string a;
	cout<<"Enter the plaintext  : ";
	cin>>a;
	int l=a.length();
	double n=ceil(sqrt(l));
	int j=n;
	char te[j][j];
	int  mn=0;
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<n;y++)
		{
			te[x][y]=a[mn++];
		}
	}
	
	cout<<"\n\nCiphertext is  :  ";
	
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<n;y++)
		{
			cout<<te[y][x];
		}
		
    }
   
}