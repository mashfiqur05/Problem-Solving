#include<bits/stdc++.h>
using namespace std;

struct Trie {
    struct node {
        node* nxt[10];
        bool isEnd;
        node() {
            for(int i = 0; i < 10; i++) nxt[i] = nullptr;
            isEnd = false;
        }
    }*root;

    Trie() { root = new node(); }

    bool insert(string& s) {
        node* cur = root;
        bool f = false;
        for(char c : s) {
            int b = c - '0';
            if(cur->nxt[b] == NULL) cur->nxt[b] = new node();
            cur = cur->nxt[b];
            if (cur->isEnd == true) f = true;
        }
        cur->isEnd = true;

        return f;
    }

    // checks if query string exists exactly OR is a prefix of any inserted string
    pair<bool,bool> query(string& s) {
        node* cur = root;
        for(char c : s) {
            int b = c - '0';
            if(cur->nxt[b] == NULL) return {false, false}; // doesn't exist at all
            cur = cur->nxt[b];
        }

        bool isExact  = cur->isEnd;         // exact match exists
        bool isPrefix = true;               // we reached here = it's a prefix
        return {isExact, isPrefix};
    }

    void clear(node* cur) {
        if(cur == nullptr) return;

        for(int i = 0; i < 10; i++)
            clear(cur->nxt[i]);

        delete cur;
    }

    ~Trie() {
        clear(root);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    for (int tt = 1; tt <= test; tt++)
    {
        cout << "Case " << tt << ": "; 
        Trie t;
        bool f = 0;
        int n;
        cin >> n;
        while (n--)
        {
            string s;
            cin >> s;
            auto [isExact, isPrefix] = t.query(s);
            if (isExact || isPrefix)
                f = 1;
            f |= t.insert(s);
        }

        if (!f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
