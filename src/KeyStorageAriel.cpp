#include <iostream>
#include <stdexcept>
#include "KeyStorage.h"
#include "StorageDevice.h"


void KeyStorage::add(const std::string& name,const std::string& key,const std::string& value){
    bool key_found = false;
    try{
        auto str = this->storage_device->read(name, key);
        key_found = true;
        throw std::runtime_error("Error: Key already has assigned value. Use update().");
    }
    catch(std::exception e) {
        if (key_found)
            throw e;
        else {
            this->storage_device->write(name, key, value);
        }
    }
}

void KeyStorage::remove(const std::string& name,const std::string& key){
    this->storage_device->remove(name, key);
}
