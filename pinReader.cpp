#include "pinReader.h"


pinReader::pinReader() {
    sequence_offset = {};
    header_offset = {};
}

void  pinReader::read_index(string file_name) {
    //reads the info on the database from the .pin binary file
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if(file.is_open()){

        uint32_t version;
        file.read((char *)&version, sizeof(uint32_t));
        version = __builtin_bswap32(version);
<<<<<<< HEAD
        //std::cout << "Version : " << version<<endl;
=======
        std::cout << "Version : " << version<<endl;
>>>>>>> 5d4bb6846ba04b2eaeb8bcfeb68614386f8bafe5

        uint32_t type;
        file.read((char *)&type, sizeof(uint32_t));
        type = __builtin_bswap32(type);
<<<<<<< HEAD
        //std::cout << "Database type (0-DNA/1-Protein) : " << type <<endl;
=======
        std::cout << "Database type (0-DNA/1-Protein) : " << type <<endl;
>>>>>>> 5d4bb6846ba04b2eaeb8bcfeb68614386f8bafe5

        uint32_t length;
        file.read((char*)&length, sizeof(uint32_t));
        length = __builtin_bswap32(length);
        //std::cout << length <<endl;

        char title[length+1];
        file.read(title, length);
        title[length] = '\0';
<<<<<<< HEAD
        std::cout << "Database file:    " <<  title << endl;
=======
>>>>>>> 5d4bb6846ba04b2eaeb8bcfeb68614386f8bafe5
        std::cout << "Database title:    " <<  title << endl;

        uint32_t timestamp_length;
        file.read((char*)&timestamp_length, sizeof(uint32_t));
        timestamp_length = __builtin_bswap32(timestamp_length);
        //std::cout << timestamp_length <<endl;

        char timestamp[timestamp_length + 1];
        file.read(timestamp, timestamp_length);
        timestamp[timestamp_length] = '\0';
        std::cout << "Database time:     " << timestamp <<endl;

        uint32_t number_seq;
        file.read((char*)&number_seq, sizeof(uint32_t));
        number_seq = __builtin_bswap32(number_seq);
        //std::cout << "Number of sequences : " << num_seq << " residues in "<< res_count<<" sequences"<<endl;

        uint64_t res_count;
        file.read((char*)&res_count, sizeof(uint64_t));
        std::cout << "Database size:     " << res_count << " residues in "<< number_seq <<" sequences"<<endl;

        uint32_t max_seq;
        file.read((char*)&max_seq, sizeof(uint32_t));
        max_seq = __builtin_bswap32(max_seq);
<<<<<<< HEAD
        std::cout << "Longest db seq:    " << max_seq << " residues" <<endl;
=======
        std::cout << "Longest db seq:    " << max_seq <<endl;
>>>>>>> 5d4bb6846ba04b2eaeb8bcfeb68614386f8bafe5

        //std::vector<uint32_t> header_offset;
        for (int i = 0;i<number_seq+1;i++){
            uint32_t offset;
            file.read((char*)&offset, sizeof(uint32_t));
            offset = __builtin_bswap32(offset);
            header_offset.push_back(offset);
        }

        for (int i = 0;i<number_seq+1;i++){
            uint32_t offset;
            file.read((char*)&offset, sizeof(uint32_t));
            offset = __builtin_bswap32(offset);
            sequence_offset.push_back(offset);
        }
    }
}
