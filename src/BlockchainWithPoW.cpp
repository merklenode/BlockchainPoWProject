// BlockchainWithPoW.cpp

#include "BlockchainWithPoW.h"
#include <iostream>

using namespace std;

BlockchainWithPoW::BlockchainWithPoW(int difficulty)
    : Blockchain(), difficulty(difficulty) {}

void BlockchainWithPoW::mineBlock(int index, string data) {
    Block newBlock(index, data, getLastBlock().hash);
    string target = string(difficulty, '0');
    
    cout << "Mining block with difficulty " << difficulty << "...\n";
    while (newBlock.hash.substr(0, difficulty) != target) {
        newBlock = Block(index, data, getLastBlock().hash);
    }

    cout << "Block mined: " << newBlock.hash << "\n";
    addBlock(data);
}
