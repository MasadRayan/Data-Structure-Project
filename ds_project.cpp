#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

char filename[] = "teachersignup.txt";
int number_of_accounts;
struct login
{
    char id[50], pass[50];
};
struct login loginInfo[10000];
int opt;
struct signup
{
    char id[100], password[20];
};
int number_of_teacher;
struct signup signuplist[10000];
int i;
struct student_below_8
{
    char name[100], mobile[20], section[10];
    int roll, classs, bangla, english, math, science, bangladesh_and_global_studies, islam;
    int total_marks()
    {
        return bangla + english + math + science + bangladesh_and_global_studies + islam;
    }
    string grade()
    {
        int total = total_marks();
        if (total >= 480)
            return "A+";
        else if (total >= 420)
            return "A";
        else if (total >= 360)
            return "B";
        else if (total >= 300)
            return "C";
        else if (total >= 240)
            return "D";
        else
            return "F";
    }
};
struct student_below_8 below_8_list[10000];

struct student_above_8_science
{
    char name1[100], mobile1[20], section1[10];
    int roll1, classs1, bangla_1st_2nd1, english_1st_2nd1, islam_and_moral1, bangladesh_and_global1, ict1, math1, highermath, physics, chemistry, biology, physical_education1;
    int total_marks()
    {
        return bangla_1st_2nd1 + english_1st_2nd1 + islam_and_moral1 + bangladesh_and_global1 + ict1 +
               math1 + highermath + physics + chemistry + biology + physical_education1;
    }
    string grade()
    {
        int total = total_marks();
        if (total >= 1040)
            return "A+";
        else if (total >= 910)
            return "A";
        else if (total >= 780)
            return "B";
        else if (total >= 650)
            return "C";
        else if (total >= 520)
            return "D";
        else
            return "F";
    }
};
struct student_above_8_science student_science[10000];

struct student_above_8_commerce
{
    char name2[100], mobile2[20], section2[10];
    int roll2, classs2, bangla_1st_2nd2, english_1st_2nd2, islam_and_moral2, bangladesh_and_global2, ict2, math2, accounting, finence, business_venture, physical_education2;
    int total_marks()
    {
        return bangla_1st_2nd2 + english_1st_2nd2 + islam_and_moral2 + bangladesh_and_global2 + ict2 +
               math2 + accounting + finence + business_venture + physical_education2;
    }
    string grade()
    {
        int total = total_marks();
        if (total >= 960)
            return "A+";
        else if (total >= 840)
            return "A";
        else if (total >= 720)
            return "B";
        else if (total >= 600)
            return "C";
        else if (total >= 480)
            return "D";
        else
            return "F";
    }
};
struct student_above_8_commerce students_commerce[10000];

struct student_above_8_arts
{
    char name3[100], mobile3[20], section3[10];
    int roll3, classs3, bangla_1st_2nd3, english_1st_2nd3, islam_and_moral3, bangladesh_and_global3, ict3, math3, geography, municipal_policy, history, economy, physical_education3;
    int total_marks()
    {
        return bangla_1st_2nd3 + english_1st_2nd3 + islam_and_moral3 + bangladesh_and_global3 + ict3 +
               math3 + geography + municipal_policy + history + economy + physical_education3;
    }
    string grade()
    {
        int total = total_marks();
        if (total >= 1040)
            return "A+";
        else if (total >= 910)
            return "A";
        else if (total >= 780)
            return "B";
        else if (total >= 650)
            return "C";
        else if (total >= 520)
            return "D";
        else
            return "F";
    }
};
struct student_above_8_arts student_arts[10000];
int nos, f = 0;
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
void setColor(int textColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

int login()
{
    FILE *fr, *fw;
    fr = fopen(filename, "r");
    if (fr == 0)
    {
        fw = fopen(filename, "w");
        fclose(fw);
    }
    fclose(fr);
    char idInput[50], passInput[50];
    gotoxy(30, 8);
    cout << "---Login to your account---" << endl;
    gotoxy(30, 10);
    cout << "1. Enter your id: ";
    cin >> idInput;
    gotoxy(30, 12);
    cout << "2. Enter your password: ";
    cin >> passInput;
    int i = 0;
    FILE *fin = fopen(filename, "r");
    while (fscanf(fin, "\n%[^\n]", loginInfo[i].id) == 1)
    {
        fscanf(fin, " %[^\n]", loginInfo[i].pass);
        i++;
    }
    number_of_accounts = i;
    fclose(fin);
    int idcom, passcom, f = 0;
    for (i = 0; i < number_of_accounts; i++)
    {
        idcom = strcmp(loginInfo[i].id, idInput);
        passcom = strcmp(loginInfo[i].pass, passInput);
        if (idcom == 0 && passcom == 0)
        {
            f = 1;
            break;
        }
    }
    return f;
}

void signupp()
{
    while (1)
    {
        gotoxy(30, 8);
        cout << "1. Continue Signing-up" << endl;
        gotoxy(30, 10);
        cout << "2. Back" << endl;
        gotoxy(30, 12);
        cout << "Select option: ";
        cin >> opt;
        system("cls");
        if (opt == 1)
        {
            ///----->read file---->copy in array--->write file--read
            FILE *sup = fopen(filename, "r");
            if (sup == 0)
            {
                sup = fopen(filename, "w");
                fclose(sup);
            }

            else if (sup != 0)
            {
                int i = 0;
                while (fscanf(sup, "\n%[^\n]", signuplist[i].id) == 1)
                {
                    fscanf(sup, "\n%[^\n]", signuplist[i].password);
                    i++;
                }
                number_of_teacher = i;
            }
            fclose(sup);

            struct signup a;

            gotoxy(30, 8);
            cout << " ---Sign Up---" << endl;
            gotoxy(30, 10);
            cout << "Enter your ID: ";
            cin >> a.id;
            gotoxy(30, 12);
            cout << "Enter your password: ";
            cin >> a.password;

            signuplist[number_of_teacher] = a;
            number_of_teacher++;

            /// array-->write
            FILE *fout = fopen(filename, "w");
            for (i = 0; i < number_of_teacher; i++)
            {
                cout << fout << signuplist[i].id;
                fprintf(fout, "%s\n", signuplist[i].id);
                fprintf(fout, "%s\n", signuplist[i].password);
            }
            fclose(fout);
            system("cls");
            setColor(10);
            gotoxy(30, 14);
            cout << "Account created successfully!" << endl;
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
            gotoxy(30, 14);
            cout << "Invalid input!" << endl;
            setColor(7);
            Sleep(700);
            system("cls");
        }
    }
}

void below_8_student_addd()
{
    FILE *student_below_8 = fopen("below_class_8.txt", "r");
    if (student_below_8 == NULL)
    {
        student_below_8 = fopen("below_class_8.txt", "w");
        fclose(student_below_8);
        student_below_8 = NULL;
    }
    else
    {
        int i = 0;
        while (fscanf(student_below_8, "\n%[^\n]", below_8_list[i].name) == 1)
        {
            fscanf(student_below_8, "%d", &below_8_list[i].roll);
            fscanf(student_below_8, "%d", &below_8_list[i].classs);
            fscanf(student_below_8, "%s", below_8_list[i].section);
            fscanf(student_below_8, "%d", &below_8_list[i].bangla);
            fscanf(student_below_8, "%d", &below_8_list[i].english);
            fscanf(student_below_8, "%d", &below_8_list[i].math);
            fscanf(student_below_8, "%d", &below_8_list[i].science);
            fscanf(student_below_8, "%d", &below_8_list[i].bangladesh_and_global_studies);
            fscanf(student_below_8, "%d", &below_8_list[i].islam);
            i++;
        }
        nos = i;
        fclose(student_below_8);
    }

    struct student_below_8 a;
    gotoxy(30, 2);
    cout << "--Add Student Info & Result--" << endl;
    gotoxy(30, 4);
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(a.name, 100);
    gotoxy(30, 6);
    cout << "Enter Roll: ";
    cin >> a.roll;
    gotoxy(30, 8);
    cout << "Enter Class: ";
    cin >> a.classs;
    gotoxy(30, 10);
    cout << "Enter Section: ";
    cin >> a.section;
    gotoxy(30, 14);
    cout << "--Enter Result--" << endl;
    gotoxy(30, 16);
    cout << "Enter The result of Bangla: ";
    cin >> a.bangla;
    gotoxy(30, 18);
    cout << "Enter The result of English: ";
    cin >> a.english;
    gotoxy(30, 20);
    cout << "Enter The result of Math: ";
    cin >> a.math;
    gotoxy(30, 22);
    cout << "Enter The result of Science: ";
    cin >> a.science;
    gotoxy(30, 24);
    cout << "Enter The result of Bangladesh and Global Studies: ";
    cin >> a.bangladesh_and_global_studies;
    gotoxy(30, 26);
    cout << "Enter The result of Islam and Moral Education: ";
    cin >> a.islam;

    below_8_list[nos] = a;
    nos++;

    FILE *below_8_student_add = fopen("below_class_8.txt", "w");
    if (below_8_student_add != NULL)
    {
        for (int i = 0; i < nos; i++)
        {
            fprintf(below_8_student_add, "%s\n", below_8_list[i].name);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].roll);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].classs);
            fprintf(below_8_student_add, "%s\n", below_8_list[i].section);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].bangla);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].english);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].math);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].science);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].bangladesh_and_global_studies);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].islam);
        }
        fclose(below_8_student_add);
    }
    else
    {
        setColor(4);
        gotoxy(30, 28);
        cout << "Error saving data!" << endl;
        setColor(7);
    }

    setColor(10);
    gotoxy(30, 28);
    cout << "Info Successfully Added" << endl;
    setColor(7);
    Sleep(1000);
    system("cls");
}

