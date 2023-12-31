#include "LinearProbing.h"

void LinearProbing::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    if(bankStorage1d.size() == 0) {
    Account account;
    account.id = "abdullah";
    account.balance = -1;
    bankStorage1d.resize(100000,account);
    }

    int i = hash(id);
    Account newAccount;
    newAccount.id = id;
    newAccount.balance = count;

    while (bankStorage1d[i].balance != -1 && bankStorage1d[i].balance != -2) {
        i = (i + 1)%100000;
    }
    // Insert the key into the empty or deleted account slot
    bankStorage1d[i] = newAccount;

}

std::vector<int> LinearProbing::getTopK(int k) {
    // IMPLEMENT YOUR CODE HERE
    std::vector<int> v;
    for(auto i : bankStorage1d) {
        if(i.balance >= 0) {
        auto it = lower_bound(v.begin(), v.end(), i.balance);
        v.insert(it, i.balance);
        }
    }
    std::vector<int> ans;
    for (int i = 0; i < k; i++) {
        if (!v.empty()) {
            int e = v.back();  
            v.pop_back();     
            ans.push_back(e);
        } else {
            break; 
        }
    }
    return ans;

    return std::vector<int>(); // Placeholder return value
}

int LinearProbing::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int i = hash(id);

    while (bankStorage1d[i].balance != -1) {
        if (bankStorage1d[i].id == id) {
            return bankStorage1d[i].balance;
        }
        i = (i + 1) % 100000;
    }

    return -1;

    return 0; // Placeholder return value
}

void LinearProbing::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    int i = hash(id);
    bool found = false;
    while(bankStorage1d[i].balance != -1) {
        if(bankStorage1d[i].id == id) {
            found = true;
            bankStorage1d[i].balance += count;
        }
        i = (i + 1) % 100000;
    }
    if(!found) {
        createAccount(id, count);
    }

}

bool LinearProbing::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int i = hash(id);
    while(bankStorage1d[i].balance != -1) {
        if(bankStorage1d[i].id == id) {
            return true;
        }
        i = (i + 1) % 100000;
    }

    return false; // Placeholder return value
}

bool LinearProbing::deleteAccount(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int i = hash(id);

    while(bankStorage1d[i].balance != -1) {
        if(bankStorage1d[i].id == id) {
            bankStorage1d[i].balance = -2;
            bankStorage1d[i].id = "abdullah";
            return true;
        }
        i = (i + 1) % 100000;
    }

    return false; // Placeholder return value
}
int LinearProbing::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    int count = 0;
    for(auto i : bankStorage1d) {
        if(i.balance != -1 && i.balance != -2) {
            count++;
        }
    }
    return count;

    return 0; // Placeholder return value
}

int LinearProbing::hash(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    const int prime = 31;
    int hashValue = 0;

    for (char c : id) {
        hashValue = (hashValue * prime) + static_cast<int>(c);
    }
    if (hashValue < 0) {
        hashValue = -hashValue;
    }
    return hashValue%100000;

    return 0; // Placeholder return value
}