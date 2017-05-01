#include <bits/stdc++.h>
using namespace std;

void printResult(char result[],int len)
{
	for(int i=0;i<len;i++)
		printf("%c",result[i]);

	printf("\n");
}

void Permutation(char c[],int cout[],char result[],int depth,int len)
{
	if(depth == len)
	{
		printResult(result,len);
		return;
	}

	for(int i=0;i<len;i++)
	{
		if(cout[i] != 0)
		{
			result[depth] = c[i];
			cout[i]--;
			Permutation(c,cout,result,depth+1,len);
			cout[i]++;
		}
	}
}

void StringPermutation(char exp[])
{
	int l = strlen(exp);
	map<char,int> cmap;
	for(int i=0;exp[i];i++)
	{
		cmap.insert(pair<char,int>(exp[i],0));
		map<char,int> ::iterator it;

		it = cmap.find(exp[i]);
		++it->second;

		cmap.insert(pair<char,int>(exp[i],it->second));
	}
	char c[l+1];
	int  oc[l+1];

	int cs = 0;//no of unique characters
	map<char,int>::iterator it;

	for(it = cmap.begin();it != cmap.end();it++)
	{
		c[cs] = it->first;
		oc[cs] = it->second;
		cs++;
	}

	char result[cs];
	Permutation(c,oc,result,0,cs);
}

int main()
{
	char exp[1000];
	cout << "Enter expression : ";
	cin>>exp;

	StringPermutation(exp);
	return 0;
}