/*!
	@file	MAIN.h
	@date	2019/03/23
	@author	番場 宥輝
	@brief	メインクラス
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
		@brief	正常終了時の戻り値 
		@detail	これ以外はエラー扱い
	*/
	static constexpr int c_OK = 0;

	/*!
		@brief	文字列バッファのサイズ
	*/
	static constexpr unsigned int c_MaxBufferSize = 1024;

	/*!
		@var	c_SpecifyCurrentDirectoryKeyword
		@brief	カレントディレクトリを指定するキーワード
	*/
	static constexpr std::string_view c_SpecifyCurrentDirectoryKeyword[] = { "null","NULL","0" };
	//static constexpr std::string_view c_SpecifyCurrentDirectoryKeyword = "d";
};

