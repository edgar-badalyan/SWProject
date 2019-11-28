#include "pinReader.h"
#include "psqReader.h"

int main(int argc, char* argv[]){
    psqReader* psqFile = new psqReader();
    pinReader* pinFile = new pinReader();
    vector<uint32_t> header_offset;
    string sequence = psqFile->get_sequence_fasta("P00533.fasta"); //query sequence
    std::cout << "sequence:" << endl << sequence << endl;
    psqFile->find_sequence("uniprot_sprot.fasta.psq", sequence);
    pinFile->read_index("uniprot_sprot.fasta.pin", header_offset);
}