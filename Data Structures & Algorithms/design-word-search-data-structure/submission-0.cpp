struct Node{
    Node* links[26];
    bool flag;

    Node() : flag(false) {
        for (int i = 0; i < 26; ++i) links[i] = nullptr;   // init pointers
    }

    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* transfer(char ch){
        return links[ch - 'a'];
    }
    void setEnd() { 
        flag = true; 
    }

    // Fix: use node->links, guard nulls, and handle last char correctly
    bool searchWord(Node* node, char ch, std::string word){
        if (!node) return false;

        if (ch != '.') {
            if (!node->containsKey(ch)) return false;
            Node* next = node->links[ch - 'a'];
            if (word.empty()) return next && next->flag;     // last char
            return searchWord(next, word[0], word.substr(1));
        } else {
            for (int i = 0; i < 26; ++i) {
                Node* next = node->links[i];
                if (!next) continue;
                if (word.empty()) {                           // last char = '.'
                    if (next->flag) return true;
                } else if (searchWord(next, word[0], word.substr(1))) {
                    return true;
                }
            }
            return false;
        }
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(std::string word) {
        Node* node = root;
        for (int i = 0; i < (int)word.size(); i++){
            if (!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->transfer(word[i]);
        }
        node->setEnd();
    }
    
    bool search(std::string word) {
        if (word.empty()) return false; // optional safety guard
        return root->searchWord(root, word[0], word.substr(1));
    }
};
