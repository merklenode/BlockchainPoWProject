// Blockchain.h

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
public:
    std::vector<Block> chain;

    Blockchain();
    Block createGenesisBlock();
    Block getLastBlock();
    void addBlock(std::string data);
    bool isBlockchainValid();
    void printBlockchain();
};

#endif // BLOCKCHAIN_H
