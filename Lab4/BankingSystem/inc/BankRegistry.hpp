#ifndef BANK_REGISTRY_HPP
#define BANK_REGISTRY_HPP

#include <string>
#include <vector>

class BankRegistry {
private:
    std::vector<std::string> registeredIbans;
    BankRegistry();

public:
    void logRegistration(const std::string& iban);
    void printRegistry() const;

    //  Garanteaza ca registrul este creat la primul apel
    static BankRegistry& getInstance();
};

#endif