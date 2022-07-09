#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

class On
{
	int* occurances;
	int size;

public:
	On():size(0), occurances(NULL) {};

	bool anagram(string s1, string s2)
	{
		if (s1.length() != s2.length())
			return false;
		
		int sizeofstring = s1.length();

		size = 26;
		occurances = new int[size] {0};

		for_each(s1.begin(), s1.end(), [](char& c) {
			c = ::tolower(c);
		});

		for_each(s2.begin(), s2.end(), [](char& c) {
			c = ::tolower(c);
			});

		for (int i = 0; i < sizeofstring; i++)
		{
			occurances[(int(s1[i])) - 97]++;
			occurances[(int(s2[i])) - 97]--;
		}

		for (int i = 0; i < size; i++)
		{
			if (occurances[i] != 0)
			{
				clear();
				return false;
			}
		}
		clear();
		return true;
	}

	int minimum(int* arr, int size)
	{
		if (size > 0)
		{
			int m = arr[0];
			for (int i = 1; i < size; i++)
			{
				if (m > arr[i])
					m = arr[i];
			}
			return m;
		}
		return -1;
	}

	int maximum(int arr[], int size)
	{
		if (size > 0)
		{
			int m = arr[0];
			for (int i = 1; i < size; i++)
			{
				if (m < arr[i])
					m = arr[i];
			}
			return m;
		}
		return -1;
	}

	void sorting(int arr1[], int arr2[], int s1, int s2)
	{
		int min = minimum(arr1, s1);
		int max = maximum(arr1, s1);

		size = max - min + 1;

		occurances = new int[size] {0};

		for (int i = 0; i < s1; i++)
		{
			occurances[arr1[i]-min]++;
		}

		/*
		for (int i = 0; i < size; i++)
		{
			cout << occurances[i] << "  ";
		}
		cout << endl;
		*/

		for (int i = 0; i < s2; i++)
		{
			for (int j = 0; j < occurances[arr2[i] - min];)
			{
				cout << arr2[i] << "  ";
				occurances[arr2[i] - min]--;
			}
		}

		
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < occurances[i];)
			{
				cout << i + min << "  ";
				occurances[i]--;
			}
		}
		clear();
	}

	void intersection(int arr1[], int arr2[], int s1, int s2)
	{
		int min1 = minimum(arr1, s1);
		int min2 = minimum(arr2, s2);
		int max1 = maximum(arr1, s1);
		int max2 = maximum(arr2, s2);
		int min = (min1 < min2) ? min1 : min2;
		int max = (max1 > max2) ? max1 : max2;

		size = max - min + 1;
		occurances = new int [size] {0};

		for (int i = 0; i < s1; i++)
		{
			occurances[arr1[i] - min] = true;
		}

		for (int i = 0; i < s2; i++)
		{
			if (occurances[arr2[i] - min])
			{
				cout << arr2[i] << "  ";
			}
		}
	}

	void _union(int arr1[], int arr2[], int s1, int s2)
	{
		int min1 = minimum(arr1, s1);
		int min2 = minimum(arr2, s2);
		int max1 = maximum(arr1, s1);
		int max2 = maximum(arr2, s2);
		int min = (min1 < min2) ? min1 : min2;
		int max = (max1 > max2) ? max1 : max2;

		size = max - min + 1;
		occurances = new int [size] {0};

		for (int i = 0; i < s1; i++)
		{
			occurances[arr1[i] - min] = true;
			cout << arr1[i] << "  ";
		}

		for (int i = 0; i < s2; i++)
		{
			if (!occurances[arr2[i] - min])
			{
				occurances[arr2[i] - min] = true;
				cout << arr2[i] << "  ";
			}
		}
	}

	void clear()
	{
		if (size > 0)
			delete[] occurances;
		size = 0;
		occurances = NULL;
	}

	~On()
	{
		clear();
	}
};

int main()
{
	On Obj;

	//cout << Obj.anagram("silent", "listen");

	//int arr1[] = { 5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4 };
	//int arr2[] = { 3, 5, 7, 2 };

	//Obj.sorting(arr1, arr2, 15, 4);

	int arr1[] = { 5, 8, 9 };
	int arr2[] = { 3, 5, 7, 2 };

	Obj._union(arr1, arr2, 3, 4);
	cout << endl;
	Obj.intersection(arr1, arr2, 3, 4);
}