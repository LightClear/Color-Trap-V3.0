#pragma once

#include<graphics.h>
#include<string>
#include<fstream>
#include <sstream> // 包含标准库中的字符串流头文件
using std::wstring;
using std::ofstream;
using std::ifstream;

//放置含透明度信息的图片
#pragma comment(lib, "MSIMG32.LIB")
#pragma comment(lib,"winmm.lib")
inline void PPutimage(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

class PROP {
private:
	int num;
	char key;
	int px, py;
	int width, height;
	bool clicked;
	IMAGE propimg;
	RECT numrect;
	RECT keyrect;
	wstring numtext;
	wstring keytext;
	LPCTSTR file;
	LPCTSTR musicop, musicpl, musiccl;
	bool* prop;
	int textsize;
	int textrectwid=10, textrecthei=10;
	//IMAGE numimg;
//protected:
//	virtual void onclick() = 0;
public:
	//构造函数
	PROP(LPCTSTR propimg0, LPCTSTR numlocate, LPCTSTR musop, LPCTSTR muspl, LPCTSTR muscl, int px0, int py0, char key0, int width0, int height0, bool* pro) {
		px = px0, py = py0, key = key0, width = width0, height = height0, prop=pro, clicked=false;
		numrect = { px0 + width - textrectwid,py0 + height - textrecthei,px0 + width,py0 + height };
		keyrect = { px,py,px + textrectwid,py + textrecthei };
		loadimage(&propimg, propimg0);
		textsize = 30;
		file = numlocate;
		musicop = musop;
		musicpl = muspl;
		musiccl = muscl;
		ifstream ifs(numlocate, std::ios::in | std::ios::binary);
		int tmp;
		ifs.read((char*)&tmp, sizeof(int));
		num = tmp;
		ifs.close();
		mciSendString(musicop, NULL, 0, NULL);
	}

	//重新设置坐标和key
	void setxyk(int sx, int sy, char sk) {
		*prop = false;
		px = sx, py = sy;
		key = sk;
		numrect = { px + width - textrectwid,py + height - textrecthei,px + width,py + height };
		keyrect = { px,py,px + textrectwid,py + textrecthei };
	}

	//放置图片
	void putall() {
		PPutimage(px, py, &propimg);
		//PPutimage(nx, ny, &numimg);
		setNumKeytext();
		settextcolor(YELLOW);
		setbkmode(TRANSPARENT);
		settextstyle(textsize, 0, _T("华文琥珀"));
		drawtext(numtext.c_str(), &numrect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		setbkmode(TRANSPARENT);
		settextcolor(GREEN);
		drawtext(keytext.c_str(), &keyrect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	}

	//得到数量的文本
	void setNumKeytext() {
		std::wstringstream wss1; // 创建一个宽字符串流对象
		// 设置精度并插入格式化的字符串
		wss1 << L"" << std::fixed << num;
		// 从字符串流中获取格式化后的字符串，并赋值给 wstring 变量
		numtext = wss1.str();
		std::wstringstream wss2;
		wss2 << L"" << std::fixed << key;
		keytext = wss2.str();
	}

	//放置数量
	void putnum() {
		setNumKeytext();
		settextcolor(YELLOW);
		setbkmode(TRANSPARENT);
		settextstyle(textsize, 0, _T("华文琥珀"));
		drawtext(numtext.c_str(), &numrect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	}

	//检测是否在按钮内部
	bool inbutton(int x, int y) {
		return x >= px && x <= px + width && y >= py && y <= py + height;
	}

	void playmusic() {
		mciSendString(musiccl, NULL, 0, NULL);
		mciSendString(musicop, NULL, 0, NULL);
		mciSendString(_T("setaudio music/suspend.mp3 volume to 500"), NULL, 0, NULL);
		mciSendString(_T("setaudio music/hamburger.mp3 volume to 500"), NULL, 0, NULL);
		mciSendString(_T("setaudio music/eatapple.mp3 volume to 700"), NULL, 0, NULL);
		mciSendString(musicpl, NULL, 0, NULL);
	}

	//检测是否点击
	void checkclick(const ExMessage& msg) {
		//道具数量大于0时生效
		if (num > 0) {
			switch (msg.message) {
			case WM_KEYUP:
				if (msg.vkcode == key) {
					*prop = true;
					num--;
					putall();
					playmusic();
					updatenum(false);
				}
				break;
			case WM_LBUTTONDOWN:	//按下左键
				if (inbutton(msg.x, msg.y))		//在按钮内部
					clicked = true;
				break;
			case WM_LBUTTONUP:		//左键抬起
				if (clicked && inbutton(msg.x, msg.y)) {
					*prop = true;
					num--;
					putall();
					playmusic();
					updatenum(false);
				}
				clicked = false;
				break;
			defalut:
				break;
			}
		}
	}

	//更新道具数量
	void updatenum(bool ch) {
		if (ch)num++;
		ofstream ofs(file, std::ios::out | std::ios::binary);
		ofs.write((const char*)&num, sizeof(int));
		ofs.close();
	}
};