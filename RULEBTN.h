#pragma once
#include<graphics.h>

bool MAIN_RULE = false, RACE_RULE = false, LIMIT_RULE = false, SURVIVAL_RULE = false, HELL_RULE = false, PROP_RULE = false;
bool* NOW_RULE = NULL;


//״̬
enum StatusRule {
	rWait,rHold,rPushed,rShow
};

//������͸����ͼƬ
#pragma comment(lib, "MSIMG32.LIB")
inline void RPutimage(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

class RULEBTN {
private:
	IMAGE wait;
	IMAGE hold;
	IMAGE pushed;
	IMAGE show;
	IMAGE rule;		//h8*75=500,w1280-200-100-150=830
	int x, y;
	int showx, showy;
	int rulex, ruley;
	int width, height;	//��rShow״̬�ĳ���
	RECT rect;			//��rShow״̬������
	StatusRule status;
	bool* thisrule;

public:
	//���캯��
	RULEBTN(LPCTSTR& wai, LPCTSTR& hol, LPCTSTR& pus, LPCTSTR& sho, LPCTSTR& rul, RECT& rect, int& x_, int& y_, int& shx, bool* th) {
		loadimage(&wait, wai);
		loadimage(&hold, hol);
		loadimage(&pushed, pus);
		loadimage(&show, sho);
		loadimage(&rule, rul);
		showx = shx;
		showy = y_;
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
		x = x_;
		y = y_;
		status = rWait;
		thisrule = th;
		rulex = 100+150, ruley = 75+30;
	}

	//�ֶ����øմ򿪹�����ܽ���ʱ����������
	void setmain() {
		*thisrule = true;
		NOW_RULE = thisrule;
		status = rShow;
	}

	//����ͼƬ
	void put() {
		if (*thisrule == false && status == rShow)status = rWait;
		switch (status) {
		case StatusRule::rWait:
			RPutimage(x, y, &wait);
			break;
		case StatusRule::rHold:
			RPutimage(x, y, &hold);
			break;
		case StatusRule::rPushed:
			RPutimage(x, y, &pushed);
			break;
		case StatusRule::rShow:
			RPutimage(rulex, ruley, &rule);
			RPutimage(showx, showy, &show);
			break;
		defalut:
			break;
		}
	}

	//����Ƿ��ڰ�ť��Χ��
	bool inbutton(int cx, int cy) {
		if (cx >= x && cx <= x + width && cy >= y && cy <= y + height)return true;
		return false;
	}

	//���°�������ö�Ӧ�Ĺ���
	void onclick() {
		RPutimage(rulex, ruley, &rule);
	}

	//�ı䰴ť״̬
	void checkstatus(const ExMessage& msg) {

		if (status != rShow) {
			switch (msg.message) {
			case WM_MOUSEMOVE:	//��������ƶ�
				if (status == rWait && inbutton(msg.x, msg.y))status = rHold;			//�Ƶ���ť�ڲ�
				else if (status == rHold && !inbutton(msg.x, msg.y))status = rWait;	//�Ƶ���ť�ⲿ
				break;
			case WM_LBUTTONDOWN:	//�������
				if (inbutton(msg.x, msg.y))		//�ڰ�ť�ڲ�
					status = rPushed;
				break;
			case WM_LBUTTONUP:		//���̧��
				if (status == rPushed && inbutton(msg.x, msg.y)) {
					NOW_RULE = thisrule;
					*thisrule = true;
					if (&MAIN_RULE != thisrule)MAIN_RULE = false;
					if (&RACE_RULE != thisrule)RACE_RULE = false;
					if (&LIMIT_RULE != thisrule)LIMIT_RULE = false;
					if (&SURVIVAL_RULE != thisrule)SURVIVAL_RULE = false;
					if (&HELL_RULE != thisrule)HELL_RULE = false;
					if (&PROP_RULE != thisrule)PROP_RULE = false;
					status = rShow;
					onclick();		//�����ڲ���������
				}
				else status = rWait;
				break;
			defalut:
				break;
			}
		}
	}

	//Ϊ���� �ұ������ģ��
	
	//Ϊ���� Ⱦ���˷��
	
	//Ϊ���� ���Ϻ���αװ

	//Ϊ���� �����ĳ�

	//���ǻ��ܲ����ټ���

	//���ڷ�ǰ������˼�ǧ��

	//Ը���ü���������һ����Ե

	//ϣ�����Ըж� ����

	//���ǻ��ܲ����ܲ����ټ���

	//���ڷ�ǰ������˼�ǧ��

	//������̤�������κ���֮ǰ

	//��������һ�������
};