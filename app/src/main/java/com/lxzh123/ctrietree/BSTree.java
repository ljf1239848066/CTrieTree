package com.lxzh123.ctrietree;

public class BSTree {
    public static class BSTNode {
        char data;
        BSTNode left;
        BSTNode right;
        TrieTree.TrieNode node;

        public BSTNode(char data) {
            this.data = data;
            this.left = null;
            this.right = null;
            this.node = null;
        }

        public boolean hasLeft() {
            return this.left != null;
        }

        public boolean hasRight() {
            return this.right != null;
        }

        @Override
        public String toString() {
            return "" + data;
        }
    }

    BSTNode mRoot;

    public BSTree() {
//        this.mRoot = new BSTNode();
    }

    public BSTNode addNode(char value) {
        BSTNode node = new BSTNode(value);
        if (mRoot == null) {
            mRoot = node;
            return node;
        }
        BSTNode cur = mRoot;
        while (true) {
            if (value < cur.data) {
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

    public boolean hasNode(char value) {
        if (mRoot == null) {
            return false;
        }
        BSTNode cur = mRoot;
        while (true) {
            if (value == cur.data) {
                return true;
            } else if (value < cur.data) {
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

    public BSTNode findNode(char value) {
        if (mRoot == null) {
            return null;
        }
        BSTNode cur = mRoot;
        while (true) {
            if (value == cur.data) {
                return cur;
            } else if (value < cur.data) {
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
