# Huffman Coding in Preorder Traversal

## Overview
This project implements Huffman coding in **C++** to generate Huffman codes based on character frequencies. The program then prints the Huffman codes in **preorder traversal** of the Huffman tree.

## How Huffman Coding Works
Huffman coding is a **greedy algorithm** that assigns variable-length binary codes to characters, ensuring that no code is a prefix of another. This is useful for data compression.

### **Steps Involved:**
1. Construct a **min-heap priority queue** of nodes based on character frequencies.
2. Repeatedly remove the two nodes with the lowest frequency and combine them into a new node.
3. Assign `0` to the left branch and `1` to the right branch.
4. Store the Huffman codes for each character.
5. Perform a **preorder traversal** (root → left → right) to print the Huffman codes.
#Input and Output
#Example Input

#string S = "abcdef";
vector<int> f = {5, 9, 12, 13, 16, 45};
#Expected Output

0 100 101 1100 1101 111
#Explanation
#Huffman codes generated:


f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
#The preorder traversal of the Huffman tree prints them in the order above.
