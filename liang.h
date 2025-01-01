#pragma once
#include<graphics.h>
#include<cmath>

#pragma comment(lib, "MSIMG32.LIB")
#pragma comment(lib,"winmm.lib")
inline void LPutimage(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

//wd 830 hei470
//left x285,y105   105+540
class LIANG {
private:
	IMAGE img;
	int x, y;
	int corex, corey;
	int wid, hei;
	int safe;
public:
	LIANG() {
		wid = 80, hei = 78;
		x = 557.5, y = 105-hei;
		corex = x + wid / 2;
		corey = y + hei / 2;
		loadimage(&img, _T("images/liangup.png"));
		safe = 20;
	}

	void init() {
		loadimage(&img, _T("images/liangup.png"));
		x = 557.5, y = 105 - hei;
		corex = x + wid / 2;
		corey = y + hei / 2;
	}

	void check(const ExMessage& msg) {
		if (msg.x > x && msg.x < x + wid && msg.y>y && msg.y < y + hei) {
			if (y == 105 - hei)y = 105 + 540;
			else y = 105 - hei;
		}
		else if (msg.y > y && msg.y < y + hei) {
			if (msg.x < x && x - msg.x < safe)x += safe - (x - msg.x);
			if (msg.x > x + wid && msg.x - x - wid < safe)x -= safe - (msg.x - x - wid);
		}
		else if (/*msg.x < x && x - msg.x < 5 || msg.x > x + wid && msg.x - x - wid < 5*/msg.x > x && msg.x < x + wid) {
			if (msg.y < y && y - hei - msg.y < safe) {
				if (msg.x > corex)x = msg.x - safe - wid;
				else x = msg.x + safe;
			}
			if (msg.y > y + hei && msg.y - y - hei < safe) {
				if (msg.x > corex)x = msg.x - safe - wid;
				else x = msg.x + safe;
			}
		}
		else if(msg.x>=285+wid/2&&msg.x<=285+830-wid/2-1&&msg.y>=105+50&&msg.y<=105+540-60)x = msg.x - wid / 2;
		if (x < 285) {
			x = 285;
			if (y == 105 - hei)y = 105 + 540;
			else y = 105 - hei;
		}
		else if (x + wid > 285 + 830) {
			x = 285 + 830 - wid;
			if (y == 105 - hei)y = 105 + 540;
			else y = 105 - hei;
		}
		if(y==105-hei)loadimage(&img, _T("images/liangup.png"));
		else loadimage(&img, _T("images/liangdown.png"));
		corex = x + wid / 2;
		corey = y + hei / 2;
		Putimage(x, y, &img);
	}


};