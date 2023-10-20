# Priyanshu Srivastava
---
---
---

# Compound Word Finder


The Compound Word Finder is a C++ program designed to find the longest and second-longest compound words from a list of words in a given text file. The program employs a trie data structure and dynamic programming with caching to efficiently identify compound words. This README provides an overview of the program, design decisions, and steps to execute it.


## Design Decisions
- Trie Data Structure: We utilize a trie (prefix tree) data structure for storing and searching words. Tries are efficient for word storage and retrieval.

- Dynamic Programming with Caching: To determine if a word is a compound word, the program uses dynamic programming to break down the word into prefixes and suffixes. Additionally, a caching mechanism is used to store the results of previous compound word checks, avoiding redundant computations and improving performance.

- Longest and Second-Longest Search: The program searches for the longest and second-longest compound words without the need to sort the word list, ensuring quick results, even for large lists of words.
## Approach
1. Read Input File: The program reads a list of words from an input file and stores them in a vector called wordList.

2. Sort by Length: The wordList is sorted in descending order of word lengths, enabling efficient compound word checks without the need for sorting during processing.

3. Trie Insertion: The sorted wordList is inserted into a trie data structure. The trie structure aids in fast word retrieval and searching.

4. Searching for Compound Words: The core logic of identifying compound words is implemented in the isCompoundWord function. This function breaks down a word into prefixes and suffixes and utilizes the trie structure to determine if both parts exist in the list of words, indicating a compound word.

5. Caching Mechanism: The program uses a caching mechanism to store and reuse the results of previous compound word checks. This prevents redundant computations, further enhancing the program's efficiency.

6. Longest and Second-Longest Search: After processing all words, the program identifies the longest and second-longest compound words based on their lengths.
## Steps to Execute The code

To run Code, run the following command on terminal or cmd 

1. Compile the Code: Open a terminal and navigate to the directory containing the source code. Compile the code using a C++ compiler. 
For example:
```bash
 gcc compound_word_finder.cpp or g++ compound_word_finder.cpp
```
2. Run the compiled program: To compile a C++ program, use a command 
```bash
./compound_word_finder
```


## Authors

- [@Priyanshu Srivastava ](https://github.com/priyanshu28012002)
