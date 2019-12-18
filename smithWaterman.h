#include <string>
#include <vector>

class smithWaterman {

public:
    smithWaterman();
    void read_blosum();

    int algo(std::vector<int> & seq1, std::vector<int> & seq2);
    void set_blosum(std::string file_name) { blosum_file = file_name; }
    void set_openPenalty(int penalty) { openPenalty = penalty; }
    void set_extPenalty(int penalty) { extPenalty = penalty; }

private:
    int residueScores[300];
    int openPenalty;
    int extPenalty;
    std::string blosum_file;

    int residue_index(int residue);
    int residues_to_pass(int line_number);
    int get_index(int res1, int res2);
};