void add_science_student()
{
    FILE *student_above_8_science = fopen("above_class_8_science.txt", "r");
    if (student_above_8_science == NULL)
    {
        student_above_8_science = fopen("above_class_8_science.txt", "w");
        fclose(student_above_8_science);
        student_above_8_science = NULL;
    }
    else
    {
        int i = 0;
        while (fscanf(student_above_8_science, "\n%[^\n]", student_science[i].name1) == 1)
        {
            fscanf(student_above_8_science, "%d", &student_science[i].roll1);
            fscanf(student_above_8_science, "%d", &student_science[i].classs1);
            fscanf(student_above_8_science, "%s", student_science[i].section1);
            fscanf(student_above_8_science, "%d", &student_science[i].bangla_1st_2nd1);
            fscanf(student_above_8_science, "%d", &student_science[i].english_1st_2nd1);
            fscanf(student_above_8_science, "%d", &student_science[i].islam_and_moral1);
            fscanf(student_above_8_science, "%d", &student_science[i].bangladesh_and_global1);
            fscanf(student_above_8_science, "%d", &student_science[i].ict1);
            fscanf(student_above_8_science, "%d", &student_science[i].math1);
            fscanf(student_above_8_science, "%d", &student_science[i].highermath);
            fscanf(student_above_8_science, "%d", &student_science[i].physics);
            fscanf(student_above_8_science, "%d", &student_science[i].chemistry);
            fscanf(student_above_8_science, "%d", &student_science[i].biology);
            fscanf(student_above_8_science, "%d", &student_science[i].physical_education1);
            i++;
        }
        nos = i;
        fclose(student_above_8_science);
    }

    struct student_above_8_science a;
    gotoxy(30, 2);
    cout << "--Add Student Info & Result--" << endl;
    gotoxy(30, 4);
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(a.name1, 100);
    gotoxy(30, 6);
    cout << "Enter Roll: ";
    cin >> a.roll1;
    gotoxy(30, 8);
    cout << "Enter Class: ";
    cin >> a.classs1;
    gotoxy(30, 10);
    cout << "Enter Section: ";
    cin >> a.section1;
    gotoxy(45, 14);

    cout << "--Enter Result--" << endl;
    gotoxy(7, 16);
    cout << "Enter The result of Bangla 1st & 2nd: ";
    cin >> a.bangla_1st_2nd1;
    gotoxy(7, 18);
    cout << "Enter The result of English 1st & 2nd: ";
    cin >> a.english_1st_2nd1;
    gotoxy(7, 20);
    cout << "Enter The result of Ialam and Moral Studies: ";
    cin >> a.islam_and_moral1;
    gotoxy(7, 22);
    cout << "Enter The result of Bangladesh and Global Studies: ";
    cin >> a.bangladesh_and_global1;
    gotoxy(7, 24);
    cout << "Enter The result of ICT: ";
    cin >> a.ict1;
    gotoxy(7, 26);
    cout << "Enter The result of Math: ";
    cin >> a.math1;
    gotoxy(65, 16);
    cout << "Enter The result of Higher Math: ";
    cin >> a.highermath;
    gotoxy(65, 18);
    cout << "Enter The result of Physics: ";
    cin >> a.physics;
    gotoxy(65, 20);
    cout << "Enter The result of Chemistry: ";
    cin >> a.chemistry;
    gotoxy(65, 22);
    cout << "Enter The result of Biology: ";
    cin >> a.biology;
    gotoxy(65, 24);
    cout << "Enter The result of Physical Education: ";
    cin >> a.physical_education1;

    student_science[nos] = a;
    nos++;

    FILE *above_8_student_science_add = fopen("above_class_8_science.txt", "w");
    if (above_8_student_science_add != NULL)
    {
        for (int i = 0; i < nos; i++)
        {
            fprintf(above_8_student_science_add, "%s\n", student_science[i].name1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].roll1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].classs1);
            fprintf(above_8_student_science_add, "%s\n", student_science[i].section1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].bangla_1st_2nd1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].english_1st_2nd1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].islam_and_moral1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].bangladesh_and_global1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].ict1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].math1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].highermath);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].physics);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].chemistry);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].biology);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].physical_education1);
        }
        fclose(above_8_student_science_add);
    }
    else
    {
        setColor(4);
        gotoxy(30, 28);
        cout << "Error saving data!" << endl;
        setColor(7);
    }

    setColor(10);
    gotoxy(30, 28);
    cout << "Info Successfully Added" << endl;
    setColor(7);
    Sleep(1000);
    system("cls");
}

