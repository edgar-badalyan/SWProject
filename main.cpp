#include "pinReader.h"
#include "psqReader.h"
#include "phrReader.h"

int main(int argc, char* argv[]){
    psqReader* psqFile = new psqReader();
    pinReader* pinFile = new pinReader();
    phrReader* phrfile = new phrReader();
    //vector<uint32_t> header_offset;
    string sequence = psqFile->get_sequence_fasta("P00533.fasta"); //query sequence
    std::cout << "sequence:" << endl << sequence << endl;
    pinFile->read_index("uniprot_sprot.fasta.pin", psqFile, phrfile);
    int index = psqFile->find_sequence("uniprot_sprot.fasta.psq", sequence);
    //std::cout << "index: " <<index <<endl;
    string header = phrfile->read_header("uniprot_sprot.fasta.phr", index);
    std::cout << header <<endl;
}
