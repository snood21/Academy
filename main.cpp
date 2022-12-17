#pragma warning(disable:4326)

#include<iostream>
#include<string>
using namespace std;

#define delimiter "\n---------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS	const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS	last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//						Constructor
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//						Methods:
	virtual std::ostream& info(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " лет,";
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
  return obj.info (os);
}

#define STUDENT_TAKE_PARAMETERS	const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS	speciality, group, rating, attendance

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;		//успеваемость
	double attendance;	//посещаемость
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//					Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//					Methods:
	std::ostream& info(std::ostream& os)const 
	{
		return Human::info(os) << speciality << " " << group << " " << rating << " " << attendance;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//					Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//					Methods:
	std::ostream& info(std::ostream& os)const 
	{
		return Human::info(os) << speciality << " " << experience;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//					Constructors:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//				Methods:
	std::ostream& info(std::ostream& os)const 
	{
		return Student::info(os) << subject;
	}
};

//#define INHERITANCE
#define POLYMORPHISM

int main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.info();

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90);
	stud.info();

	Teacher white("White", "Walter", 50, "Chemistry", 25);
	white.info();

	Graduate grad("Schrader", "Hank", 40, "Criminalistic", "OBN", 85, 80, "How to catch Heisenberg");
	grad.info();
#endif // INHERITANCE

#ifdef POLYMORPHISM
	/*
	--------------------------
	Polymorhism (Poly - много, Morhis - форма)
	Ad-hoc polymorphism - это перегрузка функций, методов, и операторов,
						  реализуется на этапе компиляции, поэтому еще называется
						  Compile-time polymorhism.
	Inclusion polymorphism (Полиморфизм подтипов) - это способность объектов вести себя по разному,
						  в зависимости от того, кем они являеются.
						  Например, любое животное издает звуки, но каждое животное издает звук,
						  в зависимости от того, кем оно является:
						  Собаки лают, Коты мяукают.
	Реализуется при помощи:
	1. указателей на базовый класс.
	   Указатель на базовый класс может хранить адрес дочернего объекта,
	   это позволяет выполнят Generalisation (Обобщение)
	   Upcast - приведение к базовому типу.
	2. виртуальных методов.
	   Виртуальным называется метод, который может быть переопределен в дочернем классе,
	   с учетом его полей.
	   Виртуальные методы позволяют выполнять Specialisation (уточнение) - переход
	   от чего-то более абстрактного, более конктреному, такой переход еще называют Downcast.
	--------------------------
	*/

	/*Human* p_human1 = new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90);
	Human* p_human2 = new Teacher("White", "Walter", 50, "Chemistry", 25);
	p_human1->info();
	p_human2->info();*/

	//Generalisation:
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90),
		new Teacher("White", "Walter", 50, "Chemistry", 25),	//UpCast
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 85, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Criminalistic", "Vice", 85, 98),
		new Teacher("Diaz", "Ricardo", 50, "Weapons ditribution", 20),
	};

	cout << delimiter << endl;
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // POLYMORPHISM

}