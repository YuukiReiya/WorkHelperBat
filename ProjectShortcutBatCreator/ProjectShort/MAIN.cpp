#include "MAIN.h"

using namespace std;
using namespace std::filesystem;


MAIN::MAIN()
{
	m_path = current_path().generic_string();
}

MAIN::~MAIN()
{
}

/*!
	@brief	������
*/
void MAIN::Setup()
{
	cout << "�f�B���N�g���̃p�X����͂��Ă��������B" << endl
		<< "�� �u null , 0 , NULL �v����͂���ƌ��݂̃J�����g�p�X����\�����[�V������ݒ肵�܂�"
		<< endl
		<< "���̏ꍇ�A�g���q.sln�̓��K�w�ɔz�u�����s���Ă��������B(�v���W�F�N�g�� = .sln���ł���K�v������܂�)"
		<< endl << endl << "PATH:";

	cout << endl;
}

/*!
	@brief	�\��
*/
void MAIN::Display()
{
}

/*!
	@brief	����
*/
void MAIN::Input()
{
	
	cin >> m_path;

	if (IsSetupCurrentDirectry(m_path)) {
		SetupCurrentDirectry(m_path);
	}

	//	�p�X�m�F
	if (!IsFileExists(m_path)) {
		return;
	}

	//if (IsSetupCurrentDirectry(m_path)) 
	//{
	//	SetupCurrentDirectry(m_path);
	//}

	MakeBatFile();
	cout << endl;
	system("pause");
}

/*!
	@brief	�J�����g�f�B���N�g����ݒ肷�邩����
*/
bool MAIN::IsSetupCurrentDirectry(std::filesystem::path value)
{
	for (auto itr : c_SpecifyCurrentDirectoryKeyword)
	{
		if (value == itr.data()) 
		{
			return true;
		}
	}
	return false;
}

/*!
	@brief	�J�����g�f�B���N�g����ݒ肷��	
*/
void MAIN::SetupCurrentDirectry(path&value)
{
	error_code error;
	value = current_path(error);

	//	�G���[�R�[�h
	if (error.value() != c_OK) {
		cout << "�J�����g�f�B���N�g���̐ݒ�Ɏ��s�B" << endl
			<< "�����𒆎~���܂��B" << endl;
		cout << error.value() << ":" << error.message() << endl;
		return;
	}

	//	���b�Z�[�W
	cout << "�ȉ����J�����g�f�B���N�g����ݒ肵�܂����B" << endl
		<< value << endl;
}

/*!
	@brief	�t�@�C��(�f�B���N�g��)�̑��݂��m�F
*/
bool MAIN::IsFileExists(std::filesystem::path value)
{
	if (!exists(value)) 
	{
		cout << value.generic_string().c_str() << "�͑��݂��܂���B" << endl
			<< "�p�X���m�F���Ă��������B" << endl;
		return false;
	}

	return true;
}

/*!
	@brief	.bat�t�@�C���̍쐬
*/
void MAIN::MakeBatFile()
{
	ofstream ofs;
	string fileName = m_path.filename().generic_string();
	string filePath = m_path.generic_string() + ".bat";
	ofs.open(filePath);

	//	�f�B���N�g�������݂��Ȃ�
	if (!exists(m_path)) { 
		cout << "�t�H���_�����݂��܂���ł����B" << endl;
		ofs.close();
		return; 
	}
	ofs << "cd " << m_path << endl
		<< "explorer ." << endl;

	string slnPath = fileName + ".sln";

	//	�\�����[�V�����t�@�C�������݂��Ȃ�
	if (!exists(slnPath)) {
		cout << "�\�����[�V���������݂��܂���ł����B" << endl
			<<"�Y���t�H���_�̂݊J���o�b�`�t�@�C�����쐬���܂��B";
		ofs.close();
		return;
	}
	ofs << "start " << slnPath;
	ofs.close();
}
