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

int main() {

}

void readFile(Candidate candidates[]) {
	string line;
	ifstream infile;
	infile.open("elections.txt");
	while (!infile.eof()) {
		getline(infile,line);
	}
	infile.close();
}

void displayList(Candidate candidates[]) {
}

void sortByVotes(Candidate candidates[]) {
}

void displayCandidate(Candidate cand) {
}

Candidate getWinner(Candidate candidates[]) {
}

Candidate getLast(Candidate candidates[]) {
}

void calculateScores(Candidate candidates[]) {
}

void roundScore(Candidate &cand) {
}
