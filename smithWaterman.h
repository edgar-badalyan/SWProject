<<<<<<< HEAD

#include <string>
using namespace std;

class smithWaterman {
public:
    smithWaterman(string file_name = "BLOSUM62");

    int residues_to_pass(int line_number);
    int get_index(char res1, char res2);
    void read_blosum(string file_name);
    void run(string seq1, string seq2, double openPenalty = 11.0, double extPenalty = 1.0);
private:
=======
#include <string>
#include <vector>

class smithWaterman {

public:
    smithWaterman();
    void read_blosum();

    int algo(const std::vector<int> & seq1, const std::vector<int> & seq2);
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
>>>>>>> master2
};
