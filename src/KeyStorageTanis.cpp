//
// Created by tanis on 9/25/2023.
//

#include <string>
#include <stdexcept>

#include "KeyStorage.h"
#include "FlatFileStorageDevice.h"

void KeyStorage::update(const std::string& name, const std::string& key, const std::string& value) {
    // Find the existing value for the key provided
    std::string existing_value = find(name, key);

    // update() will crash if find() does not return a value.
    // This means that either the key was not found or the
    // named KVS does not exist. We assume that find() works
    // correctly otherwise.

    // We can proceed to call write(), which will overwrite
    // the existing key with the new one (even though they are
    // the same, this acts as a way of updating the value while
    // keeping the "original" key).

    this->storage_device->write(name, key, value);
}

std::string KeyStorage::find(const std::string& name, const std::string& key) {
    // Search the KVS for the provided key
    std::string value = this->storage_device->read(name, key);

    // find() will crash if read() does not return a value,
    // meaning that the key was not found. We assume that
    // read() works correctly otherwise.

    // At this point, we can just return value.
    return value;
}