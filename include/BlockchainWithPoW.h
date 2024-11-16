// BlockchainWithPoW.h

#ifndef BLOCKCHAINWITHPOW_H
#define BLOCKCHAINWITHPOW_H

#include "Blockchain.h"

class BlockchainWithPoW : public Blockchain {
public:
    int difficulty;

    BlockchainWithPoW(int difficulty);
    void mineBlock(int index, std::string data);
};

#endif // BLOCKCHAINWITHPOW_H
