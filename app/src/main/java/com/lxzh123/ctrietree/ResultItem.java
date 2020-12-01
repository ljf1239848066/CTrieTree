package com.lxzh123.ctrietree;

/**
 * description 字典树、正则匹配查找结果, 包含分类、等级
 * 内部使用
 * author      Created by lxzh
 * date        2020-09-04
 */
public class ResultItem {
    private String keyword;
    private String category;
    private String riskLevel;
    private int start;
    private int end;

    public String getKeyword() {
        return keyword;
    }

    public void setKeyword(String keyword) {
        this.keyword = keyword;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public String getRiskLevel() {
        return riskLevel;
    }

    public void setRiskLevel(String riskLevel) {
        this.riskLevel = riskLevel;
    }

    public int getStart() {
        return start;
    }

    public void setStart(int start) {
        this.start = start;
    }

    public int getEnd() {
        return end;
    }

    public void setEnd(int end) {
        this.end = end;
    }

    public ResultItem(String keyword, int start, int end) {
        this.keyword = keyword;
        this.start = start;
        this.end = end;
    }

    public ResultItem(String keyword, int start, int end, String category, String riskLevel) {
        this.keyword = keyword;
        this.start = start;
        this.end = end;
        this.category = category;
        this.riskLevel = riskLevel;
    }

    @Override
    public String toString() {
        return "RI{" +
                "kw='" + keyword + '\'' +
                ", s=" + start +
                ", e=" + end +
                ", c=" + category +
                ", rl=" + riskLevel +
                '}';
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof ResultItem) {
            ResultItem rl = (ResultItem) obj;
            return start == rl.start && end == rl.end;
        } else {
            return false;
        }
    }

    @Override
    public int hashCode() {
        long value = (((long) start) << 32) | end;
        return (int) (value ^ (value >>> 32));
    }
}
