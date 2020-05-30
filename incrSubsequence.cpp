// incrSubsequence.cpp

#include <iostream>
#include <vector>
using namespace std;

int main() {
	// INITIALIZE VECTOR OF SEQUENCES
	int n(1), x, count(0);  // n=length of sequence, x=each val in sequence
	vector<vector<int>*> sqs;  // holds all sequences, vector of vector
	while (n != 0) {
		sqs.push_back(new vector<int>);
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> x;
			sqs[count]->push_back(x);
		}
		count++;
	}

	// PRINT BACK SEQUENCES
	for (int i=0; i<sqs.size(); i++) {
		for (int j=0; j<sqs[i]->size(); j++) cout << sqs[i]->at(j) << " ";
		if (i!=sqs.size()-1) cout << endl;
	}

	return 0;
}

