#include "Chaining.h"

void Chaining::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    if(bankStorage2d.size()==0){
        bankStorage2d.resize(100000);
    }
    int i = hash(id);
    Account newAccount;
    newAccount.id = id;
    newAccount.balance = count;
    bankStorage2d[i].push_back(newAccount);
}

std::vector<int> Chaining::getTopK(int k) {
    // IMPLEMENT YOUR CODE HERE
    std::vector<int> v;
    for(auto i : bankStorage2d) {
        for(auto j : i) {
        auto it = lower_bound(v.begin(), v.end(), j.balance);
        v.insert(it, j.balance);
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

int Chaining::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE

    int i = hash(id);
    for (auto& account : bankStorage2d[i]) {
        if (account.id == id) {
            return account.balance;
        }
    }
    return -1;

    return 0; // Placeholder return value
}

void Chaining::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    
    int i = hash(id);
    for(auto& account : bankStorage2d[i]) {
        if(account.id == id) {
            account.balance += count;
            return;
        }
    }
    Account newAccount;
    newAccount.id = id;
    newAccount.balance = count;
    bankStorage2d[i].push_back(newAccount);
     
}

bool Chaining::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int i = hash(id);
    for(auto& account : bankStorage2d[i]) {
        if(account.id == id) {
            return true;
        }
    }

    return false; // Placeholder return value
}

bool Chaining::deleteAccount(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int i = hash(id);

    for (auto account = bankStorage2d[i].begin(); account != bankStorage2d[i].end(); ++account) {
        if (account->id == id) {
            bankStorage2d[i].erase(account);
            return true; 
        }
    }
     
    return false; // Placeholder return value
}
int Chaining::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    int s = 0;
        for(auto& account : bankStorage2d) {
            s += account.size();
        }

        return s;

    return 0; // Placeholder return value
}

int Chaining::hash(std::string id) {
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

