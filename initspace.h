#pragma once
#include"MBUTTON.h"
#include"GameButton.h"

namespace init {
	int WINDOWS_WIDTH = 1280, WINDOWS_HEIGHT = 720;
	int MENUBTN_WIDTH = 180, MENUBTN_HEIGHT = 70;
	int x0 = 75, y0 = 341;		//x0Ϊ���˵�����ĸ���ť��x���꣬yoΪ���˵������ĸ���ť�����y����
	int x1 = 1280 - 75 - MENUBTN_WIDTH;	//��Ϊ�˵��ұ��ĸ���ť��x����
	int GAP = 5,GAP1=GAP+MENUBTN_HEIGHT;

	int GMMODE_WIDTH = 300, GMMODE_HEIGHT = 150;

	int RETURNBTN_WIDTH, RETURNBTN_HEIGHT;

	//��ʼ��Ϸ��ť
	LPCTSTR st_bkwait = _T("images/initmenu/start/wait.png");
	LPCTSTR st_bkhold = _T("images/initmenu/start/hold.png");
	LPCTSTR st_bkpushed = _T("images/initmenu/start/pushed.png");
	int x_st_bkrect = x0, y_st_bkrect = y0;
	RECT st_bkrect = { x_st_bkrect,y_st_bkrect,x_st_bkrect+MENUBTN_WIDTH,y_st_bkrect+MENUBTN_HEIGHT };
	StartButton stbtn(st_bkwait, st_bkhold, st_bkpushed, st_bkrect, x_st_bkrect, y_st_bkrect);

	//����һ����Ϸ��ť
	LPCTSTR restart_bkwait = _T("images/clearmenu/wait.png");
	LPCTSTR restart_bkhold = _T("images/clearmenu/hold.png");
	LPCTSTR restart_bkpushed = _T("images/clearmenu/pushed.png");
	int x_restart_bkrect = 530, y_restart_bkrect = 290;		//����ǵø�2024.12.20	�Ѹ�24.12.21
	RECT restart_bkrect = { x_restart_bkrect, y_restart_bkrect, x_restart_bkrect + 240, y_restart_bkrect + 120 };
	StartButton restartbtn(restart_bkwait, restart_bkhold, restart_bkpushed, restart_bkrect, x_restart_bkrect, y_restart_bkrect);

	//������Ϸģʽѡ��ť������ʼ�˵���
	LPCTSTR chmode_bkwait = _T("images/initmenu/mode/wait.png");
	LPCTSTR chmode_bkhold = _T("images/initmenu/mode/hold.png");
	LPCTSTR chmode_bkpushed = _T("images/initmenu/mode/pushed.png");
	int x_chmode_bkrect = x0, y_chmode_bkrect = y0+ GAP1;
	RECT chmode_bkrect = { x_chmode_bkrect, y_chmode_bkrect, x_chmode_bkrect + MENUBTN_WIDTH, y_chmode_bkrect + MENUBTN_HEIGHT };
	ChooseModeButton chmodebtn(chmode_bkwait, chmode_bkhold, chmode_bkpushed, chmode_bkrect, x_chmode_bkrect, y_chmode_bkrect);

	//������Ϸģʽѡ��ť��������ҳ�洦
	LPCTSTR chmode_clear_bkwait = _T("images/clearmenu/chmode_wait.png");
	LPCTSTR chmode_clear_bkhold = _T("images/clearmenu/chmode_hold.png");
	LPCTSTR chmode_clear_bkpushed = _T("images/clearmenu/chmode_pushed.png");
	int x_chmode_clear_bkrect = 530, y_chmode_clear_bkrect = 290 + 10 + 110;
	RECT chmode_clear_bkrect = { x_chmode_clear_bkrect, y_chmode_clear_bkrect, x_chmode_clear_bkrect + 220, y_chmode_clear_bkrect + 110 };
	ChooseModeButton chmodebtn_clearmenu(chmode_clear_bkwait, chmode_clear_bkhold, chmode_clear_bkpushed, chmode_clear_bkrect, x_chmode_clear_bkrect, y_chmode_clear_bkrect);
	
