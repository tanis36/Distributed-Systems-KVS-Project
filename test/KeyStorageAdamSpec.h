// Adam Rilatt
// 28 September 2023
// Distributed Systems -- Project 1 KeyStorageAdam Test Suite

/*
Are these proper unit tests? Absolutely not. In a proper testing circumstance,
I'd hook up listeners to the StorageDevice listeners to determine whether the
KeyStorage functions I'm testing will correctly call StorageDevice. I have tests
to evaluate StorageDevice already, so if all of the high-level KeyStorage code
works, the whole system works. In reality, I'm actually implicitly testing the
StorageDevice behavior here, which isn't ideal. I'm relying on the fact that
I've previously tested FlatFileStorageDevice and I know that under the correct
behavior it'll have observable effects on a filesystem.
*/

#ifndef KEY_STORAGE_ADAM_SPEC_H
#define KEY_STORAGE_ADAM_SPEC_H

#include <iostream>
#include <functional>
#include <fstream>
#include <vector>

#include "../src/KeyStorage.h"
#include "../src/FlatFileStorageDevice.h"
#include "TestUtils.h"

using namespace std;

// Create the database and confirm the new file exists.
bool initializes() {
  
  // If any of the temporary test files exist, remove them first.
   if (exists("../test_kvs_dir/create_kvs_test.txt"))
     std::remove("../test_kvs_dir/create_kvs_test.txt");
  
  KeyStorage ks;

  // Success-- the directory should exist already; if it doesn't, make it so.
  ks.initialize("../test_kvs_dir");  

  // Failure-- directory does not exist.
  try {
    
    ks.initialize("../nonexistentdir");
    cout << "initializes(): KVS should have failed to initialize, but didn't." << endl;
    return false;

  }
  catch (std::exception e) {
    // Expected result
  }
    
  return true;
  
}

bool creates_kvs() {

  KeyStorage ks;

  ks.initialize("../test_kvs_dir");

  // Success-- assuming the underlying FlatFileStorageDevice is sound, the file
  // will be created.
  ks.create_kvs("create_kvs_test");
  bool file_exists = exists("../test_kvs_dir/create_kvs_test.txt");

  if (!file_exists) {
    cout << "creates_kvs(): KVS should have created location, but didn't. Empty the ../test_kvs_dir and try again." << endl;
    return false;
  }

  // Failure-- creating the same KVS twice should fail, assuming the underlying
  // FlatFileStorageDevice is sound.
  try {
    
    ks.create_kvs("create_kvs_test");
    cout << "creates_kvs(): KVS should have failed to create location, but didn't." << endl;
    return false;

  }
  catch (std::exception e) {
    // Expected result
  }

  return true;
  
}

void run_KeyStorageAdam_spec() {

  vector<function<bool()>> tests = {
    initializes,
    creates_kvs
  };
  
  for (auto t : tests) {
    if (!t()) {
      cout << "KeyStorageAdam test threw an error. Halting." << endl;
      return;
    }
  }
  
  cout << "All KeyStorageAdam tests were passed." << endl;
  
}

#endif
