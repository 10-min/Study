
#include <iostream>
#include <cstring>
using namespace std;

const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main() {
    cout << "학급의 학생 수를 입력하십시오: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i <entered; i++) {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    cout << "프로그램을 종료합니다.\n";
    return 0;
}

int getinfo(student pa[], int n) {
    cout << "학생 정보를 입력하세요.\n";
    int i;
    for (i = 0; i < n; i++) {
        char fullname[SLEN];
        char hobby[SLEN];
        int ooplevel;
        cout << "Student " << i + 1 << endl;
        cout << "이름: ";
        cin >> fullname;
        if (fullname[0] == '\0') {
            break;
        }
        strcpy(pa[i].fullname, fullname);
        cout << "취미: ";
        cin >> pa[i].hobby;
        cout << "OOP Level: ";
        cin >> pa[i].ooplevel;
    }
    cout << "입력을 종료합니다.\n";
    return i;
}

void display1(student st) {
    cout << "이름: " << st.fullname << endl;
    cout << "취미: " << st.hobby << endl;
    cout << "OOP Level: " << st.ooplevel << endl;
}

void display2(const student *st) {
    display1(*st);
}

void display3(const student pa[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << endl;
        display1(pa[i]);
    }
}