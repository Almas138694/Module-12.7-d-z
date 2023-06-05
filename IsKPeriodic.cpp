#include <iostream>
using namespace std;

void IsKPeriodic(const string& txt, const std::string& pad, int k)
{
	const int n = txt.size();

	int s = 0;	
	int i = 0;
	int j = 0;
	int* arr = new int[n] {0};
	while (i < n)
	{
		if (pad[j] == txt[i] && j < pad.size()) {
			s++;
			arr[s-1] = i;
			j++;
			i++;
		}
		if (j >= pad.size())
			j = 0;

		while (pad[j] != txt[i] && i < n)
			i++;		
	}
	char* arr2 = new char[s] {0};

		int sum = s % k;
		if (sum != 0) {
			cout << endl << "Не кратно " << k << endl;
		}
		else
		{
			for (int h = 0; h < s; h++)
			{
				int a = arr[h];
				arr2[h] = txt[a];
				cout << arr2[h];
			}
				cout << endl << "кратно " << k << endl;
		}
}
int main()
{
	setlocale(0, "rus");
	std::string txt = "abcabcabcabc";
	std::string pad;
	std::cout << "Ввидите подстраку: ";
	std::cin >> pad;
	int k = 0;
	std::cout << "Видите число для проверки кратности: ";
	std::cin >> k;
	IsKPeriodic(txt, pad, k);
}