#include <fstream>
#include <vector>
#include <iostream>
#include <string>

namespace SOLID {
    class Journal {
        std::string m_title;
        std::vector<std::string> m_entries;

    public:
        explicit Journal(std::string title) : m_title(std::move(title))
        {
            std::cout << "Creating journal with title: " << m_title << ".\n";
        }

        void add_entry(const std::string &entry) {

            m_entries.emplace_back(std::to_string(m_entries.size() + 1) + " " + entry);
        }

        static void save(const std::string& filename, const std::vector<std::string>& entries){

            std::cout << "Adding save method to Journal Class violates Single Responsability Principle.\n";
            std::ofstream ofs(filename);

            for (const auto &s : entries) {
                ofs << s << std::endl;
            }
        }

        [[nodiscard]] auto get_entries() const { return m_entries; }

    };

    struct SavingManager {
        static void save(const Journal &journal, const std::string& filename) {
            std::cout << "Moving save functionality to separate class leaves much more managable code.\n";
            std::ofstream ofs(filename);

            for (const auto &s : journal.get_entries()) {
                ofs << s << std::endl;
            }
        }
    };
}
