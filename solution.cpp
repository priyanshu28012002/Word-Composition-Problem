#include <bits/stdc++.h>
#include <cstring> // For the strerror function
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

bool isCompoundWord(const string &word, Trie *t)
{
    if (word.empty())
    {
        return false;
    }

    int n = word.size();
    for (int i = 1; i <= n; i++)
    {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i, n - i);

        if (t->searchWord(prefix))
        {
            if (t->searchWord(suffix) || isCompoundWord(suffix, t))
            {
                return true;
            }
        }
    }

    return false;
}
// Function to convert path separators to match the platform
void convertPathToPlatformStyle(std::string& path) {
    for (char& character : path) {
        if (character == '/' || character == '\\') {
            character = '/'; // Use forward slash for compatibility
        }
    }
}
int main()
{
    auto start = chrono::high_resolution_clock::now();
    Trie *t = new Trie();
    char cwd[1024]; // Create a character array to store the current working directory
    string fullFilePath,filename;
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        filename = "Input_02.txt"; // Your file name

        // Combine cwd and filename to create the full file path
         fullFilePath = std::string(cwd) + "/" + filename;

        // Convert the file path to match the platform style
        convertPathToPlatformStyle(fullFilePath);

        // std::cout << "Full File Path: " << fullFilePath << std::endl;
    }
    // } else {
    //     std::cerr << "Error getting current working directory: " << std::strerror(errno) << std::endl;
    // }

   // cout<<fullFilePath<<endl;
    ifstream file(fullFilePath);

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
    for (const string &word : wordList)
    {
        t->insertWord(word);
    }
    // empty string for longest and shortest words
    string longestCompoundWord = "";
    string secondLongestCompoundWord = "";

    for (const string &word : wordList)
    {
        if (isCompoundWord(word, t))
        {
            // compoundedWords.push_back(word);
            if (longestCompoundWord.empty())
            {
                longestCompoundWord = word;
            }
            else if (word.length() == longestCompoundWord.length())
            {
                // If two words have the same length, the second one becomes the second longest
                secondLongestCompoundWord = word;
            }
            else
            {
                // Update the second longest only if the length is different from the longest
                secondLongestCompoundWord = word;
                break; // No need to continue
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
