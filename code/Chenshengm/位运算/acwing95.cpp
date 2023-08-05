#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
#include<string>
int cal(int line, int sum, int mat[7][7]);
int matr[7][7] = { 0 };
int sum = 0;
void click(int x, int y, int mat[7][7])
{
	mat[x][y] = !mat[x][y];
	mat[x + 1][y] = !mat[x + 1][y];
	mat[x - 1][y] = !mat[x - 1][y];
	mat[x][y + 1] = !mat[x][y + 1];
	mat[x][y - 1] = !mat[x][y - 1];
}
int minnum = -1;
void stick1(int row)
{
	if (row == 6)
	{
		int matCopy[7][7]; // Create a local copy of the matrix

		// Copy the original matrix to the local copy
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				matCopy[i][j] = matr[i][j];
			}
		}
		int k = cal(1, sum, matCopy);
		if (minnum == -1)
		{
			minnum = k;
		}
		else if (k != -1)
		{
			minnum = min(minnum, k);
		}
		return;
	}
	stick1(row + 1);

	//点
	click(1, row, matr);
	sum++;
	stick1(row + 1);

	//回溯
	click(1, row, matr);
	sum--;

}


int cal(int line, int sum, int mat[7][7])
{
	if (line == 5)
	{
		for (int i = 1; i < 6; i++)
		{
			if (mat[5][i] != 1)
			{
				return -1;
			}
		}
		if (sum > 6)
		{
			return -1;
		}
		return sum;
	}
	for (int i = 1; i < 6; i++)
	{
		if (mat[line][i] == 0)
		{
			click(line + 1, i, mat);
			sum++;
		}
	}
	cal(line + 1, sum, mat);
}
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		for (int i = 1; i < 6; i++)
		{
			string s;
			cin >> s;
			for (int j = 1; j < 6; j++)
			{
				matr[i][j] = s[j - 1] - '0';

			}
		}
		//固定第一行
		stick1(1);
		cout << minnum << endl;
		minnum = -1;
	}
}

