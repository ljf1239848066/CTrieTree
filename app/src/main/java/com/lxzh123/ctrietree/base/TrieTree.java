package com.lxzh123.ctrietree.base;

import java.util.List;

public abstract class TrieTree<T, K> {

    public abstract void insert(T data);

    public abstract List<K> search(T data);
}
