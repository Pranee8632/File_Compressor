 //Header Guards to prevent header files from being included multiple times
#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//Defining Huffman Tree Node
struct Node {
    char data;
    unsigned freq;
    string code;
    Node *left, *right;

    Node() {
        left = right = NULL;
    }
};

class huffman {
    private:
        vector <Node*> arr;

        fstream inFile, outFile;

        string inFileName, outFileName;
        
        Node *root;
        
        class Compare {
            public:
                bool operator() (Node* l, Node* r)
                {
                    return l->freq > r->freq;
                }
        };
//If the frequency of the left node (l) is greater than the frequency of the right node (r), the function returns true.
//This means that in the context of a priority queue, the node with the higher frequency will have lower priority and will be placed behind the node with the lower frequency.

        priority_queue <Node*, vector<Node*>, Compare> minHeap;
        
//Node*: This indicates that the elements in the priority queue are pointers to Node objects. Using pointers allows efficient management of dynamically allocated memory.
//vector<Node*>: This specifies the underlying container for the priority queue. In this case, a vector is used to store the pointers. The vector is a dynamic array that can resize itself as needed.
//Compare: This is a custom comparison class (defined elsewhere in your code) that determines the ordering of the elements in the priority queue.
        
        //Initializing a vector of tree nodes representing character's ascii value and initializing its frequency with 0
        void createArr();
        
        //Traversing the constructed tree to generate huffman codes of each present character
        void traverse(Node*, string);
        
        //Function to convert binary string to its equivalent decimal value
        int binToDec(string);
        
        //Function to convert a decimal number to its equivalent binary string
        string decToBin(int);
        
        //Reconstructing the Huffman tree while Decoding the file
        void buildTree(char, string&);

        //Creating Min Heap of Nodes by frequency of characters in the input file
        void createMinHeap();
        
        //Constructing the Huffman tree
        void createTree();
        
        //Generating Huffman codes
        void createCodes();
        
        //Saving Huffman Encoded File
        void saveEncodedFile();
        
        //Saving Decoded File to obtain the original File
        void saveDecodedFile();
        
        //Reading the file to reconstruct the Huffman tree
        void getTree();

    public:
        //Constructor
        huffman(string inFileName, string outFileName)
        {
            this->inFileName = inFileName;
            this->outFileName = outFileName;
            createArr();
        }
        //Compressing input file
        void compress();
        //Decrompressing input file
        void decompress();
};
#endif
