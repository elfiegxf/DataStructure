
## Grep Search Engine
- This program implements the simple version of grep command on the Unix.
- Acknowledgements for the textbook: Data Structure and Algorithm Analysis in C++ by  Mark Allen Weiss. Also Google.
- hashTable.h.(.cpp) implement the hash table. Indexfunction.h(.cpp) index all the words of the files in the directory using two ways, one is the case sensitive, another is the case insensitive. Searchfunctnion.h(.cpp) search the keyword in the directory. gerp.cpp makes the pieces a whole program.
- Compile by option 1: clang++ -Wall -std=c++11 -Wextra; or by option 2: simply MAKE
- Use hashing to index all the words of the files in the directory. In order to implement two modes, the case sensitive and the case insensitive, I index them using two hash tables.
The table will record the target and the locations(which are int indexes of file and line). One uses the original words, another processes all the words into lowercase and then index them. The hash table is implemented by the vector, and each entry of the table is implemented by another vector. Each element is a HashedObj including a target and a vector recorded all the locations the target appears.

