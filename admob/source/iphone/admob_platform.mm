/*
 * iphone-specific implementation of the admob extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "admob_internal.h"

s3eResult admobInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void admobTerminate_platform()
{
    // Add any platform-specific termination code here
}

s3eResult admob_initSmart_platform(const char* pub_id, int orientation, int x, int y, int w, int h)
{
    return S3E_RESULT_ERROR;
}

s3eResult admob_moveSmart_platform(int orientation, int x, int y, int w, int h)
{
    return S3E_RESULT_ERROR;
}

s3eResult admob_init_platform(const char* pub_id, int ad_type, int orientation, int x, int y)
{
    return S3E_RESULT_ERROR;
}

s3eResult admob_resize_platform(int ad_type)
{
    return S3E_RESULT_ERROR;
}

s3eResult admob_show_platform()
{
    return S3E_RESULT_ERROR;
}

s3eResult admob_refresh_platform()
{
    return S3E_RESULT_ERROR;
}

s3eResult admob_hide_platform()
{
    return S3E_RESULT_ERROR;
}

s3eResult admob_move_platform(int orientation, int x, int y)
{
    return S3E_RESULT_ERROR;
}

s3eResult admob_interestial_preload_platform(const char * pub_id)
{
    return S3E_RESULT_ERROR;
}

bool admob_interestial_isReady_platform()
{
    return false;
}

bool admob_interestial_isShown_platform()
{
    return false;
}

bool admob_interestial_wasShown_platform()
{
    return false;
}

bool admob_interestial_hasBeenUsed_platform()
{
    return false;
}

s3eResult admob_interestial_show_platform()
{
    return S3E_RESULT_ERROR;
}

s3eResult admob_interestial_hide_platform()
{
    return S3E_RESULT_ERROR;
}

bool admob_banner_isClicked_platform()
{
    return false;
}

bool admob_interestial_isClicked_platform()
{
    return false;
}
