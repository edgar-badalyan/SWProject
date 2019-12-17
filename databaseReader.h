#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include "pinReader.h"
#include "phrReader.h"
#include "psqReader.h"

using namespace std;

class databaseReader {
public:
    databaseReader(string database_path, string fasta_seq_path);
    ~databaseReader();

    vector<int> get_fasta_seq(string file_name);

private:
    pinReader* pinFile;
    phrReader* phrFile;
    psqReader* psqFile;
    std::map<char, int> decode_residue = {{'A', 1},{'B', 2},{'C', 3},{'D', 4},{'E', 5},{'F', 6},{'G', 7},{'H', 8},{'I', 9},{'K', 10},{'L', 11},{'M', 12},{'N', 13},{'P', 14},{'Q', 15},{'R', 16},{'S', 17},{'T', 18},{'V', 19},{'W', 20},{'X', 21},{'Y', 22},{'Z', 23},{'U', 24},{'*', 25},{'O', 26},{'J', 27}, };

};
