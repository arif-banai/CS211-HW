#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int countTeamMembers(string str, char c) {
        int result = 0;
        for(int i = 0;i < str.length();i++) {
                if(str[i] == c)
                        result++;
        }

        return result;
}

bool valid(string race, string teams) {
	if(race.length() % teams.length() != 0)
		return false;
	
	int peoplePerTeam = race.length() / teams.length();
	
	for(int i = 0;i < teams.length();i++) {
		if(countTeamMembers(race, teams[i]) != peoplePerTeam)
			return false;
	}
	
	return true;
}
	
double score(string race, char team) {
	int players = 0;
	double s = 0;
	for(int i = 0; i < race.length(); i++) {
		if(race[i] == team) {
			s += i+1;
			players++;
		}
	}
	return s / players;
}

string getTeams(string race) {
	string teams = "";
	sort(race.begin(), race.end());
	char c = race[0];
	teams += c;
	for(int i = 0;i < race.length(); i++) {
		if(race[i] != c) {
			c = race[i];
			teams += c;
		}
	}
	return teams;
}

int main() {
	string race, teams;
	
	do {
		cout << "Please enter the results of the race: " << endl;
		cin >> race;
		teams = getTeams(race);
	} while(!valid(race, teams));

	cout << endl << "There are "<< teams.length() << " teams."<< endl << endl;
	
	cout << "Each team has " << race.length() / teams.length() << " runners." << endl << endl;
	
	cout <<'\t' << "Team" << '\t' << "Score" << endl;
	
	double winningScore = score(race,teams[0]);
	char winningTeam = teams[0];
	
	for(int i = 0;i < teams.length();i++) {
		char c = teams[i];
		double s = score(race,c);
		cout << '\t' << c << '\t' << s << endl;
		
		if(s < winningScore) {
			winningScore = s;
			winningTeam = c;
		}
	}
	cout << endl << "The winning team is "<< winningTeam << " with a score of " << winningScore << endl;

	return 0;
}

