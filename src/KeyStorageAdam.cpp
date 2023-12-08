// Adam Rilatt
// 29 September 2023
// Database Project 1 -- Abstract Key-Value Storage -- Initialize, Create_KVS

#include <string>
#include <stdexcept>

#include "KeyStorage.h"
#include "FlatFileStorageDevice.h"

using std::string;

void KeyStorage::initialize(const string& directory_name) {

  // Attempt to create a StorageDevice at the specified location.
  // If anything goes wrong, the error will propagate on its own.
  // Around these parts, we fail often and we fail DESCRIPTIVELY,
  // daggummit.

  this->storage_device = new FlatFileStorageDevice(directory_name);
  
}

void KeyStorage::create_kvs(const string& name) {

  if (!this->storage_device)
    throw std::runtime_error("Cannot create KVS without first initialize()ing.");

  this->storage_device->create_location(name);
  
}