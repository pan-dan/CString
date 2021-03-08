#include <iostream>
#include <Windows.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

//BASE_STRING_OPERATIONS
int StrLen(char str[]);

void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << tab << char(i) << endl;
	}
}

void to_upper(char str[]);
void to_lower(char str[]);
void capitalaize(char str[]);
void shrink(char str[]);

void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]);


//Numeric functions

bool is_int_number(char str[]); //���������� �������
int to_int_number(char str[]);

int bin_to_dec(char str[]);
bool is_bin_number(char str[]);

bool is_hex_number(char str[]);
int  hex_to_dec(char str[]);

//#define BASE_STRING_OPERATIONS

void main()
{
	setlocale(LC_ALL, "Rus");
	system("CHCP 1251"); // ���������
	system("CLS");	// ������� ��� ������� �� �������

#ifdef BASE_STRING_OPERATIONS
			//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
//char str[] = "Hello";

	const int n = 1000;
	char str[n];
	//ASCII();

	cout << "������� ������: " << endl;
	//SetConsoleCP(1251);


	//cin >> str;
	cin.getline(str, n);

	cout << "---------------------------------------------------------" << endl;

	//SetConsoleCP(866);
	/*cout << str << endl;
	cout << "---------------------------------------------------------" << endl;*/

	cout << "������ ������ � ������: " << sizeof(str) << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "������� �������� � ������: " << StrLen(str) << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "��� ����� ���������:" << endl;
	to_upper(str);
	cout << str << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "��� ����� ��������:" << endl;
	to_lower(str);
	cout << str << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "��������� ����� � ������ ������� �����:" << endl;
	capitalaize(str);
	cout << str << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "������� ������ �������:" << endl;
	shrink(str);
	cout << str << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "�������� �� ������ �����������" << endl;
	cout << (is_palindrome(str) ? "��" : "���") << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << str << endl;
#endif // BASE_STRING_OPERATIONS

	const int n = 256;
	char str[n] = {};
	//ASCII();
	cout << "�������� ������: ";
	//cin >> str;
	cin.getline(str, n);

	// �������� �� ������ ������
	//cout << (is_int_number(str) ? "�����" : "�� �����");
	//cout << to_int_number(str)<< endl;

	// �������� �� ������ �������� ������
	//cout << (is_bin_number(str) ? "�������� �������� ������" : "�� �������� �������� ������" ) << endl;
	//cout << "������ " << (is_bin_number(str) ? "" : "�� ") << "�������� �������� ������ " << endl;

	// ������� �� �������� � ���������� ��
	//bin_to_dec(str);
	//cout << bin_to_dec(str);

	// �������� �� ������ ����������������� ������
	cout << "������ " << (is_hex_number(str) ? "" : "�� ") << "�������� ����������������� ������ " << endl;

	//������� �� 16-�� � 10-�� ��
	hex_to_dec(str);
	cout << hex_to_dec(str);

}


int StrLen(char str[])
{
	/*for (int i = 0; i < INT_MAX; i++)
	{
		if (str[i] == 0) return i;
	}*/

	int i = 0;
	for (; str[i]; i++);
	return i;

}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' && str[i] <= '�')str[i] -= 32;
		else if (str[i] == '�') str[i] -= 16;
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '�' && str[i] <= '�') str[i] += 32;
		else if (str[i] == '�') str[i] += 16;
	}
}

void capitalaize(char str[])
{
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= '�' && str[0] <= '�') str[0] -= 32;
	else if (str[0] == '�') str[0] -= 16;
	for (int i = 1; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' && str[i] <= '�') && str[i - 1] == ' ') str[i] -= 32;
		else if (str[i] == '�' && str[i - 1] == ' ') str[i] -= 16;
		/*if (str[i] == ' ')
		else if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' && str[i] <= '�')

		str[i + 1] -= 32;*/
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

bool is_palindrome(char str[])
{//1) ���������� ����� ������
	int size = StrLen(str);

	char* buffer = new char[size + 1]{};
	/*for (int i = 0; str[i]; i++)
	{
		buffer[i] = str[i];
	}*/
	strcpy(buffer, str); // string copy. 
	//buffer - ����������, str - ������ ��������

	remove_symbol(buffer, ' ');
	to_lower(buffer);
	size = StrLen(buffer);

	for (int i = 0; i < size / 2; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}



bool is_int_number(char str[])  //���������� �������	(����������� ������� - Function defenition)
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ') return false;
		if (str[i] == ' ' && str[i + 1] == ' ') return false;
	}

	return true;
}

int to_int_number(char str[])
{
	if (!is_int_number(str)) return 0;
	int number = 0;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') continue;
		number *= 10; //�������� �� ������ ����� (����������� ������� ������)
		number += str[i] - 48;

	}

	return number;
}



bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')return false;
	}
	return true;
}


int bin_to_dec(char str[])
{
	if (!is_bin_number(str)) return 0;
	int n = StrLen(str); //size ��� ����������� �����
	int decimal = 0;
	int weight = 1;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') weight++;

	}

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') continue;
		int digit = str[i] - 48;
		decimal += digit * pow(2, n - weight);
		weight++;
	}

	return decimal;
}



bool is_hex_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9' /*&& str[i] != ' '*/) && !(str[i] >= 'A' && str[i] <= 'F') && !(str[i] >= 'a' && str[i] <= 'f')) return false;
	}
	return true;


}

int hex_to_dec(char str[])
{
	if (!is_hex_number(str)) return 0;
	int n = StrLen(str); //size ��� ����������� �����
	int hexadecimal = 0;
	int weight = 1;
	int digit;

	char* buffer = new char[n + 1];
	strcpy(buffer, str);
	remove_symbol(buffer, ' ');
	n = StrLen(buffer);
	

	for (int i = 0; buffer[i]; i++)
	{
		if (buffer[i] >= 'A' && buffer[i] <= 'F') 
		{
			buffer[i] +=32;
		}

		if (buffer[i] >= 'a' && buffer[i] <= 'f')
		{
			digit = buffer[i] - 87;
		}
		else
		{
			digit = buffer[i] - 48;
		}

		hexadecimal += digit * pow(16, n - weight);
		weight++;
	}

	return hexadecimal;

	
	
}


