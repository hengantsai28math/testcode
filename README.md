# testcode

## trie.cpp

A C++ implementation of a [Trie](https://en.wikipedia.org/wiki/Trie) (prefix tree) that answers prefix-search queries: given a prefix, return up to `k` matching words in lexicographic order.

### Build

```bash
g++ -O2 -o trie trie.cpp
```

### Input format

```
W
word_1
word_2
...
word_W
Q
prefix_1 k_1
prefix_2 k_2
...
prefix_Q k_Q
```

- `W` — number of words to insert into the trie
- `Q` — number of queries
- Each query is a prefix and an integer `k`; the program prints up to `k` words that start with that prefix, in lexicographic order (space-separated), or a blank line if none match

### Example

Input:

```
4
cat
car
card
dog
2
ca 2
do 5
```

Output:

```
car card
dog
```

### Notes

Words are assumed to be lowercase `a`–`z` only, since each trie node has 26 children indexed by `c - 'a'`.
