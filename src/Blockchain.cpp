// Blockchain.cpp

#include "Blockchain.h"
#include <iostream>

using namespace std;

Blockchain::Blockchain() {
    chain.push_back(createGenesisBlock());
}

Block Blockchain::createGenesisBlock() {
    return Block(0, "Genesis Block", "0");
}

Block Blockchain::getLastBlock() {
    return chain.back();
}

void Blockchain::addBlock(string data) {
    Block newBlock(chain.size(), data, getLastBlock().hash);
    chain.push_back(newBlock);
}

bool Blockchain::isBlockchainValid() {
    for (int i = 1; i < chain.size(); i++) {
        Block currentBlock = chain[i];
        Block previousBlock = chain[i - 1];

        if (currentBlock.hash != currentBlock.calculateHash()) {
            return false;
        }

        if (currentBlock.previousHash != previousBlock.hash) {
            return false;
        }
    }
    return true;
}

void Blockchain::printBlockchain() {
    for (const Block& block : chain) {
        cout << "Block #" << block.index << "\n";
        cout << "Timestamp: " << block.timestamp;
        cout << "Data: " << block.data << "\n";
        cout << "Hash: " << block.hash << "\n";
        cout << "Previous Hash: " << block.previousHash << "\n";
        cout << "--------------------------------------\n";
    }
}
