# DOKUMENTASI SISTEM MANAJEMEN TOURNAMENT ESPORT

## STRUKTUR PROJECT

```
Tubes-Std/
├── bin/
│   └── app.exe              # File executable hasil compile
├── src/
│   ├── tournament.h         # Header Tournament (struktur & deklarasi)
│   ├── tournament.cpp       # Implementasi Tournament & Delete Operations
│   ├── match.h              # Header Match (struktur & deklarasi)
│   ├── match.cpp            # Implementasi Match
│   ├── menu.h               # Header Menu (deklarasi fungsi UI)
│   ├── menu.cpp             # Implementasi Menu & UI Handlers
│   ├── query.cpp            # Implementasi Query, Counting & Statistics
│   ├── utils.h              # Header Utility Functions
│   ├── utils.cpp            # Implementasi Utility Functions
│   ├── data_loader.h        # Header Data Loader
│   └── data_loader.cpp      # Implementasi File Loading
├── main.cpp                 # Program utama
├── data.txt                 # File data tournament dan match
└── README.md                # Dokumentasi ini
```

## STRUKTUR DATA

### 1. Tournament (Parent)

```cpp
struct Tournament {
    int tournamentID;
    string tournamentName;
    string game;
    string startDate;
    string endDate;
    int totalPrize;
    adrMatch firstMatch;     // Pointer ke child list
};
```

### 2. Match (Child)

```cpp
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
```

### 3. Relasi

- **Multi Level List**: Tournament → Match (One-to-Many)
- **Tournament List**: Single Linked List
- **Match List**: Single Linked List per Tournament

## PENGELOMPOKAN FUNGSI

### A. TOURNAMENT OPERATIONS (tournament.cpp)

#### 1. Inisialisasi & Pembuatan

- `createListTournament(ListTournament &L)`
- `createElmTournament(Tournament data) → adrTournament`

#### 2. Insertion

- `insertFirstTournament(ListTournament &L, adrTournament P)`
- `insertLastTournament(ListTournament &L, adrTournament P)`
- `insertAfterTournament(ListTournament &L, adrTournament Prec, adrTournament P)`

#### 3. Search & Retrieval

- `findTournamentByID(ListTournament L, int tournamentID) → adrTournament`
- `findTournamentByName(ListTournament L, string name) → adrTournament`

#### 4. Display

- `showAllTournaments(ListTournament L)`

#### 5. Update & Delete

- `updateTournament(ListTournament &L, int tournamentID)`
- `deleteTournament(ListTournament &L, int tournamentID)`
- `deleteFirstTournament(ListTournament &L)`
- `deleteLastTournament(ListTournament &L)`
- `deleteAllTournaments(ListTournament &L)`

### B. MATCH OPERATIONS (match.cpp)

#### 1. Pembuatan

- `createElmMatch(Match data) → adrMatch`

#### 2. Insertion

- `insertFirstMatch(adrTournament P, adrMatch M)`
- `insertLastMatch(adrTournament P, adrMatch M)`

#### 3. Search

- `findMatchByID(adrTournament P, int matchID) → adrMatch`
- `findMatchByName(adrTournament P, string matchName) → adrMatch`

#### 4. Display

- `showAllMatches(adrTournament P)`

#### 5. Update & Delete

- `updateMatch(adrTournament P, int matchID)`
- `deleteMatch(adrTournament P, int matchID)`
- `deleteAllMatches(adrTournament P)`

### C. QUERY, STATISTICS & AGGREGATION (query.cpp)

#### 1. Query

- `queryTournamentByPrize(ListTournament L, int minPrize)`
  - Mencari tournament dengan hadiah >= nilai tertentu

#### 2. Counting

- `countAllTournaments(ListTournament L) → int`
- `countAllMatches(ListTournament L) → int`
- `countMatchesByTournament(adrTournament P) → int`

#### 3. Average & Statistics

- `getAveragePrize(ListTournament L) → float`
- `getAverageMatchPerTournament(ListTournament L) → float`

#### 4. Group By

- `groupTournamentByGame(ListTournament L)`
  - Grouping tournament berdasarkan game
  - Menampilkan total tournament, total prize, dan avg prize per game

### D. MENU & USER INTERFACE (menu.cpp)

#### 1. Display Menu

- `displayMainMenu()`
- `displayTournamentMenu()`
- `displayMatchMenu()`

###UpdateTournament(ListTournament &L)`

- `DeleteTournament(ListTournament &L)`

#### 4. Match UI Handlers

- `addMatch(ListTournament &L)`
- `ShowMatches(ListTournament L)`
- `searchMatchByID(ListTournament L)`
- `UpdateMatch(ListTournament L)`
- `DeleteMatch(ListTournament L)`

#### 5. Feature Menus

