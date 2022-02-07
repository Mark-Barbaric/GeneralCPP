#include "SingleResponsability.h"

namespace SOLID {
    inline void runSingleResponsability() {
        Journal journal("Journal 1");
        journal.add_entry("Entry 1");
        journal.add_entry("Entry 2");
        Journal::save("Journal.txt", journal.get_entries());
        SavingManager::save(journal, "journal2.txt");
    }

    inline void runLiskovSubstitutionPrinciple(){

    }

    inline void runSOLIDExamples(){
        std::cout << "Running SOLID Examples.\n\n";
        std::cout << "Running Single Responsability Principle.\n";
        runSingleResponsability();
    }
}
