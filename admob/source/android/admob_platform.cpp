/*
 * android-specific implementation of the admob extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "admob_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_admob_init;
static jmethodID g_admob_initSmart;
static jmethodID g_admob_resize;
static jmethodID g_admob_show;
static jmethodID g_admob_refresh;
static jmethodID g_admob_hide;
static jmethodID g_admob_move;
static jmethodID g_admob_moveSmart;
static jmethodID g_admob_interestial_preload;
static jmethodID g_admob_interestial_isReady;
static jmethodID g_admob_interestial_isShown;
static jmethodID g_admob_interestial_wasShown;
static jmethodID g_admob_interestial_hasBeenUsed;
static jmethodID g_admob_interestial_show;
static jmethodID g_admob_interestial_hide;
static jmethodID g_admob_banner_isClicked;
static jmethodID g_admob_interestial_isClicked;

s3eResult admobInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("admob");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_admob_init = env->GetMethodID(cls, "admob_init", "(Ljava/lang/String;IIII)I");
    if (!g_admob_init)
        goto fail;

    g_admob_initSmart = env->GetMethodID(cls, "admob_initSmart", "(Ljava/lang/String;IIIII)I");
    if (!g_admob_initSmart)
        goto fail;

    g_admob_resize = env->GetMethodID(cls, "admob_resize", "(I)I");
    if (!g_admob_resize)
        goto fail;

    g_admob_show = env->GetMethodID(cls, "admob_show", "()I");
    if (!g_admob_show)
        goto fail;

    g_admob_refresh = env->GetMethodID(cls, "admob_refresh", "()I");
    if (!g_admob_refresh)
        goto fail;

    g_admob_hide = env->GetMethodID(cls, "admob_hide", "()I");
    if (!g_admob_hide)
        goto fail;

    g_admob_move = env->GetMethodID(cls, "admob_move", "(III)I");
    if (!g_admob_move)
        goto fail;

    g_admob_moveSmart = env->GetMethodID(cls, "admob_moveSmart", "(IIIII)I");
    if (!g_admob_moveSmart)
        goto fail;

    g_admob_interestial_preload = env->GetMethodID(cls, "admob_interestial_preload", "(Ljava/lang/String;)I");
    if (!g_admob_interestial_preload)
        goto fail;

    g_admob_interestial_isReady = env->GetMethodID(cls, "admob_interestial_isReady", "()Z");
    if (!g_admob_interestial_isReady)
        goto fail;

    g_admob_interestial_isShown = env->GetMethodID(cls, "admob_interestial_isShown", "()Z");
    if (!g_admob_interestial_isShown)
        goto fail;

    g_admob_interestial_wasShown = env->GetMethodID(cls, "admob_interestial_wasShown", "()Z");
    if (!g_admob_interestial_wasShown)
        goto fail;

    g_admob_interestial_hasBeenUsed = env->GetMethodID(cls, "admob_interestial_hasBeenUsed", "()Z");
    if (!g_admob_interestial_hasBeenUsed)
        goto fail;

    g_admob_interestial_show = env->GetMethodID(cls, "admob_interestial_show", "()I");
    if (!g_admob_interestial_show)
        goto fail;

    g_admob_interestial_hide = env->GetMethodID(cls, "admob_interestial_hide", "()I");
    if (!g_admob_interestial_hide)
        goto fail;

    g_admob_banner_isClicked = env->GetMethodID(cls, "admob_banner_isClicked", "()Z");
    if (!g_admob_banner_isClicked)
        goto fail;

    g_admob_interestial_isClicked = env->GetMethodID(cls, "admob_interestial_isClicked", "()Z");
    if (!g_admob_interestial_isClicked)
        goto fail;



    IwTrace(ADMOB, ("ADMOB init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(admob, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void admobTerminate_platform()
{
    // Add any platform-specific termination code here
}

s3eResult admob_init_platform(const char* pub_id, int ad_type, int orientation, int x, int y)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring pub_id_jstr = env->NewStringUTF(pub_id);
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_init, pub_id_jstr, ad_type, orientation, x, y);
}

s3eResult admob_initSmart_platform(const char* pub_id, int orientation, int x, int y, int w, int h)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring pub_id_jstr = env->NewStringUTF(pub_id);
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_initSmart, pub_id_jstr, orientation, x, y, w, h);
}

s3eResult admob_resize_platform(int ad_type)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_resize, ad_type);
}

s3eResult admob_show_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_show);
}

s3eResult admob_refresh_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_refresh);
}

s3eResult admob_hide_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_hide);
}

s3eResult admob_move_platform(int orientation, int x, int y)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_move, orientation, x, y);
}

s3eResult admob_moveSmart_platform(int orientation, int x, int y, int w, int h)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_moveSmart, orientation, x, y, w, h);
}

s3eResult admob_interestial_preload_platform(const char * pub_id)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring pub_id_jstr = env->NewStringUTF(pub_id);
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_interestial_preload, pub_id_jstr);
}

bool admob_interestial_isReady_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_admob_interestial_isReady);
}

bool admob_interestial_isShown_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_admob_interestial_isShown);
}

bool admob_interestial_wasShown_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_admob_interestial_wasShown);
}

bool admob_interestial_hasBeenUsed_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_admob_interestial_hasBeenUsed);
}

s3eResult admob_interestial_show_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_interestial_show);
}

s3eResult admob_interestial_hide_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_admob_interestial_hide);
}

bool admob_banner_isClicked_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_admob_banner_isClicked);
}

bool admob_interestial_isClicked_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_admob_interestial_isClicked);
}



