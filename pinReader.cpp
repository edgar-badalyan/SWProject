#include "pinReader.h"


pinReader::pinReader() {
}

void pinReader::read_index(string file_name, vector<uint32_t> header_offset) {
    //reads the info on the database from the .pin binary file
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if(file.is_open()){

        uint32_t version;
        file.read((char *)&version, sizeof(uint32_t));
        version = __builtin_bswap32(version);
        std::cout << version<<endl;

        uint32_t type;
        file.read((char *)&type, sizeof(uint32_t));
        type = __builtin_bswap32(type);
        std::cout << type <<endl;

        uint32_t length;
        file.read((char*)&length, sizeof(uint32_t));
        length = __builtin_bswap32(length);
        std::cout << length <<endl;

        char title[length+1];
        file.read(title, length);
        title[length] = '\0';
        std::cout << title << endl;

        uint32_t timestamp_length;
        file.read((char*)&timestamp_length, sizeof(uint32_t));
        timestamp_length = __builtin_bswap32(timestamp_length);
        std::cout << timestamp_length <<endl;

        char timestamp[timestamp_length + 1];
        file.read(timestamp, timestamp_length);
        timestamp[timestamp_length] = '\0';
        std::cout << timestamp <<endl;

        uint32_t num_seq;
        file.read((char*)&num_seq, sizeof(uint32_t));
        num_seq = __builtin_bswap32(num_seq);
        std::cout << num_seq <<endl;

        uint64_t res_count;
        file.read((char*)&res_count, sizeof(uint64_t));
        std::cout << res_count <<endl;

        uint32_t max_seq;
        file.read((char*)&max_seq, sizeof(uint32_t));
        max_seq = __builtin_bswap32(max_seq);
        std::cout << max_seq <<endl;

        //std::vector<uint32_t> header_offset;
        for (int i = 0;i<10;i++){
            uint32_t offset;
            file.read((char*)&offset, sizeof(uint32_t));
            offset = __builtin_bswap32(offset);
            header_offset.push_back(offset);
            std::cout << offset <<endl;
        }
    }
}
