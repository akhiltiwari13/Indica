#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <iostream>

struct Record {
    int id;
    std::string name;
};

typedef boost::multi_index_container<
Record,
    boost::multi_index::indexed_by<
    boost::multi_index::ordered_unique<
    boost::multi_index::member<Record, int, &Record::id>
    >,
    boost::multi_index::ordered_non_unique<
    boost::multi_index::member<Record, std::string, &Record::name>
    >
    >
    > RecordContainer;

    int main() {
        RecordContainer records;
        records.insert({1, "Alice"});
        records.insert({2, "Bob"});
        records.insert({3, "Charlie"});

        // Access the first index (ordered by id)
        auto& id_index = records.get<0>();
        auto it = id_index.find(2);
        if (it != id_index.end()) {
            std::cout << "Found record with id 2: " << it->name << '\n';
        }

        // Access the second index (ordered by name)
        auto& name_index = records.get<1>();
        auto range = name_index.equal_range("Bob");
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << "Found record with name Bob: " << it->id << '\n';
        }

        return 0;
    }

