#include "common.h"

#include <jni.h>

#define INT_A 0xFF000000
#define INT_B 0x00FF0000
#define INT_C 0x0000FF00
#define INT_D 0x000000FF

/**
 * 处理 java 报错
 * @param env
 */
void errorCatch(JNIEnv *env) {
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
}

/**
 * 截取子字符串生成 jstring 对象
 * @param env
 * @param buff
 * @param start
 * @param len
 * @return
 */
jbyteArray subString(JNIEnv *env, uint8_t *buff, int start, int len, jbyte **tmp) {
    *tmp = (jbyte *) malloc(len);
    memcpy(*tmp, buff + start, len);
//    print("ss", (unsigned char *)(*tmp), len);
    jbyteArray result = env->NewByteArray(len);
    env->SetByteArrayRegion(result, 0, len, *tmp);
    return result;
}

/**
 * 用来生成影藏魔鬼数字的函数，避免被编译器直接优化成明文
 * @param input
 * @return
 */
int getMagic(int input) {
    int a = (input & INT_A) >> 24;
    int b = (input & INT_B) >> 16;
    int c = (input & INT_C) >> 8;
    int d = (input & INT_D);
    int e = (d << 24) | (b << 16) | (c << 8)  | (a);// 顺序打乱一下，其实顺序无所谓
    int len = 0;
    int tmp = e;
    while (tmp > 0) {
        if (tmp & 0x1) {
            len++;
        }
        tmp >>= 1;
    }
    return len;
}

void char2Hex(char *inBuf, int inLen, char **outBuf, int *outLen) {
    *outLen = inLen * 2 + 1;
    *outBuf = (char *) malloc(*outLen);
    memset(*outBuf, 0, *outLen);
    int j = 0;
    for (int i = 0; i < inLen; ++i) {
        j += sprintf((*outBuf) + j, "%02x", (unsigned char)inBuf[i]);
    }
//    print("char2Hex outBuf:", (unsigned char *)*outBuf, 32);
    *outLen = inLen * 2;
}

void printHex(char m[], unsigned char *v, unsigned long n) {
    char *out = (char *) malloc(n * 2 + 1);
    memset(out, 0, n * 2 + 1);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        j += sprintf(out + j, "%02x", (unsigned char)v[i]);
    }
    LOGD("%s %s len:%d", m, out, j);
    free(out);
}

void print(char m[], unsigned char *v, unsigned long n) {
    char *out = (char *) malloc(n + 1);
    memset(out, 0, n + 1);
    memcpy(out, v, n);
    LOGD("%s %s len:%d", m, out, n);
    free(out);
}
