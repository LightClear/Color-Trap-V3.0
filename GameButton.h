#pragma once
#include<graphics.h>
#include<cstdio>
#include<string>
using std::wstring;

int QUESTION_NUM = 0;
bool IS_BINGO = false;
DWORD START_BINGO_WRONG;

enum COLOR {
	black, green, yellow, red, brown, blue, purple, cyan, null
};

//���ư���͸������Ϣ��ͼƬ
#pragma comment(lib, "MSIMG32.LIB")
inline void Putimage1(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

//��ʱ����,����Ҳ����������͸����ͼƬ��
//#pragma comment(lib, "MSIMG32.LIB")
//void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg) {
//	HDC dstDC = GetImageHDC(dstimg);
//	HDC srcDC = GetImageHDC(srcimg);
//	int w = srcimg->getwidth();
//	int h = srcimg->getheight();
//	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
//	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
//}

class GameButton {
private:
	RECT rect;
	COLOR color;
	wstring text;
	IMAGE bk;
	int textsize;
	int texttype;

public:
	//��ʼ���캯��
	GameButton(RECT rec, COLOR col, wstring tex, LPCTSTR bkname, int size) {
		rect = rec;
		color = col;
		text = tex;
		loadimage(&bk, bkname);
		textsize = size;
	}

	//���������������ݵĹ��캯��
	void reset(COLOR col, wstring tex) {
		color = col;
		text = tex;
	}

	//���ð�ť����
	void settype(int x) {
		texttype = x;
	}

	//���ñ������ı�
	//black,green,yellow,red,brown,blue,purple,cyan
	void putthings() {
		if (texttype == 1)putimage(rect.left, rect.top, &bk);
		else Putimage1(rect.left, rect.top, &bk);
		int wd = 0, he = 0;
		switch (color) {
		case black: {
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			settextstyle(textsize, 0, _T("��������"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			break;
		}
		case green: {
			settextcolor(GREEN);
			setbkmode(TRANSPARENT);
			settextstyle(textsize, 0, _T("��������"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			break;
		}
		case yellow: {
			settextcolor(YELLOW);
			setbkmode(TRANSPARENT);
			settextstyle(textsize, 0, _T("��������"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			break;
		}
		case red: {
			settextcolor(RED);
			setbkmode(TRANSPARENT);
			settextstyle(textsize, 0, _T("��������"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			break;
		}
		case brown: {
			settextcolor(BROWN);
			setbkmode(TRANSPARENT);
			settextstyle(textsize, 0, _T("��������"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			break;
		}
		case blue: {
			settextcolor(BLUE);
			setbkmode(TRANSPARENT);
			settextstyle(textsize, 0, _T("��������"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			break;
		}
		case purple: {
			settextcolor(MAGENTA);
			setbkmode(TRANSPARENT);
			settextstyle(textsize, 0, _T("��������"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			break;
		}
		case cyan: {
			settextcolor(CYAN);
			setbkmode(TRANSPARENT);
			settextstyle(textsize, 0, _T("��������"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			break;
		}
		}
	}

	//����������Χ
	bool checkclick(const ExMessage& msg) {
		if (msg.message==WM_LBUTTONDOWN && msg.x >= rect.left && msg.x <= rect.right && msg.y >= rect.top && msg.y <= rect.bottom)return true;
		return false;
	}

	//���ƶ�����ı�
	void gettext(wstring& s) {
		s = text;
	}

	//���colorֵ
	COLOR getcolor() {
		return color;
	}

};


//��Ұ��İ�ť
class Ken :public GameButton {		//ΪʲôҪ��Ken������֣���Ϊ�Ҹ�����ġ����۶�������ȡ��
public:
	Ken(RECT rec, COLOR col, wstring tex, LPCTSTR bkname, int size) :GameButton(rec, col, tex, bkname, size) {}
	

};


//��Ŀ�İ�ť
class Title :public GameButton {
public:
	Title(RECT rec, COLOR col, wstring tex, LPCTSTR bkname, int size):GameButton(rec, col, tex, bkname, size){}

	//����Ƿ�÷�
	//black,green,yellow,red,brown,blue,purple,cyan
	bool checkscore(Ken& but) {
		wstring s;
		but.gettext(s);
		COLOR check = null;
		int i = 0;
		wstring sc1 = { _T("��ɫ") };
		wstring sc2 = { _T("��ɫ") };
		wstring sc3 = { _T("��ɫ") };
		wstring sc4 = { _T("��ɫ") };
		wstring sc5 = { _T("��ɫ") };
		wstring sc6 = { _T("��ɫ") };
		wstring sc7 = { _T("��ɫ") };
		wstring sc8 = { _T("��ɫ") };
		COLOR assign[8] = { black,green,yellow,red,brown,blue,purple,cyan };
		if (s == sc1) { check = assign[0]; }
		if (s == sc2) { check = assign[1]; }
		if (s == sc3) { check = assign[2]; }
		if (s == sc4) { check = assign[3]; }
		if (s == sc5) { check = assign[4]; }
		if (s == sc6) { check = assign[5]; }
		if (s == sc7) { check = assign[6]; }
		if (s == sc8) { check = assign[7]; }
		START_BINGO_WRONG = GetTickCount();
		if (check == getcolor()) {
			IS_BINGO = true;
		}
		else {
			IS_BINGO = false;
		}
		QUESTION_NUM = 1;
		return check == getcolor();
	}
};