void add_commerce_student()
{
    FILE *student_above_8_commerce = fopen("above_class_8_commerce.txt", "r");
    if (student_above_8_commerce == NULL)
    {
        student_above_8_commerce = fopen("above_class_8_commerce.txt", "w");
        fclose(student_above_8_commerce);
        student_above_8_commerce = NULL;
    }
    else
    {
        int i = 0;
        while (fscanf(student_above_8_commerce, "\n%[^\n]", students_commerce[i].name2) == 1)
        {
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].roll2);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].classs2);
            fscanf(student_above_8_commerce, "%s", students_commerce[i].section2);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].bangla_1st_2nd2);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].english_1st_2nd2);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].islam_and_moral2);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].bangladesh_and_global2);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].ict2);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].math2);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].accounting);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].finence);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].business_venture);
            fscanf(student_above_8_commerce, "%d", &students_commerce[i].physical_education2);
            i++;
        }
        nos = i;
        fclose(student_above_8_commerce);
    }

    struct student_above_8_commerce a;
    gotoxy(30, 2);
    cout << "--Add Student Info & Result--" << endl;
    gotoxy(30, 4);
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(a.name2, 100);
    gotoxy(30, 6);
    cout << "Enter Roll: ";
    cin >> a.roll2;
    gotoxy(30, 8);
    cout << "Enter Class: ";
    cin >> a.classs2;
    gotoxy(30, 10);
    cout << "Enter Section: ";
    cin >> a.section2;
    gotoxy(45, 14);

    cout << "--Enter Result--" << endl;
    gotoxy(7, 16);
    cout << "Enter The result of Bangla 1st & 2nd: ";
    cin >> a.bangla_1st_2nd2;
    gotoxy(7, 18);
    cout << "Enter The result of English 1st & 2nd: ";
    cin >> a.english_1st_2nd2;
    gotoxy(7, 20);
    cout << "Enter The result of Ialam and Moral Studies: ";
    cin >> a.islam_and_moral2;
    gotoxy(7, 22);
    cout << "Enter The result of Bangladesh and Global Studies: ";
    cin >> a.bangladesh_and_global2;
    gotoxy(7, 24);
    cout << "Enter The result of ICT: ";
    cin >> a.ict2;
    gotoxy(7, 26);
    cout << "Enter The result of Math: ";
    cin >> a.math2;
    gotoxy(65, 16);
    cout << "Enter The result of Accounting: ";
    cin >> a.accounting;
    gotoxy(65, 18);
    cout << "Enter The result of Finance: ";
    cin >> a.finence;
    gotoxy(65, 20);
    cout << "Enter The result of Businiess Venture: ";
    cin >> a.business_venture;
    gotoxy(65, 22);
    cout << "Enter The result of Physical Education: ";
    cin >> a.physical_education2;

    students_commerce[nos] = a;
    nos++;

    FILE *above_8_student_commerce_add = fopen("above_class_8_commerce.txt", "w");
    if (above_8_student_commerce_add != NULL)
    {
        for (int i = 0; i < nos; i++)
        {
            fprintf(above_8_student_commerce_add, "%s\n", students_commerce[i].name2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].roll2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].classs2);
            fprintf(above_8_student_commerce_add, "%s\n", students_commerce[i].section2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].bangla_1st_2nd2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].english_1st_2nd2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].islam_and_moral2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].bangladesh_and_global2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].ict2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].math2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].accounting);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].finence);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].business_venture);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].physical_education2);
        }
        fclose(above_8_student_commerce_add);
    }
    else
    {
        setColor(4);
        gotoxy(30, 28);
        cout << "Error saving data!" << endl;
        setColor(7);
    }
    setColor(10);
    gotoxy(30, 28);
    cout << "Info Successfully Added" << endl;
    setColor(7);
    Sleep(1000);
    system("cls");
}

void add_arts_student()
{
    FILE *student_above_8_arts = fopen("above_class_8_arts.txt", "r");
    if (student_above_8_arts == NULL)
    {
        student_above_8_arts = fopen("above_class_8_arts.txt", "w");
        fclose(student_above_8_arts);
        student_above_8_arts = NULL;
    }
    else
    {
        int i = 0;
        while (fscanf(student_above_8_arts, "\n%[^\n]", student_arts[i].name3) == 1)
        {
            fscanf(student_above_8_arts, "%d", &student_arts[i].roll3);
            fscanf(student_above_8_arts, "%d", &student_arts[i].classs3);
            fscanf(student_above_8_arts, "%s", student_arts[i].section3);
            fscanf(student_above_8_arts, "%d", &student_arts[i].bangla_1st_2nd3);
            fscanf(student_above_8_arts, "%d", &student_arts[i].english_1st_2nd3);
            fscanf(student_above_8_arts, "%d", &student_arts[i].islam_and_moral3);
            fscanf(student_above_8_arts, "%d", &student_arts[i].bangladesh_and_global3);
            fscanf(student_above_8_arts, "%d", &student_arts[i].ict3);
            fscanf(student_above_8_arts, "%d", &student_arts[i].math3);
            fscanf(student_above_8_arts, "%d", &student_arts[i].geography);
            fscanf(student_above_8_arts, "%d", &student_arts[i].municipal_policy);
            fscanf(student_above_8_arts, "%d", &student_arts[i].history);
            fscanf(student_above_8_arts, "%d", &student_arts[i].economy);
            fscanf(student_above_8_arts, "%d", &student_arts[i].physical_education3);
            i++;
        }
        nos = i;
        fclose(student_above_8_arts);
    }
    struct student_above_8_arts a;
    gotoxy(30, 2);
    cout << "--Add Student Info & Result--" << endl;
    gotoxy(30, 4);
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(a.name3, 100);
    gotoxy(30, 6);
    cout << "Enter Roll: ";
    cin >> a.roll3;
    gotoxy(30, 8);
    cout << "Enter Class: ";
    cin >> a.classs3;
    gotoxy(30, 10);
    cout << "Enter Section: ";
    cin >> a.section3;
    gotoxy(45, 14);

    cout << "--Enter Result--" << endl;
    gotoxy(7, 16);
    cout << "Enter The result of Bangla 1st & 2nd: ";
    cin >> a.bangla_1st_2nd3;
    gotoxy(7, 18);
    cout << "Enter The result of English 1st & 2nd: ";
    cin >> a.english_1st_2nd3;
    gotoxy(7, 20);
    cout << "Enter The result of Ialam and Moral Studies: ";
    cin >> a.islam_and_moral3;
    gotoxy(7, 22);
    cout << "Enter The result of Bangladesh and Global Studies: ";
    cin >> a.bangladesh_and_global3;
    gotoxy(7, 24);
    cout << "Enter The result of ICT: ";
    cin >> a.ict3;
    gotoxy(7, 26);
    cout << "Enter The result of Math: ";
    cin >> a.math3;
    gotoxy(65, 16);
    cout << "Enter The result of Geography: ";
    cin >> a.geography;
    gotoxy(65, 18);
    cout << "Enter The result of Municipal Policy: ";
    cin >> a.municipal_policy;
    gotoxy(65, 20);
    cout << "Enter The result of History: ";
    cin >> a.history;
    gotoxy(65, 22);
    cout << "Enter The result of Economy: ";
    cin >> a.economy;
    gotoxy(65, 24);
    cout << "Enter The result of Physical Education: ";
    cin >> a.physical_education3;

    student_arts[nos] = a;
    nos++;
    FILE *above_8_student_arts_add = fopen("above_class_8_arts.txt", "w");
    if (above_8_student_arts_add != NULL)
    {
        for (int i = 0; i < nos; i++)
        {
            fprintf(above_8_student_arts_add, "%s\n", student_arts[i].name3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].roll3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].classs3);
            fprintf(above_8_student_arts_add, "%s\n", student_arts[i].section3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].bangla_1st_2nd3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].english_1st_2nd3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].islam_and_moral3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].bangladesh_and_global3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].ict3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].math3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].geography);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].municipal_policy);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].history);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].economy);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].physical_education3);
        }
        fclose(above_8_student_arts_add);
    }
    else
    {
        setColor(4);
        gotoxy(30, 28);
        cout << "Error saving data!" << endl;
        setColor(7);
    }
    setColor(10);
    gotoxy(30, 28);
    cout << "Info Successfully Added" << endl;
    setColor(7);
    Sleep(1000);
    system("cls");
}

