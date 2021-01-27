#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

bool isRunning = true;

string passWord = "Portocala";

void menu()
{
    cout<<"1. Crypt files\n";
    cout<<"2. Decrypt files\n";
    cout<<"3. Show crypted files\n";
    cout<<"0. Exit\n";
}

void crypt()
{
    system("clear");
    string fileName;
    cout<<"Enter the file name with extension : ";
    cin>>fileName;
    ifstream in(fileName.c_str());
    string aux = "crypted_files/";
    aux.append(fileName);
    ofstream out(aux.c_str());
    string pp;
    while(in>>pp)
    {
        bool ok = true;
        int i = 0;
        while(pp[i] != ' ')
        {
            if(ok)
                pp[i] += 3;
            else
                pp[i] -= 3;
            ok = !ok;
            i++;
        }
        out<<pp<<" ";
    }
    in.close();
    out.close();
    ofstream g("crypt.txt", ios::app);
    g<<fileName<<endl;
    g.close();
    cout<<"File crypted!\n";
    cin.get();
}

void decrypt()
{
    string fileName;
    system("clear");
    cout<<"Enter the file name with extension : ";
    cin>>fileName;
    ifstream in(fileName.c_str());
    string aux = "decrypted_files/";
    aux.append(fileName);
    ofstream out(aux.c_str());
    string pp;
    while(in>>pp)
    {
        bool ok = true;
        int i = 0;
        while(pp[i] != ' ')
        {
            if(ok)
                pp[i] -= 3;
            else
                pp[i] += 3;
            ok = !ok;
            i++;
        }
        out<<pp<<" ";
    }
    in.close();
    out.close();
    cout<<"File decrypted!\n";
    Sleep(500);
    cin.get();
}

void printCrypt()
{
    ifstream in("crypt.txt");
    string aux;
    while(in>>aux)
    {
        cout<<aux<<endl;
    }
    in.close();
}

void input()
{
    int choice = -1;
    cin>>choice;
    if(choice >= 0 && choice <= 4)
        switch(choice)
        {
            case 0:
                //Stop Running
                isRunning = false;
                break;
            case 1:
                //Crypt a file of choice
                crypt();
                break;
            case 2:
                decrypt();
                break;
            case 3:
                //Print all crypted files that exist at the moment
                printCrypt();
                break;
        }

}

int main()
{
    /*string pp;
    cout<<"Password : ";
    cin>>pp;
    if(pp == passWord)*/
        while(isRunning)
        {
            menu();
            input();
        }
    return 0;
}