#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <unordered_map>
#include "UTXO.h"
#include "Transaction.h"

class Wallet {
public:
    std::string address;
    double balance;

    // Constructor
    Wallet(const std::string& _address) : address(_address), balance(0.0) {}

    // Send a transaction
    void send_transaction(const std::string& receiver, double amount, std::unordered_map<std::string, double>& balances) {
        Transaction tx(address, receiver, amount);

        // Validate transaction
        if (tx.validate_transaction(balances)) {
            std::cout << "Transaction Validated!" << std::endl;
            // Update balances for sender and receiver
            balances[address] -= amount;
            balances[receiver] += amount;
        } else {
            std::cout << "Insufficient balance for transaction!" << std::endl;
        }
    }

    // Print wallet details
    void print_wallet_info() const {
        std::cout << "Wallet address: " << address << "\nBalance: " << balance << " coins" << std::endl;
    }
};

#endif // WALLET_H
