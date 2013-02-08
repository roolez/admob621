/*
java implementation of the admob extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.google.ads.*;
import com.google.ads.AdRequest.ErrorCode;

import android.R.string;
import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.DownloadListener;
import android.widget.FrameLayout;
import android.widget.RelativeLayout;

class admob {

	public class BannerListerner implements AdListener {

		AdView adView;
		String pub_id;
		int ad_type;
		int x;
		int y;
		int w;
		int h;
		boolean isClicked;

		FrameLayout.LayoutParams lparams;

		@Override
		public void onDismissScreen(Ad arg0) {
			Log.i("rooAdmob", "banner onDismissScreen");
		}

		@Override
		public void onFailedToReceiveAd(Ad arg0, ErrorCode arg1) {
			Log.i("rooAdmob", "banner onFailedToReceiveAd");
		}

		@Override
		public void onLeaveApplication(Ad arg0) {
			Log.i("rooAdmob", "banner onLeaveApplication");
			isClicked = true;
		}

		@Override
		public void onPresentScreen(Ad arg0) {
			Log.i("rooAdmob", "banner onPresentScreen");
		}

		@Override
		public void onReceiveAd(Ad arg0) {
			Log.i("rooAdmob", "banner onReceiveAd");
		}

	};

	BannerListerner banner = new BannerListerner();

	public class InterestialListerner implements AdListener {

		InterstitialAd interstitial;
		String pub_id;

		boolean shown;
		boolean wasShown;
		boolean ready;
		boolean fail;
		boolean isClicked;

		@Override
		public void onReceiveAd(Ad ad) {
			Log.i("rooAdmob", "Interestial onReceiveAd");
			if (ad == interstitial) {
				ready = true;
				// interstitial.show();
			}
		}

		@Override
		public void onDismissScreen(Ad arg0) {
			Log.i("rooAdmob", "Interestial onDismissScreen");

			shown = false;
			wasShown = true;
			ready = false;
		}

		@Override
		public void onFailedToReceiveAd(Ad arg0, ErrorCode arg1) {
			Log.i("rooAdmob", "Interestial onFailedToReceiveAd");
			fail = true;
			ready = false;

		}

		@Override
		public void onLeaveApplication(Ad arg0) {
			Log.i("rooAdmob", "Interestial onLeaveApplication");
			isClicked = true;
		}

		@Override
		public void onPresentScreen(Ad arg0) {
			Log.i("rooAdmob", "Interestial onPresentScreen");

		}
	};

	InterestialListerner il = new InterestialListerner();

	public int admob_init(String pub_id, int ad_type, int orientation, int x,
			int y) {
		banner.pub_id = pub_id;
		banner.ad_type = ad_type;
		banner.x = x;
		banner.y = y;
		return 0;
	}

	public int admob_initSmart(String pub_id, int orientation, int x, int y,
			int w, int h) {
		banner.pub_id = pub_id;
		banner.ad_type = 5; // Admob_GAD_SIZE_SMART
		banner.x = x;
		banner.y = y;
		banner.w = w;
		banner.h = h;
		return 0;
	}

	public int admob_resize(int ad_type) {
		return 0;
	}

	public int admob_show() {
		admob_hide();

		if (banner.ad_type == 5) {
			// 5 is Admob_GAD_SIZE_SMART

			Log.i("rooAdmob", "Show SMART " + banner.x + " " + banner.y + " " + banner.w + " " + banner.h);
			
			
			banner.lparams = new FrameLayout.LayoutParams(banner.w, banner.h);
			banner.lparams.leftMargin = banner.x;
			banner.lparams.topMargin = banner.y;
			banner.lparams.gravity = Gravity.NO_GRAVITY;
			banner.isClicked = false;

			banner.adView = new AdView(LoaderActivity.m_Activity,
					AdSize.SMART_BANNER, banner.pub_id);
			banner.adView.setLayoutParams(banner.lparams);

			LoaderActivity.m_Activity.addContentView(banner.adView,
					banner.lparams);

			banner.adView.setAdListener(banner);

			AdRequest adRequest = new AdRequest();
			// adRequest.addTestDevice("66AEC75808D62B5B3765F1458D25ECF0");
			banner.adView.loadAd(adRequest);
			return 0;

		} else {

			int w = 320;
			int h = 50;

			banner.lparams = new FrameLayout.LayoutParams(w, h);
			banner.lparams.leftMargin = banner.x;
			banner.lparams.topMargin = banner.y;
			banner.lparams.gravity = Gravity.NO_GRAVITY;
			banner.isClicked = false;

			banner.adView = new AdView(LoaderActivity.m_Activity,
					AdSize.BANNER, banner.pub_id);
			banner.adView.setLayoutParams(banner.lparams);

			LoaderActivity.m_Activity.addContentView(banner.adView,
					banner.lparams);

			banner.adView.setAdListener(banner);

			AdRequest adRequest = new AdRequest();
			// adRequest.addTestDevice("66AEC75808D62B5B3765F1458D25ECF0");
			banner.adView.loadAd(adRequest);
			return 0;

		}

	}

	public int admob_refresh() {
		return 0;
	}

	public int admob_hide() {

		if (banner.adView != null) {

			ViewGroup vg = (ViewGroup) banner.adView.getParent();
			if (vg != null) {
				vg.removeView(banner.adView);
			}

			banner.adView.destroy();
			banner.adView = null;
		}
		return 0;
	}

	public int admob_move(int orientation, int x, int y) {
		banner.x = x;
		banner.y = y;
		// banner.lparams.leftMargin= banner.x = x;
		// banner.lparams.topMargin= banner.y = y;
		// banner.adView.setLayoutParams(banner.lparams);

		return 0;
	}

	public int admob_moveSmart(int orientation, int x, int y, int w, int h) {
		banner.x = x;
		banner.y = y;
		banner.w = w;
		banner.h = h;
		// banner.lparams.leftMargin= banner.x = x;
		// banner.lparams.topMargin= banner.y = y;
		// banner.adView.setLayoutParams(banner.lparams);

		return 0;
	}

	public int admob_interestial_preload(String pub_id) {
		il.pub_id = pub_id;
		il.shown = false;
		il.wasShown = false;
		il.isClicked = false;
		il.interstitial = new InterstitialAd(LoaderActivity.m_Activity,
				il.pub_id);

		// Create ad request
		AdRequest adRequest = new AdRequest();
		// adRequest.addTestDevice("66AEC75808D62B5B3765F1458D25ECF0");
		// adRequest.setTesting(true);

		// Set Ad Listener to use the callbacks below
		il.interstitial.setAdListener(il);

		// Begin loading your interstitial
		il.interstitial.loadAd(adRequest);

		return 0;
	}

	public boolean admob_interestial_isReady() {
		return il.interstitial.isReady();
	}

	public boolean admob_interestial_isShown() {
		return il.shown;
	}

	public boolean admob_interestial_wasShown() {
		return il.wasShown;
	}

	public boolean admob_interestial_hasBeenUsed() {
		return false;
	}

	public int admob_interestial_show() {
		il.interstitial.show();
		il.shown = true;
		return 0;
	}

	public int admob_interestial_hide() {
		// il.interstitial.
		return 0;
	}

	public boolean admob_banner_isClicked() {
		return banner.isClicked;
	}

	public boolean admob_interestial_isClicked() {
		return il.isClicked;
	}

}
