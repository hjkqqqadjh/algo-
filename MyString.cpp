#include <iostream>
#include <string>

using namespace std;

int brute_match(string t, string p, int start)
{
	for(int i = start; i < t.length()-p.length(); i++)
	{
		int j;
		for(j = 0; j<p.length()&&t[i+j]==p[j]; j++);
		if(j == p.length())
			return i;
	}
	return -1;
}

int kmp_match(string t, string p, int start, int *n)
{
	int tlen = t.length();
	int plen = p.length();
	int i = 0;
	int j = 0;
	if(tlen < plen)
		return -1;
	while(i < tlen && j < plen)
	{
		if(j != -1 && t[i] != p[j])
			j = n[j];
		i++; j++;
	}
	if(j == plen)
		return i-j;
	return -1;
}

int* get_next(string p)
{
	int m = p.length();
	int j = 0;
	int k = -1;
	int *next = new int[m];
	next[0] = -1;
	while(j < m - 1)
	{
		while(k != -1 && p[k] != p[j])
			k = next[k];
		j++; k++; next[j] = k;
	}
	return next;
}


int main()
{
	string a, b;
	cin >> a >> b;
	cout << brute_match(a, b, 0) << kmp_match(a, b, 0, get_next(b)) << endl;
	return 0;
}
