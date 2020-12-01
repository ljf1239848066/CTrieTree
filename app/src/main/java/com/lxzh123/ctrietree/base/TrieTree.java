package com.lxzh123.ctrietree.base;

import com.lxzh123.ctrietree.ResultItem;
import com.lxzh123.ctrietree.TrieNodeData;

import java.util.ArrayList;
import java.util.List;

public abstract class TrieTree<T, K> {

    public abstract void insert(T data);

    public abstract List<K> search(T data);
}
