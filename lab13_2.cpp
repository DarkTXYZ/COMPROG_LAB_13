#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double A[][N]){
	for(int i = 0 ; i < N ; ++i){
		cout << "Row " << i+1 << ": ";
		for(int j = 0 ; j < N ; ++j)
			cin >> A[i][j];
	}
}

void findLocalMax(const double A[][N], bool B[][N]){
	int dx[] = {1,0,-1,0};
	int dy[] = {0,1,0,-1};
	for(int i = 0 ; i < N  ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(i == 0 || j == 0 || i == N - 1 || j == N - 1){
				B[i][j] = false;
				continue;
			}
			bool pass = true;
			for(int k = 0 ; k < 4 ; ++k){
				if(A[i][j] < A[i+dx[k]][j+dy[k]])
					pass = false;
			}
			B[i][j] = pass;
		}
	}
}

void showMatrix(const bool B[][N]){
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
}
/*
1 2 0 3 5
0 8 7 -1 2
4 4 3 5 1
0 0 1 6 0
1 2 3 4 5
*/

/*
1.1 1.2 1 2 1
0 -1.1 1 0 0
0 1 1 1 0
1.2 1.8 1.3 -0.5 0
0 1.5 0 1 -1.5
*/