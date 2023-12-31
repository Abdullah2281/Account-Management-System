# Bank Data Management System (BDMS)

BDMS is a specialized system designed for the efficient management of bank account data. Leveraging a hashmap, it ensures swift retrieval and storage of account details based on unique identifiers.

## Author: Abdullah

## Overview

BDMS employs a dedicated `BankData` class to handle hashmap operations, specifically designed for storing account identifiers comprising an 11-digit IFSC code and a 10-digit account number.

## Hashmap Implementation & Collision Strategies

The core of BDMS is its hashmap functionality, which is augmented with collision resolution mechanisms:

- **Chaining**: Utilizes linked lists at each hash index to accommodate multiple entries with identical hash codes.
- **Linear Probing**: Employs sequential slot examination to find unoccupied hash slots.
- **Quadratic Probing**: Adopts a quadratic function for more distributed collision handling.
- **Cubic Probing**: Enhances collision resolution using a cubic function.

## Account Identification

Each account within the system is uniquely tagged with an identifier in the format: `<11-digit IFSC>_<10-digit Account No.>`. Given the current system configuration, accommodating up to 10,000 unique account combinations is feasible.

## Getting Started

To run the project, follow these steps:

1. Clone the project repository.

2. Compile the project using a C++ compiler.

3. Execute the compiled program.

## Code Structure
I have provided two txt files 'in.txt' and 'out.txt' you can use the input and output in those files to check if the code is working correctly or not
