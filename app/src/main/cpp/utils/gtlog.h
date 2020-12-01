/**
 * description 公共日志模块
 * author      Created by lxzh
 * date        2020/10/19
 */
#ifndef __GEETEST_GLANCE_LOG_H__
#define __GEETEST_GLANCE_LOG_H__

#include <jni.h>
#include <android/log.h>
#include <string.h>
#include <stdlib.h>


#define TAG "Geetest_Glance"
#define LOG_LEVEL ANDROID_LOG_VERBOSE

#ifdef DEBUG
#define LOGV(FORMAT, ...) while(1){if(LOG_LEVEL<=ANDROID_LOG_VERBOSE){__android_log_print(ANDROID_LOG_VERBOSE, TAG, FORMAT, ##__VA_ARGS__);}break;};
#define LOGD(FORMAT, ...) while(1){if(LOG_LEVEL<=ANDROID_LOG_DEBUG){__android_log_print(ANDROID_LOG_DEBUG, TAG, FORMAT, ##__VA_ARGS__);}break;};
#define LOGI(FORMAT, ...) while(1){if(LOG_LEVEL<=ANDROID_LOG_INFO){__android_log_print(ANDROID_LOG_INFO, TAG, FORMAT, ##__VA_ARGS__);}break;};
#define LOGW(FORMAT, ...) while(1){if(LOG_LEVEL<=ANDROID_LOG_WARN){__android_log_print(ANDROID_LOG_WARN, TAG, FORMAT, ##__VA_ARGS__);}break;};
#define LOGE(FORMAT, ...) while(1){if(LOG_LEVEL<=ANDROID_LOG_ERROR){__android_log_print(ANDROID_LOG_ERROR, TAG, FORMAT, ##__VA_ARGS__);}break;};

#define DLOGV(FORMAT, ...) LOGV(FORMAT, ##__VA_ARGS__)
#define DLOGD(FORMAT, ...) LOGD(FORMAT, ##__VA_ARGS__)
#define DLOGI(FORMAT, ...) LOGI(FORMAT, ##__VA_ARGS__)
#define DLOGW(FORMAT, ...) LOGW(FORMAT, ##__VA_ARGS__)
#define DLOGE(FORMAT, ...) LOGE(FORMAT, ##__VA_ARGS__)

#define PLOGV(FORMAT, ...) LOGV(FORMAT, ##__VA_ARGS__)
#define PLOGD(FORMAT, ...) LOGD(FORMAT, ##__VA_ARGS__)
#define PLOGI(FORMAT, ...) LOGI(FORMAT, ##__VA_ARGS__)
#define PLOGW(FORMAT, ...) LOGW(FORMAT, ##__VA_ARGS__)
#define PLOGE(FORMAT, ...) LOGE(FORMAT, ##__VA_ARGS__)
#else
#define LOGV(FORMAT, ...)   log(ANDROID_LOG_VERBOSE, FORMAT, ##__VA_ARGS__)
#define LOGD(FORMAT, ...)   log(ANDROID_LOG_DEBUG,   FORMAT, ##__VA_ARGS__)
#define LOGI(FORMAT, ...)   log(ANDROID_LOG_INFO,    FORMAT, ##__VA_ARGS__)
#define LOGW(FORMAT, ...)   log(ANDROID_LOG_WARN,    FORMAT, ##__VA_ARGS__)
#define LOGE(FORMAT, ...)   log(ANDROID_LOG_ERROR,   FORMAT, ##__VA_ARGS__)

#define DLOGV(FORMAT, ...) dlog(ANDROID_LOG_VERBOSE, FORMAT, ##__VA_ARGS__)
#define DLOGD(FORMAT, ...) dlog(ANDROID_LOG_DEBUG,   FORMAT, ##__VA_ARGS__)
#define DLOGI(FORMAT, ...) dlog(ANDROID_LOG_INFO,    FORMAT, ##__VA_ARGS__)
#define DLOGW(FORMAT, ...) dlog(ANDROID_LOG_WARN,    FORMAT, ##__VA_ARGS__)
#define DLOGE(FORMAT, ...) dlog(ANDROID_LOG_ERROR,   FORMAT, ##__VA_ARGS__)

#define PLOGV(FORMAT, ...) plog(ANDROID_LOG_VERBOSE, FORMAT, ##__VA_ARGS__)
#define PLOGD(FORMAT, ...) plog(ANDROID_LOG_DEBUG,   FORMAT, ##__VA_ARGS__)
#define PLOGI(FORMAT, ...) plog(ANDROID_LOG_INFO,    FORMAT, ##__VA_ARGS__)
#define PLOGW(FORMAT, ...) plog(ANDROID_LOG_WARN,    FORMAT, ##__VA_ARGS__)
#define PLOGE(FORMAT, ...) plog(ANDROID_LOG_ERROR,   FORMAT, ##__VA_ARGS__)
#endif

void log(int level, const char *format, ...);
void dlog(int level, const char *format, ...);
void plog(int level, const char *format, ...);

//static int log_level = ANDROID_LOG_VERBOSE;
//static char log_tag[100] = "Geetest_Glance";
//static bool debug = true;

void setEnable(unsigned char  enable);

void initLog(int level, const char* tag, int len, unsigned char enableDebug);

void openPrint();

void logv(const char *format, ...);
void logd(const char *format, ...);
void logi(const char *format, ...);
void logw(const char *format, ...);
void loge(const char *format, ...);

void errorCatch(JNIEnv *env);

#endif //__GEETEST_GLANCE_LOG_H__