	//���а�ť������������ʵ�ڲ�����ˣ�����QAQ�������������������24.12.23
	/*LPCTSTR rk_bkwait = _T("images/rk_bk_wait.png");
	LPCTSTR rk_bkhold = _T("images/rk_bk_hold.png");
	LPCTSTR rk_bkpushed = _T("images/rk_bk_pushed.png");
	int x_rk_bkrect = x0, y_rk_bkrect = y0+ GAP1*2;
	RECT rk_bkrect = { x_rk_bkrect,y_rk_bkrect,x_rk_bkrect+MENUBTN_WIDTH,y_rk_bkrect+MENUBTN_HEIGHT };
	RankButton rkbtn(rk_bkwait, rk_bkhold, rk_bkpushed, rk_bkrect, x_rk_bkrect, y_rk_bkrect);*/

	//��Ϸ����ť
	LPCTSTR rl_bkwait = _T("images/initmenu/rule/wait.png");
	LPCTSTR rl_bkhold = _T("images/initmenu/rule/hold.png");
	LPCTSTR rl_bkpushed = _T("images/initmenu/rule/pushed.png");
	//int x_rl_bkrect = x0, y_rl_bkrect = y0 + GAP1*3;
	int x_rl_bkrect = x0, y_rl_bkrect = y0 + GAP1 * 2;
	RECT rl_bkrect = { x_rl_bkrect,y_rl_bkrect,x_rl_bkrect+MENUBTN_WIDTH,y_rl_bkrect+MENUBTN_HEIGHT };
	RuleButton rlbtn(rl_bkwait, rl_bkhold, rl_bkpushed, rl_bkrect, x_rl_bkrect, y_rl_bkrect);

	//�˳���Ϸ��ť
	LPCTSTR ex_bkwait = _T("images/initmenu/exit/wait.png");
	LPCTSTR ex_bkhold = _T("images/initmenu/exit/hold.png");
	LPCTSTR ex_bkpushed = _T("images/initmenu/exit/pushed.png");
	//int x_ex_bkrect = x0, y_ex_bkrect = y0 + GAP1*4;
	int x_ex_bkrect = x0, y_ex_bkrect = y0 + GAP1 * 3;
	RECT ex_bkrect = { x_ex_bkrect,y_ex_bkrect,x_ex_bkrect + MENUBTN_WIDTH,y_ex_bkrect + MENUBTN_HEIGHT };
	ExitButton exbtn(ex_bkwait, ex_bkhold, ex_bkpushed, ex_bkrect, x_ex_bkrect, y_ex_bkrect);

	//ѡ����Ϸģʽ��ť��������ģʽ
	LPCTSTR race_mode_bkwait = _T("images/chmode/race_bk_wait.png");
	LPCTSTR race_mode_bkhold = _T("images/chmode/race_bk_hold.png");
	LPCTSTR race_mode_bkpushed = _T("images/chmode/race_bk_pushed.png");
	int x_race_mode = 300, y_race_mode = 250;
	RECT race_mode_bkrect = { x_race_mode,y_race_mode,x_race_mode + GMMODE_WIDTH,y_race_mode + GMMODE_HEIGHT };
	GameModeButton race_modebtn{ race_mode_bkwait,race_mode_bkhold,race_mode_bkpushed,race_mode_bkrect,x_race_mode,y_race_mode };

	//ѡ����Ϸģʽ��ť��������ģʽ
	LPCTSTR survival_mode_bkwait = _T("images/chmode/survival_bk_wait.png");
	LPCTSTR survival_mode_bkhold = _T("images/chmode/survival_bk_hold.png");
	LPCTSTR survival_mode_bkpushed = _T("images/chmode/survival_bk_pushed.png");
	int x_survival_mode = 680, y_survival_mode = 250;
	RECT survival_mode_bkrect = { x_survival_mode,y_survival_mode,x_survival_mode + GMMODE_WIDTH,y_survival_mode + GMMODE_HEIGHT };
	GameModeButton survival_modebtn{ survival_mode_bkwait,survival_mode_bkhold,survival_mode_bkpushed,survival_mode_bkrect,x_survival_mode,y_survival_mode };
	
