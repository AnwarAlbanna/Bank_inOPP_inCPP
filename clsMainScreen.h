#pragma once
#include "clsScreen.h"
#include <iostream>
using namespace std;
class clsMainScreen :protected clsScreen
{
private:

public :

	static void MainMenue() {
		clsScreen::HeaderScreen("Main Screen", "this is Screen is Main :-)");
	}
};

