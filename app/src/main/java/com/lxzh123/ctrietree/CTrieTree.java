package com.lxzh123.ctrietree;

import android.content.Context;

import java.util.ArrayList;
import java.util.List;

public class CTrieTree {
    private Context mContext;
    private long tHandle;

    public CTrieTree(Context context) {
        mContext = context;
        tHandle = Native.ttInit(context);
    }

    public void insert(String content) {
        Native.ttInsert(tHandle, mContext, content);
    }

    public List<ResultItem> search(String content) {
        ResultBuilder builder = new ResultBuilder(content);
        Native.ttSearch(tHandle, mContext, content, builder);
        List<ResultItem> resultItems = builder.getResults();
//        int len = result.length;
//        int start, end;
//        for (int i = 0; i < len - 1; i += 2) {
//            start = result[i];
//            end = result[i + 1];
//            if (start >= 0 && end > start) {
//                resultItems.add(new ResultItem(content.substring(start, end), start, end));
//            }
//        }
        return resultItems;
    }
}
