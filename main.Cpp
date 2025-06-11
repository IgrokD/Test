#include <iostream>
#include <vector>
#include <string>
int main()
{

}

class chess {
private:std::vector<std::string> figures_positions;
private:std::vector<std::string> change_saver;
private:bool isWhiteTurn;//перевірка для таймерів
public: void StartPosition() {
        figures_positions = std::vector<std::string>{ "WRA1","WHB1","WBC1","WQD1",
            "WKE1","WBF1","WHG1","WRH1","BRA8","BHB8","BBC8","BQD8","BKE8","BBF8","BHG8","BRH8"};
        for (int i = 0; i < 8; i++) {
            char tcol=char(65+i);
            std::string temp;
            temp.push_back('W');
            temp.push_back('P');
            temp.push_back(tcol);
            temp.push_back('2');
            figures_positions.push_back(temp);
            temp.clear();
            temp.push_back('B');
            temp.push_back('P');
            temp.push_back(tcol);
            temp.push_back('7');
            figures_positions.push_back(temp);
            temp.clear();
        }
    }
public: void Timers(int timer) {
        int timerW=timer;
        int timerB=timer;
        if (isWhiteTurn) {
            timerW--;
        }
        else {
            timerB--;
        }
    }
//Фігуру зберігається колір тип колонка і ряд в MoveTo тільки колонка і ряд
private: bool MoveChecker(std::string figure,std::string posible_position) {
    //Перевірка чи не виходить за обмеження можлива зміна позиціїї
    if (posible_position[0] < 'A' || posible_position[0]>'H' || posible_position[1] < '1' || posible_position[1]>'8') return true;
    //Перевірка чи змінюється позиція не на ту самуж клітинку
    if (figure[2, 3] == posible_position[0, 1])return true;
    //Перевірка чи гравець не намагається походити фігурою опонента
    if (figure[0] == 'W' && !isWhiteTurn)return true;
    else if (figure[0] == 'B' && isWhiteTurn)return true;
    //перевірка чи немає на зміненної позиції фігури тогож кольору
    if(CheckPositionForAlly(figure[0],posible_position))return true;
    
    
    
    
    return false;
}
private: std::string FigureFinder(std::string position) {
    //Забув як робити цикл foreach тому можеш якщо захочеш переробити
    for (int i = 0; i < figures_positions.size(); i++) {
        if (figures_positions[i][2, 3] == position[0, 1]) {
            return figures_positions[i];
        }
    }
    return "NOTF";
}
private: bool CheckRookMovment(std::string current_position, std::string posible_position) {
    int colchanger = int(current_position[0]-posible_position[0]);
    int rowchanger = int(current_position[1] - posible_position[1]);
    if (colchanger != 0 && rowchanger != 0)return true;
    else if (colchanger != 0) {
        if (colchanger < 0) {
            for (int i = int('A' - current_position[0]) + 1; i<int('A' - posible_position[0]); i++) {
                std::string temp;
                temp.push_back(char(int(current_position[0]) + i));
                temp.push_back(current_position[1]);
                if (FigureFinder(temp) != "NOTF")return true;
                temp.clear();
            }
        }
        else {
            for (int i = int('A' - posible_position[0]) + 1; i<int('A' - current_position[0]); i++) {
                std::string temp;
                temp.push_back(char(int(current_position[0]) - i));
                temp.push_back(current_position[1]);
                if (FigureFinder(temp) != "NOTF")return true;
                temp.clear();
            }
        }
    }
    else if (rowchanger != 0) {
        if (rowchanger < 0) {
            for (int i = int('0' - current_position[1]) + 1; i<int('0' - posible_position[1]); i++) {
                std::string temp;
                temp.push_back(current_position[0]);
                temp.push_back(char(int(current_position[1]) + i));
                if (FigureFinder(temp) != "NOTF")return true;
                temp.clear();
            }
        }
        else {
            for (int i = int('0' - posible_position[1]) + 1; i<int('0' - current_position[1]); i++) {
                std::string temp;
                temp.push_back(current_position[0]);
                temp.push_back(char(int(current_position[1]) - i));
                if (FigureFinder(temp) != "NOTF")return true;
                temp.clear();
            }
        }
    }
    return false;
}
private: bool CheckBishopMovment(std::string current_position, std::string posible_position) {
    int colchanger = int(current_position[0] - posible_position[0]);
    int rowchanger = int(current_position[1] - posible_position[1]);
    if (colchanger != rowchanger && colchanger * -1 != rowchanger)return true;
    if (colchanger < 0) {
        if (rowchanger < 0) {
            for (int i = int('A' - current_position[0]) + 1; i<int('A' - posible_position[0]); i++) {
                std::string temp;
                temp.push_back(char(int(current_position[0]) + i));
                temp.push_back(char(int(current_position[1]) + i));
                if (FigureFinder(temp) != "NOTF")return true;
                temp.clear();
            }
        }
        else {
            for (int i = int('A' - current_position[0]) + 1; i<int('A' - posible_position[0]); i++) {
                std::string temp;
                temp.push_back(char(int(current_position[0]) + i));
                temp.push_back(char(int(current_position[1]) - i));
                if (FigureFinder(temp) != "NOTF")return true;
                temp.clear();
            }
        }
    }
    else {
        if (rowchanger < 0) {
            for (int i = int('A' - current_position[0]) + 1; i<int('A' - posible_position[0]); i++) {
                std::string temp;
                temp.push_back(char(int(current_position[0]) - i));
                temp.push_back(char(int(current_position[1]) + i));
                if (FigureFinder(temp) != "NOTF")return true;
                temp.clear();
            }
        }
        else {
            for (int i = int('A' - current_position[0]) + 1; i<int('A' - posible_position[0]); i++) {
                std::string temp;
                temp.push_back(char(int(current_position[0]) - i));
                temp.push_back(char(int(current_position[1]) - i));
                if (FigureFinder(temp) != "NOTF")return true;
                temp.clear();
            }
        }
    }
    return false;
}
private: bool CheckQueentMovment(std::string current_position, std::string posible_position) {
    if (CheckBishopMovment && CheckRookMovment)return true;
    return false;
}
private: bool CheckKingMovment(std::string current_position, std::string posible_position) {
    int colchanger = int(current_position[0] - posible_position[0]);
    int rowchanger = int(current_position[1] - posible_position[1]);
    if (colchanger<-1||colchanger>1||rowchanger<-1||rowchanger>1||(colchanger==0&&rowchanger==0))return true;
    return false;
}
private: bool CheckPositionForAlly(char color, std::string position) {
    std::string figure = FigureFinder(position);
    if (figure == "NOTF")return true;
    if (color == figure[0])return true;
    return false;
}
};