- `queryTournament(ListTournament L)` - Query by prize
- `menuAverage(ListTournament L)` - Average menu handler
- `menuGroupBy(ListTournament L)` - Group by menu handler
- `showStatistics(ListTournament L)` - Display stats

### E. UTILITY FUNCTIONS (utils.cpp)

#### 1. Screen Control

- `pauseScreen()` - Pause dengan "Tekan Enter..."

#### 2. Display Helpers

- `displayTournamentInfo(adrTournament P)` - Tampilkan info tournament

#### 3. Selection Helpers

- `selectTournamentFromList(ListTournament L) → int` - Pilih tournament dari list

### F. DATA LOADER (data_loader.cpp)

[from data.txt]
└─> Main Menu Loop
├─> 1. menuTournament()
│ ├─> Add Tournament
│ ├─> Show All
│ ├─> Search by ID
│ ├─> Search by Name
│ ├─> Update
│ ├─> Delete
│ ├─> Delete First
│ └─> Delete Last
├─> 2. menuMatch()
│ ├─> Add Match to Tournament
│ ├─> Show All Matches
│ ├─> Search Match
│ ├─> Update Match
│ └─> Delete Match
├─> 3. queryTournament()
│ └─> Query by Min Prize
├─> 4. menuAverage()
│ ├─> Average Prize
│ └─> Average Match per Tournament
├─> 5. menuGroupBy()
│ └─> Group Tournament by Game
├─> 6. showStatistics()
│ ├─> Total Tournament
│ └─> Total Matchsrc\data_loader.cpp src\utils.cpp

```
main.cpp
  └─> createListTournament()
  └─> loadSampleData()
  └─> Main Menu Loop
       ├─> 1. menuTournament()
       │    ├─> Add Tournament
       │    ├─> Show All
       │    ├─> Search by ID
       │    ├─> Search by Name
       │    ├─> Update
       │    └─> Delete
       ├─> 2. menuMatch()
       │    ├─> Add Match to Tournament
       │    ├─> Show All Matches
       │    ├─> Search Match
       │    ├─> Update Match
       │    └─> Delete Match
       ├─> 3. searchTournament()
       ├─> 4. queryTournament()
       ├─> 5. showStatistics()
       └─> 0. Exit + deleteAllTournaments()
```

## COMPILE & RUN

### Compile

```powershell
g++ main.cpp src\tournament.cpp src\match.cpp src\menu.cpp src\query.cpp -o bin\app.exe
```

### Run

```poDelete First & Delete Last Tournament
   - Search by ID atau Name
   - List semua tournament

2. **Match Management**

   - CRUD Match dalam Tournament
   - Search match by ID
   - List semua match per tournament

3. **Query & Search**

   - Query tournament berdasarkan minimal prize
   - Search tournament by ID atau Name

4. **Statistics & Aggregation**

   - Count total tournament
   - Count total match
   - Count match per tournament
   - Average Prize Tournament
   - Average Match per Tournament
   - Group Tournament by Game (dengan total & avg prize)

5. **Data Loading**
   - Auto-load dari data.txt saat program start
   - 4 Tournament sample data:
     - MPL Season 12 (Mobile Legends) - 3 matches
     - VCT Masters (Valorant) - 4 matches
     - PMPL ID Season 5 (PUBG Mobile) - 5 matches
     - MLBB World Championship (Mobile Legends) - 7 matches
   - Hitung total match
   - Hitung match per tournament

4. **Sample Data**(dan `<string>`, `<fstream>` untuk data loading)
- **Input Style**: `cin>>` (no getline, kecuali di search by name)
- **Output Style**: `cout<<` (no spacing, no `\n` literals)
- **Formatting**: Variasi style (if/while spacing, brace position)
- **Pause**: Menggunakan `pauseScreen()` dari utils.cpp
- **Memory Management**: Manual delete dengan deleteAll functions
- **Control Flow**: Menggunakan if-else block (no early return pattern)
- **Data Source**: External file `data.txt` (pipe-delimited format)
- **Code Organization**:
  - tournament.cpp: CRUD & delete operations
  - match.cpp: Match operations
  - query.cpp: Query, statistics, aggregation
  - utils.cpp: Reusable helper functions
  - data_loader.cpp: File loading functionality
  - menu.cpp: UI & menu handler

## CATATAN TEKNIS

- **Library**: Hanya menggunakan `<iostream>` dan `<string>`
- **Input Style**: `cin>>` (no getline, kecuali di search)
- **Output Style**: `cout<<` (no spacing)
- **Formatting**: Variasi style (if/while spacing, brace position)
- **Pause**: `cin.ignore() + cin.get()` setelah list display
- **Memory Management**: Manual delete dengan deleteAll functions
```
