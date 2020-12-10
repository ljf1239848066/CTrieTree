package com.lxzh123.ctrietree;

import android.util.Log;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ResultBuilder {
    private String mContent;
    private List<ResultItem> mResults;

    public ResultBuilder(String content) {
        this.mContent = content;
        this.mResults = new ArrayList<>();
    }

    public void addResult(int start, int end, byte[] category, byte[] riskLevel) {
        Log.d("Geetest_Glance", "addResult start=" + start + " end=" + end);
        String keyword = mContent.substring(start, end);
        String cat = new String(category);
        String risk = new String(riskLevel);
        Log.d("Geetest_Glance", "addResult start=" + start + " end=" + end + " cat=" + cat + " risk=" + risk);
        ResultItem item = new ResultItem(keyword, start, end, cat, risk);
        mResults.add(item);
    }

    public List<ResultItem> getResults() {
        return mResults;
    }
}
