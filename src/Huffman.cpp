//
// Created by ling on 2025/10/30.
//
#include <bits/stdc++.h>

// 哈夫曼树，使用 build 方法可以打印出每个符号的编码
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

    void build(const std::string &s) const {
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

// 二叉堆，可在 O(logn) 的时间复杂度和 O(n) 的空间复杂度内取出 freq 最小的一个元素

struct priority_queue {
private:
    std::vector<huffman *> data;

    bool comp(int i, int parent) {
        if (data[i]->freq == data[parent]->freq) {
            if (flag) {
                return data[i]->ch < data[parent]->ch;
            } else {
                return data[i]->ch > data[parent]->ch;
            }
        }
        return data[i]->freq < data[parent]->freq;
    }

    void up(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (comp(i, parent)) {
                std::swap(data[i], data[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void down(int i) {
        int n = data.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && comp(left, largest)) {
                largest = left;
            }
            if (right < n && comp(right, largest)) {
                largest = right;
            }
            if (largest != i) {
                std::swap(data[i], data[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

public:
    bool flag;

    priority_queue(bool flag) : flag(flag) {
    }

    void push(huffman *huffman) {
        data.push_back(huffman);
        up(data.size() - 1);
    }

    huffman *pop() {
        if (data.empty()) return nullptr;
        std::swap(data[0], data[data.size() - 1]);
        huffman *maxNode = data.back();
        data.pop_back();
        down(0);
        return maxNode;
    }

    huffman *top() {
        if (data.empty()) return nullptr;
        return data[0];
    }

    int size() {
        return data.size();
    }
};

// 总体时间复杂度为O(nlogn) 空间复杂度为 O(n)
int main() {
    std::string s;
    std::cin >> s;
    //当频率相同时有限将ascii码大的置后
    for (auto f:{true,false}) {
        std::map<char, int> mp;
        for (auto i: s) {
            mp[i]++;
        }
        priority_queue pq(f);
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
        std::cout<<std::endl;
    }
}
