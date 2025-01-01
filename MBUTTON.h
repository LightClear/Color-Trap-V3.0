#pragma once
#include<graphics.h>
bool gameend = false, gamestart = false, rank = false, rule = false, Exit = false;  //��Ϸ��������ʼ�����а�����������濪�����˳���Ϸ
bool INIT_MENU_RUNNING = true, CLEAR_MENU_RUNNING = false, PROGRAM_RUNNING = true, this_game = false;	//��ʼ�˵����桢������桢�����������п��ء��˾���Ϸ
bool CHOOSE_GAMEMODE = false, CHOOSE_GAMEMODE_INIT = false, CHOOSE_GAMEMODE_NEXT, COUNTDOWN = false;	//����ѡ����Ϸģʽ����ʼѡ����Ϸ���桢����ѡ����Ϸ���桢���ֵ���ʱ
bool CHMODE_CLEAR;	//����������ѡ����Ϸģʽ
bool ACHIEVEMENT = false, BGM = false, ABOUTAUTHOR = false;	//����ɾͽ��桢�������ֽ��桢�������߽���

double DIFFICULTY_TIME, DIFFICULTY_HP, DIFFICULTY_TIME_ALL = 60, PENALTY = 3;	//��Ϸ�Ѷ�-ʱ�䣬��Ϸ�Ѷ�-Ѫ��������ģʽ�µ���ʱ�䣬����ģʽ�µĵ��γͷ�ֵ
double FULLNESS = 5;	//��ʼ��ʳ��

//��Ϸģʽ��race���涨ʱ���ڱ�ƴ��ȷ���� survival��������������һ���������� limit�����Ƶ�����Ŀ��ʱ�䣻 hell���������������Ƶ�����Ŀʱ��
enum GameMode {
	race,survival,limit,hell,nullmode
};

GameMode GAMEMODE;	//��ǰ��Ϸģʽ

//���ư���͸������Ϣ��ͼƬ
#pragma comment(lib, "MSIMG32.LIB")
inline void Putimage(int x,int y,IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}


//�˵���ť����
class MBUTTON {
private:

	enum Status {
		Wait, Pushed, Hold
	};
	IMAGE bk_hold;
	IMAGE bk_pushed;
	IMAGE bk_wait;
	Status status = Wait;
	int x, y;	//���Ͻ�����
	int height, width;
	RECT rect;

protected:
	virtual void onclick() = 0;

public:
	//���캯��
	MBUTTON(LPCTSTR& bkwait, LPCTSTR& bkhold, LPCTSTR& bkpushed, RECT& re, int& x_, int& y_) {
		x = x_;
		y = y_;
		rect = re;
		loadimage(&bk_wait, bkwait);
		loadimage(&bk_hold, bkhold);
		loadimage(&bk_pushed, bkpushed);
		height = re.bottom - y_;
		width = re.right - x_;
	}

	//�ı�ͼ�����Ͻ�����
	void setxy(int x_, int y_) {
		x = x_, y = y_;
	}

	//���ò˵���ť
	void putmenu() {
		switch (status) {
		case Status::Wait:
			Putimage(x, y, &bk_wait);
			break;
		case Status::Hold:
			Putimage(x, y, &bk_hold);
			break;
		case Status::Pushed:
			Putimage(x, y, &bk_pushed);
			break;
		defalut:
			break;
		}
	}

	//�ı䰴ť״̬
	void checkstatus(const ExMessage& msg) {
		//if (status == Wait && inbutton(msg.x, msg.y))status = Hold;			//�Ƶ���ť�ڲ�

		switch (msg.message) {
		case WM_MOUSEMOVE:	//��������ƶ�
			if (status == Wait && inbutton(msg.x, msg.y))status = Hold;			//�Ƶ���ť�ڲ�
			else if (status == Hold && !inbutton(msg.x, msg.y))status = Wait;	//�Ƶ���ť�ⲿ
			break;
		case WM_LBUTTONDOWN:	//�������
			if (inbutton(msg.x, msg.y))		//�ڰ�ť�ڲ�
				status = Pushed;
			break;
		case WM_LBUTTONUP:		//���̧��
			if (status == Pushed && inbutton(msg.x, msg.y)) {
				status = Wait;
				onclick();		//�����ڲ���������
			}
			else status = Wait;
			break;
		defalut:
			break;
		}
	}

	//����Ƿ��ڰ�ť��Χ��
	bool inbutton(int cx, int cy) {
		if (cx >= x && cx <= x+width && cy >= y && cy <= y+height)return true;
		return false;
	}

};

//����������Ϸ��ť
class EndButton :public MBUTTON {
public:
	EndButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}
protected:
	//��Ϸ����
	void onclick() {
		gameend = true;
	}
};

//��ʼһ����Ϸ��ť
class StartButton :public MBUTTON {
public:
	StartButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}
protected:
	//��Ϸ��ʼ
	void onclick() {
		gamestart = true;
		this_game = true;
		COUNTDOWN = true;
		INIT_MENU_RUNNING = false;
		CLEAR_MENU_RUNNING = false;
	}
};

//�����а�ť
class RankButton :public MBUTTON {
public:
	RankButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}
protected:
	//�򿪻�ر����а�
	void onclick() {
		rank = true;
		INIT_MENU_RUNNING = false;
	}
};

//�򿪳ɾͽ��水ť
class AchievementButton :public MBUTTON {
public:
	AchievementButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}