void delet_below_8_student()
{
    FILE *student_below_8 = fopen("below_class_8.txt", "r");
    if (student_below_8 == NULL)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "Error: File does not exist!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }

    int i = 0;
    while (fscanf(student_below_8, "\n%[^\n]", below_8_list[i].name) == 1)
    {
        fscanf(student_below_8, "%d", &below_8_list[i].roll);
        fscanf(student_below_8, "%d", &below_8_list[i].classs);
        fscanf(student_below_8, "%s", below_8_list[i].section);
        fscanf(student_below_8, "%d", &below_8_list[i].bangla);
        fscanf(student_below_8, "%d", &below_8_list[i].english);
        fscanf(student_below_8, "%d", &below_8_list[i].math);
        fscanf(student_below_8, "%d", &below_8_list[i].science);
        fscanf(student_below_8, "%d", &below_8_list[i].bangladesh_and_global_studies);
        fscanf(student_below_8, "%d", &below_8_list[i].islam);
        i++;
    }
    nos = i;
    fclose(student_below_8);

    int grade, rollnum, pos = -1;
    gotoxy(30, 14);
    cout << "Enter Class of the student: ";
    cin >> grade;
    gotoxy(30, 16);
    cout << "Enter the roll of the student: ";
    cin >> rollnum;

    for (i = 0; i < nos; i++)
    {
        if (below_8_list[i].classs == grade && below_8_list[i].roll == rollnum)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        setColor(4);
        gotoxy(30, 18);
        cout << "Invalid Input!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }

    for (i = pos + 1; i < nos; i++)
    {
        below_8_list[i - 1] = below_8_list[i];
    }
    nos--;

    FILE *below_8_student_add = fopen("below_class_8.txt", "w");
    if (below_8_student_add != NULL)
    {
        for (i = 0; i < nos; i++)
        {
            fprintf(below_8_student_add, "%s\n", below_8_list[i].name);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].roll);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].classs);
            fprintf(below_8_student_add, "%s\n", below_8_list[i].section);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].bangla);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].english);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].math);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].science);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].bangladesh_and_global_studies);
            fprintf(below_8_student_add, "%d\n", below_8_list[i].islam);
        }
        fclose(below_8_student_add);
    }

    setColor(10);
    gotoxy(30, 18);
    cout << "Info Successfully Deleted" << endl;
    setColor(7);
    Sleep(1000);
    system("cls");
}

void science_student_delet()
{
    FILE *student_above_8_science = fopen("above_class_8_science.txt", "r");
    if (student_above_8_science == NULL)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "Error: File does not exist!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }
    int i = 0;
    while (fscanf(student_above_8_science, "\n%[^\n]", student_science[i].name1) == 1)
    {
        fscanf(student_above_8_science, "%d", &student_science[i].roll1);
        fscanf(student_above_8_science, "%d", &student_science[i].classs1);
        fscanf(student_above_8_science, "%s", student_science[i].section1);
        fscanf(student_above_8_science, "%d", &student_science[i].bangla_1st_2nd1);
        fscanf(student_above_8_science, "%d", &student_science[i].english_1st_2nd1);
        fscanf(student_above_8_science, "%d", &student_science[i].islam_and_moral1);
        fscanf(student_above_8_science, "%d", &student_science[i].bangladesh_and_global1);
        fscanf(student_above_8_science, "%d", &student_science[i].ict1);
        fscanf(student_above_8_science, "%d", &student_science[i].math1);
        fscanf(student_above_8_science, "%d", &student_science[i].highermath);
        fscanf(student_above_8_science, "%d", &student_science[i].physics);
        fscanf(student_above_8_science, "%d", &student_science[i].chemistry);
        fscanf(student_above_8_science, "%d", &student_science[i].biology);
        fscanf(student_above_8_science, "%d", &student_science[i].physical_education1);
        i++;
    }
    nos = i;
    fclose(student_above_8_science);

    int grade, rollnum, pos = -1;
    gotoxy(30, 14);
    cout << "Enter Class of the student: ";
    cin >> grade;
    gotoxy(30, 16);
    cout << "Enter the roll of the student: ";
    cin >> rollnum;

    for (i = 0; i < nos; i++)
    {
        if (student_science[i].classs1 == grade && student_science[i].roll1 == rollnum)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        setColor(4);
        gotoxy(30, 18);
        cout << "Invalid Input!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }

    for (i = pos + 1; i < nos; i++)
    {
        student_science[i - 1] = student_science[i];
    }
    nos--;

    FILE *above_8_student_science_add = fopen("above_class_8_science.txt", "w");
    if (above_8_student_science_add != NULL)
    {
        for (int i = 0; i < nos; i++)
        {
            fprintf(above_8_student_science_add, "%s\n", student_science[i].name1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].roll1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].classs1);
            fprintf(above_8_student_science_add, "%s\n", student_science[i].section1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].bangla_1st_2nd1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].english_1st_2nd1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].islam_and_moral1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].bangladesh_and_global1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].ict1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].math1);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].highermath);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].physics);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].chemistry);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].biology);
            fprintf(above_8_student_science_add, "%d\n", student_science[i].physical_education1);
        }
        fclose(above_8_student_science_add);
    }
    setColor(10);
    gotoxy(30, 18);
    cout << "Info Successfully Deleted" << endl;
    setColor(7);
    Sleep(1000);
    system("cls");
}

