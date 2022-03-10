#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** a, const int k, const int n, const int Low, const int High);
void Print1(int** a, const int k, const int n);
int Math(int** a, int* b, const int k, const int n);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 10;
	int n;
	int k;
	int z = 0;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	int** a = (int**) new int[k][5];
	int* b = new int[k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High);
	Print1(a, k, n);
	Math(a, b, k, n);
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	delete[] b;
	return 0;
}
void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);

}
void Print1(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int Math(int** a, int* b, const int k, const int n) {
	int s=0;
	for (int i = 0;i < k;i++) {
		for (int j = 0;j < n;j++) {
			if (a[i][j] < 0) {
				for (int z = 0;z < k;z++) {
					s += a[z][j];
				}
				b[j] = s;
				s = 0;
			}
		}
	}
	for (int x = 0;x < n;x++) {
		cout << b[x] << endl;
	}
	return 0;
}