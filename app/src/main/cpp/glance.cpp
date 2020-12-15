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
    TrieNode *root = NULL;
    makeNode(&root);
    PLOGI("[+] i s 1");
    addDictionary1(env, &root, "百度", "哈哈", "");
    PLOGI("[+] i s 2");
    addDictionary1(env, &root, "家", "哈哈", "");
    addDictionary1(env, &root, "家家", "哈哈", "");
    addDictionary1(env, &root, "高科技", "哈哈", "");
    addDictionary1(env, &root, "技公", "哈哈", "");
    addDictionary1(env, &root, "科技", "哈哈", "");
    addDictionary1(env, &root, "科技公司", "哈哈", "");
    PLOGI("[+] i s 3");
    searchDictionary1(env, root, "百度是家高科技公司");
    PLOGI("[+] i s search finished");
}

JNIEXPORT jlong JNICALL
ttInit(JNIEnv *env, jclass clazz, jobject context) {
    TrieNode *root = NULL;
    makeNode(&root);
    return (jlong) root;
}

JNIEXPORT void JNICALL
ttInsert(JNIEnv *env, jclass clazz, jlong handle, jobject context, jstring content) {
    TrieNode *root = (TrieNode *) handle;
    const jchar *jchs = env->GetStringChars(content, NULL);
    int jlen = env->GetStringLength(content);
    addDictionary(env, &root, jchs, jlen, "哈哈", "呵呵");
}

JNIEXPORT void JNICALL
ttSearch(JNIEnv *env, jclass clazz, jlong handle, jobject context, jstring content,
         jobject builder) {
    LOGD("ttSearch 1");
    TrieNode *root = (TrieNode *) handle;
    const jchar *jchs = env->GetStringChars(content, NULL);
    int jlen = env->GetStringLength(content);
    ResultList *resultList = searchDictionary(env, root, jchs, jlen);
    if (resultList == NULL) {
        return;
    }
    LOGD("ttSearch 2");
    jclass builderClass = env->GetObjectClass(builder);
    jmethodID addMethod = env->GetMethodID(builderClass, "addResult", "(II[B[B)V");
    if (addMethod == NULL) {
        LOGE("ttSearch 2, addMethod is NULL");
        return;
    }
    ResultList *tmp = NULL;
    LOGD("ttSearch 3 builder:%p addMethod:%p", builder, addMethod);
    while (resultList != NULL) {
        SearchResult *result = resultList->result;
        if (result == NULL) {
            break;
        }
        int lenCat = strlen(result->category);
        int lenRisk = strlen(result->riskLevel);
        LOGD("ttSearch 3->1 result:%p lenCat:%d lenRisk:%d", result, lenCat, lenRisk);
        jbyte *tmpCat = (jbyte *) malloc(lenCat);
        jbyte *tmpRisk = (jbyte *) malloc(lenRisk);
        memcpy(tmpCat, result->category, lenCat);
        memcpy(tmpRisk, result->riskLevel, lenRisk);
        jbyteArray category = env->NewByteArray(lenCat);
        jbyteArray riskLevel = env->NewByteArray(lenRisk);
        env->SetByteArrayRegion(category, 0, lenCat, tmpCat);
        env->SetByteArrayRegion(riskLevel, 0, lenRisk, tmpRisk);
        LOGD("ttSearch 3->2 start:%d end:%d category:%s riskLevel:%s", result->start, result->end,
             result->category, result->riskLevel);
        LOGD("ttSearch 3->2 category:%p riskLevel:%p", category, riskLevel);
        env->CallVoidMethod(builder, addMethod, result->start, result->end, category, riskLevel);
        LOGD("ttSearch 3->3");
        env->ReleaseByteArrayElements(category, tmpCat, JNI_ABORT);
        env->ReleaseByteArrayElements(riskLevel, tmpRisk, JNI_ABORT);
        LOGD("ttSearch 3->4");
        env->DeleteLocalRef(category);
        env->DeleteLocalRef(riskLevel);
        LOGD("ttSearch 3->5");
        tmp = resultList;
        resultList = resultList->next;
        free(tmp->result);
        tmp->next = NULL;
        tmp->result = NULL;
        LOGD("ttSearch 3->6");
    }
    env->DeleteLocalRef(builderClass);
    LOGD("ttSearch 4");
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
        {"init",     "(Landroid/content/Context;)V",                                      (void *) a},
        {"ttInit",   "(Landroid/content/Context;)J",                                      (void *) ttInit},
        {"ttInsert", "(JLandroid/content/Context;Ljava/lang/String;)V",                   (void *) ttInsert},
        {"ttSearch", "(JLandroid/content/Context;Ljava/lang/String;Ljava/lang/Object;)V", (void *) ttSearch}
        /*,{"il",   "(ILjava/lang/String;Z)V",                         (void *) f},
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