#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<windows.h>

using namespace std;

float a, b, c;
void swap(float x, float y){
	float temporay;
	temporay = x;
	x = y;
	y = temporay;
}

int solve(float M[3][4]){
	for (int t1 = 0; t1 < 2; t1++){
		for (int t2 = 0; t2 < 2 - t2 - 1; t2++){
			if (abs(M[t2][0]) < abs(M[t2 + 1][0])){
				for (int t3 = 0; t3 <= 3; t3++){
					swap(M[t2][t3], M[t2 - 1][t3]);
				}
			}
		}
	}

	if (!abs(M[0][0]) < 0.0001){
		float temp = M[0][0];
		for (int a = 0; a <= 3; a++){
			M[0][a] = M[0][a] / temp;
		}
		temp = M[1][0];
		for (int a = 0; a <= 3; a++){
			M[1][a] = M[1][a] - (M[0][a] * temp);
		}
		temp = M[2][0];
		for (int a = 0; a <= 3; a++){
			M[2][a] = M[2][a] - (M[0][a] * temp);
		}
		if (abs(M[1][1])<abs(M[2][1])){
			for (int a = 1; a <= 3; a++){
				swap(M[2][a], M[1][a]);
			}
		}
		if (!abs(M[1][1]) < 0.0001){
			temp = M[1][1];
			for (int a = 1; a <= 3; a++){
				M[1][a] = M[1][a] / temp;
			}
			temp = M[0][1];
			for (int a = 1; a <= 3; a++){
				M[0][a] = M[0][a] - (M[1][a] * temp);
			}
			temp = M[2][1];
			for (int a = 0; a <= 3; a++){
				M[2][a] = M[2][a] - (M[1][a] * temp);
			}

			if (!abs(M[2][2]) < 0.0001){
				temp = M[2][2];
				for (int a = 2; a <= 3; a++){
					M[2][a] = M[2][a] / temp;
				}
				temp = M[0][2];
				for (int a = 2; a <= 3; a++){
					M[0][a] = M[0][a] - (M[2][a] * temp);
				}
				temp = M[1][2];
				for (int a = 0; a <= 3; a++){
					M[1][a] = M[1][a] - (M[2][a] * temp);
				}
				a = M[0][3];
				b = M[1][3];
				c = M[2][3];
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}


int main(){
	float M[3][4] = { { 8, 5, 4, 7 }, { 1, 2, 3, 4 }, { 4, 7, 5, 7 } };
	if (solve(M)){
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}
	else{
		cout << "solution not exist" << endl;
	}
	_getch();
}