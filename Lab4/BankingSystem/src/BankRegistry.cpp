#include "BankRegistry.hpp"
#include <iostream>

BankRegistry::BankRegistry() {
    std::cout << "[BankRegistry] Initializat cu succes (instanta statica creata la cerere).\n";
}

void BankRegistry::logRegistration(const std::string& iban) {
    registeredIbans.push_back(iban);
}

void BankRegistry::printRegistry() const {
    std::cout << "--- Registru Bancar (Total conturi: " << registeredIbans.size() << ") ---\n";
    for (const auto& iban : registeredIbans) {
        std::cout << " - " << iban << "\n";
    }
}

BankRegistry& BankRegistry::getInstance() {
    static BankRegistry instance;
    return instance;
}