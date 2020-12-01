/**
 * description 公共模块
 * author      Created by lxzh
 * date        2020/10/15
 */
#ifndef __GEETEST_GLANCE_COMMON_H__
#define __GEETEST_GLANCE_COMMON_H__

#include <jni.h>
#include <android/log.h>
#include <string.h>

#include "gtlog.h"

#define GT_OK   (0)
#define GT_ERR  (-1)

#ifndef i8
typedef signed char        i8;
#endif
#ifndef i16
typedef short              i16;
#endif
#ifndef i32
typedef int                i32;
#endif
#ifndef i64
typedef long long          i64;
#endif
#ifndef u8
typedef unsigned char      u8;
#endif
#ifndef u16
typedef unsigned short     u16;
#endif
#ifndef u32
typedef unsigned int       u32;
#endif
#ifndef u64
typedef unsigned long long u64;
#endif

void errorCatch(JNIEnv *env);
jbyteArray subString(JNIEnv *env, uint8_t *buff, int start, int len, jbyte **tmp);
int getMagic(int input);
void char2Hex(char *inBuf, int inLen, char **outBuf, int *outLen);
void printHex(char m[], unsigned char *v, unsigned long n);
void print(char m[], unsigned char *v, unsigned long n);

#endif //__GEETEST_GLANCE_COMMON_H__
