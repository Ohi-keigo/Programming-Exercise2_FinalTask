#include <iostream>
#include <vector>
#include "class.h"
#include <fstream>
#include <regex>
#include <random>

using namespace std;

vector<int> v1; //�̗͂��i�[����vector
vector<int> v2; //�_�Q�L�U���͂��i�[����vector
vector<int> v3; //�n�T�~�U���͂��i�[����vector
vector<int> v4; //�i�Q�U���͂��i�[����vector
vector<int> v5; //�^�v�f���i�[����vector


void data_read() { //

	ifstream datafile("data.txt");

	regex rx(R"(\s)"); //�󔒂ŕ���
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

	vector<Data> v6; //Data�^��vector�ł���v6���쐬
	size_t t = 0;
	while (t < r) { //vector:v1�Ɠ����T�C�Y����v6�ɃI�u�W�F�N�g��ǉ�
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

	vector<Data> v6; //Data�^��vector�ł���v6���쐬
	size_t t = 0;
	while (t < r) { //vector:v1�Ɠ����T�C�Y����v6�ɃI�u�W�F�N�g��ǉ�
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

	cout << "�M���t�@�m�R�M���N���K�^�����ꂽ�I" << endl;
	cout << endl;
	cout << "���[�������F\n�L�~�͂��̐X�̕��a����邽�߂Ƀ��c��|���Ȃ��Ă͂Ȃ�Ȃ��B�g���̂̓J�u�g���V�I���U�݂͌���[1:�_�Q�L�A2�F�n�T�~�A3:�i�Q]��3��ނ��B";
	cout << "�_�Q�L�̓n�T�~�ɋ����A�n�T�~�̓i�Q�ɋ����A�i�Q�̓_�Q�L�ɋ����B���U�ɂ͂��݂��K�E���U������B�J�u�g���V�̓i�Q�A�M���t�@�m�R�M���N���K�^�̓n�T�~���B�K�E���U�͑�_���[�W��_���邼�I" << endl;
	cout << "����̃��U�����؂��čU�����A�M���t�@�m�R�M���N���K�^��X����ǂ��o����!" << endl;
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


		cout << "�J�u�g���VHP" << "[" << v6[0].gethp() << "]" << "," << "�M���t�@�m�R�M���N���K�^HP" << "[" << v6[1].gethp() << "]" << endl;
		cout << "�L�~�͂ǂ�����H[1:�_�Q�L�A2�F�n�T�~�A3:�i�Q]" << endl;

		if (comp != 1) {
			cout << "����͂�����̕K�E�Z���x�����Ă���I" << endl;
		}

		if (random_damege_k >= 5) {
			cout << "�`�����X���I" << endl;
		}
		if (random_damege_g >= 5) {
			cout << "�}�Y���I" << endl;
		}


		if (advice >= 5 && comp == 1) {
			cout << "�M���t�@�m�R�M���N���K�^�͕K�E�Z�̍\���ł͂Ȃ����I" << endl;
		}
		if (advice >= 5 && comp == 2) {
			cout << "�M���t�@�m�R�M���N���K�^�͕K�E�Z�̍\���ł͂Ȃ����I" << endl;
		}


		cin >> user;

		int diff = (user - comp + 3) % 3;

		if (diff == 0) {
			a = v6[0].gethp() - 2 - random_damege_k;
			b = v6[1].gethp() - 2 - random_damege_k;
			cout << "���ł����I���҂Ƃ���"<<2+random_damege_k<<"�_���[�W" << endl;
		}

		else if (user == 1 && comp == 2) {
			a = v6[0].gethp();
			b = v6[1].gethp() - v6[0].getdageki() - random_damege_k * v6[0].getluck();
			cout << "�J�u�g���V�̃_�Q�L�I�M���t�@�m�R�M���N���K�^��"<< v6[0].getdageki()+random_damege_k*v6[0].getluck() <<"�_���[�W!" << endl;
		}
		else if (user == 2 && comp == 3) {
			a = v6[0].gethp();
			b = v6[1].gethp() - v6[0].gethasami() - random_damege_k * v6[0].getluck();
			cout << "�J�u�g���V�̃n�T�~�I�M���t�@�m�R�M���N���K�^��" << v6[0].gethasami() + random_damege_k * v6[0].getluck() << "�_���[�W!" << endl;
		}
		else if (user == 3 && comp == 1) {
			a = v6[0].gethp();
			b = v6[1].gethp() - v6[0].getnage() - random_damege_k * v6[0].getluck();
			cout << "�J�u�g���V�̃i�Q�I�M���t�@�m�R�M���N���K�^��" << v6[0].getnage() + random_damege_k * v6[0].getluck() << "�_���[�W!" << endl;
		}
		else if (user == 2 && comp == 1) {
			a = v6[0].gethp() - v6[1].getdageki() - random_damege_g * v6[1].getluck();
			b = v6[1].gethp();
			cout << "�M���t�@�m�R�M���N���K�^�̃_�Q�L�I�J�u�g���V��" << v6[1].getdageki() + random_damege_g * v6[1].getluck() << "�_���[�W!" << endl;
		}
		else if (user == 3 && comp == 2) {
			a = v6[0].gethp() - v6[1].gethasami() - random_damege_g * v6[1].getluck();
			b = v6[1].gethp();
			cout << "�M���t�@�m�R�M���N���K�^�̃n�T�~�I�J�u�g���V��" << v6[1].gethasami() + random_damege_g * v6[1].getluck() << "�_���[�W!" << endl;
		}
		else if (user == 1 && comp == 3) {
			a = v6[0].gethp() - v6[1].getnage() - random_damege_g * v6[1].getluck();
			b = v6[1].gethp();
			cout << "�M���t�@�m�R�M���N���K�^�̃i�Q�I�J�u�g���V��" << v6[1].getnage() + random_damege_g * v6[1].getluck() << "�_���[�W!" << endl;
		}

		
		v6[0].sethp(a);
		v6[1].sethp(b);

		
		cout << endl;

		if (v6[1].gethp() <= 0) {
			cout << "WIN" << endl;
			cout << "�X�̕��a�͕ۂ��ꂽ" << endl;
			return 0;
		}

		if (v6[0].gethp() <= 0) {
			cout << "GAME OVER" << endl;
			cout << "�����Ă��܂���...�ڂ̑O���^���ÂɂȂ����B" << endl;
			return 0;
		}

		if (!cin) { //���l�ȊO�͋����Ȃ�
			cin.clear();
			cin.ignore();
			cout << "[1,2,3]�����ꂩ�̐��l����͂��Ă��������B" << endl;
		}
	}
}
