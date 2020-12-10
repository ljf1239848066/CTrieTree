package com.lxzh123.ctrietree;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.lxzh123.ctrietree.base.TrieTree;

import java.util.List;

public class MainActivity extends AppCompatActivity {
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.test).setOnClickListener(v->{
            Native.init(this);
            testCTrieTree();
        });
        testTTree();
    }

    private void testTTree() {
        Log.d("Geetest_Glance", "java start");
        TrieTree trieTree = new SearchTrieTree();
        trieTree.insert("百度");
        trieTree.insert("家");
        trieTree.insert("家家");
        trieTree.insert("高科技");
        trieTree.insert("技公");
        trieTree.insert("科技");
        trieTree.insert("科技公司");

        List<ResultItem> itemList = trieTree.search("百度是家高科技公司");
        int size = itemList.size();
        for (int i = 0; i < size; i++) {
            Log.d("Geetest_Glance", "i=" + i + " item=" + itemList.get(i));
        }
        Log.d("Geetest_Glance", "java end");
    }

    private void testCTrieTree() {
        Log.d("Geetest_Glance", "java->c start");
        CTrieTree trieTree = new CTrieTree(getApplicationContext());
        trieTree.insert("百度");
        trieTree.insert("家");
        trieTree.insert("家家");
        trieTree.insert("高科技");
        trieTree.insert("技公");
        trieTree.insert("科技");
        trieTree.insert("科技公司");
        List<ResultItem> itemList = trieTree.search("百度是家高科技公司");
        int size = itemList.size();
        for (int i = 0; i < size; i++) {
            Log.d("Geetest_Glance", "i=" + i + " item=" + itemList.get(i));
        }
        Log.d("Geetest_Glance", "java->c end");
    }
}