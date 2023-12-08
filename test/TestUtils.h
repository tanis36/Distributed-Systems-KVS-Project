// Adam Rilatt
// 28 September 2023
// Distributed Systems -- Project 1 TestUtils

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <fstream>
#include <string>

bool exists(const std::string& loc) {
  std::ifstream ifs { loc };
  return ifs.is_open();
}

#endif
