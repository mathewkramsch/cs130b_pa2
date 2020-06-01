// incrSubsequence.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void printVector(vector<int> v) {
	for (int i=0;i<v.size();i++) cout << v[i] << ' ';
	cout << endl;
}

void printSequence(vector<vector<int>> v) {
	for (int i=0; i<v.size(); i++) {
		cout << "[" << i << "]: ";
		for (int j=0;j<v[i].size();j++) cout << v[i][j] << ' ';
		cout << endl;
	}
}

int main() {
	int n(1), x;  // n = length of sequence, x = each val in sequence
	while (n!=0) {
		// GET INPUT
		cin >> n;
		if (n==0) break;
		vector<int> v;  // stores input sequence
		for (int i=0; i<n; i++) {
			cin >> x;
			v.push_back(x);
		}

		// STORE LIS ENDING w/ v[i] FOR EACH SUBSEQUENCE v[0..i]
		vector<vector<int>> lis(n);
		lis[0].push_back(v[0]);
		for (int i=1; i<n; i++) {  // store the lis up to v[i] in lis
			for (int prev=0; prev<i; prev++) {
				if (v[prev]<v[i]) {
					if (lis[prev].size()>lis[i].size()) lis[i] = lis[prev];  // copy largest prev lis -> curr
					if (lis[prev].size()==lis[i].size()) {  // find which one is lexicographically-earliest
						for (int k=0;k<lis[i].size();k++)
							if (lis[prev][k] < lis[i][k]) lis[i] = lis[prev];
					}
				}
			}
			lis[i].push_back(v[i]);
		}

		// GET LONGEST & LEXICOGRAPHICALLY-EARLIEST LIS IN LIS
		vector<int> l;  // stores the longest lis ln lis
		for (int i=0; i<n; i++) {
			if (l.size()<lis[i].size()) l = lis[i];
			if (l.size()==lis[i].size()) {
				for (int k=0;k<lis[i].size();k++) { if (lis[i][k]<l[k]) l=lis[i]; }
			}
		}

		cout << l.size() << ' ';
		printVector(l);
		
	}
	return 0;
}