void commerce_student_delet()
{
    FILE *student_above_8_commerce = fopen("above_class_8_commerce.txt", "r");
    if (student_above_8_commerce == NULL)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "Error: File does not exist!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }
    int i = 0;
    while (fscanf(student_above_8_commerce, "\n%[^\n]", students_commerce[i].name2) == 1)
    {
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].roll2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].classs2);
        fscanf(student_above_8_commerce, "%s", students_commerce[i].section2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].bangla_1st_2nd2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].english_1st_2nd2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].islam_and_moral2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].bangladesh_and_global2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].ict2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].math2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].accounting);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].finence);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].business_venture);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].physical_education2);
        i++;
    }
    nos = i;
    fclose(student_above_8_commerce);

    int grade, rollnum, pos = -1;
    gotoxy(30, 14);
    cout << "Enter Class of the student: ";
    cin >> grade;
    gotoxy(30, 16);
    cout << "Enter the roll of the student: ";
    cin >> rollnum;

    for (i = 0; i < nos; i++)
    {
        if (students_commerce[i].classs2 == grade && students_commerce[i].roll2 == rollnum)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        setColor(4);
        gotoxy(30, 18);
        cout << "Invalid Input!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }

    for (i = pos + 1; i < nos; i++)
    {
        students_commerce[i - 1] = students_commerce[i];
    }
    nos--;

    FILE *above_8_student_commerce_add = fopen("above_class_8_commerce.txt", "w");
    if (above_8_student_commerce_add != NULL)
    {
        for (int i = 0; i < nos; i++)
        {
            fprintf(above_8_student_commerce_add, "%s\n", students_commerce[i].name2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].roll2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].classs2);
            fprintf(above_8_student_commerce_add, "%s\n", students_commerce[i].section2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].bangla_1st_2nd2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].english_1st_2nd2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].islam_and_moral2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].bangladesh_and_global2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].ict2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].math2);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].accounting);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].finence);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].business_venture);
            fprintf(above_8_student_commerce_add, "%d\n", students_commerce[i].physical_education2);
        }
        fclose(above_8_student_commerce_add);
    }
    setColor(10);
    gotoxy(30, 18);
    cout << "Info Successfully Deleted" << endl;
    setColor(7);
    Sleep(1000);
    system("cls");
}

void arts_student_delet()
{
    FILE *student_above_8_arts = fopen("above_class_8_arts.txt", "r");
    if (student_above_8_arts == NULL)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "Error: File does not exist!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }
    int i = 0;
    while (fscanf(student_above_8_arts, "\n%[^\n]", student_arts[i].name3) == 1)
    {
        fscanf(student_above_8_arts, "%d", &student_arts[i].roll3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].classs3);
        fscanf(student_above_8_arts, "%s", student_arts[i].section3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].bangla_1st_2nd3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].english_1st_2nd3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].islam_and_moral3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].bangladesh_and_global3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].ict3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].math3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].geography);
        fscanf(student_above_8_arts, "%d", &student_arts[i].municipal_policy);
        fscanf(student_above_8_arts, "%d", &student_arts[i].history);
        fscanf(student_above_8_arts, "%d", &student_arts[i].economy);
        fscanf(student_above_8_arts, "%d", &student_arts[i].physical_education3);
        i++;
    }
    nos = i;
    fclose(student_above_8_arts);

    int grade, rollnum, pos = -1;
    gotoxy(30, 14);
    cout << "Enter Class of the student: ";
    cin >> grade;
    gotoxy(30, 16);
    cout << "Enter the roll of the student: ";
    cin >> rollnum;

    for (i = 0; i < nos; i++)
    {
        if (student_arts[i].classs3 == grade && student_arts[i].roll3 == rollnum)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        setColor(4);
        gotoxy(30, 18);
        cout << "Invalid Input!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }

    for (i = pos + 1; i < nos; i++)
    {
        student_arts[i - 1] = student_arts[i];
    }
    nos--;
    FILE *above_8_student_arts_add = fopen("above_class_8_arts.txt", "w");
    if (above_8_student_arts_add != NULL)
    {
        for (int i = 0; i < nos; i++)
        {
            fprintf(above_8_student_arts_add, "%s\n", student_arts[i].name3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].roll3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].classs3);
            fprintf(above_8_student_arts_add, "%s\n", student_arts[i].section3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].bangla_1st_2nd3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].english_1st_2nd3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].islam_and_moral3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].bangladesh_and_global3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].ict3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].math3);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].geography);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].municipal_policy);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].history);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].economy);
            fprintf(above_8_student_arts_add, "%d\n", student_arts[i].physical_education3);
        }
        fclose(above_8_student_arts_add);
    }
    setColor(10);
    gotoxy(30, 18);
    cout << "Info Successfully Deleted" << endl;
    setColor(7);
    Sleep(1000);
    system("cls");
}

void search_below_8()
{
    int f=0;
    FILE *student_below_8 = fopen("below_class_8.txt", "r");
    if (student_below_8 == NULL)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "Error: File does not exist!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }

    int i = 0;
    while (fscanf(student_below_8, "\n%[^\n]", below_8_list[i].name) == 1)
    {
        fscanf(student_below_8, "%d", &below_8_list[i].roll);
        fscanf(student_below_8, "%d", &below_8_list[i].classs);
        fscanf(student_below_8, "%s", below_8_list[i].section);
        fscanf(student_below_8, "%d", &below_8_list[i].bangla);
        fscanf(student_below_8, "%d", &below_8_list[i].english);
        fscanf(student_below_8, "%d", &below_8_list[i].math);
        fscanf(student_below_8, "%d", &below_8_list[i].science);
        fscanf(student_below_8, "%d", &below_8_list[i].bangladesh_and_global_studies);
        fscanf(student_below_8, "%d", &below_8_list[i].islam);
        i++;
    }
    nos = i;
    fclose(student_below_8);

    int roll,clas;
    gotoxy(30,8);cout << "---Search---" << endl;
    gotoxy(30,10);cout << "Enter the Class you want to search: ";
    cin >> clas;
    gotoxy(30,12);cout << "Enter the Roll you want to search: " ;
    cin >> roll;
    system("cls");
    for( i = 0 ; i < nos ; i++ )
    {
        if(below_8_list[i].classs == clas && below_8_list[i].roll == roll )
        {
            f=1;
            gotoxy(30,4); cout << "Name: " << below_8_list[i].name << endl;
            gotoxy(30,6); cout << "Roll: " << below_8_list[i].roll << endl;
            gotoxy(30,8); cout << "Class: " << below_8_list[i].classs << endl;
            gotoxy(30,10); cout << "Section: " << below_8_list[i].section<< endl;
            gotoxy(30,12); cout << "Result of Bangla: " << below_8_list[i].bangla << endl;
            gotoxy(30,14); cout << "Result of English: " << below_8_list[i].english << endl;
            gotoxy(30,16); cout << "Result of Math: " << below_8_list[i].math << endl;
            gotoxy(30,18); cout << "Result of Science: " << below_8_list[i].science << endl;
            gotoxy(30,20); cout << "Result of Bangladesh and global studies: " << below_8_list[i].bangladesh_and_global_studies << endl;
            gotoxy(30,22); cout << "Result of Ialam and Moral Education: " << below_8_list[i].islam << endl;
            gotoxy(30,24); cout << "The total marks of the student: " << below_8_list[i].total_marks() << endl;
            gotoxy(30,26); cout << "Grade: " << below_8_list[i].grade() << endl;
            setColor(10);
            gotoxy(30,28); cout << "Press any key to continue..." ; setColor(7);
            getchar();
            getchar();
            system("cls");
        }
    }
    if(f==0)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "No Match Found...!!" << endl;
        setColor(7);
        gotoxy(30,16);cout << "Press any key to continue...." ;
        getchar();
        getchar();
        system("cls");
    }
}

