#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <exception>

// Forward declaration of std::pair<Key, Value>


// Primary template for DataBase
template <
    class Key,
    class Value,
    template <typename, typename> class Container = std::map
>
class DataBase
{
public:
    DataBase() {}
    ~DataBase() {}
    DataBase(const DataBase& copy) : _database(copy._database) {}
    DataBase& operator=(const DataBase& assign) { _database = assign._database; return *this; }

private:
    Container<Key, Value> _database;
};

// Partial specialization for DataBase with std::vector and std::pair
template <
    class Key,
    class Value
>
class DataBase<Key, Value, std::vector>
{
public:
    DataBase() {}
    ~DataBase() {}
    DataBase(const DataBase& copy) : _database(copy._database) {}
    DataBase& operator=(const DataBase& assign) { _database = assign._database; return *this; }

private:
    std::vector<std::pair<Key, Value> > _database;
};