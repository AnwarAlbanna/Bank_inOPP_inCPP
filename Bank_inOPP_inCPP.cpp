
#include <iostream>
#include "clsBankClient.h"

using namespace std;
int main()
{
    clsBankClient Client = clsBankClient::Find("A11");
    Client.Print();
    

   cout<<endl<< Client.IsClientExist("A11");
}

