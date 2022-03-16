#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <random>
#include <time.h>

using namespace std;

class tile {
public:
    enum bombPosition{
        bomb,
        empty
    };
    enum tileVisible {
        visible,
        invisible
    };
    enum bombCheck {
        bome,
        none
    };
    enum tileNumber {
        zero,
        one,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight
    };
    struct tileState {
        bombPosition gameBomb;
        tileVisible gameVisible;
        bombCheck gameBombCheck;
        tileNumber gameNumber;
    };
    vector<vector<tileState>> mainTile;
    void consoleSetting();
    void cinClear();
    void Difficulty();
    void startSetting();
    void start();
    void draw();
    void getEvent();
    void operation1();
    void operation2();
    void eventOperation();
    int difficulty;
    int lengthX;
    int lengthY;
    int userInputX;
    int userInputY;
    int userInputCommand;
    int random;
}; 
//void gotoxy(int x, int y){
//    COORD pos = { x,y };
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//void textcolor(int color_number){
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
//}
void tile::consoleSetting() {
    system("mode con cols=100 lines=30 | title 제목명");

}
void tile::cinClear() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
    }
}
void tile::Difficulty() {
    cinClear();
    cout << "난이도를 선택해주세요." << endl;
    cout << "쉬움: 1" << endl;
    cout << "쉬움: 2" << endl;
    cout << "쉬움: 3" << endl;
    cout << "커스텀: 4" << endl;
    cin >> difficulty;
    if (difficulty == 4) {
        cout << "x축의 길이를 적어주세요: ";
        cin >> lengthX;
        cout << "y축의 길이를 적어주세요: ";
        cin >> lengthY;
    }
    else if (difficulty >= 1 && difficulty <= 3) {
        lengthX = difficulty * 8-1;
        lengthY = difficulty * 8-1;
    }
    else {
        system("cls");
        cout << "다시 입력해주세요" << endl;
        Difficulty();
    }
}
void tile::startSetting() {
    for (int i = 0; i < lengthX; i++) {
        for (int j = 0; j < lengthY; j++) {
            random = ((rand() % 12) / difficulty);
            if (random == 1)
                mainTile[i][j].gameBomb = bomb;
            else
                mainTile[i][j].gameBomb = empty;
            mainTile[i][j].gameVisible = invisible;
            mainTile[i][j].gameBombCheck = none;
            mainTile[i][j].gameNumber = zero;
        }
    }
    mainTile[userInputX][userInputY].gameBomb = empty;
}
void tile::start() {
    draw();
    getEvent();
}
void tile::draw() {
    system("cls");
    for (int i = -2; i < lengthY; i++) {
        for (int j = -2; j < lengthX; j++) {
            if (i == -2 && j == -2)
                cout << "  ";
            else if (i == -1 && j == -1)
                cout << "┼";
            else if (i == -1)
                cout << "──";
            else if (j == -1)
                cout << "│";
            else if (i == -2)
                cout << setw(2) << j + 1;
            else if (j == -2)
                cout << setw(2) << i + 1;
            else {
                if (mainTile[i][j].gameVisible == visible) {
                    if (mainTile[i][j].gameBomb == empty) {
                        cout << "  ";
                    }
                    else {
                        cout << "Bo";
                    }
                }
                else {
                    cout << "【】";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
    //입력값받아오기
}
void tile::getEvent() {
    cinClear();
    cout << "좌표 값 입력(x y):";
    cin >> userInputX >> userInputY;
    if((userInputX>=0&&userInputX<=lengthX)&&(userInputY>=0&&userInputX<=lengthY)){
        cout << endl;
        cout << "확인: 1" << endl;
        cout << "지뢰표시: 2 " << endl;
        cout << "수행할 작업 입력: ";
        cinClear();
        cin >> userInputCommand;
        if (userInputCommand == 1)
            operation1();
        else if (userInputCommand == 2)
            operation2();
    }
    system("cls");

    getEvent();
}
void tile::operation1() {

}
void tile::operation2() {

}
void tile::eventOperation() {

}
int main()
{
    srand((unsigned int)time(NULL));
    tile game;
    game.consoleSetting();
    game.Difficulty();
    game.startSetting();
    game.start();
}