#include "pinReader.h"
#include "psqReader.h"
#include "phrReader.h"

int main(int argc, char* argv[]){
<<<<<<< HEAD
    if(argc != 5){
        cout << "missing file path, in order = .pin, .fasta, .phr, .psq"<< endl;
    }
    else{
        pinReader* pinFile = new pinReader();
        phrReader* phrFile = new phrReader();
        psqReader* psqFile = new psqReader();

        pinFile->read_index(argv[1]);

        phrFile->set_header_offset(pinFile->get_header_offset());
        psqFile->set_sequence_offset(pinFile->get_sequence_offset());

        string sequence = psqFile->get_sequence_fasta(argv[2]); //query sequence
        //std::cout << "sequence:" << endl << sequence << endl;

        string header= phrFile->read_header(argv[3],psqFile->find_sequence(argv[4],sequence));
        cout << "Query description: "<< header << endl;
    }
    
=======
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
>>>>>>> 5d4bb6846ba04b2eaeb8bcfeb68614386f8bafe5
}
