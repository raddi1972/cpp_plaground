#include <stdio.h>
#include <string.h>

// lvalue, rvalue, std::move semantics

class String
{
public:
    String() = default;

    String(const char *string)
    {
        printf("Creted\n");
        m_size = strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size);
    }

    String(const String &string)
    {
        printf("Copied\n");
        m_size = string.m_size;
        m_data = new char[m_size];
        memcpy(m_data, string.m_data, m_size);
    }

    String(String &&string)
    {
        printf("Moved\n");
        m_size = string.m_size;
        m_data = string.m_data;

        string.m_data = nullptr;
        string.m_size = 0;
    }

    void Print()
    {
        for (int i = 0; i < m_size; i++)
        {
            printf("%c", m_data[i]);
        }
        printf("\n");
    }

    ~String()
    {
        printf("Deleted\n");
        delete m_data;
    }

private:
    char *m_data;
    int m_size;
};

class Entity
{
public:
    Entity(String &&name)
        : m_name((String &&) name)
    {
    }

    Entity(const String &name)
        : m_name(name)
    {
    }

    void PrintName()
    {
        m_name.Print();
    }

private:
    String m_name;
};

int main()
{
    Entity str = Entity("Hello");
    // String another_one = str;
    str.PrintName();
}
