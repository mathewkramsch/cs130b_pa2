// incrSubsequence.cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSequences(vector<vector<int>*> s) {
// PRECONDITION: s is a vector of vector pointers
// POSTCONDITION: prints all the sequences that each vector pointer in s points to
	for (int i=0; i<s.size(); i++) {
		for (int j=0; j<s[i]->size(); j++) cout << s[i]->at(j) << " ";
		if (i!=s.size()-1) cout << endl;
	}
}

void clearVector(vector<vector<int>*> v) {
// PRECONDITION: v is a vector of vector pointers
// POSTCONDITION: frees up all dynamically allocated memory in v
	for (int i=0; i<v.size(); i++) delete v[i];
}
	

int main() {
	// INITIALIZE VECTOR OF SEQUENCES
	int n(1), x, count(0);  // n=length of sequence, x=each val in sequence
	vector<vector<int>*> seq;  // holds all sequences, vector of vector
	while (n != 0) {
		cin >> n;
		if (n!=0) seq.push_back(new vector<int>);
		for (int i=0; i<n; i++) {
			cin >> x;
			seq[count]->push_back(x);
		}
		count++;
	}

	// PRINT BACK SEQUENCES
	// printSequences(seq);

	// vector<vector<int>*> sub;  // holds all longest incr subsequences
	for (int i=0; i<seq.size(); i++) {
		// vector<int> *s = new vector<int>;

		// vector length that is n long, initializd to {0}
		vector<int> length(seq[i]->size(),0);
		length[0]=1;  // length of subsequence ending with seq[i]->at(0) is 1

		for (int j=1; j<seq[i]->size(); j++) {  // ignore 1st character
			for (int k=0; k<j; k++) {  // subsequence ends w/ seq[i]->at(k)
				if (seq[i]->at(k)<seq[i]->at(j) && length[k]>length[j])
					length[j]=length[k];
			}
			length[j]++;  // adds seq[i]->at(j) to s	
		}
		int lisLength = 0;
		for (int j=0; j<seq[i]->size(); j++) {  // find max length
			lisLength = max(lisLength, length[j]);
		}
		cout << "length of lis: " << lisLength << endl;

		// sub.push_back(s);
	}

	// FREE UP ALL MEMORY
	clearVector(seq);
		
	return 0;
}
