/**
 * Description: Prefix tree
 * Time: Both operations are O(string length).
 */

struct Trie {
    struct Node {
        Node* child[26];
        int exist, cnt;

        Node() {
            for (int i = 0; i < 26; i++) child[i] = NULL;
            exist = cnt = 0;
        }
    };

    int cur;
    Node* root;
    Trie() : cur(0) {
        root = new Node();
    };

    void add_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == NULL) p->child[c] = new Node();
            p = p->child[c];
            p->cnt++;
        }
        p->exist++;
    }

    bool delete_string_recursive(Node* p, string& s, int i) {
        if (i != (int)s.size()) {
            int c = s[i] - 'a';
            bool isChildDeleted = delete_string_recursive(p->child[c], s, i + 1);
            if (isChildDeleted) p->child[c] = NULL;
        }
        else p->exist--;

        if (p != root) {
            p->cnt--;
            if (p->cnt == 0) {
                delete(p); 
                return true;
            }
        }
        return false;
    }

    void delete_string(string s) {
        if (find_string(s) == false) return;

        delete_string_recursive(root, s, 0);
    }

    bool find_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == NULL) return false;
            p = p->child[c];
        }
        return (p->exist != 0);
    }

    void dfs(Node* p, string& cur_string, vector<string>& res) {
        for (int i = 0; i < 26; i++) {
            if (p->child[i] != NULL) {
                cur_string += char(i + 'a');
                dfs(p->child[i], cur_string, res);
                cur_string.pop_back();
            }
        }
    }

    vector<string> sorted_strings() {
        vector<string> res;
        string current_string = "";
        dfs(0, current_string, res);
        return res;
    }
};
