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
	@brief	初期化
*/
void MAIN::Setup()
{
	cout << "ディレクトリのパスを入力してください。" << endl
		<< "※ 「 null , 0 , NULL 」を入力すると現在のカレントパスからソリューションを設定します"
		<< endl
		<< "その場合、拡張子.slnの同階層に配置し実行してください。(プロジェクト名 = .sln名である必要もあります)"
		<< endl << endl << "PATH:";

	cout << endl;
}

/*!
	@brief	表示
*/
void MAIN::Display()
{
}

/*!
	@brief	入力
*/
void MAIN::Input()
{
	
	cin >> m_path;

	if (IsSetupCurrentDirectry(m_path)) {
		SetupCurrentDirectry(m_path);
	}

	//	パス確認
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
	@brief	カレントディレクトリを設定するか判定
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
	@brief	カレントディレクトリを設定する	
*/
void MAIN::SetupCurrentDirectry(path&value)
{
	error_code error;
	value = current_path(error);

	//	エラーコード
	if (error.value() != c_OK) {
		cout << "カレントディレクトリの設定に失敗。" << endl
			<< "処理を中止します。" << endl;
		cout << error.value() << ":" << error.message() << endl;
		return;
	}

	//	メッセージ
	cout << "以下をカレントディレクトリを設定しました。" << endl
		<< value << endl;
}

/*!
	@brief	ファイル(ディレクトリ)の存在を確認
*/
bool MAIN::IsFileExists(std::filesystem::path value)
{
	if (!exists(value)) 
	{
		cout << value.generic_string().c_str() << "は存在しません。" << endl
			<< "パスを確認してください。" << endl;
		return false;
	}

	return true;
}

/*!
	@brief	.batファイルの作成
*/
void MAIN::MakeBatFile()
{
	ofstream ofs;
	string fileName = m_path.filename().generic_string();
	string filePath = m_path.generic_string() + ".bat";
	ofs.open(filePath);

	//	ディレクトリが存在しない
	if (!exists(m_path)) { 
		cout << "フォルダが存在しませんでした。" << endl;
		ofs.close();
		return; 
	}
	ofs << "cd " << m_path << endl
		<< "explorer ." << endl;

	string slnPath = fileName + ".sln";

	//	ソリューションファイルが存在しない
	if (!exists(slnPath)) {
		cout << "ソリューションが存在しませんでした。" << endl
			<<"該当フォルダのみ開くバッチファイルを作成します。";
		ofs.close();
		return;
	}
	ofs << "start " << slnPath;
	ofs.close();
}
