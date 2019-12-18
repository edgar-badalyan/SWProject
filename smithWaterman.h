// header for smithWaterman.cpp

#ifndef SMITH_WATERMAN_H
#define SMITH_WATERMAN_H

#include <string>
#include <vector>

class smithWaterman {

public:
    smithWaterman(int openPenalty, int extPenalty, std::string blosum_file);
    void read_blosum();
    int algo(const std::vector<int> & seq1, const std::vector<int> & seq2);

private:
    int residueScores[300];
    int openPenalty;
    int extPenalty;
    std::string blosum_file;

    int residue_index(int residue);
    int residues_to_pass(int line_number);
    int get_index(int res1, int res2);
};

#endif
