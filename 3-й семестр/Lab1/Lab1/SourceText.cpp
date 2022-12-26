#include "Class_for_crypto_algorithm.h"

using namespace std;

void SourseText::SetSourseElement(const string& stext)
{
	for (int i = 0; i < stext.length(); i++) {
		int q = stext[i];
		soursetext.push_back(q);
	}
}
void SourseText::GetSourseText()
{
	for (int i = 0; i < soursetext.size(); i++)
	{
		cout << soursetext[i] << " ";
	}
}
vector <int> SourseText::GetTextForEncrypt()
{
	return soursetext;
}