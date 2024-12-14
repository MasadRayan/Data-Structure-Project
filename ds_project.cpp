#include<bits/stdc++.h>
#include<windows.h>
using namespace std;


char filename[]="teachersignup.txt";
int number_of_accounts;
struct login
{
    char id[50],pass[50];
};
struct login loginInfo[10000];
struct signup
{
    char id[100], password[20];
};
struct signup signuplist[10000];
int i;
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
void setColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}
int number_of_teacher;


int main()
{
    int opt;
    while(1)
    {

        gotoxy(30,8);cout << "--Menu--" << endl;
        gotoxy(30,10);cout << "1. Teacher" << endl;
        gotoxy(30,12);cout << "2. Student" << endl;
        gotoxy(30,14);cout << "3. About us" << endl;
        gotoxy(30,16);cout << "4. Exit program" << endl;
        gotoxy(30,18);cout << "Select option: " ;
        cin >> opt;
        system("cls");

        if (opt == 1)
        {
            while (1)
            {
                //Teacher
                gotoxy(30,8);cout << "1. Login" << endl;
                gotoxy(30,10);cout << "2. Sign up" << endl;
                gotoxy(30,12);cout << "3. Back" << endl;
                gotoxy(30,14);cout << "Select option: ";
                cin >> opt;
                system("cls");
                if (opt == 1)
                {
                    
                    //Login
                    FILE *fr,*fw;
                    fr=fopen(filename,"r");
                    if(fr==0)
                    {
                        fw=fopen(filename,"w");
                        fclose(fw);
                    }
                    fclose(fr);
                    char idInput[50],passInput[50];
                    gotoxy(30,8);cout <<"---Login to your account---" << endl;
                    gotoxy(30,10);cout << "1. Enter your id: ";
                    cin >> idInput;
                    gotoxy(30,12);cout << "2. Enter your password: " ;
                    cin >> passInput;
                    int i=0;
                    FILE *fin=fopen(filename,"r");
                    while(fscanf(fin,"\n%[^\n]",loginInfo[i].id)==1)
                    {
                        fscanf(fin," %[^\n]",loginInfo[i].pass);
                        i++;
                    }
                    number_of_accounts=i;
                    fclose(fin);
                    int idcom,passcom,f=0;
                    for(i=0; i<number_of_accounts; i++)
                    {
                        idcom=strcmp(loginInfo[i].id,idInput);
                        passcom=strcmp(loginInfo[i].pass,passInput);
                        if(idcom==0 && passcom==0)
                        {
                            f=1;
                            break;
                        }
                    }
                    if(f==1)
                    {
                        setColor(10);
                        gotoxy(30,14);printf("Access Granted\n");
                        setColor(7);
                        Sleep(1000);
                        while (1)
                        {
                            system("cls");
                            gotoxy(30,8);cout << "--Teacher's Menu--"<<endl;
                            gotoxy(30,10);cout << "1.Add student info"<<endl;
                            gotoxy(30,12);cout << "2.Delete student info"<<endl;
                            gotoxy(30,14);cout << "3.Update student info"<<endl;
                            gotoxy(30,16);cout << "4.Back"<<endl;
                            gotoxy(30,18);cout << "Select option: ";
                            cin >> opt;
                            system("cls");

                            if(opt == 1)
                            {
                                //Add a student info
                                while (1)
                                {
                                    gotoxy(30,8);cout << "--Select the class of a student--" << endl;
                                    gotoxy(30,10);cout <<"1. Below class 8" << endl;
                                    gotoxy(30,12);cout <<"2. Above class 8" << endl;
                                    gotoxy(30,14);cout <<"3.Back" << endl;
                                    gotoxy(30,16);cout <<"Select option: ";
                                    cin >> opt;
                                    system("cls");
                                    if (opt==1)
                                    {
                                        //Add a student info below class 8
                                    }
                                    else if (opt==2)
                                    {
                                        //Add a student info above class 8
                                    }
                                    else if (opt ==3)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setColor(4);
                                        gotoxy(30,14);cout << "Invalid Input!" << endl;
                                        setColor(7);
                                        Sleep(800);
                                        system("cls");
                                    }
                                }
                            }
                            else if (opt ==2)
                            {
                                //delete a strudent info
                            }
                            else if (opt == 3)
                            {
                                //Update a student info
                            }
                            else if (opt == 4)
                            {
                                break;
                            }
                            else
                            {
                                setColor(4);
                                gotoxy(30,14);cout << "Invalid input!" << endl;
                                setColor(7);
                                Sleep(900);
                                system("cls");
                            }
                        }
                        
                    }
                    else
                    {
                        system("cls");
                        setColor(4);
                        gotoxy(30,14);cout << "Account Not Found" << endl;
                        setColor(7);
                        Sleep(900);
                        system("cls");
                        //break;
                    }
                }
                else if(opt == 2)
                {
                    ///Sign up
                    while (1)
                    {
                        gotoxy(30,8);cout << "1. Continue Signing-up" << endl;
                        gotoxy(30,10);cout << "2. Back" << endl;
                        gotoxy(30,12);cout << "Select option: " ;
                        cin >> opt;
                        system("cls");
                        if (opt == 1)
                        {
                            ///----->read file---->copy in array--->write file--read
                            FILE *sup = fopen(filename, "r");
                            if(sup == 0)
                            {
                                sup = fopen(filename, "w");
                                fclose(sup);
                            }

                            else if(sup != 0)
                            {
                                int i = 0;
                                while(fscanf(sup, "\n%[^\n]",signuplist[i].id)==1)
                                {
                                    fscanf(sup, "\n%[^\n]",signuplist[i].password);
                                    i++;
                                }
                                number_of_teacher = i;
                            }
                            fclose(sup);


                            struct signup a ;

                            gotoxy(30,8);cout <<" ---Sign Up---" << endl;
                            gotoxy(30,10);cout <<"Enter your ID: ";
                            cin >> a.id;
                            gotoxy(30,12);cout << "Enter your password: ";
                            cin >> a.password;

                            signuplist[number_of_teacher] = a;
                            number_of_teacher++;

                            ///array-->write
                            FILE *fout = fopen(filename, "w");
                            for (i = 0; i < number_of_teacher; i++)
                            {
                                cout << fout << signuplist[i].id ;
                                fprintf(fout, "%s\n", signuplist[i].id);
                                fprintf(fout, "%s\n", signuplist[i].password);
                            }
                            fclose(fout);
                            system("cls");
                            setColor(10);
                            gotoxy(30,14);cout <<"Account created successfully!" << endl;
                            setColor(7);
                            Sleep(1000);
                            system("cls");
                            break;
                        }
                        else if (opt == 2)
                        {
                            break;
                        }
                        else
                        {
                            setColor(4);
                            gotoxy(30,14);cout << "Invalid input!" << endl;
                            setColor(7);
                            Sleep(700);
                            system("cls");
                        }
                    }
                }

                else if (opt==3)
                {
                    break;
                }
                
                else
                {
                    setColor(4);
                    gotoxy(30,14);cout << "Invalid input!" << endl;
                    setColor(7);
                    Sleep(700);
                    system("cls");
                }

            }

        }
        else if (opt == 2)
        {
            //Student
        }
        else if (opt == 3)
        {
            //About us
        }
        else if (opt == 4)
        {
            break;
        }
        else
        {
            setColor(4);
            gotoxy(30,14);cout << "Invalid input!" << endl;
            setColor(7);
            Sleep(700);
            system("cls");
        }
    }
}
