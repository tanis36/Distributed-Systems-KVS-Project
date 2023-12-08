# Distributed-Systems-KVS-Project
A project for a Distributed Systems class that implements a persistent key value store as a C++ library.

This library exposes a small set of functions that a client program will use to create and manage a named KVS:

- **initialize(directory_name)** -- initialize the KVS. The parameter is the name of a filesystem folder where the persistent data for our named KVS's is to be found. If the folder doesn't exist, we will create it (failing if we cannot).
- **create_kvs(name)** -- this function takes a string and creates a new KVS with the specified name. Fails if the KVS cannot be created (e.g., it already exists, or the name isn't legal for some reason).
- **add(name, key, value)** -- call this to add the key/value pair to the named KVS. For simplicity, everything is a std::string. Fails if the key is already present or the name doesn't exist.
- **remove(name, key)** -- deletes the key/value pair with the given key from the named KVS. Does nothing if the key doesn't exist. Fails if the named KVS doesn't exist.
- **update(name, key, value)** -- replace the value associated with a given key. Fails if the KVS or key does not exist.
- **find(name, key)** -- returns a copy of the value associated with the given key. Fails if the KVS or key does not exist.
