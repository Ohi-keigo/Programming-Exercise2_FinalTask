#include <iostream>
#include <vector>
#include "class.h"
#include <fstream>
#include <regex>
#include <random>

using namespace std;

vector<int> v1; //体力を格納するvector
vector<int> v2; //ダゲキ攻撃力を格納するvector
vector<int> v3; //ハサミ攻撃力を格納するvector
vector<int> v4; //ナゲ攻撃力を格納するvector
vector<int> v5; //運要素を格納するvector


void data_read() { //

	ifstream datafile("data.txt");

	regex rx(R"(\s)"); //空白で分割
	string strd;

	int a;
	int b;
	int c;
	int d;
	int e;

	while (getline(datafile, strd)) {
		sregex_token_iterator it(strd.begin(), strd.end(), rx, -1);
		sregex_token_iterator end;
		while (it != end) {

			a = stoi((it++)->str());
			b = stoi((it++)->str());
			c = stoi((it++)->str());
			d = stoi((it++)->str());
			e = stoi((it++)->str());

		}
		v1.push_back(a);
		v2.push_back(b);
		v3.push_back(c);
		v4.push_back(d);
		v5.push_back(e);

	}
	datafile.close();
}

void data_set() {
	size_t r = v1.size();

	vector<Data> v6; //Data型のvectorであるv6を作成
	size_t t = 0;
	while (t < r) { //vector:v1と同じサイズだけv6にオブジェクトを追加
		v6.emplace_back();
		t++;
	}
	size_t s = v6.size();
	for (size_t i = 0; i < s; i++) {

		v6[i].sethp(v1[i]);
		v6[i].setdageki(v2[i]);
		v6[i].sethasami(v3[i]);
		v6[i].setnage(v4[i]);
		v6[i].setluck(v5[i]);
	}
}


int main() {
	data_read();

	size_t r = v1.size();

	vector<Data> v6; //Data型のvectorであるv6を作成
	size_t t = 0;
	while (t < r) { //vector:v1と同じサイズだけv6にオブジェクトを追加
		v6.emplace_back();
		t++;
	}
	size_t s = v6.size();

	for ( size_t i = 0; i < s; i++) {

		v6[i].sethp(v1[i]);
		v6[i].setdageki(v2[i]);
		v6[i].sethasami(v3[i]);
		v6[i].setnage(v4[i]);
		v6[i].setluck(v5[i]);

	}

	cout << "ギラファノコギリクワガタが現れた！" << endl;
	cout << endl;
	cout << "ルール説明：\nキミはこの森の平和を守るためにヤツを倒さなくてはならない。使うのはカブトムシ！ワザは互いに[1:ダゲキ、2：ハサミ、3:ナゲ]の3種類だ。";
	cout << "ダゲキはハサミに強く、ハサミはナゲに強く、ナゲはダゲキに強い。ワザにはお互い必殺ワザがある。カブトムシはナゲ、ギラファノコギリクワガタはハサミだ。必殺ワザは大ダメージを狙えるぞ！" << endl;
	cout << "相手のワザを見切って攻撃し、ギラファノコギリクワガタを森から追い出そう!" << endl;
	cout << endl;

	while (1) {

		int a;
		int b;

		int user;
		int comp;
		int random_damege_k;
		int random_damege_g;
		int advice;
		
		random_device r;
		uniform_int_distribution<unsigned> dist1(1, 3);
		uniform_int_distribution<unsigned> dist2(1, 5);
		uniform_int_distribution<unsigned> dist3(1, 5);
		comp = dist1(r);
		random_damege_k = dist2(r);
		random_damege_g = dist2(r);
		advice = dist3(r);


		cout << "カブトムシHP" << "[" << v6[0].gethp() << "]" << "," << "ギラファノコギリクワガタHP" << "[" << v6[1].gethp() << "]" << endl;
		cout << "キミはどうする？[1:ダゲキ、2：ハサミ、3:ナゲ]" << endl;

		if (comp != 1) {
			cout << "相手はこちらの必殺技を警戒している！" << endl;
		}

		if (random_damege_k >= 5) {
			cout << "チャンスだ！" << endl;
		}
		if (random_damege_g >= 5) {
			cout << "マズい！" << endl;
		}


		if (advice >= 5 && comp == 1) {
			cout << "ギラファノコギリクワガタは必殺技の構えではないぞ！" << endl;
		}
		if (advice >= 5 && comp == 2) {
			cout << "ギラファノコギリクワガタは必殺技の構えではないぞ！" << endl;
		}


		cin >> user;

		int diff = (user - comp + 3) % 3;

		if (diff == 0) {
			a = v6[0].gethp() - 2 - random_damege_k;
			b = v6[1].gethp() - 2 - random_damege_k;
			cout << "相打ちだ！両者ともに"<<2+random_damege_k<<"ダメージ" << endl;
		}

		else if (user == 1 && comp == 2) {
			a = v6[0].gethp();
			b = v6[1].gethp() - v6[0].getdageki() - random_damege_k * v6[0].getluck();
			cout << "カブトムシのダゲキ！ギラファノコギリクワガタに"<< v6[0].getdageki()+random_damege_k*v6[0].getluck() <<"ダメージ!" << endl;
		}
		else if (user == 2 && comp == 3) {
			a = v6[0].gethp();
			b = v6[1].gethp() - v6[0].gethasami() - random_damege_k * v6[0].getluck();
			cout << "カブトムシのハサミ！ギラファノコギリクワガタに" << v6[0].gethasami() + random_damege_k * v6[0].getluck() << "ダメージ!" << endl;
		}
		else if (user == 3 && comp == 1) {
			a = v6[0].gethp();
			b = v6[1].gethp() - v6[0].getnage() - random_damege_k * v6[0].getluck();
			cout << "カブトムシのナゲ！ギラファノコギリクワガタに" << v6[0].getnage() + random_damege_k * v6[0].getluck() << "ダメージ!" << endl;
		}
		else if (user == 2 && comp == 1) {
			a = v6[0].gethp() - v6[1].getdageki() - random_damege_g * v6[1].getluck();
			b = v6[1].gethp();
			cout << "ギラファノコギリクワガタのダゲキ！カブトムシに" << v6[1].getdageki() + random_damege_g * v6[1].getluck() << "ダメージ!" << endl;
		}
		else if (user == 3 && comp == 2) {
			a = v6[0].gethp() - v6[1].gethasami() - random_damege_g * v6[1].getluck();
			b = v6[1].gethp();
			cout << "ギラファノコギリクワガタのハサミ！カブトムシに" << v6[1].gethasami() + random_damege_g * v6[1].getluck() << "ダメージ!" << endl;
		}
		else if (user == 1 && comp == 3) {
			a = v6[0].gethp() - v6[1].getnage() - random_damege_g * v6[1].getluck();
			b = v6[1].gethp();
			cout << "ギラファノコギリクワガタのナゲ！カブトムシに" << v6[1].getnage() + random_damege_g * v6[1].getluck() << "ダメージ!" << endl;
		}

		
		v6[0].sethp(a);
		v6[1].sethp(b);

		
		cout << endl;

		if (v6[1].gethp() <= 0) {
			cout << "WIN" << endl;
			cout << "森の平和は保たれた" << endl;
			return 0;
		}

		if (v6[0].gethp() <= 0) {
			cout << "GAME OVER" << endl;
			cout << "負けてしまった...目の前が真っ暗になった。" << endl;
			return 0;
		}

		if (!cin) { //数値以外は許さない
			cin.clear();
			cin.ignore();
			cout << "[1,2,3]いずれかの数値を入力してください。" << endl;
		}
	}
}
