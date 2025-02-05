#pragma once
#include <iostream>
using namespace std;
class clsScreen
{
protected:
	static void HeaderScrean(string Title, string Body) {
		cout << "\n---------------------------------------------------------";
		cout << "\n\t\t\t\t" << Title;
		if (Title!="") {
			cout << "\n\t\t\t\t" << Body;
		}
		cout << "\n---------------------------------------------------------";
			// add function choose anther one;
	}

};

