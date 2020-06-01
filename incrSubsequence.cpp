// incrSubsequence.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void printSequences(vector<vector<int>*> s) {
// PRECONDITION: s is a vector of vector pointers
// POSTCONDITION: prints all the sequences that each vector pointer in s points to
	// cout << "length of s: " << s.size() << endl;
	for (int i=0; i<s.size(); i++) {
		cout << "lis[][" << i << "]: ";
		if (!s[i]) cout << "nullptr";
		else {
			cout << s[i]->size() << " ";
			for (int j=0; j<s[i]->size(); j++) cout << s[i]->at(j) << " ";
		} cout << endl;
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

	vector<vector<int>*> sub;  // holds all longest incr subsequences
	for (int i=0; i<seq.size(); i++) {
		vector<int> *s = seq[i];  // call s the vector* at i
		int n = s->size();  // n = # elements in sequence s
	
		// ADD EVERY POSSIBLE INCREASING SUBSEQUENCE TO NEW VECTOR IN POS
		// lis[j] stores longest incr subsequence of subsequence s[0..j] (ends w/ s[j])
		vector<vector<int>*> lis;
		lis.push_back(new vector<int>);
		lis[lis.size()-1]->push_back(s->at(0));  // 1st longest incr subsequence ending w/ s->at(j) w/ j=0
		for (int j=1; j<n; j++) {  // start from 2nd element in s
			lis.push_back(new vector<int>);
			lis[j] = new vector<int>;
			// find the lis that ends w/ s[j-1], where s[j-1] < current element s[j]
			for (int k=0; k<j; k++) {  // do for each element in subseq s[0..j-1] (k=j-1)
				// if the lis for s[0..j-1] is longer than lis for s[0..j] and s[j-1]<s[j] then copy that one
				if (s->at(k) < s->at(j) && lis[k]->size() > lis[j]->size())
					lis[j]->assign(lis[k]->begin(),lis[k]->end());
			}
			lis[j]->push_back(s->at(j));
		}

		cout << "lis[" << i << "]\n";
		printSequences(lis);

		vector<int> *llis = new vector<int>;  // longest longest incr subsequence from lis
		for (int j=0; j<lis.size(); j++) {  // find max length
			if (llis->size() < lis[j]->size())
				llis->assign(lis[j]->begin(),lis[j]->end());
			if (llis->size() == lis[j]->size()) {  // gets the lexicographically-earliest sequence
				for (int i=0; i<lis[j]->size(); i++)
					if (llis->at(i) > lis[j]->at(i)) llis->assign(lis[j]->begin(),lis[j]->end());
			}
		}
		
		sub.push_back(llis);
		clearVector(lis);
	}

	cout << "ans:\n";
	printSequences(sub);

	// FREE UP ALL MEMORY
	clearVector(seq);
	clearVector(sub);
		
	return 0;
}