protected:
	void onclick() {
		ACHIEVEMENT = true;
		INIT_MENU_RUNNING = false;
	}
};

//�����ֽ���
class BgmButton :public MBUTTON {
public:
	BgmButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}
protected:
	void onclick() {
		BGM = true;
		INIT_MENU_RUNNING = false;
	}
};

//�򿪹������߽���
class AboutAuthorButton :public MBUTTON {
public:
	AboutAuthorButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}
protected:
	void onclick() {
		ABOUTAUTHOR = true;
		INIT_MENU_RUNNING = false;
	}
};

//��Ϸ������ܰ�ť
class RuleButton :public MBUTTON {
public:
	RuleButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}
protected:
	//����Ϸ����
	void onclick() {
		rule = true;
		INIT_MENU_RUNNING = false;
	}
};

//�˳�����ť
class ExitButton :public MBUTTON {
public:
	ExitButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}
protected:
	//�رճ���
	void onclick() {
		PROGRAM_RUNNING = false;
		INIT_MENU_RUNNING = false;
	}
};

//ѡ����Ϸģʽ��ť�������˵�����
class ChooseModeButton :public MBUTTON {
public:
	ChooseModeButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}
protected:
	//���س�ʼ�˵�
	void onclick() {
		CHOOSE_GAMEMODE = true;
		CHOOSE_GAMEMODE_INIT = true;
		INIT_MENU_RUNNING = false;
	}
};

//���س�ʼ�˵���ť
class ReturnMenuButton :public MBUTTON {
public:
	ReturnMenuButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}
protected:
	//���س�ʼ�˵�
	void onclick() {
		INIT_MENU_RUNNING = true;
		rank = false, rule = false, CLEAR_MENU_RUNNING = false, this_game = false, gamestart = false;
		CHOOSE_GAMEMODE = false, CHOOSE_GAMEMODE_INIT = false, COUNTDOWN = false;
		ACHIEVEMENT = false, BGM = false, ABOUTAUTHOR = false;
	}
};

//ѡ��ʱ���ѶȰ�ť����Ҫ����race��hell��survivalģʽ�е��Ѷ���ֵ����
class DifficultyTimeButton :public MBUTTON {
private:
	int the_difficulty_time;
public:
	DifficultyTimeButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}

	//����difficultyֵ
	void setdifficulty(int dif){
		the_difficulty_time = dif;
	}

protected:
	//�ı���Ϸʱ���Ѷ��Ѷ�
	void onclick() {
		DIFFICULTY_TIME = the_difficulty_time;
	}
};

//ѡ�������ѶȰ�ť����Ҫ����race��hell��survivalģʽ�е��Ѷ���ֵ����
class DifficultyHpButton :public MBUTTON {
private:
	int the_difficulty_hp;
public:
	DifficultyHpButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}

	//����difficultyֵ
	void setdifficulty(int dif) {
		the_difficulty_hp = dif;
	}

protected:
	//�ı���Ϸ�����Ѷ��Ѷ�
	void onclick() {
		DIFFICULTY_HP = the_difficulty_hp;
	}
};


//������Ϸģʽ��ť
//��Ϸģʽ��race���涨ʱ���ڱ�ƴ��ȷ���� survival��������������һ���������� limit�����Ƶ�����Ŀ��ʱ�䣻 hell���������������Ƶ�����Ŀʱ��
class GameModeButton :public MBUTTON {
private:
	GameMode the_gamemode;
	IMAGE successset;
	int suc_x, suc_y;
public:
	GameModeButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}

	//������Ϸģʽ�ͳɹ����ú����Ϣͼ�������Ͻ�����
	void setGamemode(GameMode gmode/*, IMAGE suc, int sx, int sy*/) {
		//successset = suc;
		the_gamemode = gmode;
		//suc_x = sx;
		//suc_y = sy;
	}
protected:
	//�ı���Ϸģʽ
	void onclick() {
		//putimage(suc_x, suc_y, &successset);
		GAMEMODE = the_gamemode;
		CHOOSE_GAMEMODE_INIT = false;
		CHOOSE_GAMEMODE_NEXT = true;	//�˳���ʼѡ��ģʽ����
	}
};

//���س�ʼѡ��ģʽ���水ť
class ReturnChmdButton :public MBUTTON {
public:
	ReturnChmdButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}

protected:
	//�򿪻�رյ�ǰģʽѡ�����
	void onclick() {
		CHOOSE_GAMEMODE_NEXT = false;
		CHOOSE_GAMEMODE_INIT = true;
	}
};

//������һ����ť
class ReturnUplevButton :public MBUTTON {
private:
	bool* upperlev;
	bool* thislev1;
	bool* thislev2;
	bool* thislev3;
public:
	ReturnUplevButton(LPCTSTR bkwait, LPCTSTR bkhold, LPCTSTR bkpushed, RECT re, int x_, int y_) :MBUTTON(bkwait, bkhold, bkpushed, re, x_, y_) {}

	//��õ�ǰ����һ������ָ��
	void setlevel(bool* up, bool* th1, bool* th2, bool* th3) {
		upperlev = up;
		thislev1 = th1;
		thislev2 = th2;
		thislev3 = th3;
	}
protected:
	//�򿪻�رյ�ǰģʽѡ�����
	void onclick() {
		if (upperlev != NULL)*upperlev = true;
		if (thislev1 != NULL)(*thislev1) = false;
		if (thislev2 != NULL)(*thislev2) = false;
		if (thislev3 != NULL)(*thislev3) = false;
	}
};
