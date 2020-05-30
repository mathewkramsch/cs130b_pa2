// incrSubsequence.cpp

#include <iostream>
#include <vector>
using namespace std;

int main() {
	// right now just print vectors back

	int n=1; // holds length of each sequence
	int x;  // holds each integer in sequene
	vector<int> s;
	while (n != 0) {
		s.clear();
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> x;
			s.push_back(x);
		}
	}
	return 0;
}

