package com.lxzh123.ctrietree;

import android.content.Context;

public class Native {
    static {
        System.loadLibrary("TrieTree");
    }

    public static native void init(Context context);

    public static native long ttInit(Context context);

    public static native void ttInsert(long handle, Context context, String content);

    public static native void ttSearch(long handle, Context context, String content, Object builder);

    public static String newString(byte[] bytes) {
        String rst = new String(bytes);
        return rst;
    }
}
