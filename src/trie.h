#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_COUNTS_UPPER_LOWER 52

struct trie_node {
    struct trie_node *nodes[ALPHABET_COUNTS_UPPER_LOWER];
    char ch;
};

void trie_init(struct trie_node *root);

void trie_insert_str(const char *str);

void trie_delete_str(const char *str);

void trie_auto_compelete(const char *str);

void trie_release_all(struct trie_node *root);

#endif