	//ѡ����Ϸģʽ��ť�������Ƶ�����Ŀʱ��ģʽ-limit
	LPCTSTR limit_mode_bkwait = _T("images/chmode/limit_bk_wait.png");
	LPCTSTR limit_mode_bkhold = _T("images/chmode/limit_bk_hold.png");
	LPCTSTR limit_mode_bkpushed = _T("images/chmode/limit_bk_pushed.png");
	int x_limit_mode = 300, y_limit_mode = 480;
	RECT limit_mode_bkrect = { x_limit_mode,y_limit_mode,x_limit_mode + GMMODE_WIDTH,y_limit_mode + GMMODE_HEIGHT };
	GameModeButton limit_modebtn{ limit_mode_bkwait,limit_mode_bkhold,limit_mode_bkpushed,limit_mode_bkrect,x_limit_mode,y_limit_mode };

	//ѡ����Ϸģʽ��ť��������ģʽ-hell
	LPCTSTR hell_mode_bkwait = _T("images/chmode/hell_bk_wait.png");
	LPCTSTR hell_mode_bkhold = _T("images/chmode/hell_bk_hold.png");
	LPCTSTR hell_mode_bkpushed = _T("images/chmode/hell_bk_pushed.png");
	int x_hell_mode = 680, y_hell_mode = 480;
	RECT hell_mode_bkrect = { x_hell_mode,y_hell_mode,x_hell_mode + GMMODE_WIDTH,y_hell_mode + GMMODE_HEIGHT };
	GameModeButton hell_modebtn{ hell_mode_bkwait,hell_mode_bkhold,hell_mode_bkpushed,hell_mode_bkrect,x_hell_mode,y_hell_mode };

	//�������˵���ť�����ڳ�ʼ�����еġ���������ʵ�Ƿǽ���ҳ���Լ��Ƕ���ģʽѡ������µĶ������
	LPCTSTR remenu_bkwait = _T("images/remenu/remenu_bk_wait.png");
	LPCTSTR remenu_bkhold = _T("images/remenu/remenu_bk_hold.png");
	LPCTSTR remenu_bkpushed = _T("images/remenu/remenu_bk_pushed.png");
	int x_remenu_bkrect = 0, y_remenu_bkrect = 0;
	RECT remenu_bkrect = { x_remenu_bkrect,y_remenu_bkrect,x_remenu_bkrect+125,y_remenu_bkrect+75 };
	ReturnMenuButton remenubtn(remenu_bkwait, remenu_bkhold, remenu_bkpushed, remenu_bkrect,x_remenu_bkrect,y_remenu_bkrect);

	//�ӽ���������ģʽѡ�����󷵻ؽ������
	ReturnUplevButton reclearmenu(remenu_bkwait, remenu_bkhold, remenu_bkpushed, remenu_bkrect, x_remenu_bkrect, y_remenu_bkrect);

	//�ӽ�����淵�����˵�
	LPCTSTR remenu_clearbkwait = _T("images/clearmenu/remenu_wait.png");
	LPCTSTR remenu_clearbkhold = _T("images/clearmenu/remenu_hold.png");
	LPCTSTR remenu_clearbkpushed = _T("images/clearmenu/remenu_pushed.png");
	int x_remenu_clear_bkrect = 530, y_remenu_clear_bkrect = 290 + 110 * 2 + 20;  //530
	RECT remenu_clearbkrect = { x_remenu_clear_bkrect,y_remenu_clear_bkrect,x_remenu_clear_bkrect + 240,y_remenu_clear_bkrect + 120};
	ReturnMenuButton remenubtn_clear(remenu_clearbkwait, remenu_clearbkhold, remenu_clearbkpushed, remenu_clearbkrect, x_remenu_clear_bkrect, y_remenu_clear_bkrect);

	//���س�ʼѡ��ģʽ���水ť��������������ĺͽ������Ľ���
	/*LPCTSTR rechmode_bkwait = _T("images/remenu/remenu_bk_wait.png");		��remenuһ��
	LPCTSTR rechmode_bkhold = _T("images/remenu/remenu_bk_hold.png");
	LPCTSTR rechmode_bkpushed = _T("images/remenu/remenu_bk_pushed.png");
	int x_rechmode_bkrect = 0, y_rechmode_bkrect = 0;*/
	RECT rechmode_bkrect = { x_remenu_bkrect,y_remenu_bkrect,x_remenu_bkrect + 125,y_remenu_bkrect + 75 };
	ReturnChmdButton rechmodebtn(remenu_bkwait, remenu_bkhold, remenu_bkpushed, rechmode_bkrect, x_remenu_bkrect, y_remenu_bkrect);

