#include <string>
#include <functional>
#include <vector>

class BloomFilter
{
private:
    // add whatever you want here
    static constexpr unsigned long long U = 1e9+7;
    std::vector<bool> bits;
    std::vector<std::function<size_t(const std::string&)>> hash_func;
    int S;

public:
    // Size is the size of the bit array
    // You should accept arbitrary number of hash functions!
    BloomFilter(int size, std::initializer_list<std::function<size_t(const std::string&)>> hashes): S(size), bits(size, 0){
        for (const auto& hash: hashes) {
            hash_func.push_back(hash);
        }
    }


    // Destructor
    // Implement if necessary to handle cleanup or memory management.

    // Method to add an item to the filter.
    void add(const std::string& item) {
        for (const auto& hash: hash_func) {
            size_t val = hash(item);
            bits[val % S] = bits[val % S] | 1;
        }
    }

    // Method to check if the filter contains the item... possibly!
    bool possibly_contains(const std::string& item) {
        for (const auto& hash: hash_func) {
            size_t val = hash(item);
            if (!bits[val % S]) {return false;}
        }
        return true;
    }

    // Generate a hash function with a given seed.
    static std::function<size_t(const std::string&)> generate_hash_function(int seed) {
        return [seed] (const std::string& input) -> size_t {
            std::hash<std::string> hash;
            unsigned long long s = seed;
            s ^= seed >> 12;
            s ^= seed << 25;
            s ^= seed >> 27;
            return hash(input)^(s * U);
        };
    }
};