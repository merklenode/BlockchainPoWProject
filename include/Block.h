// Block.h

#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {
public:
    int index;
    std::string timestamp;
    std::string data;
    std::string previousHash;
    std::string hash;

    Block(int index, std::string data, std::string previousHash);
    std::string calculateHash();
    static std::string getTimestamp();
};

#endif // BLOCK_H
