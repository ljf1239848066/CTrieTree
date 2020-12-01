package com.lxzh123.ctrietree.base;

public class TrieNode<T extends IContainer> {
    public int length;
    public T next;
    public Object extraInfo;

    public TrieNode() {
        this.length = -1;
        this.next = null;
        this.extraInfo = null;
    }
}