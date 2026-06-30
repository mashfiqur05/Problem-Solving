#include<bits/stdc++.h>
using namespace std;

struct Trie {
    struct node {
        node* nxt[4];
        int cnt;
        node() {
            for(int i = 0; i < 4; i++) nxt[i] = NULL;
            cnt = 0;
        }
    }*root;

    Trie() { root = new node(); }
    int getId(char c) {
        if (c == 'A') return 0;
        if (c == 'C') return 1;
        if (c == 'G') return 2;
        return 3;
    }

    void insert(string& s) {
        node* cur = root;
        for(char c : s) {
            int b = getId(c);
            if(cur->nxt[b] == NULL) cur->nxt[b] = new node();
            cur = cur->nxt[b];
            cur->cnt++;
        }
    }

    int ans = 0;

    void dfs(node *cur, int depth)
    {
        ans = max(ans, depth * cur->cnt);

        for (int i = 0; i < 4; i++)
        {
            if (cur->nxt[i])
            {
                dfs(cur->nxt[i], depth + 1);
            }
        }
    }

    void clear(node* cur) {
        if(cur == nullptr) return;

        for(int i = 0; i < 4; i++)
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

    int test; cin >> test;

    for (int tt = 1; tt <= test; tt++)
    {
        Trie t;
        int n; cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s; cin >> s;
            t.insert (s);
        }

        t.dfs (t.root, 0);

        cout << "Case " << tt << ": " << t.ans << endl;
    }


    return 0;
}
