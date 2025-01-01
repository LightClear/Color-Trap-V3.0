#pragma once
#include<graphics.h>
#include<cstdio>
#include<string>
using std::wstring;

enum COLOR {
	black,green,yellow,red,brown,blue,purple,cyan
};

class Button {
private:
	int x, y;
	wstring text;
	COLOR textcolor;
	int width, length;
	IMAGE background;

public:
	//初始化左上角坐标与长宽
	void initdigit(int& dx, int& dy,int& length_,int& width_) {
		x = dx, y = dy, width = width_, length = length_;
	}

	//初始化背景图片
	void initbk(IMAGE& bk) {
		background = bk;
	}

	//初始化文本的颜色
	void intitextcolor(COLOR& col) {
		textcolor = col;
	}

	//初始化文本内容
	void inittext(wstring& s) {
		text = s;
	}
	
	//放置背景及文本
	//black,green,yellow,red,brown,blue,purple,cyan
	void putthings() {

		/*int width1 = textwidth(text) / 2;
		int height1 = textheight(text) / 2;
		int wd = length / 2 - width1;
		int he = width / 2 - height1;
		 drawtext(100, 100, wstr.c_str());
		*/

		//int tw = textwidth(text.c_str());
		//int th = textheight(text.c_str());

		//// 计算文本的输出位置，使其居中于图片
		//int tx = x + (length - tw) / 2; // 文本的x坐标
		//int ty = y + (width - th) / 2; // 文本的y坐标

		//// 定义矩形区域
		////RECT rect = { x + (length - tw) / 2, y + (width - th) / 2, x + (length + tw) / 2, y + (width + th) / 2 };

		putimage(x, y, &background);
		int wd = 0, he = 0;
		RECT rect = { x, y, x+length, y+width };
		switch (textcolor) {
		case black: {
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("微软雅黑"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case green: {
			settextcolor(GREEN);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("微软雅黑"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case yellow: {
			settextcolor(YELLOW);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("微软雅黑"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case red: {
			settextcolor(RED);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("微软雅黑"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case brown: {
			settextcolor(BROWN);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("微软雅黑"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case blue: {
			settextcolor(BLUE);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("微软雅黑"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case purple: {
			settextcolor(MAGENTA);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("微软雅黑"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case cyan: {
			settextcolor(CYAN);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("微软雅黑"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		}
	}

	//检测鼠标点击范围
	bool checkclick(int& cx, int& cy) {
		if (cx >= x && cx <= x + length && cy >= y && cy <= y + width)return true;
		return false;
	}

	//复制对象的文本
	void gettext(wstring& s) {
		s = text;
	}

	//检测是否得分
	//black,green,yellow,red,brown,blue,purple,cyan
	bool checkscore(Button& but) {
		wstring s;
		but.gettext(s);
		COLOR check;
		int i = 0;
		wstring sc1 = { _T("黑色") };
		wstring sc2 = { _T("绿色") };
		wstring sc3 = { _T("黄色") };
		wstring sc4 = { _T("红色") };
		wstring sc5 = { _T("棕色") };
		wstring sc6 = { _T("蓝色") };
		wstring sc7 = { _T("紫色") };
		wstring sc8 = { _T("青色") };
		COLOR assign[8] = { black,green,yellow,red,brown,blue,purple,cyan };
		if (s == sc1) { check = assign[0]; }
		if (s == sc2) { check = assign[1]; }
		if (s == sc3) { check = assign[2]; }
		if (s == sc4) { check = assign[3]; }
		if (s == sc5) { check = assign[4]; }
		if (s == sc6) { check = assign[5]; }
		if (s == sc7) { check = assign[6]; }
		if (s == sc8) { check = assign[7]; }
		return check == textcolor;
	}

};