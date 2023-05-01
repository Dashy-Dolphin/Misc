#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int depth;
    map<char, node *> children;
};

class trie
{
public:
    node *root;
    int leaves;
    trie()
    {
        root = new node();
        root->depth = 0;
        leaves = 0;
    }

    void insert(char *word, int k)
    {
        node *curr = root;
        for (int i = 0; i < k; i++)
        {
            if (curr->children.find(word[i]) == curr->children.end())
            {
                leaves += i == (k - 1);
                node *newNode = new node();
                newNode->depth = curr->depth + 1;
                curr->children[word[i]] = newNode;
            }
            curr = curr->children[word[i]];
        }
    }

    void print(int k)
    {
        cout << "The total number of k-mers are: " << leaves << "\n";
        char word[k + 2] = "";

        stack<node *> dfs_stack;
        stack<char> word_stack;
        dfs_stack.push(root);
        word_stack.push('\t');

        while (!dfs_stack.empty())
        {
            auto top = dfs_stack.top();
            dfs_stack.pop();

            auto top_word = word_stack.top();
            word_stack.pop();

            word[top->depth] = top_word;

            // iterate over children
            if (top->depth == k)
            {
                cout << word << "\n";
            }
            else
            {
                for (auto it = top->children.rbegin(); it != top->children.rend(); it++)
                {
                    dfs_stack.push(it->second);
                    word_stack.push(it->first);
                }
            }
        }
    }
};

int main()
{
    int n;
    // cout << "Enter the length of sequence: ";
    // cin >> n;

    string sequ;
    cout << "Enter the sequence: ";
    cin >> sequ;

    n = sequ.length();
    char sequence[n];
    strcpy(sequence, sequ.c_str());

    trie t;

    int k;
    cout << "Length of the above sequence is " << n << "\n";
    cout << "Enter the value of k to find the k-mers of above sequence : ";
    cin >> k;

    assert(k <= n);
    for (int i = 0; i <= n - k; i++)
    {
        t.insert(sequence + i, k);
    }

    t.print(k);
}