void search_above_8_science()
{
    f=0;
    FILE *student_above_8_science = fopen("above_class_8_science.txt", "r");
    if (student_above_8_science == NULL)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "Error: File does not exist!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }
    int i = 0;
    while (fscanf(student_above_8_science, "\n%[^\n]", student_science[i].name1) == 1)
    {
        fscanf(student_above_8_science, "%d", &student_science[i].roll1);
        fscanf(student_above_8_science, "%d", &student_science[i].classs1);
        fscanf(student_above_8_science, "%s", student_science[i].section1);
        fscanf(student_above_8_science, "%d", &student_science[i].bangla_1st_2nd1);
        fscanf(student_above_8_science, "%d", &student_science[i].english_1st_2nd1);
        fscanf(student_above_8_science, "%d", &student_science[i].islam_and_moral1);
        fscanf(student_above_8_science, "%d", &student_science[i].bangladesh_and_global1);
        fscanf(student_above_8_science, "%d", &student_science[i].ict1);
        fscanf(student_above_8_science, "%d", &student_science[i].math1);
        fscanf(student_above_8_science, "%d", &student_science[i].highermath);
        fscanf(student_above_8_science, "%d", &student_science[i].physics);
        fscanf(student_above_8_science, "%d", &student_science[i].chemistry);
        fscanf(student_above_8_science, "%d", &student_science[i].biology);
        fscanf(student_above_8_science, "%d", &student_science[i].physical_education1);
        i++;
    }
    nos = i;
    fclose(student_above_8_science);

    int roll,clas;
    gotoxy(30,8);cout << "---Search---" << endl;
    gotoxy(30,10);cout << "Enter the Class you want to search: ";
    cin >> clas;
    gotoxy(30,12);cout << "Enter the Roll you want to search: " ;
    cin >> roll;
    system("cls");

    for( i = 0 ; i < nos ; i++ )
    {
        if(student_science[i].classs1 == clas && student_science[i].roll1 == roll )
        {
            f=1;
            gotoxy(10,4); cout << "Name: " << student_science[i].name1 << endl;
            gotoxy(10,6); cout << "Roll: " << student_science[i].roll1 << endl;
            gotoxy(10,8); cout << "Class: " << student_science[i].classs1 << endl;
            gotoxy(10,10); cout << "Section: " << student_science[i].section1<< endl;
            gotoxy(10,12); cout << "Result of Bangla 1st and Bangla 2nd: " << student_science[i].bangla_1st_2nd1 << endl;
            gotoxy(10,14); cout << "Result of English 1st and english 2nd: " << student_science[i].english_1st_2nd1 << endl;
            gotoxy(10,16); cout << "Result of Islam and Moral Studies: " << student_science[i].islam_and_moral1 << endl;
            gotoxy(60,4); cout << "Result of Bangladesh and Global Studies: " << student_science[i].bangladesh_and_global1 << endl;
            gotoxy(60,6); cout << "Result of Ict: " << student_science[i].ict1 << endl;
            gotoxy(60,8); cout << "Result of Math: " << student_science[i].math1 << endl;
            gotoxy(60,10); cout << "Result of Higher Math: " << student_science[i].highermath<< endl;
            gotoxy(60,12); cout << "Result of Physics: " << student_science[i].physics << endl;
            gotoxy(60,14); cout << "Result of Chemistry: " << student_science[i].chemistry << endl;
            gotoxy(60,16); cout << "Result of Biology: " << student_science[i].biology<< endl;
            gotoxy(60,18); cout << "Result of Physical Education: " << student_science[i].physical_education1 << endl;
            gotoxy(30,20); cout << "The total number of student: " << student_science[i].total_marks() << endl;
            gotoxy(30,22); cout << "Grade: " << student_science[i].grade() << endl;
            setColor(10);
            gotoxy(30,24); cout << "Press any key to continue..." ; setColor(7);
            getchar();
            getchar();
            system("cls");
        }
    }
    if(f==0)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "No Match Found...!!" << endl;
        setColor(7);
        gotoxy(30,16);cout << "Press any key to continue...." ;
        getchar();
        getchar();
        system("cls");
    }
}

void search_above_8_commerce()
{
    FILE *student_above_8_commerce = fopen("above_class_8_commerce.txt", "r");
    if (student_above_8_commerce == NULL)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "Error: File does not exist!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }
    int i = 0;
    while (fscanf(student_above_8_commerce, "\n%[^\n]", students_commerce[i].name2) == 1)
    {
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].roll2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].classs2);
        fscanf(student_above_8_commerce, "%s", students_commerce[i].section2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].bangla_1st_2nd2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].english_1st_2nd2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].islam_and_moral2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].bangladesh_and_global2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].ict2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].math2);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].accounting);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].finence);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].business_venture);
        fscanf(student_above_8_commerce, "%d", &students_commerce[i].physical_education2);
        i++;
    }
    nos = i;
    fclose(student_above_8_commerce);

    int roll,clas;
    gotoxy(30,8);cout << "---Search---" << endl;
    gotoxy(30,10);cout << "Enter the Class you want to search: ";
    cin >> clas;
    gotoxy(30,12);cout << "Enter the Roll you want to search: " ;
    cin >> roll;
    system("cls");

    for( i = 0 ; i < nos ; i++ )
    {
        if(students_commerce[i].classs2 == clas && students_commerce[i].roll2 == roll )
        {
            f=1;
            gotoxy(10,4); cout << "Name: " << students_commerce[i].name2 << endl;
            gotoxy(10,6); cout << "Roll: " << students_commerce[i].roll2 << endl;
            gotoxy(10,8); cout << "Class: " << students_commerce[i].classs2 << endl;
            gotoxy(10,10); cout << "Section: " << students_commerce[i].section2 << endl;
            gotoxy(10,12); cout << "Result of Bangla 1st and Bangla 2nd: " << students_commerce[i].bangla_1st_2nd2 << endl;
            gotoxy(10,14); cout << "Result of English 1st and english 2nd: " << students_commerce[i].english_1st_2nd2 << endl;
            gotoxy(10,16); cout << "Result of Islam and Moral Studies: " << students_commerce[i].islam_and_moral2 << endl;
            gotoxy(60,4); cout << "Result of Bangladesh and Global Studies: " << students_commerce[i].bangladesh_and_global2 << endl;
            gotoxy(60,6); cout << "Result of Ict: " << students_commerce[i].ict2 << endl;
            gotoxy(60,8); cout << "Result of Math: " << students_commerce[i].math2 << endl;
            gotoxy(60,10); cout << "Result of Accounting: " << students_commerce[i].accounting<< endl;
            gotoxy(60,12); cout << "Result of Finance: " << students_commerce[i].finence << endl;
            gotoxy(60,14); cout << "Result of Business Venture: " << students_commerce[i].business_venture << endl;
            gotoxy(60,16); cout << "Result of Physical Education: " << students_commerce[i].physical_education2 << endl;
            gotoxy(30,20); cout << "The total number of student: " << students_commerce[i].total_marks() << endl;
            gotoxy(30,22); cout << "Grade: " << students_commerce[i].grade() << endl;
            setColor(10);
            gotoxy(30,24); cout << "Press any key to continue..." ; setColor(7);
            getchar();
            getchar();
            system("cls");
        }
    }
    if(f==0)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "No Match Found...!!" << endl;
        setColor(7);
        gotoxy(30,16);cout << "Press any key to continue...." ;
        getchar();
        getchar();
        system("cls");
    }
}

