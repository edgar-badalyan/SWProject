#include "pinReader.h"
#include "psqReader.h"
#include "phrReader.h"

int main(int argc, char* argv[]){
    pinReader* pinFile = new pinReader();
    phrReader* phrFile = new phrReader();
    psqReader* psqFile = new psqReader();

    pinFile->read_index("/home/rajky/Téléchargements/swipe/uniprot_sprot.fasta.pin");

    phrFile->set_header_offset(pinFile->get_header_offset());
    psqFile->set_sequence_offset(pinFile->get_sequence_offset());

    string sequence = psqFile->get_sequence_fasta("/home/rajky/Téléchargements/swipe/P00533.fasta"); //query sequence
    //std::cout << "sequence:" << endl << sequence << endl;

    string header = phrFile->read_header("/home/rajky/Téléchargements/swipe/uniprot_sprot.fasta.phr", psqFile->find_sequence("/home/rajky/Téléchargements/swipe/uniprot_sprot.fasta.psq", sequence)-1);
    cout << header << endl;
}
