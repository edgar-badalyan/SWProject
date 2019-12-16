
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
};
