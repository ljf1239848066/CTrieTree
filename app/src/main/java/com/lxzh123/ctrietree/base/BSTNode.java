package com.lxzh123.ctrietree.base;

public class BSTNode<T extends Comparable> {
    public BSTNode left;
    public BSTNode right;
    public T value;

    public BSTNode(T value) {
        this.left = null;
        this.right = null;
        this.value = value;
    }

    public boolean hasLeft() {
        return this.left != null;
    }

    public boolean hasRight() {
        return this.right != null;
    }

    @Override
    public String toString() {
        return value == null ? "null" : value.toString();
    }
}
