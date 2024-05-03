#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MAXV = 20;
struct MaTranKe {
	int mtk[MAXV][MAXV];
	int n;
};

//Ham doc ma tran ke tu file van ban
bool docMaTran(const char* file, MaTranKe& maTran) {
	FILE* filePointer = fopen(file, "rt");
	if (filePointer == NULL) return false;
	fscanf(filePointer, "%d", &maTran.n);
	for (int i = 0; i < maTran.n; i++)
	{
		for (int j = 0; j < maTran.n; j++)
		{
			fscanf(filePointer, "%d", &maTran.mtk[i][j]);
		}
	}
	fclose(filePointer);
	return true;
}

//Ham xuat ma tran ke
void inMaTran(MaTranKe maTran) {
	for (int i = 0; i < maTran.n; i++)
	{
		cout << endl;
		for (int j = 0; j < maTran.n; j++)
		{
			cout << maTran.mtk[i][j] << " ";
		}
	}
}


//Ham tra ve so canh cua do thi 
int demSoCanh(MaTranKe maTran) {
	int count = 0;
	for (int i = 0; i < maTran.n; i++)
	{
		for (int j = 0; j < maTran.n; j++)
		{
			if (maTran.mtk[i][j] != 0)
				count++;
		}
	}
	return count;
}

//Ham tinh bac ra cua dinh u trong do thi
int soBacRa(MaTranKe maTran, int u) {
	int count = 0;
	for (int i = 0; i < maTran.n; i++) {
		if (maTran.mtk[u][i] != 0) {
			count++;
		}
	}
	return count;
}

//Ham tim canh co trong so V lon nhat cua dinh U
int timCanhLonNhatCuaDinh(MaTranKe maTran, int u, int& v) {
	for (int i = 0; i < maTran.n; i++) {
		if (maTran.mtk[u][i] > v) {
			v = maTran.mtk[u][i];
		}
	}
	return v;
}

int main() {
	MaTranKe maTran;
	if (docMaTran("MaTranKe.txt", maTran) == true) {
		cout << "Ma tran co: ";
		inMaTran(maTran);
		cout << "\nSo canh cua do thi: " << demSoCanh(maTran);
	}
	else 
		cout << "\nKhong doc duoc ma tran." << endl;

	int u;
	cout << "\n\nNhap bac muon kiem tra so bac ra: "; cin >> u;
	cout << "Bac cua "<< u << ": "  << soBacRa(maTran, u);

	int x, v = 0;
	cout << "\n\nNhap bac muon tim canh co trong so lon nhat: "; cin >> x;
	cout << "Canh co trong so lon nhat cua " << x << " la: " << timCanhLonNhatCuaDinh(maTran, x, v);

	return 0;
}