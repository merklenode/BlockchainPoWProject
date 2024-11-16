// main.cpp

#include <iostream>
#include "BlockchainWithPoW.h"

using namespace std;

int main() {
    BlockchainWithPoW myBlockchain(4);  // Difficulty set to 4 leading zeros

    cout << "Starting the Blockchain...\n";
    myBlockchain.mineBlock(1, "Transaction 1");
    myBlockchain.mineBlock(2, "Transaction 2");
    myBlockchain.mineBlock(3, "Transaction 3");

    myBlockchain.printBlockchain();

    cout << "Blockchain valid: " << (myBlockchain.isBlockchainValid() ? "Yes" : "No") << "\n";
    return 0;
}
