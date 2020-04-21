//#include <bits/stdc++.h>
#include<string>//getline
#include<iostream>
using namespace std;
int a[26];
int main(){
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++){
		if ('A' <= s[i] && s[i] <= 'Z')
			a[s[i] - 'A']++;
		else if ('a' <= s[i] && s[i] <= 'z')
			a[s[i] - 'a']++;
	}
	int max = 0, maxi;
	for (int i = 0; i < 26; i++) {
		if (a[i] > max) {
			max = a[i];
			maxi = i;
		}	
	}
	cout << char(maxi + 'a') << " " << max;
	return 0;
}
