package com.lxzh123.ctrietree;

import java.util.ArrayList;
import java.util.List;

public class TrieTree {
    public static class TrieNode {
        int length;
        String category;
        String riskLevel;
        BSTree next;

        public TrieNode() {
            this.length = -1;
            this.category = null;
            this.riskLevel = null;
            this.next = new BSTree();
        }

        @Override
        public String toString() {
            return "TN{" +
                    "l=" + length +
                    ", c='" + category + '\'' +
                    ", rl='" + riskLevel + '\'' +
                    ", n=" + next +
                    '}';
        }


    }

    private TrieNode mTRoot;

    public TrieTree() {
        this.mTRoot = new TrieNode();
    }

    public void insert(String data, String category, String riskLevel) {
        TrieNode cur = mTRoot;
        char[] chs = data.toCharArray();
        int len = chs.length;
        for (int i = 0; i < len; i++) {
            char ch = chs[i];
            BSTree.BSTNode bNode = cur.next.findNode(ch);
            if (bNode != null) {
                cur = bNode.node;
            } else {
                TrieNode tNode = new TrieNode();
                bNode = cur.next.addNode(ch);
                bNode.node = tNode;
                cur = tNode;
            }
        }
        cur.length = len;
        cur.category = category;
        cur.riskLevel = riskLevel;
    }

    public List<ResultItem> search(String content) {
        List<ResultItem> resultList = new ArrayList<>();
        TrieNode cur;
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
                BSTree.BSTNode bNode = cur.next.findNode(ch);
                if (bNode != null) {
                    cur = bNode.node;
                    if (cur.length > 0) {
                        end = i + cur.length;
                        tmpResult.add(new ResultItem(content.substring(i, end), i, end, cur.category, cur.riskLevel));
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
