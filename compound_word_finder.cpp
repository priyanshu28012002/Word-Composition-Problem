#include <bits/stdc++.h>
#include <cstring>
#include <unistd.h> 
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
};

bool sortAscending(const string &a, const string &b)
{
    return a.length() < b.length();
}
bool sortDecreasing(const string &a, const string &b)
{
    return a.length() > b.length();
}

bool isCompoundWord(const string &word, Trie *t, unordered_map<string, bool> &cache)
{
    if (word.empty())
    {
        return false;
    }

    if (cache.find(word) != cache.end())
    {
        return cache[word];
    }

    int n = word.size();
    bool isCompound = false;

    for (int i = 1; i <= n; i++)
    {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i, n - i);

        if (t->searchWord(prefix))
        {
            if (t->searchWord(suffix) || isCompoundWord(suffix, t, cache))
            {
                isCompound = true;
                break;
            }
        }
    }

    cache[word] = isCompound;
    return isCompound;
}


int main()
{
    auto start = chrono::high_resolution_clock::now();
    Trie *t = new Trie();
    string filename = "Input_02.txt";
    
    ifstream file(filename);

    if (!file)
    {
        cout << "Error: The file '" << filename << "' was not found." << endl;
        return 1;
    }

    // Store the whole file in vector
    vector<string> wordList;
    string word;
    while (file >> word)
    {
        wordList.push_back(word);
    }

    
    // Sort the word list according to the length of the word in descending order
    sort(wordList.begin(), wordList.end(), sortDecreasing);
    unordered_map<string, bool> cache; // Cache for storing compound word results
    for (const string &word : wordList)
    {
        t->insertWord(word);
    }
    // empty string for longest and shortest words
    string longestCompoundWord = "";
    string secondLongestCompoundWord = "";

    for (const string &word : wordList)
{
    if (isCompoundWord(word, t, cache))
    {
        if (word.length() > longestCompoundWord.length())
        {
            secondLongestCompoundWord = longestCompoundWord;
            longestCompoundWord = word;
        }
        else if (word.length() == longestCompoundWord.length() && word != longestCompoundWord)
        {
            secondLongestCompoundWord = word;
            //  break;   // if need shortest compound word use sortAscending 
        }
        else if (word.length() > secondLongestCompoundWord.length() && word != longestCompoundWord)
        {
            secondLongestCompoundWord = word;
          break ; // if longest and use sortDecreasing 
            
            
        }
    }
}

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    if (!longestCompoundWord.empty())
    {
        cout << "Longest Compounded Word: " << longestCompoundWord << endl;
    }
    else
    {
        cout << "No Longest Compounded Word is Present " << endl;
    }
    if (!secondLongestCompoundWord.empty())
    {
        cout << "Second Longest Compounded Word: " << secondLongestCompoundWord << endl;
    }
    else
    {
        cout << "NO Second Longest Compounded Word is Present  " << endl;
    }
    cout << "Time taken to process the input file: " << duration.count() << " milliseconds" << endl;

    return 0;
}