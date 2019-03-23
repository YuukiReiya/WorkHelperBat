/*!
	@file	Entry.cpp
	@date	2019/03/06
	@author	番場 宥輝
	@brief	Windowsのエントリーポイント
*/
#include <cstdio>
#include "MAIN.h"

/*!
	@var	g_pMain
*/
MAIN* g_pMain;

/*!
	@fn		Main
	@brief	エントリーポイント
*/
int main()
{
	g_pMain = new MAIN;

	g_pMain->Setup();
	g_pMain->Input();
	return 0;
}