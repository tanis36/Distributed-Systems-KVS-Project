// Adam Rilatt, Ariel Montalvo, Tanis Kay
// 14 September 2023
// Distributed Project 1 -- Main

#include "../test/FlatFileStorageDeviceSpec.h"
#include "../test/KeyStorageAdamSpec.h"
#include "../test/KeyStorageArielSpec.h"
#include "../test/KeyStorageTanisSpec.h"


int main() {

  /*
  When the project is complete, we won't include main.cpp; in other words, we
  won't have a main() function. This is because we're writing a LIBRARY for
  later use, so we'll just import our built library into whatever code we're
  working on.

  During development and testing, we use main() to run tests. I've included an
  example of what that looks like for the StorageDevice stuff. I include the
  FlatFileStorageDeviceSpec.h file above. In that file, there are several
  testing functions (reads(), writes(), removes(), etc.), and there is one
  function called run_FlatFileStorageDevice_spec() which runs all of the tests
  until one fails. I then call this function from main() to test my code:
  */
  run_FlatFileStorageDevice_spec();
  /*
  Comment out this line of code to not run these tests.
  */

  /*
  We will all write similar test functions for our work. For example, my test
  file will be KeyStorageAdamSpec.h, and it will contain a
  run_KeyStorageAdam_spec() function that tests the initialize() and
  create_location() functions that I'm implementing. I'll run my tests by
  uncommenting the following line:
  */
  run_KeyStorageAdam_spec();

  /*
  Similarly, everyone else will uncomment the line corresponding to their file
  (change the function name if you want):
  */
  run_KeyStorageAriel_spec();
  run_KeyStorageTanis_spec();
  
}
