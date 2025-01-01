#pragma once
#include"prop.h"
#include<iostream>
using std::ofstream;
using std::ifstream;

//初始化道具文件
void initproptxt() {
	int x = 3;
	ofstream ofs;
	ofs.open("datas/prop/suspend.txt", std::ios::out | std::ios::binary);
	ofs.write((const char*)&x, sizeof(int));
	ofs.close();
	ofs.open("datas/prop/goldapple.txt", std::ios::out | std::ios::binary);
	ofs.write((const char*)&x, sizeof(int));
	ofs.close();
	ofs.open("datas/prop/undead.txt", std::ios::out | std::ios::binary);
	ofs.write((const char*)&x, sizeof(int));
	ofs.close();
	ofs.open("datas/prop/hamburger.txt", std::ios::out | std::ios::binary);
	ofs.write((const char*)&x, sizeof(int));
	ofs.close();

	int n;
	ifstream ifs;
	ifs.open("datas/prop/suspend.txt", std::ios::out | std::ios::binary);
	ifs.read((char*)&n, sizeof(int));
	std::cout << n << std::endl;
	ifs.close();
	ifs.open("datas/prop/goldapple.txt", std::ios::out | std::ios::binary);
	ifs.read((char*)&n, sizeof(int));
	std::cout << n << std::endl;
	ifs.close();
	ifs.open("datas/prop/undead.txt", std::ios::out | std::ios::binary);
	ifs.read((char*)&n, sizeof(int));
	std::cout << n << std::endl;
	ifs.close();
	ifs.open("datas/prop/hamburger.txt", std::ios::out | std::ios::binary);
	ifs.read((char*)&n, sizeof(int));
	std::cout << n << std::endl;
	ifs.close();
}

namespace PropSpace {
	bool SUSPEND = false, GOLDAPPLE = false, UNDEAD = false, HAMBURGER = false;
	int propx1 = 215, propx2 = 215+95+10, propy1 = 95, propy2 = 95+95+10;
	int PROPWIDTH = 75, PROPHEIGHT = 75;
	//时停道具
	LPCTSTR suspendtime = _T("images/prop/suspend.png");
	LPCTSTR numloc_sus = _T("datas/prop/suspend.txt");
	LPCTSTR sus_msop = _T("open music/suspend.mp3");
	LPCTSTR sus_mspl = _T("play music/suspend.mp3");
	LPCTSTR sus_mspcl = _T("close music/suspend.mp3");
	PROP suspendbtn(suspendtime, numloc_sus, sus_msop, sus_mspl, sus_mspcl, 210, 95, '1', PROPWIDTH, PROPHEIGHT, &SUSPEND);

	//金苹果道具
	LPCTSTR goldapple = _T("images/prop/goldapple.png");
	LPCTSTR numloc_app = _T("datas/prop/goldapple.txt");
	LPCTSTR app_msop = _T("open music/eatapple.mp3");
	LPCTSTR app_mspl = _T("play music/eatapple.mp3");
	LPCTSTR app_mspcl = _T("close music/eatapple.mp3");
	PROP goldapplebtn(goldapple, numloc_app, app_msop, app_mspl, app_mspcl, 210, 95, '2', PROPWIDTH, PROPHEIGHT, &GOLDAPPLE);

	//不死图腾道具
	LPCTSTR undead = _T("images/prop/undead.png");
	LPCTSTR numloc_und = _T("datas/prop/undead.txt");
	LPCTSTR und_msop = _T("open music/use_undead.mp3");
	LPCTSTR und_mspl = _T("play music/use_undead.mp3");
	LPCTSTR und_mspcl = _T("close music/use_undead.mp3");
	PROP undeadbtn(undead, numloc_und, und_msop, und_mspl, und_mspcl, 210, 95, '3', PROPWIDTH, PROPHEIGHT, &UNDEAD);

	//汉堡道具
	LPCTSTR hamburger = _T("images/prop/hamburger.png");
	LPCTSTR numloc_ham = _T("datas/prop/hamburger.txt");
	LPCTSTR ham_msop = _T("open music/hamburger.mp3");
	LPCTSTR ham_mspl = _T("play music/hamburger.mp3");
	LPCTSTR ham_mspcl = _T("close music/hamburger.mp3");
	PROP hamburgerbtn(hamburger, numloc_ham, ham_msop, ham_mspl, ham_mspcl, 210, 95, '3', PROPWIDTH, PROPHEIGHT, &HAMBURGER);
}
