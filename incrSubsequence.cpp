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
		cout << s[i]->size() << " ";
		if (s[i]) { for (int j=0; j<s[i]->size(); j++) cout << s[i]->at(j) << " "; }
		else cout << "nullptr";
		cout << endl;
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
		vector<vector<int>*> pos(s->size());  // holds all possible incr subsequences of s
		pos[0] = new vector<int>;
		pos[0]->push_back(s->at(0));  // 1st incr subseq of s = s's 1st element

		for (int j=1; j<s->size(); j++) {  // ignore 1st character
			for (int k=0; k<j; k++) {  // subsequence ends w/ s->at(k)
				if (!pos[j]) pos[j] = new vector<int>;
				if (s->at(k)<s->at(j))
					pos[j]->assign(pos[k]->begin(),pos[k]->end());  // copy vector from s->at(k) to s->at(j)
			}
			if (!pos[j]) pos[j] = new vector<int>;
			pos[j]->push_back(s->at(j));  // adds seq[i]->at(j) to s	
		}

		vector<int> *lis = new vector<int>;
		for (int j=0; j<pos.size(); j++) {  // find max length
			if (lis->size() < pos[j]->size())
				lis->assign(pos[j]->begin(),pos[j]->end());
			if (lis->size() == pos[j]->size()) {
				for (int i=0; i<lis->size(); i++)
					if (lis->at(i) > pos[j]->at(i)) lis->assign(pos[j]->begin(),pos[j]->end());
			}
		}
		
		sub.push_back(lis);
		clearVector(pos);
	}

	printSequences(sub);

	// FREE UP ALL MEMORY
	clearVector(seq);
	clearVector(sub);
		
	return 0;
}
