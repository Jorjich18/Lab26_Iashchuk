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
	if (fopen_s(&f, name, "rt") != 0 || f == NULL) {
		cout << "Неможливо вiдкрити файл";
		return;
	}
	cout << "Перегляд файлу" << endl;
	while (fgets(s, 100, f)) {
		cout << s;
	}
	cout << endl;
	fclose(f);
}

void find_lng_w(char* name)
{
	setlocale(0, ".1251");
	FILE* f;
	char s[100];
	char l_w[100] = "";
	size_t max_len = 0;
	if (fopen_s(&f, name, "rt") != 0 || f == NULL) {
		cout << "Неможливо вiдкрити файл";
		return;
	}
	cout << "\nНайдовше слово у файлi: ";
	while (fgets(s, 100, f)) {
		size_t len = strlen(s);
		if (len > 0 && s[len - 1] == '\n')
			s[len - 1] = '\0';
		char* token = strtok(s, " ");
		while (token) {
			size_t word_len = strlen(token);
			if (word_len > max_len) {
				max_len = word_len;
				strcpy(l_w, token);
			}
			token = strtok(nullptr, " ");
		}
	}
	if (max_len > 0) {
		cout << "'" << l_w << "'";
		cout << " з довжиною " << max_len << " символiв" << endl;
	}
	else if (max_len == 0 || max_len < 0) {
		cout << "\nФайл порожнiй або немає слiв\n";
	}
	fclose(f);
}

int main()
{
	char name[] = "Iashchuk_2.txt";
	view_file(name);
	find_lng_w(name);
	return 0;
}