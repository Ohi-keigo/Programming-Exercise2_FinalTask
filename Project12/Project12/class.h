using namespace std;

class Data { //5��̐����l����Ȃ�N���XData���쐬
protected:

	int hp;

	int dageki;
	int hasami;
	int nage;

	int luck;

public:

	void sethp(int& newhp) { hp = newhp; }
	int gethp() { return hp; }

	void setdageki(const int& newdageki) { dageki = newdageki; }
	int getdageki() { return dageki; }
	void sethasami(const int& newhasami) { hasami = newhasami; }
	int gethasami() { return hasami; }
	void setnage(const int& newnage) { nage = newnage; }
	int getnage() { return nage; }


	void setluck(const int& newluck) { luck = newluck; }
	int getluck() { return luck; }

};
