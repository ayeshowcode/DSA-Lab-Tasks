#include <iostream>
#include<cstring>
using namespace std;

#define ALPHABET_SIZE 26 
#define MAX_PATTERNS 100 
#define MAX_LENGTH 100   
#define MAX_NODES 1000   
struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE]; 
    TrieNode *fail;                  
    int output[MAX_PATTERNS];       
    int outputCount;                 

    TrieNode()
    {
        fail = nullptr;
        outputCount = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = nullptr;
        }
        for (int i = 0; i < MAX_PATTERNS; i++)
        {
            output[i] = -1;
        }
    }
};

TrieNode *bfsQueue[MAX_NODES];
int bfsQueueFront = 0, bfsQueueBack = 0;

TrieNode *createNode()
{
    return new TrieNode();
}

// Insert patterns into the Trie
void insertPattern(TrieNode *root, const char *pattern, int index)
{
    TrieNode *current = root;
    for (int i = 0; pattern[i] != '\0'; i++)
    {
        int charIndex = pattern[i] - 'A'; 
        if (!current->children[charIndex])
        {
            current->children[charIndex] = createNode();
        }
        current = current->children[charIndex];
    }
    current->output[current->outputCount++] = index;
}


void buildAutomaton(TrieNode *root)
{
    // Initialize the BFS queue
    bfsQueueFront = bfsQueueBack = 0;

    root->fail = root;

    // Add root's children to the queue
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            root->children[i]->fail = root;
            bfsQueue[bfsQueueBack++] = root->children[i];
        }
        else
        {
            root->children[i] = root; 
        }
    }

    
    while (bfsQueueFront < bfsQueueBack)
    {
        TrieNode *current = bfsQueue[bfsQueueFront++];

        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            TrieNode *child = current->children[i];
            if (child)
            {
                TrieNode *fail = current->fail;

                while (!fail->children[i])
                {
                    fail = fail->fail;
                }

                child->fail = fail->children[i];

                TrieNode *failNode = child->fail;
                for (int j = 0; j < failNode->outputCount; j++)
                {
                    child->output[child->outputCount++] = failNode->output[j];
                }

                bfsQueue[bfsQueueBack++] = child;
            }
        }
    }
}


void searchPatterns(const char *text, TrieNode *root, const char patterns[MAX_PATTERNS][MAX_LENGTH], int patternCount)
{
    TrieNode *current = root;
    int i = 0;

    while (text[i] != '\0')
    {
        int charIndex = text[i] - 'A'; 

        while (!current->children[charIndex])
        {
            current = current->fail;
        }

        current = current->children[charIndex];

        for (int j = 0; j < current->outputCount; j++)
        {
            int patternIndex = current->output[j];
            int startIndex = i - strlen(patterns[patternIndex]) + 1;
            cout << "Pattern \"" << patterns[patternIndex] << "\" found at index " << startIndex << endl;
        }

        i++;
    }
}

int stringLength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int main()
{
    const char text[] = "ABCDEFG";                                  
    const char patterns[MAX_PATTERNS][MAX_LENGTH] = {"ABC", "EFG"}; 

    int patternCount = 2; 

    TrieNode *root = createNode();

    for (int i = 0; i < patternCount; i++)
    {
        insertPattern(root, patterns[i], i);
    }

    buildAutomaton(root);

    searchPatterns(text, root, patterns, patternCount);

    return 0;
}