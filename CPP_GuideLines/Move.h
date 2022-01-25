#include <iostream>
#include <utility>

namespace CPPGuidelines{
    class String{

        uint32_t m_size {0};
        char* m_data {nullptr};
        static size_t m_count;

    public:
        String() = default;
        String(const char* string)
        {
            m_size = strlen(string);
            m_data = new char[m_size];
            memcpy(m_data, string, m_size);
            std::cout << "String Class Constructed " << m_data << "\n";
            m_count++;
        }

        ~String() {
            if(m_data) {
                std::cout << "String Class Destroyed " << m_data << "\n";
                m_size = 0;
                delete[] m_data;
                m_data = nullptr;
            }

            m_count--;
        }

        String(const String& rhs){
            std::cout << "String Class Copy Constructor.\n";
            m_size = rhs.m_size;
            m_data = new char[m_size];
            memcpy(m_data, rhs.m_data, m_size);
        }

        String& operator =(const String& rhs){

            std::cout << "String Class Copy Assignment Operator.\n";
            if(this != & rhs) {
                m_size = rhs.m_size;
                m_data = new char[m_size];
                memcpy(m_data, rhs.m_data, m_size);
            }
            return *this;
        }

        String(String&& rhs) noexcept{
            std::cout << "String Class Move Constructor.\n";
            std::swap(m_size, rhs.m_size);
            std::swap(m_data, rhs.m_data);
        }

        String& operator=(String&& rhs) noexcept{
            std::cout << "String Class Move Assignment Operator.\n";

            if(this != &rhs){
                std::swap(m_size, rhs.m_size);
                std::swap(m_data, rhs.m_data);
            }

            return *this;
        }

        [[nodiscard]] const char* getData() const noexcept {return m_data;}
        static size_t getCount() noexcept {return m_count;}
    };

    size_t String::m_count = 0;

    class Entity{

        String m_name;

    public:

        explicit Entity(const String& name):m_name(name){
            std::cout << "Entity Class Constructed With Copy " << m_name.getData() << std::endl;
        }

        explicit Entity(String&& name):m_name(std::move(name)){
            std::cout << "Entity Class Constructed With std::move " << m_name.getData() << std::endl;
        }

        void printName() const noexcept {
            std::cout << "Entity with name: " << m_name.getData() << std::endl;
        }
    };
}