# Priyanshu Srivastava

# Compound Word Finder


This is a program designed to find the longest and second-longest compound words from a list of words in a given text file. The program uses a trie data structure and dynamic programming with caching to efficiently identify compound words.


## Design Decisions
- Trie Data Structure: We utilize a trie data structure for storing and searching words.

- Dynamic Programming with Caching: A caching mechanism is used to store the results of previous compound word checks, which avoids redundant computations and improves overall performance.

- We use isCompoundWord function to breakdown the word into prefix and suffix. This function also uses trie to search for Compound words from a list.
## Approach
1. Read Input File: The program reads a list of words from an input file and stores them in a vector called wordList.

2. Sort by Length: The wordList is sorted in descending order of word lengths, enabling efficient compound word checks without the need for sorting during processing.

3. Trie Insertion: The sorted wordList is inserted into a trie data structure. The trie structure helps in fast word retrieval and searching.

4. Searching for Compound Words: The core logic of identifying compound words is implemented in the isCompoundWord function. This function breaks down a word into prefixes and suffixes and utilizes the trie structure to determine if both parts exist in the list of words, indicating a compound word.

5. Caching Mechanism: The program uses a caching mechanism to store and reuse the results of previous compound word checks. This prevents redundant computations, which enhances the program's efficiency.

6. Longest and Second-Longest Search: After processing all words, the program identifies the longest and second-longest compound words based on their lengths.
## Steps to Execute The code

To run Code, run the following command on terminal or cmd 

1. Compile the Code: Open a terminal and navigate to the directory containing the source code and compile the code. 

```bash
 gcc compound_word_finder.cpp
```
2. Run the compiled program: To compile a C++ program, use a command 
```bash
./compound_word_finder
```
## Output of sample files


### First file Output

Longest Compounded Word: ratcatdogcat

Second Longest Compounded Word: catsdogcats

Time taken to process the input file: 0 milliseconds

### Second file Output


Longest Compounded Word: ethylenediaminetetraacetates

Second Longest Compounded Word: ethylenediaminetetraacetate

Time taken to process the input file: 188 milliseconds

## Authors

- [@Priyanshu Srivastava ](https://github.com/priyanshu28012002)
