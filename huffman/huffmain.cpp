#include <iostream>
#include <string>
using namespace std;

#define VAL 20

class HuffmanNode
{
public:
    char ch;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

class minHeap
{
    HuffmanNode *heap[VAL];
    int heapSize;
    string codes[VAL];
    char chars[VAL];
    int codeCount;

public:
    minHeap() : heapSize(0), codeCount(0) {}

    void insertNode(HuffmanNode *node);
    HuffmanNode *removeMin();
    void minHeapify(int i);
    int lchild(int i) { return (2 * i + 1); }
    int rchild(int i) { return (2 * i + 2); }
    int parent(int i) { return (i - 1) / 2; }

    void generateCodes(HuffmanNode *root, string code);
    string getEncodedString(const string &input);
    string getDecodedString(const string &encodedString, HuffmanNode *root);
    void printCodes();

    void getFrequencies(const string &input, char freqChars[], int freq[], int &uniqueCount);
    int size() const { return heapSize; }
};

void minHeap::insertNode(HuffmanNode *node)
{
    if (heapSize == VAL)
    {
        cout << "Heap overflow" << endl;
        return;
    }
    heap[heapSize] = node;
    int i = heapSize++;

    while (i != 0 && heap[parent(i)]->freq > heap[i]->freq)
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

HuffmanNode *minHeap::removeMin()
{
    if (heapSize <= 0)
        return nullptr;

    if (heapSize == 1)
        return heap[--heapSize];

    HuffmanNode *root = heap[0];
    heap[0] = heap[--heapSize];
    minHeapify(0);
    return root;
}

void minHeap::minHeapify(int i)
{
    int l = lchild(i);
    int r = rchild(i);
    int smallest = i;

    if (l < heapSize && heap[l]->freq < heap[smallest]->freq)
        smallest = l;
    if (r < heapSize && heap[r]->freq < heap[smallest]->freq)
        smallest = r;
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        minHeapify(smallest);
    }
}

void minHeap::generateCodes(HuffmanNode *root, string code)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        codes[codeCount] = code;
        chars[codeCount] = root->ch;
        codeCount++;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

string minHeap::getEncodedString(const string &input)
{
    string encodedString = "";
    for (char ch : input)
    {
        for (int i = 0; i < codeCount; i++)
        {
            if (chars[i] == ch)
            {
                encodedString += codes[i];
                break;
            }
        }
    }
    return encodedString;
}

string minHeap::getDecodedString(const string &encodedString, HuffmanNode *root)
{
    string decodedString = "";
    HuffmanNode *current = root;
    for (char bit : encodedString)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (!current->left && !current->right)
        {
            decodedString += current->ch;
            current = root;
        }
    }
    return decodedString;
}

void minHeap::printCodes()
{
    cout << "Huffman Codes:\n";
    for (int i = 0; i < codeCount; i++)
    {
        cout << chars[i] << ": " << codes[i] << endl;
    }
}

void minHeap::getFrequencies(const string &input, char freqChars[], int freq[], int &uniqueCount)
{
    int charCount[256] = {0};
    uniqueCount = 0;

    for (char ch : input)
    {
        charCount[ch]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (charCount[i] > 0)
        {
            freqChars[uniqueCount] = (char)i;
            freq[uniqueCount] = charCount[i];
            uniqueCount++;
        }
    }
}

int main()
{
    string text = "AYESH";
    char freqChars[VAL];
    int freq[VAL];
    int uniqueCount;

    minHeap heap;
    heap.getFrequencies(text, freqChars, freq, uniqueCount);

    for (int i = 0; i < uniqueCount; i++)
    {
        heap.insertNode(new HuffmanNode(freqChars[i], freq[i]));
    }

    while (heap.size() > 1)
    {
        HuffmanNode *left = heap.removeMin();
        HuffmanNode *right = heap.removeMin();
        HuffmanNode *combined = new HuffmanNode('\0', left->freq + right->freq);
        combined->left = left;
        combined->right = right;
        heap.insertNode(combined);
    }

    HuffmanNode *root = heap.removeMin();
    heap.generateCodes(root, "");
    heap.printCodes();

    string encodedString = heap.getEncodedString(text);
    cout << "Encoded string: " << encodedString << endl;

    string decodedString = heap.getDecodedString(encodedString, root);
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}