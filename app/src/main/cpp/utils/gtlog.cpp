#include "gtlog.h"

#include <jni.h>

#define I_LOGV(TAG, FORMAT, ...) while(1){__android_log_print(ANDROID_LOG_VERBOSE, TAG, FORMAT, ##__VA_ARGS__);break;};
#define I_LOGD(TAG, FORMAT, ...) while(1){__android_log_print(ANDROID_LOG_DEBUG,   TAG, FORMAT, ##__VA_ARGS__);break;};
#define I_LOGI(TAG, FORMAT, ...) while(1){__android_log_print(ANDROID_LOG_INFO,    TAG, FORMAT, ##__VA_ARGS__);break;};
#define I_LOGW(TAG, FORMAT, ...) while(1){__android_log_print(ANDROID_LOG_WARN,    TAG, FORMAT, ##__VA_ARGS__);break;};
#define I_LOGE(TAG, FORMAT, ...) while(1){__android_log_print(ANDROID_LOG_ERROR,   TAG, FORMAT, ##__VA_ARGS__);break;};

//#define LOG(LEVEL, TAG, FORMAT, ...) while(1) {__android_log_print(LEVEL, TAG, FORMAT, ##__VA_ARGS__);break;};

static int log_level = ANDROID_LOG_VERBOSE;
static char tag[100] = "Geetest_Glance";
static bool debug = true;
static bool print = false;

void setEnable(unsigned char  enable) {
    log_level = enable ? ANDROID_LOG_VERBOSE : ANDROID_LOG_FATAL;
}

void initLog(int level, const char *log_tag, int len, unsigned char enableDebug) {
    log_level = level;
    memcpy(tag, log_tag, len);
    debug = enableDebug;
}

void openPrint() {
    print = true;
}

void log(int level, const char *format, ...) {
    va_list args;
    va_start(args, format);
    __android_log_vprint(level, tag, format, args);
    va_end(args);
}

void dlog(int level, const char *format, ...) {
    va_list args;
    va_start(args, format);
#ifdef DEBUG
    if (debug) {
        __android_log_vprint(level, tag, format, args);
    }
#endif
    plog(level, tag, format, args);
    va_end(args);
}

void plog(int level, const char *format, ...) {
    if (print) {
        va_list args;
        va_start(args, format);
        __android_log_vprint(level, tag, format, args);
        va_end(args);
    }
}

void logv(const char *format, ...) {
    va_list args;
    va_start(args, format);
    if (log_level <= ANDROID_LOG_VERBOSE) {
        log(ANDROID_LOG_VERBOSE, format, args);
    }
    plog(ANDROID_LOG_VERBOSE, format, args);
    va_end(args);
}

void logd(const char *format, ...) {
    va_list args;
    va_start(args, format);
    if (log_level <= ANDROID_LOG_DEBUG) {
        log(ANDROID_LOG_DEBUG, format, args);
    }
    plog(ANDROID_LOG_DEBUG, format, args);
    va_end(args);
}

void logi(const char *format, ...) {
    va_list args;
    va_start(args, format);
    if (log_level <= ANDROID_LOG_INFO) {
        log(ANDROID_LOG_INFO, format, args);
    }
    plog(ANDROID_LOG_INFO, format, args);
    va_end(args);
}

void logw(const char *format, ...) {
    va_list args;
    va_start(args, format);
    if (log_level <= ANDROID_LOG_WARN) {
        log(ANDROID_LOG_WARN, format, args);
    }
    plog(ANDROID_LOG_WARN, format, args);
    va_end(args);
}

void loge(const char *format, ...) {
    va_list args;
    va_start(args, format);
    if (log_level <= ANDROID_LOG_ERROR) {
        log(ANDROID_LOG_ERROR, format, args);
    }
    plog(ANDROID_LOG_ERROR, format, args);
    va_end(args);
}
