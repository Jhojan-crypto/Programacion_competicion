class TrieNode {
    constructor() {
        this.children = {};
        this.isEndOfWord = false;
    }
}

class Trie {
    constructor() {
        this.root = new TrieNode();
    }

    insert(word) {
        let current = this.root;
        for (let char of word) {
            if (!current.children[char]) {
                current.children[char] = new TrieNode();
            }
            current = current.children[char];
        }
        current.isEndOfWord = true;
    }

    autoComplete(prefix) {
        let current = this.root;
        for (let char of prefix) {
            if (!current.children[char]) {
                return [];
            }
            current = current.children[char];
        }
        return this.autoCompleteHelper(current, prefix);
    }

    autoCompleteHelper(node, currentPrefix) {
        let suggestions = [];
        if (node.isEndOfWord) {
            suggestions.push(currentPrefix);
        }
        for (let char in node.children) {
            suggestions = suggestions.concat(this.autoCompleteHelper(node.children[char], currentPrefix + char));
        }
        return suggestions;
    }
}
