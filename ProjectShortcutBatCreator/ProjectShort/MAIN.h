/*!
	@file	MAIN.h
	@date	2019/03/23
	@author	�ԏ� �G�P
	@brief	���C���N���X
*/
#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string_view>

class MAIN
{
public:
	explicit MAIN();
	~MAIN();

	void Setup();
	void Display();
	void Input();
private:
	bool IsSetupCurrentDirectry(std::filesystem::path value);
	void SetupCurrentDirectry(std::filesystem::path& value);
	bool IsFileExists(std::filesystem::path value);
	void MakeBatFile();

	//std::string m_path;
	std::string m_input;
	std::filesystem::path m_path;
	/*!
		@var	c_OK
		@brief	����I�����̖߂�l 
		@detail	����ȊO�̓G���[����
	*/
	static constexpr int c_OK = 0;

	/*!
		@brief	������o�b�t�@�̃T�C�Y
	*/
	static constexpr unsigned int c_MaxBufferSize = 1024;

	/*!
		@var	c_SpecifyCurrentDirectoryKeyword
		@brief	�J�����g�f�B���N�g�����w�肷��L�[���[�h
	*/
	static constexpr std::string_view c_SpecifyCurrentDirectoryKeyword[] = { "null","NULL","0" };
	//static constexpr std::string_view c_SpecifyCurrentDirectoryKeyword = "d";
};

