#include "tournament.h"
#include "match.h"
#include <iostream>
#include <iomanip>
using namespace std;

void deleteAllMatches(adrTournament P) {
    adrMatch M = P->info.firstMatch;
    while (M != nullptr) {
        adrMatch temp = M;
        M = M->next;
        delete temp;
    }
    P->info.firstMatch = nullptr;
}

void deleteAllTournaments(ListTournament &L) {
    adrTournament P = L.first;
    while (P != nullptr) {
        deleteAllMatches(P);
        adrTournament temp = P;
        P = P->next;
        delete temp;
    }
    L.first = nullptr;
}
