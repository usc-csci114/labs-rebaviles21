#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <utility>
#include <vector>
#include <map>
#include <stdexcept>
#include <utility>
#include <iostream>

template <typename K, typename V>
class HashTable {
public:
	HashTable();
	~HashTable();
	void insert(K key, V value);
	V find(K key);
	void remove(K key);
	size_t size();
	bool empty();
	
private:
	std::vector< std::map<K,V> > table;
	void resize();
	size_t size_;
	size_t alpha;
	uint64_t hash(K key);
};

template <typename K, typename V>
HashTable<K,V>::HashTable() { table.resize(1); alpha = 1; size_ = 0;};

template <typename K, typename V>
HashTable<K,V>::~HashTable() {};

template <typename K, typename V>
uint64_t HashTable<K,V>::hash(K key)
{
	std::hash<K> hasher;
	return hasher(key);
}


// - Use this index to insert the key,value pair into the map at `table[idx]`. This is one line.
// - Increment `size_`

template <typename K, typename V>
void HashTable<K,V>::insert(K key, V value)
{
//resizes the table if the table size is greater than alpha
 //std::cout << "new insert() size now_ " << size_ << " table.size(): " << table.size() << std::endl;
 if ( (size_+1) / table.size() >= alpha) {
	resize();
 }
 //idx for the key by hashing the key and modding table size
 size_t idx = hash(key) % table.size();

 table[idx][key] = value;
 size_++;
 //std::cout << "after insert() size now_ " << size_ << " table.size(): " << table.size() << std::endl;
}

template <typename K, typename V>
V HashTable<K,V>::find(K key)
{
	size_t idx = hash(key) % table.size();
	if(table[idx].count(key) > 0 )
	{
		return table[idx][key];
	}
	throw std::range_error("Key not found.");
}

template <typename K, typename V>
void HashTable<K,V>::remove(K key)
{
	size_t index = hash(key) % table.size(); 
	if(table[index].count(key) > 0 )
	{
		table[index].erase(key);
		size_--;
	}
	else {
		throw std::range_error("Key not found.");
	}	
}

template <typename K, typename V>
size_t HashTable<K,V>::size()
{
	return size_;
}

template <typename K, typename V>
bool HashTable<K,V>::empty()
{
	if(size_ == 0) {
		return true;
	}
	return false;
}

template <typename K, typename V>
void HashTable<K,V>::resize()
{
//Resize the hash table so that `table.size()` grows by 2x.

// - Make a copy of the existing `table` called `old_table`
auto old_table = table;
// - Resize `table` to size zero and then to size `2*old_table.size()` to clear out the old entries on `table`
table.resize(0); 
table.resize(2*old_table.size());
// - Set `size_` to zero
//size_ = 0;
// - For every location in `old_table`  (old table is a vector, so you can iterate with an index or with iterators), pull out the map into a temporary variable (best if you do it with a reference)
for(size_t i = 0; i < old_table.size();i++) {
	const auto& map = old_table[i]; // pull out map with temporary 
	auto iterator = map.begin(); //initialize the iterator
	while(iterator != map.end()) {
		insert(iterator->first,iterator->second);
		iterator++; //have to auto increment because of while loop structure
	}
}
// - For every item in the map (use iterators) call `insert()` to insert the key, value pair into `table`
// - Remember for the map iterator you can use `->first` and `->second` to get the key and value for that item.
	//std::cout << "resizing " << table.size() << " -> " << table.size()*2 << std::endl;
}
#endif