	//�����Ѷ�ʱ�䰴ť
	//30��
	LPCTSTR diftime_30_bkwait = _T("images/difficulty/30s_bk_wait.png");
	LPCTSTR diftime_30_bkhold = _T("images/difficulty/30s_bk_hold.png");
	LPCTSTR diftime_30_bkpushed = _T("images/difficulty/30s_bk_pushed.png");
	int x_diftime_30_bkrect = 490, y_diftime_30_bkrect = 370;
	RECT diftime_30_bkrect = { x_diftime_30_bkrect,y_diftime_30_bkrect,x_diftime_30_bkrect + 300,y_diftime_30_bkrect + 125 };
	DifficultyTimeButton diftime30btn(diftime_30_bkwait, diftime_30_bkhold, diftime_30_bkpushed, diftime_30_bkrect, x_diftime_30_bkrect, y_diftime_30_bkrect);
	//60��
	LPCTSTR diftime_60_bkwait = _T("images/difficulty/60s_bk_wait.png");
	LPCTSTR diftime_60_bkhold = _T("images/difficulty/60s_bk_hold.png");
	LPCTSTR diftime_60_bkpushed = _T("images/difficulty/60s_bk_pushed.png");
	int x_diftime_60_bkrect = 490, y_diftime_60_bkrect = 200;
	RECT diftime_60_bkrect = { x_diftime_60_bkrect,y_diftime_60_bkrect,x_diftime_60_bkrect + 300,y_diftime_60_bkrect + 125 };
	DifficultyTimeButton diftime60btn(diftime_60_bkwait, diftime_60_bkhold, diftime_60_bkpushed, diftime_60_bkrect, x_diftime_60_bkrect, y_diftime_60_bkrect);
	//15��
	LPCTSTR diftime_15_bkwait = _T("images/difficulty/15s_bk_wait.png");
	LPCTSTR diftime_15_bkhold = _T("images/difficulty/15s_bk_hold.png");
	LPCTSTR diftime_15_bkpushed = _T("images/difficulty/15s_bk_pushed.png");
	int x_diftime_15_bkrect = 490, y_diftime_15_bkrect = 540;
	RECT diftime_15_bkrect = { x_diftime_15_bkrect,y_diftime_15_bkrect,x_diftime_15_bkrect + 300,y_diftime_15_bkrect + 125 };
	DifficultyTimeButton diftime15btn(diftime_15_bkwait, diftime_15_bkhold, diftime_15_bkpushed, diftime_15_bkrect, x_diftime_15_bkrect, y_diftime_15_bkrect);
	//3��
	LPCTSTR diftime_3_bkwait = _T("images/difficulty/3s_bk_wait.png");
	LPCTSTR diftime_3_bkhold = _T("images/difficulty/3s_bk_hold.png");
	LPCTSTR diftime_3_bkpushed = _T("images/difficulty/3s_bk_pushed.png");
	int x_diftime_3_bkrect = 490, y_diftime_3_bkrect = 540;
	RECT diftime_3_bkrect = { x_diftime_3_bkrect,y_diftime_3_bkrect,x_diftime_3_bkrect + 300,y_diftime_3_bkrect + 125 };
	DifficultyTimeButton diftime3btn(diftime_3_bkwait, diftime_3_bkhold, diftime_3_bkpushed, diftime_3_bkrect, x_diftime_3_bkrect, y_diftime_3_bkrect);
	//5��
	LPCTSTR diftime_5_bkwait = _T("images/difficulty/5s_bk_wait.png");
	LPCTSTR diftime_5_bkhold = _T("images/difficulty/5s_bk_hold.png");
	LPCTSTR diftime_5_bkpushed = _T("images/difficulty/5s_bk_pushed.png");
	int x_diftime_5_bkrect = 490, y_diftime_5_bkrect = 540;
	RECT diftime_5_bkrect = { x_diftime_5_bkrect,y_diftime_5_bkrect,x_diftime_5_bkrect + 300,y_diftime_5_bkrect + 125 };
	DifficultyTimeButton diftime5btn(diftime_5_bkwait, diftime_5_bkhold, diftime_5_bkpushed, diftime_5_bkrect, x_diftime_5_bkrect, y_diftime_5_bkrect);
	//8��
	LPCTSTR diftime_8_bkwait = _T("images/difficulty/8s_bk_wait.png");
	LPCTSTR diftime_8_bkhold = _T("images/difficulty/8s_bk_hold.png");
	LPCTSTR diftime_8_bkpushed = _T("images/difficulty/8s_bk_pushed.png");
	int x_diftime_8_bkrect = 490, y_diftime_8_bkrect = 540;
	RECT diftime_8_bkrect = { x_diftime_8_bkrect,y_diftime_8_bkrect,x_diftime_8_bkrect + 300,y_diftime_8_bkrect + 125 };
	DifficultyTimeButton diftime8btn(diftime_8_bkwait, diftime_8_bkhold, diftime_8_bkpushed, diftime_8_bkrect, x_diftime_8_bkrect, y_diftime_8_bkrect);

