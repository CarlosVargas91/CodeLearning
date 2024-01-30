#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <boost/lexical_cast.hpp>
#include <vector>

class Database
{
public:
    virtual int get_population(const std::string &name) = 0;
};

class SingletonDatabase : public Database
{
private:
    SingletonDatabase() // private constructor
    {
        std::cout << "Initializing database" << std::endl;

        std::ifstream ifs("capitals.txt");

        std::string s, s2;
        while (getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = boost::lexical_cast<int>(s2);
            capitals[s] = pop;
        }
    }

    std::map<std::string, int> capitals;

public:
    SingletonDatabase(SingletonDatabase const &) = delete; // delete the copy constructor
    void operator=(SingletonDatabase const &) = delete;

    static SingletonDatabase &get()
    {
        static SingletonDatabase db;
        return db;
    }

    int get_population(const std::string &name) override
    {
        return capitals[name];
    }

    
    static SingletonDatabase* get_instance()
    {
      if (!instance)
        instance = new SingletonDatabase;
      return instance; // atexit
    }
    
};

void main()
{
    SingletonDatabase::get().get_population("Goyi");  //Get instance of the class

    auto dbins = SingletonDatabase::get_instance();
}