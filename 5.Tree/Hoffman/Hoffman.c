#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 512

// Huffman tree node
typedef struct Node {
    char ch;
    int freq;
    struct Node* left;
    struct Node* right;
} Node;

// Min-heap (priority queue) to store nodes
typedef struct MinHeap {
    int size;
    Node* array[MAX_TREE_NODES];
} MinHeap;

// Create a new node
Node* newNode(char ch, int freq) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Swap two nodes
void swapNodes(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

// Heapify at given index
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Build a min-heap
void buildMinHeap(MinHeap* heap) {
    int n = heap->size - 1;
    for (int i = (n-1)/2; i >= 0; i--)
        minHeapify(heap, i);
}

// Extract the min node from heap
Node* extractMin(MinHeap* heap) {
    Node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return temp;
}

// Insert a node into min-heap
void insertMinHeap(MinHeap* heap, Node* node) {
    heap->size++;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Check if node is leaf
int isLeaf(Node* node) {
    return !(node->left) && !(node->right);
}

// Create and build min heap from frequency array
MinHeap* createAndBuildMinHeap(int freq[], char chars[], int size) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;

    for (int i = 0; i < size; i++) {
        heap->array[i] = newNode(chars[i], freq[i]);
    }
    heap->size = size;
    buildMinHeap(heap);
    return heap;
}

// Recursive function to store Huffman codes in codes array
void printCodesUtil(Node* root, char* code, int top, char codes[256][256]) {
    if (root->left) {
        code[top] = '0';
        printCodesUtil(root->left, code, top + 1, codes);
    }
    if (root->right) {
        code[top] = '1';
        printCodesUtil(root->right, code, top + 1, codes);
    }

    // If leaf node, store the code string
    if (isLeaf(root)) {
        code[top] = '\0';
        strcpy(codes[(unsigned char)root->ch], code);
    }
}

// Build Huffman Tree and print codes
void buildHuffmanTree(char text[]) {
    int freq[256] = {0};

    int length = strlen(text);

    // Count frequency
    for (int i = 0; i < length; i++)
        freq[(unsigned char)text[i]]++;

    // Count unique chars
    int unique_chars = 0;
    char chars[256];
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            chars[unique_chars++] = (char)i;
        }
    }

    // Create min heap
    MinHeap* heap = createAndBuildMinHeap(freq, chars, unique_chars);

    // Iterate until only one node remains
    while (heap->size > 1) {
        Node* left = extractMin(heap);
        Node* right = extractMin(heap);

        Node* top = newNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(heap, top);
    }

    // Root of Huffman Tree
    Node* root = extractMin(heap);

    // Store codes here
    char codes[256][256] = {{0}};
    char code[256];
    printCodesUtil(root, code, 0, codes);

    // Print codes
    printf("Huffman Codes:\n");
    for (int i = 0; i < unique_chars; i++) {
        printf("%c: %s\n", chars[i], codes[(unsigned char)chars[i]]);
    }

    // Encode the text
    printf("\nEncoded string:\n");
    for (int i = 0; i < length; i++) {
        printf("%s", codes[(unsigned char)text[i]]);
    }
    printf("\n");

    // Decode the string
    printf("\nDecoded string:\n");
    Node* curr = root;
    for (int i = 0; i < length; i++) {
        curr = root;
        // Traverse the tree using code string
        char* code_str = codes[(unsigned char)text[i]];
        for (int j = 0; code_str[j]; j++) {
            if (code_str[j] == '0')
                curr = curr->left;
            else
                curr = curr->right;
        }
        printf("%c", curr->ch);
    }
    printf("\n");

    // Cleanup omitted for brevity
}

int main() {
    char text[] = "HUFFMAN";
    buildHuffmanTree(text);
    return 0;
}
