#include <iostream>
#include <fstream>
#include <sstream>
#include "Blockchain.h"
#include "Transaction.h"

bool load_blockchain_data(const std::string& filename, Blockchain& blockchain) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return false;
    }

    std::string line;
    std::vector<Transaction> current_block;
    bool reading_balances = false;

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        if (line.find("Block") != std::string::npos) {
            if (!current_block.empty()) {
                blockchain.add_block(current_block);
                current_block.clear();
            }
            continue;
        }

        if (line.find("Balances") != std::string::npos) {
            reading_balances = true;
            continue;
        }

        if (!reading_balances) {
            std::string sender, receiver;
            double amount;
            std::istringstream ss(line);
            ss.ignore(8); ss >> sender;
            ss.ignore(11); ss >> receiver;
            ss.ignore(8); ss >> amount;

            current_block.push_back(Transaction(sender, receiver, amount));
        } else {
            std::string address;
            double balance;
            std::istringstream ss(line);
            ss >> address;
            ss.ignore(1); ss >> balance;

            blockchain.balances[address] = balance;
        }
    }

    if (!current_block.empty()) {
        blockchain.add_block(current_block);
    }

    file.close();
    return true;
}

int main() {
    Blockchain blockchain;

    if (load_blockchain_data("data/blockchain_data.txt", blockchain)) {
        blockchain.print_blockchain();
    } else {
        std::cerr << "Failed to load blockchain data." << std::endl;
    }

    return 0;
}
