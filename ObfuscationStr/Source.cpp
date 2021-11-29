#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

#define MIN  ((__TIME__[3] - '0') * 10 + __TIME__[4] - '0')
#define SEC  ((__TIME__[6] - '0') * 10 + __TIME__[7] - '0')
#define KEY MIN*SEC

//получаем длину строки
constexpr auto getSize(const char str[])
{
	auto i = 0;
	while (str[i] != '\0') { i++; }
	return i + 1;
}

template<size_t SIZE> struct obfuscationStr
{
	short buf[SIZE];
	constexpr obfuscationStr() :buf{ 0 } { }
	//дешифруем в процессе выполнени€
	string decStr() const
	{
		string decDat;
		for (auto i = 0; i < SIZE - 1; i++) {
			decDat.push_back(buf[i] - KEY);
		}
		return decDat;
	}
};

//шифруем  на этапе компил€ции
template<size_t SIZE> constexpr auto encStr(const char str[SIZE])
{
	obfuscationStr <SIZE> encDat;
	for (auto i = 0; i < SIZE - 1; i++)
		encDat.buf[i] = str[i] + KEY;
	return encDat;

}

int main()
{
	auto temp = "uncrypt data for example";
	constexpr auto str = encStr <getSize("apple apple cat")>("apple apple cat");
	cout << str.decStr() << endl;
	system("pause");
	return 0;

}