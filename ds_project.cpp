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
};
struct student_below_8 below_8_list[10000];
struct student_above_8_science
{
    char name1[100], mobile1[20], section1[10];
    int roll1, classs1, bangla_1st_2nd1, english_1st_2nd1, islam_and_moral1, bangladesh_and_global1, ict1, math1, highermath, physics, chemistry, biology, physical_education1;
};
struct student_above_8_science student_science[10000];
struct student_above_8_commerce
{
    char name2[100], mobile2[20], section2[10];
    int roll2, classs2, bangla_1st_2nd2, english_1st_2nd2, islam_and_moral2, bangladesh_and_global2, ict2, math2, accounting, finence, business_venture, physical_education2;
};
struct student_above_8_commerce students_commerce[10000];
struct student_above_8_arts
{
    char name3[100], mobile3[20], section3[10];
    int roll3, classs3, bangla_1st_2nd3, english_1st_2nd3, islam_and_moral3, bangladesh_and_global3, ict3, math3, geography, municipal_policy, history, economy, physical_education3;
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
    FILE *student_above_8_arts = fopen("above_class_8_science.txt", "r");
    if (student_above_8_arts == NULL)
    {
        student_above_8_arts = fopen("above_class_8_science.txt", "w");
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
    FILE *above_8_student_arts_add = fopen("above_class_8_science.txt", "w");
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
                            cout << "3.Update student info" << endl;
                            gotoxy(30, 16);
                            cout << "4. Back" << endl;
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
                                // delete a strudent info
                            }
                            else if (opt == 3)
                            {
                                // Update a student info
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
                        else if(opt == 2)
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
        else if (opt == 2)
        {
            
        }
        else if (opt == 3)
        {
            // About us
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
