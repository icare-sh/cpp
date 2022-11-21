// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful


template <typename T>
void read_file_to_cont(std::ifstream &fi, std::list<T> &cont) {
    T val;
    while (fi >> val) {
        cont.push_back(val);
    }
}

template <typename U>
void read_and_sort(std::ifstream &fi, std::ofstream &fo) {
  std::list<U> cont;
  read_file_to_cont(fi, cont);
  my_selection_sort(cont.begin(), cont.end());
  for (auto &val : cont) {
    fo << val << std::endl;
  }
}

template <typename V>
void read_and_sort_decide_container(std::ifstream &fi, std::ofstream &fo) {
  if (fi.peek() == EOF) {
    return;
  }
  V val;
  fi >> val;
  if (fi.peek() == EOF) {
    fo << val << std::endl;
    return;
  }
  fi.seekg(0);
  read_and_sort<V>(fi, fo);
}

void read_and_sort_decide_valuetype(std::ifstream &fi, std::ofstream &fo) {
  if (fi.peek() == EOF) {
    return;
  }
  char c = fi.peek();
  if (c == '-' || (c >= '0' && c <= '9')) {
    read_and_sort_decide_container<int>(fi, fo);
  } else {
    read_and_sort_decide_container<std::string>(fi, fo);
  }
}
