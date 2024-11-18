#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <unordered_map>
#include "Transaction.h"

class Blockchain {
public:
    std::vector<std::vector<Transaction>> blockchain;  // A simple chain of transactions (blocks)
    std::unordered_map<std::string, double> balances;  // Mapping of addresses to balances

    // Constructor
    Blockchain() {}

    // Add a block (set of transactions) to the blockchain
    void add_block(const std::vector<Transaction>& block) {
        blockchain.push_back(block);
        for (const auto& tx : block) {
            balances[tx.sender] -= tx.amount;
            balances[tx.receiver] += tx.amount;
        }
    }

    // Print blockchain details
    void print_blockchain() const {
        std::cout << "Blockchain:\n";
        for (const auto& block : blockchain) {
            std::cout << "Block:\n";
            for (const auto& tx : block) {
                tx.print();
            }
        }
    }

    // Get the balance of a given address
    double get_balance(const std::string& address) const {
        auto it = balances.find(address);
        return (it != balances.end()) ? it->second : 0.0;
    }
};

#endif // BLOCKCHAIN_H