void search_above_8_arts()
{
    FILE *student_above_8_arts = fopen("above_class_8_arts.txt", "r");
    if (student_above_8_arts == NULL)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "Error: File does not exist!" << endl;
        setColor(7);
        Sleep(800);
        return;
    }
    int i = 0;
    while (fscanf(student_above_8_arts, "\n%[^\n]", student_arts[i].name3) == 1)
    {
        fscanf(student_above_8_arts, "%d", &student_arts[i].roll3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].classs3);
        fscanf(student_above_8_arts, "%s", student_arts[i].section3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].bangla_1st_2nd3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].english_1st_2nd3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].islam_and_moral3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].bangladesh_and_global3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].ict3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].math3);
        fscanf(student_above_8_arts, "%d", &student_arts[i].geography);
        fscanf(student_above_8_arts, "%d", &student_arts[i].municipal_policy);
        fscanf(student_above_8_arts, "%d", &student_arts[i].history);
        fscanf(student_above_8_arts, "%d", &student_arts[i].economy);
        fscanf(student_above_8_arts, "%d", &student_arts[i].physical_education3);
        i++;
    }
    nos = i;
    fclose(student_above_8_arts);
    int roll,clas;
    gotoxy(30,8);cout << "---Search---" << endl;
    gotoxy(30,10);cout << "Enter the Class you want to search: ";
    cin >> clas;
    gotoxy(30,12);cout << "Enter the Roll you want to search: " ;
    cin >> roll;
    system("cls");

    for( i = 0 ; i < nos ; i++ )
    {
        if(student_arts[i].classs3 == clas && student_arts[i].roll3 == roll )
        {
            f=1;
            gotoxy(10,4); cout << "Name: " << student_arts[i].name3 << endl;
            gotoxy(10,6); cout << "Roll: " << student_arts[i].roll3 << endl;
            gotoxy(10,8); cout << "Class: " << student_arts[i].classs3 << endl;
            gotoxy(10,10); cout << "Section: " << student_arts[i].section3 << endl;
            gotoxy(10,12); cout << "Result of Bangla 1st and Bangla 2nd: " << student_arts[i].bangla_1st_2nd3 << endl;
            gotoxy(10,14); cout << "Result of English 1st and english 2nd: " << student_arts[i].english_1st_2nd3 << endl;
            gotoxy(10,16); cout << "Result of Islam and Moral Studies: " << student_arts[i].islam_and_moral3 << endl;
            gotoxy(60,4); cout << "Result of Bangladesh and Global Studies: " << student_arts[i].bangladesh_and_global3 << endl;
            gotoxy(60,6); cout << "Result of Ict: " << student_arts[i].ict3 << endl;
            gotoxy(60,8); cout << "Result of Math: " << student_arts[i].math3 << endl;
            gotoxy(60,10); cout << "Result of Geography: " << student_arts[i].geography<< endl;
            gotoxy(60,12); cout << "Result of Municipal Policy: " << student_arts[i].municipal_policy << endl;
            gotoxy(60,14); cout << "Result of History: " << student_arts[i].history << endl;
            gotoxy(60,16); cout << "Result of Economy: " << student_arts[i].economy << endl;
            gotoxy(60,18); cout << "Result of Physical Education: " << student_arts[i].physical_education3 << endl;
            gotoxy(30,20); cout << "The total number of student: " << student_arts[i].total_marks() << endl;
            gotoxy(30,22); cout << "Grade: " << student_arts[i].grade() << endl;
            setColor(10);
            gotoxy(30,24); cout << "Press any key to continue..." ; setColor(7);
            getchar();
            getchar();
            system("cls");
        }
    }
    if(f==0)
    {
        setColor(4);
        gotoxy(30, 14);
        cout << "No Match Found...!!" << endl;
        setColor(7);
        gotoxy(30,16);cout << "Press any key to continue...." ;
        getchar();
        getchar();
        system("cls");
    }
}

