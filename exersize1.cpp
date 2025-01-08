#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>

using namespace std;

void view_file(char* name)
{
	setlocale(LC_ALL, ".1251");
	FILE* f;
	char s[100];
	if (fopen_s(&f, name, "rt") != 0 || f == 0) {
		cout << "Неможливо вiдкрити файл" << endl;
		return;
	}
	cout << "/nПерегляд файлу:" << endl;
	while (fgets(s, 100, f)) cout << s;
	fclose(f);
}

void long_str(char* name)
{
	setlocale(LC_ALL, ".1251");
	FILE* f;
	char s[100];
	char max_str[100] = "";
	size_t max_len = 0;
	if (fopen_s(&f, name, "rt") != 0 || f == 0) {
		cout << "Неможливо вiдкрити файл" << endl;
		return;
	}
	while (fgets(s, 100, f)) {
		size_t len = strlen(s);
		if (len > 0 && s[len - 1] == '\n') {
			s[len - 1] = '\0';
			len--;
		}
		if (len > max_len) {
			max_len = len;
			strcpy(max_str, s);
		}
	}
	if (max_len > 0) {
		cout << "\nНайбiльший рядок у файлi:\n";
		cout << max_str << endl;
	}
	else {
		cout << "\nФайл порожнiй або не мiстить даних.\n";
	}
	fclose(f);
}

int main()
{
	char name[] = "Iashchuk1.txt";
	view_file(name);
	long_str(name);
	return 0;
}