#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool Include(const char* s, const char* cs)
{
	bool r = true;
	for (int i = 0; cs[i] != '\0'; i++)
		r = r && (strchr(s, cs[i]));
	return r;
}
bool Include_z(const char* s, const char* zs)
{
	bool r = true;
	for (int i = 0; zs[i] != '\0'; i++)
		r = r && (strchr(s, zs[i]));
	return r;
}
char* modified(char* str)
{
	if (strlen(str) < 5)
		return str;

	char* tmp = new char[strlen(str) * 3 / 5 + 1];
	char* t = tmp;

	tmp[0] = '\0';
	int i = 0;
	while (str[i] != 0)
	{
		if (str[i] == 'A' &&
			str[i + 1] == 'G' &&
			str[i + 2] == 'A' &&
			str[i + 3] == 'O' &&
			str[i + 4] == 'G' &&
			str[i + 5] == 'O')
		{
			strcat_s(t, sizeof(str) + 10, "**");
			t += 4;
			i += 5;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy_s(str, sizeof(str) + 10, tmp);
	return tmp;
}
void print(const char* x)
{
	int i = 0;
	while (x[i] != '\0')
		cout << x[i++];
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	char cs[] = "AGA";
	if (Include(str, cs))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	char zs[] = "OGO";
	if (Include_z(str, zs))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
	cout << "Modified string: ";
	print(modified(str));
}
