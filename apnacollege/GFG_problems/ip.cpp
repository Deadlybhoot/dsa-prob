// C++ program to generate all possible
// valid IP addresses from given string

//Aim:- C++ program to generate all possible
// valid IP addresses from given string

// There are some condition we must have to apply on ip address are:-
// 1)length not greater than 12 && Not less than 4 && every part of string must be less than or equals to 3
// 2)range 0-255
// 3)three dots
// 4)0.0.252.06 ==>NOt allowed or 0.0.252.6==>allowed
// 5)

//Here cout comments are For your reference
#include <bits/stdc++.h>
using namespace std;

// Function checks whether IP digits
// are valid or not.
int is_valid(string ip)
{
    // Splitting by "."
    	// cout<<"hi"<<" "<<ip<<endl;
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++)
    {	// cout<<"i"<<i<<" "<<"ip[i]="<<ip[i]<<endl;
        if (ip[i] == '.')
        {	// cout<<"ex pushed:-"<<ex<<endl;
            ips.push_back(ex);
            ex = "";
        }
        else
        {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);//For remaining digits 


    // cout << ip << endl;
    for (int i = 0; i < ips.size(); i++)
    {   	// cout << ips[i] <<endl;
		//jyachyan False yete te add
        // cout << ips[i] <<endl;
        if (ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255) //--> This is For length & Range checking
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) == 0)//-->This is For rule no.4
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) != 0 && ips[i][0] == '0')//-->This is FOr No many zeros allowed if string is greater than 1
            return 0;
    }
    return 1;
}

// Function converts string to IP address
vector<string> convert(string ip)
{
    int l = ip.length();

    // Check for string size
    if (l > 12 || l < 4)
    {
        cout << "Not Valid IP Address";
    }

    string check = ip;
    vector<string> ans;

    // Generating different combinations.
    	//three for loops for because we have to find alll possibilities of three dots & think this three dots are like pointers on spaces
    for (int i = 1; i < l - 2; i++)
    {
        for (int j = i + 1; j < l - 1; j++)
        {
            for (int k = j + 1; k < l; k++)
            {
                check = check.substr(0, k) + "." + check.substr(k);//FOr placing first Dot
                    //   cout<<"i"<<i<<" "<<"j"<<j<<" "<<"k"<<k<<" ";
                    //     std::cout << "First check"<<check << '\n';
                check = check.substr(0, j) + "." + check.substr(j);//FOr placing second Dot after palcing First
                  //    std::cout << "Second check"<<check << '\n';
                check = check.substr(0, i) + "." + check.substr(i);  //FOr placing Third Dot after placing second, First
                        // std::cout << "Third check"<<check << '\n';

                // cout<< check <<endl;
                // Check for the validity of combination
                if (is_valid(check))//-->Here third check will Go 
                {
                    ans.push_back(check);
                    // std::cout << check << '\n';
                }
                check = ip;
            }
        }
    }
    return ans;
}

// Driver code
int main()
{
    string A = "25525511135";
    // string B = "25505011535";

    convert(A);
    // convert(B);
    vector<string> v = convert(A);

    for (auto x : v)
    {
        cout << x << " " << endl;
    }
    return 0;
}

// This code is contributed by Harshit
