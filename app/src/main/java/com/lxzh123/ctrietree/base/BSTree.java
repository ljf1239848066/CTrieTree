package com.lxzh123.ctrietree.base;

public class BSTree<T extends Comparable> implements IContainer<BSTNode, T> {
    BSTNode mRoot;

    public BSTree() {
        this.mRoot = null;
    }

    @Override
    public BSTNode addItem(BSTNode node) {
        if (mRoot == null) {
            mRoot = node;
            return node;
        }
        BSTNode cur = mRoot;
        while (true) {
            if (node.value.compareTo(cur.value) < 0) {
                if (cur.hasLeft()) {
                    cur = cur.left;
                } else {
                    cur.left = node;
                    break;
                }
            } else {
                if (cur.hasRight()) {
                    cur = cur.right;
                } else {
                    cur.right = node;
                    break;
                }
            }
        }
        return node;
    }

    @Override
    public boolean hasItem(BSTNode node) {
        if (mRoot == null) {
            return false;
        }
        BSTNode cur = mRoot;
        while (true) {
            int c = node.value.compareTo(cur.value);
            if (c == 0) {
                return true;
            } else if (c < 0) {
                if (cur.hasLeft()) {
                    cur = cur.left;
                } else {
                    return false;
                }
            } else {
                if (cur.hasRight()) {
                    cur = cur.right;
                } else {
                    return false;
                }
            }
        }
    }

    @Override
    public BSTNode findItem(T data) {
        if (mRoot == null) {
            return null;
        }
        BSTNode cur = mRoot;
        while (true) {
            int c = data.compareTo(cur.value);
            if (c == 0) {
                return cur;
            } else if (c < 0) {
                if (cur.hasLeft()) {
                    cur = cur.left;
                } else {
                    return null;
                }
            } else {
                if (cur.hasRight()) {
                    cur = cur.right;
                } else {
                    return null;
                }
            }
        }
    }

    @Override
    public String toString() {
        return "BSTree{" +
                "root=" + mRoot +
                '}';
    }
}
