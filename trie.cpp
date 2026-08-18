#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

// insert 接收 root 參數,不再依賴全域變數
void insert(TrieNode* root, const string& s) {
    TrieNode* cur = root;
    for (char c : s) {
        int idx = c - 'a';
        if (!cur->child[idx]) cur->child[idx] = new TrieNode();
        cur = cur->child[idx];
    }
    cur->isEnd = true;
}

// DFS 依字典序收集最多 k 個單字
void dfs(TrieNode* node, string& path, int k, vector<string>& result) {
    if ((int)result.size() >= k) return;

    if (node->isEnd) {
        result.push_back(path);
        if ((int)result.size() >= k) return;
    }

    for (int i = 0; i < 26; i++) {
        if (node->child[i]) {
            path.push_back('a' + i);
            dfs(node->child[i], path, k, result);
            path.pop_back();
            if ((int)result.size() >= k) return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // root 是 main() 裡的區域變數
    TrieNode* root = new TrieNode();

    int W;
    cin >> W;
    for (int i = 0; i < W; i++) {
        string w;
        cin >> w;
        insert(root, w);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        string p;
        int k;
        cin >> p >> k;

        // 找到 prefix 對應的節點
        TrieNode* cur = root;
        bool ok = true;
        for (char c : p) {
            int idx = c - 'a';
            if (!cur->child[idx]) {
                ok = false;
                break;
            }
            cur = cur->child[idx];
        }

        vector<string> result;
        if (ok) {
            string path = p;
            dfs(cur, path, k, result);
        }

        // 輸出
        if (result.empty()) {
            cout << "\n";
        } else {
            for (int i = 0; i < (int)result.size(); i++) {
                cout << result[i];
                if (i + 1 != (int)result.size()) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}