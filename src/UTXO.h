#ifndef UTXO_H
#define UTXO_H

#include <string>
#include <iostream>

class UTXO {
public:
    std::string transaction_id;
    int output_index;
    double value;
    bool is_spent;

    // Constructor
    UTXO(const std::string& _transaction_id, int _output_index, double _value)
        : transaction_id(_transaction_id), output_index(_output_index), value(_value), is_spent(false) {}

    // Mark this UTXO as spent
    void mark_as_spent() {
        is_spent = true;
    }

    // Check if this UTXO is available (not spent)
    bool is_available() const {
        return !is_spent;
    }

    // Print UTXO details
    void print() const {
        std::cout << "TX ID: " << transaction_id << ", Output Index: " << output_index << ", Value: " << value << ", Spent: " << (is_spent ? "Yes" : "No") << std::endl;
    }
};

#endif // UTXO_H
