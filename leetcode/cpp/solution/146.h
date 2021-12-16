#ifndef LEETCODE_CPP_SOLUTION_146
#define LEETCODE_CPP_SOLUTION_146

#include "leetcode.h"

class LRUCache {
 private:
  using Key = int;
  using Value = int;
  using Pair = std::pair<Key, Value>;

 public:
  LRUCache(int capacity) : capacity_{capacity} { hash_.reserve(capacity_); }

  int get(Key key) {
    auto find_result = hash_.find(key);
    if (find_result != hash_.end()) {
      Value result = find_result->second->second;
      AdjustToFront(key);
      return result;
    } else {
      return -1;
    }
  }

  void put(Key key, Value value) {
    if (hash_.find(key) != hash_.end()) {
      hash_[key]->second = value;
      AdjustToFront(key);
    } else {
      values_.push_front({key, value});
      hash_[key] = values_.begin();
    }

    if (values_.size() > capacity_) {
      Key least_used_key = values_.back().first;
      hash_.erase(least_used_key);
      values_.pop_back();
    }
#if 0
    for (auto pair : hash_) {
      std::cout << pair.first << " -> " << pair.second->second << std::endl;
    }
    std::cout << std::endl;
#endif
  }

  void AdjustToFront(Key key) {
    Value value = hash_[key]->second;
    auto values_pos = hash_[key];
    values_.erase(values_pos);
    values_.push_front({key, value});
    hash_[key] = values_.begin();
  }

 private:
  int capacity_;
  std::list<Pair> values_;
  std::unordered_map<Key, typename std::list<Pair>::iterator> hash_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/* expect: 0, -1, -1, 3, 4 */
void Case1() {
  int capacity = 2;
  LRUCache* obj = new LRUCache(capacity);

  obj->put(1, 0);
  obj->put(2, 2);
  std::cout << obj->get(1) << std::endl;
  obj->put(3, 3);
  std::cout << obj->get(2) << std::endl;
  obj->put(4, 4);
  std::cout << obj->get(1) << std::endl;
  std::cout << obj->get(3) << std::endl;
  std::cout << obj->get(4) << std::endl;

  delete obj;
}

/* expect: 1, -1, 1 */
void Case2() {
  int capacity = 2;
  LRUCache* obj = new LRUCache(capacity);

  obj->put(2, 1);
  obj->put(1, 1);
  std::cout << obj->get(2) << std::endl;
  obj->put(4, 1);
  std::cout << obj->get(1) << std::endl;
  std::cout << obj->get(2) << std::endl;

  delete obj;
}

/* expeect: -1, 3 */
void Case3() {
  int capacity = 2;
  LRUCache* obj = new LRUCache(capacity);

  obj->put(2, 1);
  obj->put(1, 1);
  obj->put(2, 3);
  obj->put(4, 1);
  std::cout << obj->get(1) << std::endl;
  std::cout << obj->get(2) << std::endl;

  delete obj;
}

int Leetcode() {
  Case3();
  return 0;
}

#endif /* LEETCODE_CPP_SOLUTION_146 */
