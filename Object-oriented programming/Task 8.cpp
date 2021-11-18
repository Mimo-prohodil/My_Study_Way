#include <clocale>
#include <iostream>
#include <stdexcept>

#pragma region Task_1
template<typename T> T div(T op1, T op2) {
    if (op2 == 0) {        
        throw std::runtime_error("DivisionByZero");
    }
    return op1 / op2;
}

#pragma endregion 

#pragma region Task_2

class Ex {
private:
    int x;
public:
    Ex(int x) : x(x){}
    friend std::ostream& operator<<(std::ostream& os, const Ex m_Ex);
};

std::ostream& operator<<(std::ostream& os, const Ex m_Ex) {
    os << m_Ex.x;
    return os;
}

class Bar {
private:
    int y;
public: 
    Bar() : y(0) {}
    void setY(int a) {
        y = a;
    }
    int getY() {
        return y;
    }
};

#pragma endregion 

#pragma region Task_3

//class OffTheField {
//private:
//    int position;
//    int direction;
//public:
//    OffTheField(int position, int direction) : position(position), direction(direction) {}
//    int getPosition() {
//        return position;
//    }
//    int getDirection() {
//        return direction;
//    }
//};
//
//class IllegalCommand {
//private:
//    int position;
//    int direction;
//public:
//    IllegalCommand(int position, int direction) : position(position), direction(direction) {}
//    int getPosition() {
//        return position;
//    }
//    int getDirection() {
//        return direction;
//    }
//};
//
//class Robot {
//private:
//    int field[10][10];
//    int** position;
//    char direction;
//public:
//    Robot() : direction('0') {
//        field[10][10] = { 0 };
//        position = new field;
//    }
//    void setDirection(char a) {
//        direction = a;
//    }
//    void setPosition(int a, int b) {
//        position[a][b] = 1;
//    }
//    void movement(char dir, int&& pos) {
//        if (dir == 'w') {
//            pos[][]
//        }
//    }
//};
enum Command
{
	MOVE_NORTH,
	MOVE_WEST,
	MOVE_SOUTH,
	MOVE_EAST,
	MOVE_UP,
	MOVE_DOWN,
};

const char* commandToString(Command command)
{
	switch (command)
	{
	case MOVE_NORTH: return "MOVE_NORTH";
	case MOVE_WEST: return "MOVE_WEST";
	case MOVE_SOUTH: return "MOVE_SOUTH";
	case MOVE_EAST: return "MOVE_EAST";
	case MOVE_UP: return "MOVE_UP";
	case MOVE_DOWN: return "MOVE_DOWN";
	}
	return "";
}

class OffTheField : public std::range_error
{
public:
	int posX;
	int posY;
	Command command;

	OffTheField(int posX, int posY, Command command, const char* message = "") : std::range_error(message), posX(posX), posY(posY), command(command) {}
};

class IllegalCommand : public std::range_error
{
public:
	Command command;

	IllegalCommand(Command command, const char* message = "") : std::range_error(message), command(command) {}
};

class Robot
{
public:
	int posX;
	int posY;

	Robot(int posX, int posY) : posX(posX), posY(posY) {}

	void move(Command command)
	{
		switch (command)
		{
		case MOVE_NORTH:
			if (posY == 0)
				throw OffTheField(posX, posY, command, "OffTheField");
			--posY;
			break;

		case MOVE_WEST:
			if (posX == 0)
				throw OffTheField(posX, posY, command, "OffTheField");
			--posX;
			break;

		case MOVE_SOUTH:
			if (posY == 9)
				throw OffTheField(posX, posY, command, "OffTheField");
			++posY;
			break;

		case MOVE_EAST:
			if (posX == 9)
				throw OffTheField(posX, posY, command, "OffTheField");
			++posX;
			break;

		default:
			throw IllegalCommand(command, "IllegalCommand");
		}
	}
};

void task3_robotMoveTest(Robot& robot, Command command)
{
	try
	{
		robot.move(command);
	}
	catch (OffTheField& offTheField)
	{
		printf("%s: pos(%d, %d) command %s\n", offTheField.what(), offTheField.posX, offTheField.posY, commandToString(offTheField.command));
	}
	catch (IllegalCommand& illegalCommand)
	{
		printf("%s: %s\n", illegalCommand.what(), commandToString(illegalCommand.command));
	}
}

#pragma endregion 

int main()
{
    setlocale(LC_ALL, "Russian");

    /*{
        std::cout << "№1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero," << std::endl;
        std::cout << "если второй параметр равен 0. В функции main выводить результат вызова функции div в консоль, а также ловить исключения. " << std::endl;
        try {
            std::cout << "12 / 3 = " << div<int>(12, 3) << std::endl;
            std::cout << "13 / 0 = " << div<int>(13, 0) << std::endl;
        }
        catch (std::runtime_error e) {
            std::cout << e.what() << std::endl;
        }
    }*/

    /*{
        std::cout << "№2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра. " << std::endl;
        std::cout << " Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a. " << std::endl;
        std::cout << " Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a. В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n." << std::endl;
        std::cout << " Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения." << std::endl;
        Bar b; 
        int n;
        do {
            std::cout << "Введте число :";
            std::cin >> n;            
            try {
                if ((b.getY() + n) > 100) {
                    throw Ex(n * b.getY());
                }
                b.setY(n);
            }
            catch(Ex){
                std::cout << Ex(n * b.getY()) << std::endl;
            }
        } while (n != 0);
    }*/

    {
        std::cout << "№3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию." << std::endl;
        std::cout << "Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне)." << std::endl;
        std::cout << "Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов," << std::endl;
        std::cout << "а также выводящую подробную информацию о всех возникающих ошибках." << std::endl;
        
		Robot robot(2, 2);

		bool isMoving = true;

		while (isMoving)
		{
			printf("Robot position (%d, %d)\n", robot.posX, robot.posY);

			fflush(stdin);
			char command;
			std::cin >> command;

			switch (command)
			{
			case 'n':
				task3_robotMoveTest(robot, MOVE_NORTH);
				break;
			case 'w':
				task3_robotMoveTest(robot, MOVE_WEST);
				break;
			case 's':
				task3_robotMoveTest(robot, MOVE_SOUTH);
				break;
			case 'e':
				task3_robotMoveTest(robot, MOVE_EAST);
				break;
			case 'u':
				task3_robotMoveTest(robot, MOVE_UP);
				break;
			case 'd':
				task3_robotMoveTest(robot, MOVE_DOWN);
				break;
			default:
				isMoving = false;
			}
		}
	}
    return 0;
}