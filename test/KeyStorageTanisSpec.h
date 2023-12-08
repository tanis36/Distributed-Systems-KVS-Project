//
// Created by tanis on 9/28/2023.
//

#ifndef PROJECT_1_TEAM_1_KEYSTORAGETANISSPEC_H
#define PROJECT_1_TEAM_1_KEYSTORAGETANISSPEC_H

#include <iostream>
#include <functional>
#include <vector>

#include "../src/KeyStorage.h"
#include "../src/FlatFileStorageDevice.h"

using namespace std;

bool updates() {

    KeyStorage ks;

    ks.initialize("../test_kvs_dir");

    // Success-- we assume that a kvs has already been created.
    ks.update("update_test", "color", "yellow");

    // We are making the assumption that finds() works as it should.
    string val = ks.find("update_test", "color");

    if (val != "yellow") {
        cout << "update(): The value returned should have been 'yellow', but wasn't." << endl;
        return false;
    }

    // Failure-- update() should fail if the provided key is not found
    // in the named KVS.
    try {
        ks.update("update_test", "month", "july");
        cout << "update(): KVS should have failed to update a value, but didn't." << endl;
        return false;
    }

    catch (std::exception e) {
        // Expected result
    }

    return true;

}

bool finds() {

    KeyStorage ks;

    ks.initialize("../test_kvs_dir");

    // Success-- we assume that a kvs has already been created.
    string val = ks.find("find_test", "water");

    if (val != "bottle") {
        cout << "find(): The value returned should have been 'bottle', but wasn't." << endl;
        return false;
    }

    // Failure-- find() should fail if the provided key is not found
    // in the named KVS.
    try {
        string val2 = ks.find("find_test", "nonexistent");
        cout << "find(): KVS should have failed to return a value, but didn't." << endl;
        return false;
    }

    catch (std::exception e) {
        // Expected result
    }

    return true;

}

void run_KeyStorageTanis_spec() {

    vector<function<bool()>> tests = {
            updates,
            finds
    };

    for (auto t : tests) {
        if (!t()) {
            cout << "KeyStorageTanis test threw an error. Halting." << endl;
            return;
        }
    }

    cout << "All KeyStorageTanis tests were passed." << endl;

}

#endif
