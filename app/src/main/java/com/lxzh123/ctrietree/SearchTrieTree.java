package com.lxzh123.ctrietree;

import com.lxzh123.ctrietree.base.BSTNode;
import com.lxzh123.ctrietree.base.BSTree;
import com.lxzh123.ctrietree.base.TrieNode;
import com.lxzh123.ctrietree.base.TrieTree;

import java.util.ArrayList;
import java.util.List;

public class SearchTrieTree extends TrieTree<String, ResultItem> {

    private TrieNode mTRoot;

    public SearchTrieTree() {
        this.mTRoot = new TrieNode<BSTree<TrieNodeData>>();
    }

    @Override
    public void insert(String data) {
        TrieNode<BSTree<TrieNodeData>> cur = mTRoot;
        char[] chs = data.toCharArray();
        int len = chs.length;
        for (int i = 0; i < len; i++) {
            char ch = chs[i];
            TrieNodeData nodeData = new TrieNodeData(ch);
            BSTNode<TrieNodeData> bNode = cur.next == null? null:cur.next.findItem(nodeData);
            if (bNode != null) {
                cur = bNode.value.node;
            } else {
                TrieNode tNode = new TrieNode();
                BSTNode<TrieNodeData> newNode = new BSTNode<>(nodeData);
                if(cur.next == null) {
                    cur.next = new BSTree();
                }
                bNode = cur.next.addItem(newNode);
                bNode.value.node = tNode;
                cur = tNode;
            }
        }
        cur.length = len;
    }

    @Override
    public List<ResultItem> search(String content) {
        List<ResultItem> resultList = new ArrayList<>();
        TrieNode<BSTree<TrieNodeData>> cur;
        int len = content.length();
        char ch;
        int i = 0;
        int end = 0;
        while (i < len) {
            cur = mTRoot;
            List<ResultItem> tmpResult = new ArrayList<>();
            String subStr = content.substring(i);
            int subLen = subStr.length();
            char[] chs = subStr.toCharArray();
            for (int j = 0; j < subLen; j++) {
                ch = chs[j];
                TrieNodeData nodeData = new TrieNodeData(ch);
                BSTNode<TrieNodeData> bNode = cur.next == null ? null : cur.next.findItem(nodeData);
                if (bNode != null) {
                    cur = bNode.value.node;
                    if (cur.length > 0) {
                        end = i + cur.length;
                        tmpResult.add(new ResultItem(content.substring(i, end), i, end));
                    }
                } else {
                    break;
                }
            }
            int size = tmpResult.size();
            if (size > 0) {
                resultList.add(tmpResult.get(size - 1));
            }
            i = Math.max(i + 1, end);
        }
        return resultList;
    }
}
