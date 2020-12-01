package com.lxzh123.ctrietree.base;

public interface IContainer<T, K extends Comparable> {
    T addItem(T item);
    boolean hasItem(T item);
    T findItem(K data);
}
