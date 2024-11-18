cmake_minimum_required(VERSION 3.10)
project(CryptocurrencySystem)

set(CMAKE_CXX_STANDARD 11)

# Add the source files to the executable
add_executable(cryptocurrency_system
    src/Main.cpp
    src/Transaction.cpp
    src/UTXO.cpp
    src/Wallet.cpp
    src/Blockchain.cpp
)

# Include directories for header files
include_directories(src)