int main()
{
    int opt;
    while (1)
    {

        gotoxy(30, 8);
        cout << "--Menu--" << endl;
        gotoxy(30, 10);
        cout << "1. Teacher" << endl;
        gotoxy(30, 12);
        cout << "2. Student" << endl;
        gotoxy(30, 14);
        cout << "3. About us" << endl;
        gotoxy(30, 16);
        cout << "4. Exit program" << endl;
        gotoxy(30, 18);
        cout << "Select option: ";
        cin >> opt;
        system("cls");

        if (opt == 1)
        {
            while (1)
            {
                // Teacher
                gotoxy(30, 8);
                cout << "1. Login" << endl;
                gotoxy(30, 10);
                cout << "2. Sign up" << endl;
                gotoxy(30, 12);
                cout << "3. Back" << endl;
                gotoxy(30, 14);
                cout << "Select option: ";
                cin >> opt;
                system("cls");
                if (opt == 1)
                {
                    // login
                    int f = login();
                    if (f == 1)
                    {
                        setColor(10);
                        gotoxy(30, 14);
                        printf("Access Granted\n");
                        setColor(7);
                        Sleep(1000);
                        while (1)
                        {
                            system("cls");
                            gotoxy(30, 8);
                            cout << "--Teacher's Menu--" << endl;
                            gotoxy(30, 10);
                            cout << "1.Add student info and result" << endl;
                            gotoxy(30, 12);
                            cout << "2.Delete student info" << endl;
                            gotoxy(30, 14);
                            cout << "3. Back" << endl;
                            gotoxy(30, 18);
                            cout << "Select option: ";
                            cin >> opt;

                            system("cls");

                            if (opt == 1)
                            {
                                // Add a student info

                                gotoxy(30, 8);
                                cout << "--Select the class of a student--" << endl;
                                gotoxy(30, 10);
                                cout << "1. Below class 8" << endl;
                                gotoxy(30, 12);
                                cout << "2. Above class 8" << endl;
                                gotoxy(30, 16);
                                cout << "Select option: ";
                                cin >> opt;
                                system("cls");
                                if (opt == 1)
                                {
                                    /// Below class 8 srudent add
                                    below_8_student_addd();
                                }
                                else if (opt == 2)
                                {
                                    /// add a student above clas 8
                                    gotoxy(30, 8);
                                    cout << "--Select the branch of the student--" << endl;
                                    gotoxy(30, 10);
                                    cout << "1. Science" << endl;
                                    gotoxy(30, 12);
                                    cout << "2. Commerce" << endl;
                                    gotoxy(30, 14);
                                    cout << "3. Arts" << endl;
                                    gotoxy(30, 16);
                                    cout << "Select option: ";
                                    cin >> opt;
                                    system("cls");
                                    if (opt == 1)
                                    {
                                        /// Add a Student of Science
                                        add_science_student();
                                    }
                                    else if (opt == 2)
                                    {
                                        /// add a commerce student
                                        add_commerce_student();
                                    }
                                    else if (opt == 3)
                                    {
                                        /// add arts student
                                        add_arts_student();
                                    }
                                    else
                                    {
                                        setColor(4);
                                        gotoxy(30, 14);
                                        cout << "Invalid Input!" << endl;
                                        setColor(7);
                                        Sleep(800);
                                        system("cls");
                                    }
                                }
                                else
                                {
                                    setColor(4);
                                    gotoxy(30, 14);
                                    cout << "Invalid Input!" << endl;
                                    setColor(7);
                                    Sleep(800);
                                    system("cls");
                                }
                            }
                            else if (opt == 2)
                            {
                                /// Student information delet
                                while (1)
                                {
                                    gotoxy(30, 8);
                                    cout << "--Delet a Student Information--" << endl;
                                    gotoxy(30, 10);
                                    cout << "1. Below Class 9" << endl;
                                    gotoxy(30, 12);
                                    cout << "2. Above class 8" << endl;
                                    gotoxy(30, 14);
                                    cout << "3. Back" << endl;
                                    gotoxy(30, 16);
                                    cout << "Select option: ";
                                    cin >> opt;
                                    system("cls");
                                    if (opt == 1)
                                    {
                                        /// below class 8 delet
                                        delet_below_8_student();
                                    }
                                    else if (opt == 2)
                                    {
                                        /// Above class 8 delet
                                        gotoxy(30, 8);
                                        cout << "--Select the branch of the student--" << endl;
                                        gotoxy(30, 10);
                                        cout << "1. Science" << endl;
                                        gotoxy(30, 12);
                                        cout << "2. Commerce" << endl;
                                        gotoxy(30, 14);
                                        cout << "3. Arts" << endl;
                                        gotoxy(30, 16);
                                        cout << "4. Back ";
                                        gotoxy(30, 18);
                                        cout << "Select option: ";
                                        cin >> opt;
                                        system("cls");
                                        if (opt == 1)
                                        {
                                            /// Delet a science student
                                            science_student_delet();
                                        }
                                        else if (opt == 2)
                                        {
                                            /// delet a commerce student
                                            commerce_student_delet();
                                        }
                                        else if (opt == 3)
                                        {
                                            /// delet a arts student
                                            arts_student_delet();
                                        }
                                        else if (opt == 4)
                                        {
                                            break;
                                        }

                                        else
                                        {
                                            setColor(4);
                                            gotoxy(30, 14);
                                            cout << "Invalid input!" << endl;
                                            setColor(7);
                                            Sleep(900);
                                            system("cls");
                                            break;
                                        }
                                    }
                                    else if (opt == 3)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        setColor(4);
                                        gotoxy(30, 14);
                                        cout << "Invalid input!" << endl;
                                        setColor(7);
                                        Sleep(900);
                                        system("cls");
                                    }
                                }
                            }
                            else if (opt == 3)
                            {
                                break;
                            }
                            else
                            {
                                setColor(4);
                                gotoxy(30, 14);
                                cout << "Invalid input!" << endl;
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
                        gotoxy(30, 14);
                        cout << "Account Not Found" << endl;
                        setColor(7);
                        Sleep(900);
                        system("cls");
                        // break;
                    }
                }
                else if (opt == 2)
                {
                    /// Sign up
                    signupp();
                }
                else if (opt == 3)
                {
                    break;
                }
                else
                {
                    setColor(4);
                    gotoxy(30, 14);
                    cout << "Invalid input!" << endl;
                    setColor(7);
                    Sleep(700);
                    system("cls");
                }
            }
        }
        else if (opt == 2)
        {
            /// student search
            while (1)
            {
                gotoxy(30, 8);
                cout << "--Student Menu--" << endl;
                gotoxy(30, 10);
                cout << "1. Below class 8" << endl;
                gotoxy(30, 12);
                cout << "2 Above class 8" << endl;
                gotoxy(30, 14);
                cout << "3. Back" << endl;
                gotoxy(30, 16);
                cout << "Select option: ";
                cin >> opt;
                system("cls");
                if (opt == 1)
                {
                    /// Below class 8 search
                    search_below_8();
                }
                else if (opt == 2)
                {
                    while (1)
                    {
                        gotoxy(30, 10);
                        cout << "1. Science" << endl;
                        gotoxy(30, 12);
                        cout << "2. Commerce" << endl;
                        gotoxy(30, 14);
                        cout << "3. Arts" << endl;
                        gotoxy(30, 16);
                        cout << "4. Back" << endl;
                        gotoxy(30, 18);
                        cout << "Select option: ";
                        cin >> opt;
                        system("cls");
                        if (opt == 1)
                        {
                            /// search science student
                            search_above_8_science();
                        }
                        else if (opt == 2)
                        {
                            /// search commerce student
                            search_above_8_commerce();
                        }
                        else if (opt == 3)
                        {
                            /// search arts student
                            search_above_8_arts();
                        }
                        else if (opt == 4)
                        {
                            break;
                        }
                        else
                        {
                            setColor(4);
                            gotoxy(30, 14);
                            cout << "Invalid input!" << endl;
                            setColor(7);
                            Sleep(700);
                            system("cls");
                        }
                    }
                }
                else if (opt == 3)
                {
                    break;
                }
                else
                {
                    setColor(4);
                    gotoxy(30, 14);
                    cout << "Invalid input!" << endl;
                    setColor(7);
                    Sleep(700);
                    system("cls");
                }
            }
        }
        else if (opt == 3)
        {
            gotoxy(40, 8);cout << "Team Leader: Masad Rayan" << endl;
            gotoxy(40, 10);cout << "ID: C233007" << endl;
            gotoxy(40, 14);cout << "Member-1: Mohammad Shafayat Karim " << endl;
            gotoxy(40, 16);cout << "ID: C233003" << endl;
            gotoxy(40, 20);cout << "Member-2: Shafin Mahmud" << endl;
            gotoxy(40, 22);cout << "ID: C233034";
            gotoxy(40,26);cout << "Press any key to continue..." ;
            getchar();
            getchar();
            system("cls");
        }
        else if (opt == 4)
        {
            break;
        }
        else
        {
            setColor(4);
            gotoxy(30, 14);
            cout << "Invalid input!" << endl;
            setColor(7);
            Sleep(700);
            system("cls");
        }
    }
}

