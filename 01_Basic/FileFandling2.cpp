#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main () {
  string str_buf;
  string str_conma_buf;
  string input_csv_file_path  = "FileHandling1.csv";
  string output_csv_file_path = "FileHandling2.csv";

  // 読み込むcsvファイルを開く(ifstreamのコンストラクタで開く)
  ifstream ifs_csv_file(input_csv_file_path  );

  // 書き込むcsvファイルを開く(ofstreamのコンストラクタで開く)
  ofstream ofs_csv_file(output_csv_file_path );

  // getline関数で1行ずつ読み込む(読み込んだ内容はstr_bufに格納)
  while (getline(ifs_csv_file, str_buf)) {    
    // 「,」区切りごとにデータを読み込むためにistringstream型にする
    istringstream i_stream(str_buf);

    // 「,」区切りごとにデータを読み込む
    while (getline(i_stream, str_conma_buf, ',')) {
       // csvファイルに書き込む
       ofs_csv_file << str_conma_buf << ',';
       cout << str_conma_buf << "\n";
    }
    // 改行する
    ofs_csv_file << endl;
  }

  // クローズ処理は不要[理由]ifstream型・ofstream型ともにデストラクタにてファイルクローズしてくれるため
}