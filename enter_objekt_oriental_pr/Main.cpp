#include <iostream>
#include <string>


//private
//protected
//public

class Person {
protected:    //при наследовании поля становятся доступными в дочерних классах(protected)
	std::string name;
	int age;
public:

	//конструктор по умолчанию
	Person() {
		name = "No name";
		age = 18;
	}

	//параметрический конструктор
	Person(std::string name, int age) {
		this->name = name;  //указатель на самого себя (this->)
		this->age = age;
	}

	//конструктор копирования
	Person(const Person& other) {
		this->name = other.name;
		this->age = other.age;
	}

	//деструктор
	~Person() {
		std::cout << name << "destroyed" << std::endl;
	}
	void introduce() {
		std::cout << "My name is " << name << std::endl;
}

	//свойства:
//геттеры(get)
//сеттеры(set)
	void setName(std::string name) {
		this->name = name;
	}
	std::string getName() {
		return name;
	}
};

class Student : public Person {  //: показывает всё публичное наследование (public)
private:
	std::string group;
	int grades_number;
	int* grades;
public:
	Student() : Person() {
		group = "undefined";
		grades = nullptr;
		grades_number = 0;
	}
	Student(std::string name, int age, std::string group, int grades[], int grades_number) : Person(name,age) { //Person - конструктор родительского класса
		this->group = group;
		this->grades = new int[grades_number] {};
		for (int i = 0; i < grades_number; i++)
			this->grades[i] = grades[i];
	}
	~Student() {
		delete[] grades;
	}
	void printGrades() {
		for (int i = 0; i < grades_number; i++)
			std::cout << grades[i] << ' ';
		std::cout << std::endl;
	}
	
};





int main() {
	system("chcp 1251>nul");
	int n, m;

	//создание объекта класса
	/*Person p1("Bob", 25);
	p1.introduce(); 

	if (true) {
		Person tmp("Mike", 50);
		tmp.introduce();
	}

	Person p2(p1);
	p2.setName ("Tom");
	p2.introduce(); //вызов конструктора копирования

	std::cout << "Имя объекта: " << p2.getName() << std::endl;*/

	//работа с классом-наследником
	int grades[3]{ 10,12,9 };
	Student s1("Rodion", 20, "БВ322", grades,3);
	s1.introduce();
	s1.printGrades();



	return 0;
}