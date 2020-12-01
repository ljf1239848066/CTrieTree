package com.lxzh123.ctrietree;

import com.lxzh123.ctrietree.base.TrieNode;

public class TrieNodeData implements Comparable<TrieNodeData> {
    char data;
    TrieNode node;

    public TrieNodeData(char data) {
        this.data = data;
    }

    @Override
    public int compareTo(TrieNodeData o) {
        TrieNodeData tmp = (TrieNodeData) o;
        if (data < tmp.data) {
            return -1;
        } else if (data == tmp.data) {
            return 0;
        } else {
            return 1;
        }
    }
}
