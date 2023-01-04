#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const int ARR_SIZE = 100;

struct Candidate {
	string first;
	string last;
	int votes;
	double pScore;
};

void readFile(Candidate[]);
void displayList(Candidate[]);
void sortByVotes(Candidate[]);
void displayCandidate(Candidate);
Candidate getWinner(Candidate[]);
Candidate getLast(Candidate[]);
void calculateScores(Candidate[]);
void roundScore(Candidate &cand);
void formatLine(string &line);

int main() {
	Candidate cands[ARR_SIZE];
	readFile(cands);
	displayList(cands);
}

void readFile(Candidate candidates[]) {
	string line;
	ifstream infile;
	infile.open("elections.txt");
	int i = 0;
	while (!infile.eof()) {
		getline(infile,line);
		int comma1 = line.find(',');	
		int comma2 = line.find(',', comma1+1);
		if (comma2 != string::npos || line == "\n") {
			string first = line.substr(0,comma1);
			string last = line.substr(comma1+1, comma2-comma1-1);
			string votes = line.substr(comma2+1);
			formatLine(first);
			formatLine(last);
			formatLine(votes);
			candidates[i].first = first;
			candidates[i].last = last;
			candidates[i].votes = stoi(votes);
			candidates[i].pScore = 0;
			i++;
			//cout << "iter:" << first << last << votes << endl;
		}

	}
	infile.close();
}

void displayList(Candidate candidates[]) {
	cout << "ALL CANDIDATES:\n";
	cout << right << setw(11) << "First: ";
        cout << right << setw(11) << "Last:  ";
        cout << right << setw(10) << "Votes:  ";
       	cout << right << setw(11) << "\% Score: " << endl;
	for (int i = 0; i < ARR_SIZE; i++) {
		Candidate cand = candidates[i];
		if (cand.votes == 0 && cand.pScore == 0) {
			return;
		}
		cout << right << setw(11) << cand.first; 
		cout << right << setw(11) << cand.last;
		cout << right << setw(10) << cand.votes;
		cout << setw(12) << setfill(' ');
		cout << cand.pScore << '%' << endl; 
	}
	cout << endl;
}

void sortByVotes(Candidate candidates[]) {
}

void displayCandidate(Candidate cand) {
}

Candidate getWinner(Candidate candidates[]) {
	Candidate winner = candidates[0];
	for (int i = 1; i < ARR_SIZE; i++) {
		if (candidates[i].votes > winner.votes) {
			winner.first = candidates[i].first;
			winner.last = candidates[i].last;
			winner.votes = candidates[i].votes;
			winner.pScore = candidates[i].pScore;
			
		}
	}
	return winner;
}

Candidate getLast(Candidate candidates[]) {
	Candidate last = candidates[0];
	for (int i = 1; i < ARR_SIZE; i++) {
		if (last.votes > candidates[i].votes) {
			last.first = candidates[i].first;
			last.last = candidates[i].last;
			last.votes = candidates[i].votes;
			last.pScore = candidates[i].pScore;
		}
	}
	return last;
}

void calculateScores(Candidate candidates[]) {
}

void roundScore(Candidate &cand) {
}

void formatLine(string &line) {
	int equal = line.find('=');
	line = line.substr(equal+1);
}