	//���������ѶȰ�ť
	//5��
	LPCTSTR difhp_5_bkwait = _T("images/difficulty/5hp_bk_wait.png");
	LPCTSTR difhp_5_bkhold = _T("images/difficulty/5hp_bk_hold.png");
	LPCTSTR difhp_5_bkpushed = _T("images/difficulty/5hp_bk_pushed.png");
	int x_difhp_5_bkrect = 490, y_difhp_5_bkrect = 540;
	RECT difhp_5_bkrect = { x_difhp_5_bkrect,y_difhp_5_bkrect,x_difhp_5_bkrect + 300,y_difhp_5_bkrect + 125 };
	DifficultyHpButton difhp5btn(difhp_5_bkwait, difhp_5_bkhold, difhp_5_bkpushed, difhp_5_bkrect, x_difhp_5_bkrect, y_difhp_5_bkrect);
	//3��
	LPCTSTR difhp_3_bkwait = _T("images/difficulty/3hp_bk_wait.png");
	LPCTSTR difhp_3_bkhold = _T("images/difficulty/3hp_bk_hold.png");
	LPCTSTR difhp_3_bkpushed = _T("images/difficulty/3hp_bk_pushed.png");
	int x_difhp_3_bkrect = 490, y_difhp_3_bkrect = 540;
	RECT difhp_3_bkrect = { x_difhp_3_bkrect,y_difhp_3_bkrect,x_difhp_3_bkrect + 300,y_difhp_3_bkrect + 125 };
	DifficultyHpButton difhp3btn(difhp_3_bkwait, difhp_3_bkhold, difhp_3_bkpushed, difhp_3_bkrect, x_difhp_3_bkrect, y_difhp_3_bkrect);
	//1��
	LPCTSTR difhp_1_bkwait = _T("images/difficulty/1hp_bk_wait.png");
	LPCTSTR difhp_1_bkhold = _T("images/difficulty/1hp_bk_hold.png");
	LPCTSTR difhp_1_bkpushed = _T("images/difficulty/1hp_bk_pushed.png");
	int x_difhp_1_bkrect = 490, y_difhp_1_bkrect = 540;
	RECT difhp_1_bkrect = { x_difhp_1_bkrect,y_difhp_1_bkrect,x_difhp_1_bkrect + 300,y_difhp_1_bkrect + 125 };
	DifficultyHpButton difhp1btn(difhp_1_bkwait, difhp_1_bkhold, difhp_1_bkpushed, difhp_1_bkrect, x_difhp_1_bkrect, y_difhp_1_bkrect);
	
	
	//���а�ť
	LPCTSTR rk_bkwait = _T("images/initmenu/rank/wait.png");
	LPCTSTR rk_bkhold = _T("images/initmenu/rank/hold.png");
	LPCTSTR rk_bkpushed = _T("images/initmenu/rank/pushed.png");
	int x_rk_bkrect = x1, y_rk_bkrect = y0;
	RECT rk_bkrect = { x_rk_bkrect,y_rk_bkrect,x_rk_bkrect + MENUBTN_WIDTH,y_rk_bkrect + MENUBTN_HEIGHT };
	RankButton rkbtn(rk_bkwait, rk_bkhold, rk_bkpushed, rk_bkrect, x_rk_bkrect, y_rk_bkrect);

