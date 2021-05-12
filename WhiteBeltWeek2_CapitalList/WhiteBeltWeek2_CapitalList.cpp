// WhiteBeltWeek2_CapitalList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int q;
	map<string, string> capitalList;
	string cmd = "";
	string country = "";
	string capital = "";
	cout << "Enter query count q: " << endl;
	cin >> q;
	while (q) {
		cin >> cmd;
		if (cmd == "DUMP") {
			if (capitalList.size()) {
				for (const auto& elem : capitalList) {
					cout << elem.first << " " << elem.second << endl;
				}
			}
			else {
				cout << "There are no countries in the world. " << endl;
			}
		}
		else {
			cin >> country;

			map<string, string>::iterator countryIterator = capitalList.find(country);
			map<string, string>::iterator capitalListIterator = capitalList.end();
			if (cmd == "ABOUT")
			{
				if (countryIterator != capitalListIterator)
				{
					cout << "Country " << country << " has capital " << countryIterator->second;
				}
				else cout << "Country " << country << " doesn't exist" << endl;
			}
			else
			{
				cin >> capital;
				if (cmd == "RENAME")
				{
					auto iter_new_country = capitalList.find(capital);
					if (capital == country ||
						countryIterator == capitalListIterator ||
						iter_new_country != capitalListIterator)
						cout << "Incorrect rename, skip"<<endl;
					else
					{
						cout << "Country " << country << " with capital " << capitalList[country] << " has been renamed to " << capital << endl;
						capitalList[capital] = capitalList[country];
						capitalList.erase(country);
					}
				}
				else if (cmd == "CHANGE_CAPITAL")
				{
					if (capitalList[country] == capital)
						cout << "Country " << country << " hasn't changed its capital." << endl;
					else
					{
						if (countryIterator == capitalListIterator)
							cout << "Introduce new country " << country << " with capital " << capital << endl;
						else if (capitalList[country] != capital)
							cout << "Country " << country << " has changed its capital from " <<
							capitalList[country] << " to " << capital << endl;
						capitalList[country] = capital;
					}
				}
			}
			--q;
		}
	}
}

