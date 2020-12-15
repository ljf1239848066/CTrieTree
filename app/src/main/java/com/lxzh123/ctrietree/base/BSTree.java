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
        BSTNode cur = mRoot;
        int cmp;
        while (cur != null && (cmp = data.compareTo(cur.value)) != 0) {
            if (cmp < 0) {
                cur = cur.left;
            } else {
                cur = cur.right;
            }
        }
        return cur;
    }

    @Override
    public String toString() {
        return "BSTree{" +
                "root=" + mRoot +
                '}';
    }
}