	//�ɾͽ��水ť
	LPCTSTR ach_bkwait = _T("images/initmenu/achievement/wait.png");
	LPCTSTR ach_bkhold = _T("images/initmenu/achievement/hold.png");
	LPCTSTR ach_bkpushed = _T("images/initmenu/achievement/pushed.png");
	int x_ach_bkrect = x1, y_ach_bkrect = y0 + GAP1;
	RECT ach_bkrect = { x_ach_bkrect,y_ach_bkrect,x_ach_bkrect + MENUBTN_WIDTH,y_ach_bkrect + MENUBTN_HEIGHT };
	AchievementButton achbtn(ach_bkwait, ach_bkhold, ach_bkpushed, ach_bkrect, x_ach_bkrect, y_ach_bkrect);

	//�������ֽ��水ť
	LPCTSTR bgm_bkwait = _T("images/initmenu/bgm/wait.png");
	LPCTSTR bgm_bkhold = _T("images/initmenu/bgm/hold.png");
	LPCTSTR bgm_bkpushed = _T("images/initmenu/bgm/pushed.png");
	int x_bgm_bkrect = x1, y_bgm_bkrect = y0 + GAP1 * 2;
	RECT bgm_bkrect = { x_bgm_bkrect,y_bgm_bkrect,x_bgm_bkrect + MENUBTN_WIDTH,y_bgm_bkrect + MENUBTN_HEIGHT };
	BgmButton bgmbtn(bgm_bkwait, bgm_bkhold, bgm_bkpushed, bgm_bkrect, x_bgm_bkrect, y_bgm_bkrect);

	//�������߽��水ť
	LPCTSTR aba_bkwait = _T("images/initmenu/aboutauthor/wait.png");
	LPCTSTR aba_bkhold = _T("images/initmenu/aboutauthor/hold.png");
	LPCTSTR aba_bkpushed = _T("images/initmenu/aboutauthor/pushed.png");
	int x_aba_bkrect = x1, y_aba_bkrect = y0 + GAP1 * 3;
	RECT aba_bkrect = { x_aba_bkrect,y_aba_bkrect,x_aba_bkrect + MENUBTN_WIDTH,y_aba_bkrect + MENUBTN_HEIGHT };
	AboutAuthorButton ababtn(aba_bkwait, aba_bkhold, aba_bkpushed, aba_bkrect, x_aba_bkrect, y_aba_bkrect);

	
	//���ⰴť
	int	QUESIZE = 110;
	RECT que_bkrect = { 435,45,435+410,45+225 };		//410,225
	LPCTSTR GAMEBK = _T("images/GAMEBK.png");
	wstring NULLW = _T("NULL");
	COLOR NULLC = null;
	Title question(que_bkrect, NULLC, NULLW, GAMEBK,QUESIZE);

	//��Ҳٿذ�ť
	int PLAYERSIZE = 70;
	LPCTSTR PLAYERBK = _T("images/PLAYERBK.png");
	RECT pl_rect1 = { 130,350,370,470 };	//y 350�ȽϺ���24.12.20	240&120
	RECT pl_rect2 = { 390,350,630,470 };
	RECT pl_rect3 = { 650,350,890,470 };
	RECT pl_rect4 = { 910,350,1150,470 };
	RECT pl_rect5 = { 130,350+150,370,470+150 };
	RECT pl_rect6 = { 390,350+150,630,470+150 };
	RECT pl_rect7 = { 650,350+150,890,470+150 };
	RECT pl_rect8 = { 910,350+150,1150,470+150 };

	Ken player1(pl_rect1, NULLC, NULLW, PLAYERBK, PLAYERSIZE);
	Ken player2(pl_rect2, NULLC, NULLW, PLAYERBK, PLAYERSIZE);
	Ken player3(pl_rect3, NULLC, NULLW, PLAYERBK, PLAYERSIZE);
	Ken player4(pl_rect4, NULLC, NULLW, PLAYERBK, PLAYERSIZE);
	Ken player5(pl_rect5, NULLC, NULLW, PLAYERBK, PLAYERSIZE);
	Ken player6(pl_rect6, NULLC, NULLW, PLAYERBK, PLAYERSIZE);
	Ken player7(pl_rect7, NULLC, NULLW, PLAYERBK, PLAYERSIZE);
	Ken player8(pl_rect8, NULLC, NULLW, PLAYERBK, PLAYERSIZE);
}