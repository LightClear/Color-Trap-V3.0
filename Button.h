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
	//��ʼ�����Ͻ������볤��
	void initdigit(int& dx, int& dy,int& length_,int& width_) {
		x = dx, y = dy, width = width_, length = length_;
	}

	//��ʼ������ͼƬ
	void initbk(IMAGE& bk) {
		background = bk;
	}

	//��ʼ���ı�����ɫ
	void intitextcolor(COLOR& col) {
		textcolor = col;
	}

	//��ʼ���ı�����
	void inittext(wstring& s) {
		text = s;
	}
	
	//���ñ������ı�
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

		//// �����ı������λ�ã�ʹ�������ͼƬ
		//int tx = x + (length - tw) / 2; // �ı���x����
		//int ty = y + (width - th) / 2; // �ı���y����

		//// �����������
		////RECT rect = { x + (length - tw) / 2, y + (width - th) / 2, x + (length + tw) / 2, y + (width + th) / 2 };

		putimage(x, y, &background);
		int wd = 0, he = 0;
		RECT rect = { x, y, x+length, y+width };
		switch (textcolor) {
		case black: {
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("΢���ź�"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case green: {
			settextcolor(GREEN);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("΢���ź�"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case yellow: {
			settextcolor(YELLOW);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("΢���ź�"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case red: {
			settextcolor(RED);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("΢���ź�"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case brown: {
			settextcolor(BROWN);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("΢���ź�"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case blue: {
			settextcolor(BLUE);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("΢���ź�"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case purple: {
			settextcolor(MAGENTA);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("΢���ź�"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		case cyan: {
			settextcolor(CYAN);
			setbkmode(TRANSPARENT);
			settextstyle(50, 0, _T("΢���ź�"));
			drawtext(text.c_str(), &rect, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
			break;
		}
		}
	}

	//����������Χ
	bool checkclick(int& cx, int& cy) {
		if (cx >= x && cx <= x + length && cy >= y && cy <= y + width)return true;
		return false;
	}

	//���ƶ�����ı�
	void gettext(wstring& s) {
		s = text;
	}

	//����Ƿ�÷�
	//black,green,yellow,red,brown,blue,purple,cyan
	bool checkscore(Button& but) {
		wstring s;
		but.gettext(s);
		COLOR check;
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
		return check == textcolor;
	}

};