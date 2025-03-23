#include <iostream>
using namespace std;

int count(char a[])
{
	int n=0; 
	while (a[n]!='\0') {n++;}
	return n;
}

void reverse(char* a)
{
	int n; n=count(a);
	for (int i=0; i<n/2;++i)
	{
		char temp=a[i]; a[i]=a[n-i-1]; a[n-i-1]=temp;

	}
}

void delete_char(char *a, char c)
{
	int n; n=count(a);
	int k=0; for (int i=0;i<n;++i) {if (a[i]==c) ++k;}
	char temp[n-k];
	int t=0;
	for (int i=0; i<n; ++i)
	{
		if (a[i]!=c) 
			{
				temp[t]=a[i]; ++t;
			}
	}
	for (int i=0;i<n-k;++i)
		{a[i]=temp[i];}
	a[n-k]='\0';
}

void pad_left(char *a, int n)
{
	int k=count(a);
	if (k<n)
	{
		int space=n-k;
		for (int i=k-1;i>=0;--i)
		{a[i+space]=a[i];}
		for (int i=0;i<space;++i) {a[i]=' ';}
		a[n]='\0';
	}
}

void truncate(char *a, int n)
{
	int k=count(a);
	if (k>n)
	{
		a[n-1]='\0';
	}
}

bool is_palindrome(char a[])
{
	int k=count(a); bool test=true;
	for (int i=0; i<k/2;++i)
	{
		if (a[i]!=a[k-i-1]) {test=false; break;}
	}
	return test;
}

void trim_left(char *a)
{
	int i=0; while (a[i]==' ') ++i;
	int k=count(a);
	char temp[k-i];
	for (int j=0;j<k-i;++j)
	{
		temp[j]=a[j+i];
	}
	for (int j=0;j<k-i;++j)
	{
		a[j]=temp[j];
	}
	a[k-i]='\0';
}

void trim_right(char *a)
{
	int k=count(a);
	int i=0; while (a[k-i-1]==' ') ++i;
	char temp[k-i];
	a[k-i]='\0';
}

int main() 
{
    cout <<"Mang goc: hello world \n";
    char a[20]; a[0]='h'; a[1]='e'; a[2]='l'; a[3]='l'; a[4]='0'; a[5]=' '; a[6]='w'; a[7]='o'; a[8]='r'; a[9]='l'; a[10]='d'; a[11]='\0';
    reverse(a);
    cout <<a <<"\n";
    delete_char(a,'l');
    cout <<a <<"\n";
    pad_left(a,14);
    cout <<a <<"\n";
    truncate(a,12);
    cout <<a <<"<== Ket thuc o day"<<"\n";
    cout <<"Test voi mang dang xet:";
    if (is_palindrome(a)) {cout <<"true" <<"\n";} else {cout <<"false" <<"\n";}
    cout <<"Test voi mang: acbbca:";
    char b[7]; b[0]='a'; b[1]='c'; b[2]='b'; b[3]='b'; b[4]='c'; b[5]='a'; b[6]='\0';
    if (is_palindrome(b)) {cout <<"true" <<"\n";} else {cout <<"false" <<"\n";}
    trim_left(a);
    cout <<a <<"<== Ket thuc o day"<<"\n";
    trim_right(a);
    cout <<a <<"<== Ket thuc o day"<<"\n";
}
