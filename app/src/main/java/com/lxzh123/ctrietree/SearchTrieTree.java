package com.lxzh123.ctrietree;

import android.util.Log;

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
        TrieNode<BSTree<TrieNodeData>> current = mTRoot;
        char[] chs = data.toCharArray();
        int len = chs.length;
        for (int i = 0; i < len; i++) {
            char ch = chs[i];
            TrieNodeData nodeData = new TrieNodeData(ch);
            BSTNode<TrieNodeData> bNode = current.next == null ? null : current.next.findItem(nodeData);
            if (bNode != null) {
                current = bNode.value.pNext;
            } else {
                TrieNode tmpNode = new TrieNode();
                BSTNode<TrieNodeData> newNode = new BSTNode<>(nodeData);
                if (current.next == null) {
                    current.next = new BSTree();
                }
                bNode = current.next.addItem(newNode);
                bNode.value.pNext = tmpNode;
                current = tmpNode;
            }
        }
        current.length = len;
    }

    @Override
    public List<ResultItem> search(String content) {
        List<ResultItem> resultList = new ArrayList<>();
        TrieNode<BSTree<TrieNodeData>> cur;
        int len = content.length();
        char ch;
        int i = 0;
        int end = 0;
        Log.d("Geetest_Glance", "searchDictionary jlen:" + len);
        while (i < len) {
            cur = mTRoot;
            List<ResultItem> tmpResult = new ArrayList<>();
            String subStr = content.substring(i);
            int subLen = subStr.length();
            char[] chs = subStr.toCharArray();
            Log.d("Geetest_Glance", "searchDictionary i:" + i + " sub:" + (int) chs[0] + " " + chs[0]);
            for (int j = 0; j < subLen; j++) {
                ch = chs[j];
                Log.d("Geetest_Glance", "searchDictionary j:" + j + " ch:" + (int) ch + " " + ch);
                TrieNodeData nodeData = new TrieNodeData(ch);
                BSTNode<TrieNodeData> bNode = cur.next == null ? null : cur.next.findItem(nodeData);
                Log.d("Geetest_Glance", "searchDictionary j:" + j + " ch:" + ch + " findNode:" + (bNode != null ? 1 : 0));
                if (bNode != null) {
                    cur = bNode.value.pNext;
                    if (cur.length > 0) {
                        Log.d("Geetest_Glance", "searchDictionary j:" + j + " ch:" + ch + " tmp->length:" +  cur.length);
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
