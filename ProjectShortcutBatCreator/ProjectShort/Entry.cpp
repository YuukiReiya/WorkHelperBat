/*!
	@file	Entry.cpp
	@date	2019/03/06
	@author	�ԏ� �G�P
	@brief	Windows�̃G���g���[�|�C���g
*/
#include <cstdio>
#include "MAIN.h"

/*!
	@var	g_pMain
*/
MAIN* g_pMain;

/*!
	@fn		Main
	@brief	�G���g���[�|�C���g
*/
int main()
{
	g_pMain = new MAIN;

	g_pMain->Setup();
	g_pMain->Input();
	return 0;
}