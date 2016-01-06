#Project 2: DIY STL

- The Set API using a dynamic array - DONE
- The Set API using a linked list - DONE
- The Set API using an hash map - DONE
- The MultiSet API using a dynamic array - DONE
- The MultiSet API using a linked list - DONE
- The MultiSet API using an hash map - DONE
- The Map API using a dynamic array - DONE
- The Map API using a linked list - DONE
- The Map API using an hash map -  DONE 
- The MultiMap API using a dynamic array - DONE
- The MultiMap API using a linked list - DONE
- The MultiMap API using an hash map - DONE

void Set::insert(string key)
bool Set::is_in(string key)
void Set::remove(string key)
bool Set::is_empty()

void MSet::insert(string key)
bool MSet::is_in(string key)
unsigned long MSet::count(string key)
void MSet::removeOne(string key)
void MSet::removeAll(string key)
bool MSet::is_empty()

void Map::set(string key, int value)
void Map::remove(string key)
int Map::get(string key) //returns 0 if key is not part of map
int& Map::operator[](string key) //call using Map[key], returns ? if key is not part of map

void MultiMap::set(string key, int value)
void MultiMap::removeAll(string key)
int MultiMap::count(string key)
int* MultiMap::getAll(string key) //returns null pointer if key is not part of map