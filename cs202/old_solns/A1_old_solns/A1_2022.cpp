#include <iostream> 
#include <fstream> 
#include <string> 
#include <stdlib.h> 
#include <iomanip> 
 
using namespace std; 
 
const int ARR_SIZE = 100;
const int COMMA_MAX = 2;

struct Candidate {
    string first;
    string last;
    int votes;
    double pScore;
};

void readFile(Candidate[]);
bool is_valid_line(string);
bool has_decimals(double score);
void displayList(Candidate[]); 
void sortByVotes(Candidate[]); 
void displayCandidate(Candidate); 
Candidate getWinner(Candidate[]); 
Candidate getLast(Candidate[]); 
void calculateScores(Candidate[]); 
void roundScore(Candidate &cand);

int main() { 
    Candidate candidates[ARR_SIZE];
    readFile(candidates);
    displayList(candidates);
    calculateScores(candidates);
    sortByVotes(candidates);
    displayList(candidates);
    cout << "winner:\n";
    displayCandidate(getWinner(candidates));
    cout << "lowest score:\n";
    displayCandidate(getLast(candidates));
    roundScore(candidates[8]);
    roundScore(candidates[7]);
    roundScore(candidates[6]);
    displayList(candidates);
    return 0;
} 

bool is_valid_line(string line){
    // Find comma count, should only have 2
    if (line == "\n")
        return false;
    int comma_pos = line.find(',');
    int comma_count = 0;
    while (comma_pos != string::npos) {
        comma_count++;
        comma_pos = line.find(',', comma_pos + 1);
    }
    if (comma_count != COMMA_MAX)
        return false;
    return true;
}

void readFile(Candidate candidates[]) { 
    string line; 
    ifstream infile;
    string cwd = "./""CS 202""/assignments/A1/";
    infile.open(cwd + "elections.txt");
    int curr_cand = 0;
    while (!infile.eof()) { 
        getline(infile,line); 
        // your code here
        if (is_valid_line(line)){
            int line_len = line.length();
            int eq_pos = line.find('=');
            int comma_pos = line.find(',');
            int s_len = comma_pos - eq_pos - 1;
            candidates[curr_cand].first = line.substr(eq_pos+1, s_len);
            eq_pos = line.find('=', eq_pos + 1);
            comma_pos = line.find(',', comma_pos + 1);
            s_len = comma_pos - eq_pos - 1;
            candidates[curr_cand].last = line.substr(eq_pos + 1, s_len);
            eq_pos = line.find('=', eq_pos + 1);
            candidates[curr_cand].votes = stoi(line.substr(eq_pos + 1)); 
            candidates[curr_cand].pScore = 0;
            curr_cand++;
        }
    }
    infile.close();
} 
 
void displayList(Candidate candidates[]) {
    cout << "ALL CANDIDATES:\n";
    cout << setw(10) << "First: " << setw(10) << "Last: " << setw(10) << "Votes: " << setw(11) << "% Score:\n";
    int curr_cand = 0;
    while (candidates[curr_cand].first != "") {
        cout << setw(10) << candidates[curr_cand].first
            << setw(10) << candidates[curr_cand].last
            << setw(10) << candidates[curr_cand].votes;
        if (!has_decimals(candidates[curr_cand].pScore)) {
            int int_score = candidates[curr_cand].pScore;
            cout << setw(12) << int_score << '%' << endl;
        } else {
            cout << setw(12) << setprecision(2) << fixed
            << candidates[curr_cand].pScore << '%' << endl;
        }
        curr_cand++;
    }
    cout << endl;
} 
 
void sortByVotes(Candidate candidates[]) {
    int sort_votes[ARR_SIZE];
    int curr_cand = 0;
    string temp_name;
    int temp_vote;
    double temp_score;
    while (candidates[curr_cand].first != "") {
        int next_cand = 0;
        while (candidates[next_cand].first != "") {
            if (candidates[curr_cand].votes <= candidates[next_cand].votes) {
                temp_name = candidates[curr_cand].first;
                candidates[curr_cand].first = candidates[next_cand].first;
                candidates[next_cand].first = temp_name;

                temp_name = candidates[curr_cand].last;
                candidates[curr_cand].last = candidates[next_cand].last;
                candidates[next_cand].last = temp_name;

                temp_vote = candidates[curr_cand].votes;
                candidates[curr_cand].votes = candidates[next_cand].votes;
                candidates[next_cand].votes = temp_vote;

                temp_score = candidates[curr_cand].pScore;
                candidates[curr_cand].pScore = candidates[next_cand].pScore;
                candidates[next_cand].pScore = temp_score;
            }
            next_cand++;
        }
        curr_cand++;
    }
} 
 
void displayCandidate(Candidate cand) {
    cout << left << setw(12) << "FIRST NAME: " << cand.first << endl;
    cout << setw(12) << "LAST NAME: " << cand.last << endl;
    cout << setw(12) << "VOTES: " << cand.votes << endl;
    cout << setw(12) << "% GAINED: " << setprecision(2) << fixed 
    << cand.pScore << "%\n\n" << right;
} 
 
Candidate getWinner(Candidate candidates[]) {
    sortByVotes(candidates);
    int winner_index = 0;
    while (candidates[winner_index].first != "")
        winner_index++;
    return candidates[winner_index - 1];
} 
 
Candidate getLast(Candidate candidates[]) {
    sortByVotes(candidates);
    return candidates[0];
} 
 
void calculateScores(Candidate candidates[]) { 
    int total_votes = 0;
    int curr_cand = 0;
    while (candidates[curr_cand].first != "") {
        total_votes += candidates[curr_cand].votes;
        curr_cand++;
    }
    total_votes *= 1.0;
    for (int i = 0; i <= curr_cand; i++)
        candidates[i].pScore = (candidates[i].votes * 1.0 / total_votes) * 100;
}

void roundScore(Candidate &cand) {
    int int_score = cand.pScore;
    double decimal = cand.pScore - int_score;
    if (decimal >= 0.5)
        cand.pScore = int_score + 1;
    else
        cand.pScore = int_score;
}

bool has_decimals(double score) {
    int int_score = score;
    double dec = score - int_score;
    return dec != 0;
}