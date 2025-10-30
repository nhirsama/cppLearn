//
// Created by ling on 2025/10/30.
//
#include <bits/stdc++.h>

struct huffman {
    char ch;
    int freq;
    huffman *left, *right;

    huffman(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {
    }

    ~huffman() {
        delete left;
        delete right;
    }

    void build(const std::string& s) const {
        if (this->ch != '\0') {
            std::cout << ch << ':' << s << '\n';
        }
        if (this->left != nullptr) this->left->build(s + "0");

        if (this->right != nullptr) this->right->build(s + "1");
    }

    void build() const {
        if (this->left != nullptr) this->left->build("0");

        if (this->right != nullptr) this->right->build("1");
    }
};

int main() {
    std::string s;
    std::cin >> s;
    std::map<char, int> mp;
    for (auto i: s) {
        mp[i]++;
    }
    std::priority_queue<huffman *, std::vector<huffman *>, decltype([](huffman *a, huffman *b) {
        return a->freq > b->freq;
    })> pq;
    for (auto &[x,y]: mp) {
        pq.push(new huffman(x, y));
    }
    while (pq.size() > 1) {
        huffman *left = pq.top();
        pq.pop();
        huffman *right = pq.top();
        pq.pop();
        huffman *parent = new huffman('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    huffman *root = pq.top();
    pq.pop();
    root->build();
    delete root;
}
