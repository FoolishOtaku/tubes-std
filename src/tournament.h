#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>
using namespace std;

typedef struct ElmTournament* adrTournament;
typedef struct ElmMatch* adrMatch;

struct Match {
    int matchID;
    string matchName;
    string team1;
    string team2;
    int scoreTeam1;
    int scoreTeam2;
    string matchDate;
    string status;
};

struct ElmMatch {
    Match info;
    adrMatch next;
};

struct Tournament {
    int tournamentID;
    string tournamentName;
    string game;
    string startDate;
    string endDate;
    int totalPrize;
    adrMatch firstMatch;
};

struct ElmTournament {
    Tournament info;
    adrTournament next;
};

struct ListTournament {
    adrTournament first;
};

void createListTournament(ListTournament &L);
adrTournament createElmTournament(Tournament data);
void insertFirstTournament(ListTournament &L, adrTournament P);
void insertLastTournament(ListTournament &L, adrTournament P);
void insertAfterTournament(ListTournament &L, adrTournament Prec, adrTournament P);
void deleteTournament(ListTournament &L, int tournamentID);
adrTournament findTournamentByID(ListTournament L, int tournamentID);
adrTournament findTournamentByName(ListTournament L, string name);
void showAllTournaments(ListTournament L);
void updateTournament(ListTournament &L, int tournamentID);

adrMatch createElmMatch(Match data);
void insertFirstMatch(adrTournament P, adrMatch M);
void insertLastMatch(adrTournament P, adrMatch M);
void deleteMatch(adrTournament P, int matchID);
adrMatch findMatchByID(adrTournament P, int matchID);
adrMatch findMatchByName(adrTournament P, string matchName);
void showAllMatches(adrTournament P);
void updateMatch(adrTournament P, int matchID);

void queryTournamentByPrize(ListTournament L, int minPrize);

int countAllTournaments(ListTournament L);
int countAllMatches(ListTournament L);
int countMatchesByTournament(adrTournament P);

void deleteAllMatches(adrTournament P);
void deleteAllTournaments(ListTournament &L);

#endif
