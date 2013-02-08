/*
Generic implementation of the admob extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "admob_internal.h"
s3eResult admobInit()
{
    //Add any generic initialisation code here
    return admobInit_platform();
}

void admobTerminate()
{
    //Add any generic termination code here
    admobTerminate_platform();
}

s3eResult admob_initSmart(const char* pub_id, int orientation, int x, int y, int w, int h)
{
	return admob_initSmart_platform(pub_id, orientation, x, y, w, h);
}

s3eResult admob_moveSmart(int orientation, int x, int y, int w, int h)
{
	return admob_moveSmart_platform(orientation, x, y, w, h);
}

s3eResult admob_init(const char* pub_id, int ad_type, int orientation, int x, int y)
{
	return admob_init_platform(pub_id, ad_type, orientation, x, y);
}

s3eResult admob_resize(int ad_type)
{
	return admob_resize_platform(ad_type);
}

s3eResult admob_show()
{
	return admob_show_platform();
}

s3eResult admob_refresh()
{
	return admob_refresh_platform();
}

s3eResult admob_hide()
{
	return admob_hide_platform();
}

s3eResult admob_move(int orientation, int x, int y)
{
	return admob_move_platform(orientation, x, y);
}

s3eResult admob_interestial_preload(const char * pub_id)
{
	return admob_interestial_preload_platform(pub_id);
}

bool admob_interestial_isReady()
{
	return admob_interestial_isReady_platform();
}

bool admob_interestial_isShown()
{
	return admob_interestial_isShown_platform();
}

bool admob_interestial_wasShown()
{
	return admob_interestial_wasShown_platform();
}

bool admob_interestial_hasBeenUsed()
{
	return admob_interestial_hasBeenUsed_platform();
}

s3eResult admob_interestial_show()
{
	return admob_interestial_show_platform();
}

s3eResult admob_interestial_hide()
{
	return admob_interestial_hide_platform();
}

bool admob_banner_isClicked()
{
	return admob_banner_isClicked_platform();
}

bool admob_interestial_isClicked()
{
	return admob_interestial_isClicked_platform();
}
