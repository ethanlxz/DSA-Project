#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <unordered_map>
#include <regex>
#include <cmath>
#include <fstream>
#include <algorithm>

// color codes
#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

using namespace std;

class Person;
class Student;
class Teacher;

extern int studID;
extern int teacherID;
extern int totalStudents;
extern int totalTeachers;


class Person
{
protected:
	string fname; // first name
	string lname; // last name
	string name;  // first name + last name
	char gender;  // Gender is either M or F
	int id;
	string email;
	string bday;
	string contactNum;

public:
	Person();
	virtual ~Person();
	// setter
	void setgender(char g);
	void setFname(string n);
	void setLname(string n);
	void setName();
	void setID(int i);
	void setEmail(string e);
	void setBday(string b);
	void setContactNum(string c);

	// getter
	char getGender();
	string getFname();
	string getLname();
	string getName();
	int getID();
	string getEmail();
	string getBday();
	string getContactNum();
};

class Student : public Person // inherits from person class
{
private:
	string major;
public:
	Student();																	
	Student(int _id, string f, string l, char g, string c, string e, string b, string major_); 
	~Student();
	string getMajor();
	void setMajor(string m);
};

class Teacher : public Person // inherits from person class
{

public:
	Teacher();																	// default constructor
	Teacher(int _id, string f, string l, char g, string c, string e, string b); // constructor with every necessary info
	~Teacher();
};

struct sList
{
	Student *student;
	sList *next;

	// Constructor for sList that initializes a Student object
	sList(int _id, string f, string l, char g, string c, string e, string b, string major)
		: student(new Student(_id, f, l, g, c, e, b, major)), next(nullptr)
	{
	}

	// Destructor to clean up the allocated Student object
	~sList()
	{
		delete student;
	}
};

void addStudent(sList *&head);
void addStudentToEnd(sList *&head, sList *newNode);
void deleteStudent(sList *&head);

void searchStudent(sList *head); // uses Linear Search

void displayStudents(sList *&head);// uses Merge Sort
sList* mergeSort(sList* head, int option);

// Linked list for teacher
struct tList
{
	Teacher *teacher;
	tList *next;

	// Constructor for sList that initializes a Teacher object
	tList(int _id, string f, string l, char g, string c, string e, string b)
		: teacher(new Teacher(_id, f, l, g, c, e, b)), next(nullptr)
	{
	}

	// Destructor to clean up the allocated Teacher object
	~tList()
	{
		delete teacher;
	}
};

void addTeacher(tList *&head);
void addTeacherToEnd(tList *&head, tList *newNode);
void deleteTeacher(tList *&head);
void searchTeacher(tList *head);

void displayTeacher(tList *&head);
tList* insertionSort(tList* head, int option);
bool compare(tList* a, tList* b, int option);
tList* insertSorted(tList* sorted, tList* newNode, int option) ;


// Queue node
struct node {
    int id;         // ID of the person submitting the problem
    string role;    // Role of the person (Student/Teacher)
    string problem; // Description of the problem
    node *next;     // Pointer to the next node in the queue
};

// Class to implement a queue (FIFO) for problem tickets
class ADTqueue {
private:
    node *front_, *rear; // Pointers to track the front and rear of the queue
    int count;          // Count of tickets in the queue

public:
    ADTqueue();

    bool empty();
    void append(int id, const string& role, const string& problem); 
    void serve(); 
    int size(); 
    void display();
    string front();
};

// Class to manage administrative tasks (handling problem tickets)
class Admin {
private:
    ADTqueue problemQueue; // Queue to store submitted problems
    int solvedCount;       // Counter to track the number of solved problems

public:
    Admin();

    void submitProblem(int id, const string& role, const string& problem);
    void viewProblem();
    void solveProblem();
};

void submitTicket(Admin &ad, const string &role);