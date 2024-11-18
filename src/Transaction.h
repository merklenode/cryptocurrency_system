#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <unordered_map>
#include <iostream>

class Transaction {
public:
    std::string sender;
    std::string receiver;
    double amount;

    // Constructor
    Transaction(const std::string& _sender, const std::string& _receiver, double _amount)
        : sender(_sender), receiver(_receiver), amount(_amount) {}

    // Validate the transaction (ensure the sender has enough balance)
    bool validate_transaction(std::unordered_map<std::string, double>& balances) const {
        if (balances.find(sender) == balances.end()) {
            std::cerr << "Sender does not exist!" << std::endl;
            return false;
        }
        return balances.at(sender) >= amount;
    }

    // Print transaction details
    void print() const {
        std::cout << sender << " -> " << receiver << ": " << amount << " coins" << std::endl;
    }
};

#endif // TRANSACTION_H
