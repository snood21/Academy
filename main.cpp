#include <iostream>
#include <string>

#define delimiter "-------------------------------------------------------------"

#define HUMAN_TAKE_PARAMETERS	const std::string& first_name, const std::string& last_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS	first_name, last_name, age

class Human
{
  std::string first_name;
  std::string last_name;
  unsigned int age;
public:
  const std::string& get_first_name() const
  {
    return first_name;
  }
  const std::string& get_last_name() const
  {
    return last_name;
  }
  unsigned int get_age() const
  {
    return age;
  }
  void set_first_name(const std::string& first_name)
  {
    this->first_name = first_name;
  }
  void set_last_name(const std::string& last_name)
  {
    this->last_name = last_name;
  }
  void set_age(const unsigned int age)
  {
    this->age = age;
  }
  
  //Constructors
  Human(HUMAN_TAKE_PARAMETERS)
  {
    set_first_name (first_name);
    set_last_name (last_name);
    set_age (age);
    std::cout << "HConstructor:\t" << this << std::endl;
  }
  
  virtual ~Human()
  {
    std::cout << "HDestructor:\t" << this << std::endl;
  }
  
  //Methods
  virtual void info() const
  {
    std::cout << get_first_name () << " " << get_last_name () << " " << get_age () << " лет" << std::endl;
  }
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
  return os << obj.get_first_name () << " " << obj.get_last_name () << " " << obj.get_age ();
}

#define STUDENT_TAKE_PARAMETERS	const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS	speciality, group, rating, attendance

class Student :public Human
{
  std::string speciality;
  std::string group;
  double rating;
  double attendance;
public:
  const std::string& get_speciality() const
  {
    return speciality;
  }
  const std::string& get_group() const
  {
    return group;
  }
  double get_rating() const
  {
    return rating;
  }
  double get_attendance() const
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
  
  //Constructors
  Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
  {
    set_speciality (speciality);
    set_group (group);
    set_rating (rating);
    set_attendance (attendance);
    std::cout << "SConstructor:\t" << this << std::endl;
  }
  ~Student()
  {
    std::cout << "SDestructor:\t" << this << std::endl;
  }
  
  //Methods
  void info() const override
  {
    Human::info ();
    std::cout << get_speciality () << " " << get_group () << " " << get_rating () << get_rating () << std::endl;
  }
};

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
  return os << (Human&) obj << " " << obj.get_speciality () << " " << obj.get_group () << " " << obj.get_rating () << " " << obj.get_attendance ();
}

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
  std::string speciality;
  unsigned int experience;
public:
  const std::string& get_speciality() const
  {
    return speciality;
  }
  unsigned int get_experience() const
  {
    return experience;
  }
  void set_speciality (const std::string& speciality)
  {
    this->speciality = speciality;
  }
  void set_experience (unsigned int experience)
  {
    this->experience = experience;
  }
  
  //Constructors
  Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS): Human (HUMAN_GIVE_PARAMETERS)
  {
    set_speciality (speciality);
    set_experience (experience);
    std::cout << "TConstructor:\t" << this << std::endl;
  }
  ~Teacher()
  {
    std::cout << "TDestructor:\t" << this << std::endl;
  }
  //Methods
  void info() const override
  {
    Human::info ();
    std::cout << get_speciality () << " " << get_experience () << std::endl;
  }
};

std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
  return os << (Human&) obj << " " << obj.get_speciality () << " " << obj.get_experience ();
}

class Graduate: public Student
{
  std::string subject;
public:
  const std::string& get_subject() const
  {
    return subject;
  }
  void set_subject(const std::string& subject)
  {
    this->subject = subject;
  }
  //Constructors
  Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject): Student (HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
  {
    set_subject (subject);
    std::cout << "GConstructor:\t" << this << std::endl;
  }
  ~Graduate()
  {
    std::cout << "GDestructor:\t" << this << std::endl;
  }
  
  //Methods
  void info() const override
  {
    Student::info ();
    std::cout << get_subject () << std::endl;
  }
};

std::ostream& operator<<(std::ostream& os, const Graduate& obj)
{
  return os << (Student&) obj << " " << obj.get_subject ();
}

//#define INHERITANSE
#define POLYMORPHISM

int main ()
{
  setlocale (LC_ALL, "Russian");
  
#ifdef INHERITANSE
  Human human ("Montana", "Antonio", 25);
  human.info ();

  Student stud ("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90);
  stud.info ();

  Teacher white ("White", "Walter", 50, "Chemistry", 25);
  white.info ();

  Graduate grad ("Schrader", "Hank", 40, "Criminalistic", "OBN", 85, 80, "How to catch Heisenberg");
  grad.info();
#endif 

#ifdef POLYMORPHISM
  /*Human* p_human1 = new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90);
  Human* p_human2 = new Teacher("White", "Walter", 50, "Chemistry", 25);
  p_human1->info ();
  p_human2->info ();*/
  //Generalisation
  Human* group[] = 
  {
    new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90),
    new Teacher("White", "Walter", 50, "Chemistry", 25), //UpCast
    new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 85, 80, "How to catch Heisenberg"),
    new Student("Vercetti", "Tomas", 25, "Criminalistic", "Vice", 85, 98),
    new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
  };
#endif
  
  std::cout << delimiter << std::endl;
  for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
      //group[i]->info ();
      std::cout << typeid(*group[i]).name () << std::endl;

      //std::cout << *group[i] << std::endl;
      if (typeid(*group[i])==typeid(Student)) std::cout << *(dynamic_cast <Student*> (group[i])) << std::endl;
      else if (typeid(*group[i])==typeid(Teacher)) std::cout << *(dynamic_cast <Teacher*> (group[i])) << std::endl;
      else if (typeid(*group[i])==typeid(Graduate)) std::cout << *(dynamic_cast <Graduate*> (group[i])) << std::endl;
      std::cout << delimiter << std::endl;
    }
  
  for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
      delete group[i];
    }
    
  return 0;
}

