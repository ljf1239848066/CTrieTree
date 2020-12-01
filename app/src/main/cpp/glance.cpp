#include "glance.h"
#include "utils/common.h"
#include "utils/gtlog.h"
#include "trietree.h"

#include <string.h>

#define JNIREG_CLASS "com/lxzh123/ctrietree/Native"// 指定要注册的类

int gSdkInt = 0;
static jboolean PERMISSION;

/**
 *  init
 * @param env
 * @param clazz
 * @param context
 */
JNIEXPORT void JNICALL
a(JNIEnv *env, jclass clazz, jobject context) {
//    LOGI("[+] init start");
    PLOGI("[+] i s");
//    TrieNode *root = NULL;
//    buildDictionary(&root);
//    addDictionary(&root, "百度", "哈哈");
//    addDictionary(&root, "家", "哈哈");
//    addDictionary(&root, "家家", "哈哈");
//    addDictionary(&root, "高科技", "哈哈");
//    addDictionary(&root, "技公", "哈哈");
//    addDictionary(&root, "科技", "哈哈");
//    addDictionary(&root, "科技公司", "哈哈");

//    char *rst = searchDictionary(&root, "百度是家高科技公司");
//    PLOGI("[+] i s search rst:%s", rst);
}

JNIEXPORT void JNICALL
f(JNIEnv *env, jclass clazz, jint level, jstring tag, jboolean openDebug) {
    const char *logtag = env->GetStringUTFChars(tag, NULL);
    int len = strlen(logtag);
    initLog(level, logtag, len, openDebug);
    env->ReleaseStringUTFChars(tag, logtag);
    env->DeleteLocalRef(tag);
}

JNIEXPORT void JNICALL
g(JNIEnv *env, jclass clazz) {
    openPrint();
}

static JNINativeMethod gMethods[] = {
        {"init", "(Landroid/content/Context;)V",                    (void *) a}/*,
        {"il",   "(ILjava/lang/String;Z)V",                         (void *) f},
        {"op",   "()V",                                             (void *) g}*/
};

int jniRegisterNativeMethods(JNIEnv *env, const char *className, const JNINativeMethod *gMethods,
                             int numMethods) {
    PLOGI("[+] register");
    jclass clazz;
    clazz = env->FindClass(className);
    if (NULL == clazz) {
        return -1;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        PLOGI("[-] register failed");
        return -1;
    }
    return 0;
}

void initJni(JNIEnv *env) {
    PLOGI("[+] init");
    jclass VersionClass = env->FindClass("android/os/Build$VERSION");
    jfieldID SDK_INT = env->GetStaticFieldID(VersionClass, "SDK_INT", "I");

    gSdkInt = env->GetStaticIntField(VersionClass, SDK_INT);
    PLOGI("[+] init sdk_int:%d", gSdkInt);

    jniRegisterNativeMethods(env, JNIREG_CLASS, gMethods, NELEM(gMethods));
    env->DeleteLocalRef(VersionClass);
}

JNIEXPORT int JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    PLOGI("[+] JNI_OnLoad");
    JNIEnv *env;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    initJni(env);
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    PLOGI("[+] JNI_OnUnload");
}