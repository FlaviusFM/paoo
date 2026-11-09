#include "BankAccount.hpp"
#include "BankRegistry.hpp"
#include "AccountAuditor.hpp"
#include "Uncopyable.hpp"
#include <iostream>

//  Item 4: Valori neinitializate vs initializate
void demoItem4Initialization() {
    std::cout << "====================================================\n";
    std::cout << "ITEM 4: MAKE SURE OBJECTS ARE INITIALIZED BEFORE USE\n";
    std::cout << "====================================================\n";

    //  1. Tipuri primitive:
    //  int uninitVar; // undefined behavior daca este citit
    int initVar = 0;
    std::cout << "Variabila primitiva initializata manual: " << initVar << "\n";

    //  2. Registrul static local evita 'static initialization order fiasco'
    std::cout << "\nAccesam registrul prin Meyers' Singleton (garantat initializat):\n";
    BankRegistry& reg = BankRegistry::getInstance();

    //  3. Creare cont bancar (initializare const + ordine corecta a membrilor)
    BankAccount acc1("RO49BTRL0001", 1500.0);
    BankAccount acc2("RO49INGB0002", 3200.0);
    acc1.printInfo();
    acc2.printInfo();

    std::cout << "\nStarea registrului dupa crearea conturilor:\n";
    reg.printRegistry();
}

//  Item 5: Ce scrie compilatorul si cand refuza operator=
void demoItem5CompilerGeneratedFunctions() {
    std::cout << "\n====================================================\n";
    std::cout << "ITEM 5: KNOW WHAT FUNCTIONS C++ SILENTLY WRITES\n";
    std::cout << "====================================================\n";

    BankAccount acc("RO99BCR0003", 500.0);

    //  Cream doi auditori pentru cont
    AccountAuditor auditor1(acc, 101);
    AccountAuditor auditor2(acc, 102);

    //  1. Copy Constructor functioneaza: se initializeaza un nou auditor
    AccountAuditor auditorCopy(auditor1); //    Generat automat de C++
    std::cout << "Copy Constructor apelat cu succes pentru AccountAuditor:\n";
    auditorCopy.inspect();

    
    // auditor1 = auditor2; 
    
    std::cout << "-> Incercarea 'auditor1 = auditor2;' ESTE BLOCATA de compilator:\n";
    std::cout << "   Motiv: targetAccount este referinta (&), iar auditorId este const.\n";
}

//  Item 6: Interzicerea copierii
void demoItem6DisallowingFunctions() {
    std::cout << "\n====================================================\n";
    std::cout << "ITEM 6: EXPLICITLY DISALLOW COMPILER GENERATED FUNCTIONS\n";
    std::cout << "====================================================\n";

    BankAccount acc1("RO11BRDE0004", 10000.0);

    // Un cont bancar reprezintă o entitate unică în lumea reală.
    

    std::cout << "-> 'BankAccount accClone = acc1;' si 'acc1 = acc2;' sunt interzise la compilare prin '= delete'.\n";
    std::cout << "-> Mostenirea clasei 'Uncopyable' produce aceeasi protectie.\n";
}

int main() {
    demoItem4Initialization();
    demoItem5CompilerGeneratedFunctions();
    demoItem6DisallowingFunctions();

    std::cout << "\n====================================================\n";
    std::cout << "CURATARE AUTOMATA LA FINAL DE MAIN\n";
    std::cout << "====================================================\n";
    return 0;
}