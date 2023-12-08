// Adam Rilatt
// 25 September 2023
// Distributed Systems -- Project 1 FlatFileStorageDevice Test Suite

/*
We won't do proper unit testing in this project, but we'll confirm that each
function does roughly what we expect it to do. Link and compile the test file
and confirm all tests pass before pushing work to origin/main.
*/

#ifndef FLAT_FILE_STORAGE_DEVICE_SPEC_H
#define FLAT_FILE_STORAGE_DEVICE_SPEC_H

#include <iostream>
#include <functional>
#include <fstream>
#include <vector>

#include "../src/FlatFileStorageDevice.h"
#include "TestUtils.h"

using namespace std;

// Create the database and confirm the new file exists.
bool initializes_kvs() {
  
  StorageDevice* kvs = new FlatFileStorageDevice("../test_kvs_dir");
  
  if (!kvs) {
    cout << "initializes_kvs(): KVS failed to initialize. Check whether you have ../test_kvs_dir." << endl;
    return false;
  }

  // If any of the temporary test files exist, remove them first.
  if (exists("../test_kvs_dir/test_location.txt"))
    std::remove("../test_kvs_dir/test_location.txt");

  if (exists("../test_kvs_dir/write_test.txt"))
    std::remove("../test_kvs_dir/write_test.txt");
  
  if (exists("../test_kvs_dir/remove_test.txt"))
    std::remove("../test_kvs_dir/remove_test.txt");
  
  return true;
  
}

bool creates_location() {

  StorageDevice* kvs = new FlatFileStorageDevice("../test_kvs_dir");

  kvs->create_location("test_location");
  bool file_exists = exists("../test_kvs_dir/test_location.txt");

  if (!file_exists) {
    cout << "creates_location(): KVS should have created location, but didn't. Empty the ../test_kvs_dir and try again." << endl;
    return false;
  }

  // Creating the same KVS twice should fail.
  try {
    
    kvs->create_location("test_location");
    cout << "creates_location() KVS should have failed to create location, but didn't." << endl;
    return false;

  }
  catch (std::exception e) {
    // Expected result
  }

  return true;
  
}

bool reads() {

  StorageDevice* kvs = new FlatFileStorageDevice("../test_kvs_dir");
  
  if (!exists("../test_kvs_dir/read_test.txt")) {
    cout << "reads(): The read_test data is not present." << endl;
    return false;
  }

  // Success-- should return blue
  string val = kvs->read("read_test", "color");
  if (val != "blue") {
    for (char c : val)
      cout << c << endl;
    cout << "reads(): Successful read test should have returned \"blue\", but did not." << endl;
    return false;
  }

  // Failure-- location not found
  try {
    
    string val2 = kvs->read("nonexistent", "randomval");
    cout << "reads(): Failing read test (nonexistent location) should have returned an empty string, but did not." << endl;
    return false;
    
  }
  catch (std::exception e) {
    // Expected result
  }
  
  // Failure-- key not found
  try {

    string val3 = kvs->read("read_test", "grunglebungus");
    cout << "reads(): Failing read test (bad key) should have returned an empty string, but did not." << endl;
    return false;
    
  }
  catch (std::exception e) {
    // Expected result
  }
      
  return true;
  
}

bool writes() {

  StorageDevice* kvs = new FlatFileStorageDevice("../test_kvs_dir");

  kvs->create_location("write_test");

  // Successful write
  kvs->write("write_test", "filbert", "duck");
  string val = kvs->read("write_test", "filbert");
  if (val != "duck") {
    cout << "writes(): Should have successfully written to write_test and read it back out, but didn't." << endl;
    return false;
  }

  // Success-- overwriting key
  kvs->write("write_test", "filbert", "goose");
  string val2 = kvs->read("write_test", "filbert");
  if (val2 != "goose") {
    cout << "writes(): Should have overwritten \"duck\" with \"goose\", but didn't." << endl;
    return false;
  }
  
  // Failure-- location not found
  try {
    
    kvs->write("nonexistent", "randomkey", "randomval");
    cout << "writes(): Should have failed to write to nonexistent location, but didn't." << endl;
    return false;
    
  }
  catch (std::exception e) {
    // Expected result
  }
  
  return true;
  
}

bool removes() {

  StorageDevice* kvs = new FlatFileStorageDevice("../test_kvs_dir");
  
  kvs->create_location("remove_test");

  // Successful remove
  kvs->write("remove_test", "evilkey", "badvalue");
  kvs->remove("remove_test", "evilkey");

  try {

    string result4 = kvs->read("remove_test", "evilkey");
    cout << "removes(): Should have failed to read a key-value pair that has been removed, but read was successful." << endl;
    return false;

  }
  catch (std::exception e) {
    // Expected result-- should not be found
  }
  
  return true;
  
}

void run_FlatFileStorageDevice_spec() {

  vector<function<bool()>> tests = {
    initializes_kvs,
    creates_location,
    reads,
    writes,
    removes
  };
  
  for (auto t : tests) {
    if (!t()) {
      cout << "FlatFileStorageDevice test threw an error. Halting." << endl;
      return;
    }
  }
  
  cout << "All FlatFileStorageDevice tests were passed." << endl;
  
}

#endif
