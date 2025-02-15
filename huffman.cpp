#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparison function for priority queue (min-heap)
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq; // Min heap
    }
};

// Function to generate Huffman codes and store them in a map
void generateHuffmanCodes(Node* root, string code, unordered_map<char, string> &huffmanCode) {
    if (!root) return;

    // If leaf node, store code
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCode);
    generateHuffmanCodes(root->right, code + "1", huffmanCode);
}

// Function to print Huffman codes in preorder traversal
void preorderTraversal(Node* root, unordered_map<char, string> &huffmanCode) {
    if (!root) return;

    // Print the Huffman code if it’s a leaf node
    if (!root->left && !root->right) {
        cout << huffmanCode[root->ch] << " ";
    }

    preorderTraversal(root->left, huffmanCode);
    preorderTraversal(root->right, huffmanCode);
}

// Function to build Huffman tree and print Huffman codes in preorder
void buildHuffmanTree(string S, vector<int> f) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create nodes for each character and push to priority queue
    for (int i = 0; i < S.length(); i++) {
        pq.push(new Node(S[i], f[i]));
    }

    // Construct Huffman tree
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Get the root of the Huffman Tree
    Node* root = pq.top();

    // Store Huffman codes
    unordered_map<char, string> huffmanCode;
    generateHuffmanCodes(root, "", huffmanCode);

    // Print Huffman codes in preorder traversal
    preorderTraversal(root, huffmanCode);
    cout << endl;
}

// Driver code
int main() {
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};

    buildHuffmanTree(S, f);
    return 0;
}
