package com.lxzh123.ctrietree;

import android.content.Context;

public class Native {
    static {
        System.loadLibrary("TrieTree");
    }

    public static native void init(Context context);
}
