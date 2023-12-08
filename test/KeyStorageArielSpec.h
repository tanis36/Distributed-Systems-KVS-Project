//
// Created by seals on 9/28/2023.
//

#ifndef PROJECT_1_TEAM_1_KEYSTORAGEARIELSPEC_H
#define PROJECT_1_TEAM_1_KEYSTORAGEARIELSPEC_H

#include <iostream>
#include <functional>
#include <fstream>
#include <vector>

#include "../src/KeyStorage.h"


bool add_normal() {
    KeyStorage test;
    test.initialize("../test_kvs_dir");
    try{
        test.add("read_test","Obtuse" , "Rubber Goose");
        return true;
    }
    catch(std::exception e){
        std::cout << "1" << std::endl;
        return false;
    }

}

bool add_dupe() {
    KeyStorage test;
    test.initialize("../test_kvs_dir");
    try{
        test.add("read_test","Obtuse" , "Rubber Goose");
        std::cout << "2" << std::endl;
        return false;
    }
    catch(std::exception e){
        return true;
    }
}

bool add_file_dne() {
    KeyStorage test;
    test.initialize("../test_kvs_dir");
    try{
        test.add("dfljflkjflkj","Obtuse" , "Rubber Goose");
        std::cout << "3" << std::endl;
        return false;
    }
    catch(std::exception e){
        return true;
    }
}

bool remove_normal() {
    KeyStorage test;
    test.initialize("../test_kvs_dir");
    try{
        test.remove("read_test","Obtuse");
        return true;
    }
    catch(std::exception e){
        std::cout << "4" << std::endl;
        return false;
    }

}

bool remove_file_dne() {
    KeyStorage test;
    test.initialize("../test_kvs_dir");
    try{
        test.remove("fdhdfsdhgsd","Obtuse");
        std::cout << "5" << std::endl;
        return false;
    }
    catch(std::exception){
        return true;
    }
}

bool remove_key_dne() {
    KeyStorage test;
    test.initialize("../test_kvs_dir");
    try{
        test.remove("read_test","asfdfdsggggddg");
        return true;
    }
    catch(std::exception e){
        return false;
    }
}

void run_KeyStorageAriel_spec() {

    std::vector<std::function<bool()>> tests = {
            add_normal,
            add_dupe,
            add_file_dne,
            remove_normal,
            remove_file_dne,
            remove_key_dne
    };

    for (auto t : tests) {
        if (!t()) {
            std::cout << "KeyStorageArielSpec test threw an error. Halting." << std::endl;
            return;
        }
    }

    std::cout << "All KeyStorageArielSpec tests were passed." << std::endl;

}


#endif //PROJECT_1_TEAM_1_KEYSTORAGEARIELSPEC_H
