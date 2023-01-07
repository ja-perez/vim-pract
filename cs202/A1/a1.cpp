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
void setCandidate(Candidate &dest, Candidate src);

int main() {
	Candidate cands[ARR_SIZE];
	readFile(cands);
	displayList(cands);
	calculateScores(cands);
	sortByVotes(cands);
	displayList(cands);
	Candidate winner = getWinner(cands);
	Candidate last = getLast(cands);
	cout << "\nwinner:\n";
	displayCandidate(winner);
	cout << "\nlowest score:\n";
	displayCandidate(last);
	roundScore(cands[8]);
	roundScore(cands[7]);
	roundScore(cands[6]);
	cout << endl << endl;
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
		}
	}
	candidates[i].first = "END";
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
		if (cand.first == "END") {
			cout << endl;
			break;
		}
		cout << right << setw(11) << cand.first; 
		cout << right << setw(11) << cand.last;
		cout << right << setw(10) << cand.votes;
		cout << setw(10) << " ";
		if (cand.pScore - int(cand.pScore) != 0) {
			cout << right << fixed << setprecision(2) << setw(5) << cand.pScore; 
		}
		else {
			cout << right << setprecision(0) << setw(5) << cand.pScore;
		}
		cout << '%' << endl; 
	}
}

void sortByVotes(Candidate candidates[]) {
	int max_size = 0;
	for (int i = 0; i < ARR_SIZE; i++) {
		if (candidates[i].first == "END") break;
		max_size ++;
	}
	for (int i = 0; i < max_size - 1; i++) {

		for (int j = 0; j < max_size - 1 - i; j++) {
			if (candidates[j].votes > candidates[j + 1].votes) {
				Candidate temp;
				setCandidate(temp, candidates[j]);
				setCandidate(candidates[j], candidates[j+1]);
				setCandidate(candidates[j+1], temp);
			}
		}
	}
}

void displayCandidate(Candidate cand) {
	cout << setw(12) << left << "FIRST NAME: " << cand.first << endl;
	cout << setw(12) << left << "LAST NAME: " << cand.last << endl;
	cout << setw(12) << left << "VOTES: " << cand.votes << endl;
	cout << setw(12) << left << "\% GAINED : " << cand.pScore << '%' << endl;
}

Candidate getWinner(Candidate candidates[]) {
	Candidate winner = candidates[0];
	for (int i = 1; i < ARR_SIZE; i++) {
		if (candidates[i].first == "END") break;
		if (candidates[i].votes > winner.votes) {
			setCandidate(winner, candidates[i]);
		}
	}
	return winner;
}

Candidate getLast(Candidate candidates[]) {
	Candidate last = candidates[0];
	for (int i = 1; i < ARR_SIZE; i++) {
		if (candidates[i].first == "END") break;
		if (last.votes > candidates[i].votes) {
			setCandidate(last, candidates[i]);
		}
	}
	return last;
}

void calculateScores(Candidate candidates[]) {
	int total = 0;
	for (int i = 0; i < ARR_SIZE; i++) {
		if (candidates[i].first == "END") break;
		total += candidates[i].votes;
	}
	for (int i = 0; i < ARR_SIZE; i++) {
		if (candidates[i].first == "END") break;
		candidates[i].pScore = candidates[i].votes / double(total) * 100;
	}
}

void setCandidate(Candidate &dest, Candidate src) {
	dest.first = src.first;
	dest.last = src.last;
	dest.votes = src.votes;
	dest.pScore = src.pScore;
}

void roundScore(Candidate &cand) {
	 double rem = cand.pScore - int(cand.pScore);
	 int rnd = int(cand.pScore);
	 cand.pScore = rem >= 0.5 ? rnd + 1 : rnd;
}

void formatLine(string &line) {
	int equal = line.find('=');
	line = line.substr(equal+1);
}
