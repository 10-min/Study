#include <iostream>
#include <cstring>

const int strsize = 30;

struct bop {
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference; // 0 = fullname, 1 = title, 2 = bopname
};

int main() {
    using namespace std;

    bop members[3] = {
        {"Ethan Sullivan", "Software Engineer", "CodeSage", 0},
        {"Logan Mitchell", "Robotics Developer", "BugHunter", 1},
        {"Nathan Carter", "Emnbedded Systems Engineer", "AlgoKnight", 2}
    };
    
    char cmd;
    cout << "Benevolent Order of Programmers\n";

    do {
        cout << "a. 실명으로 열람\t b. 직함으로 열람\n";
        cout << "c. BOP 아이디로 열람\t d. 회원이 지정한 것으로 열람\n";
        cout << "q. 종료\n";
        cin >> cmd;

        switch (cmd) {
            case 'a':
                for (int i = 0; i < 3; i++) {
                    cout << members[i].fullname << endl;
                }
                break;
            case 'b':
                for (int i = 0; i < 3; i++) {
                    cout << members[i].title << endl;
                }
                break;
            case 'c':
                for (int i = 0; i < 3; i++) {
                    cout << members[i].bopname << endl;
                }
                break;
            case 'd':
                for (int i = 0 ; i < 3; i++) {
                    int preference = members[i].preference;
                    char preferName[strsize];
                    if (preference == 0) {
                        strcpy(preferName, members[i].fullname);
                    } else if (preference == 1) {
                        strcpy(preferName, members[i].title);
                    } else {
                        strcpy(preferName, members[i].bopname);
                    }
                    cout << preferName << endl;
                }
                break;
        }
    } while (cmd != 'q');

    return 0;
}