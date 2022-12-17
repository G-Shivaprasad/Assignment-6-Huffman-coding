#include <iostream>
#include <queue>
#include <vector>
#include <string>

//Build a minheap

struct MinHeapNode {
  char content;
  unsigned int freq;
  MinHeapNode *left, *right;

  MinHeapNode(char content, unsigned int freq) {
    left = right = nullptr;
    this->content = content;
    this->freq = freq;
  }
};

struct compare {
  bool operator() (MinHeapNode* l, MinHeapNode* r) {
    return (l-> freq > r->freq);
  }
};

void print_codes(MinHeapNode* root, std::string str) {
  if (!root) return;

  if (root->content != '$')
    std::cout << root->content << ": " << str << "\n";

  print_codes(root->left, str + "0");
  print_codes(root->right, str + "1");
}

void huffman_codes(char data[], int freq[], int size) {
  MinHeapNode *left, *right, *top;
  std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> min_heap;

  for (int i = 0; i < size; i++) {
    min_heap.push( new MinHeapNode(data[i], freq[i]));
  }


  while (min_heap.size() != 1) {
    left = min_heap.top();
    min_heap.pop();

    right = min_heap.top();
    min_heap.pop();
    top = new MinHeapNode('$', left->freq + right->freq);
    top ->left = left;
    top->right = right;

    min_heap.push(top);
  }
  
  print_codes(min_heap.top(), "");
}

int main() {

  char arr[] = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};
  int freq[] = { 5, 9, 12, 13, 16, 45, 10, 6, 2, 8};

  int size = sizeof(arr) / sizeof(arr[0]);

  huffman_codes(arr, freq, size);
  return 0;
}
