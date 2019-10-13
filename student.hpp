/*
 * Filename: student.hpp
 * Author: Robert Respicio & Joshua Yeh
 * Date Created: Sept 20, 2019
 * Last Updated: Sept 25, 2019
 * Description:
 * Header file to declare your classes; containing one parent class, Student, and 
 * two corresponding child child classes, DomesticStudents and InternationalStudents, 
 * and another seperate class, TOEFLScore, utilized for the InternationalStudents class.
 *
 */
 
//--------------------------------------------------------- 
//INCLUDES 
//---------------------------------------------------------
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

//--------------------------------------------------------- 
// CLASSES
//---------------------------------------------------------
class InternationalStudent;
class DomesticStudent;
//Main Parent Class
class Student
{
    public:
    friend int compareCGPA(DomesticStudent student1, DomesticStudent student2);
    friend int compareCGPA(InternationalStudent student1, InternationalStudent student2);
    friend int compareResearchScore(DomesticStudent student1, DomesticStudent student2);  
    friend int compareResearchScore(InternationalStudent student1, InternationalStudent student2);
    friend int compareFirstName(DomesticStudent student1, DomesticStudent student2);
    friend int compareFirstName(InternationalStudent student1, InternationalStudent student2);
    friend int compareLastName(DomesticStudent student1, DomesticStudent student2);
    friend int compareLastName(InternationalStudent student1, InternationalStudent student2);
    friend void sortArray(DomesticStudent student[], int arg, int size);
    friend void sortArray(InternationalStudent student[], int arg, int size);
    friend void sortGPA(DomesticStudent student[],int start, int size);
    friend void sortGPA(InternationalStudent student[],int start, int size);
    friend void sortRS(DomesticStudent student[],int start, int size);
    friend void sortRS(InternationalStudent student[],int start, int size);
    friend void sortFirstName(DomesticStudent student[],int start, int size);
    friend void sortFirstName(InternationalStudent student[],int start, int size);
    friend void sortLastName(DomesticStudent student[],int start, int size);
    friend void sortLastName(InternationalStudent student[],int start, int size);
    friend void sortProvince(DomesticStudent student[], int start, int size);
    friend void sortCountry(InternationalStudent student[], int start, int size);
    friend void sortOverall(DomesticStudent student[], int size);
    friend void sortOverall(InternationalStudent student[], int size);
    friend void printALLDomestic(DomesticStudent student[], int size);
    friend void printALLInternational(InternationalStudent student[], int size);


    Student(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId);   //Declaration of class
    Student(); //Declaration of empty student class
    void set(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId);  //Set function for Student class members
    void set(float Cgpa);	//Declaration of set function for just Cgpa value
    string getFirstName() const;  //Declaration of get function to get firstname string variable
    string getLastName() const;   //Declaration of get function to get lastname string variable
    float getCgpa() const;   	//Declaration of get function to get cgpa float variable
    int getResearchScore() const; //Declaration of get function to get researchScore variable
    int getStudentId() const;     //Declaration of get function to get studentID int variable
    private:
    string firstName;  //first name string variable 
    string lastName;   //last name string variable
    float cgpa;        //cgpa float variable
    int researchScore; //researchscore int variable
    int studentId;     //studentId int variable
};

//Child Class of Student Class for DomesticStudents 
class DomesticStudent : public Student
{
    public:
    friend ostream& operator <<(ostream& outs, const DomesticStudent& student);
    DomesticStudent(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId); //Declaration of class
    DomesticStudent();//Declaration of empty domesticstudent class
    void set(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId);
    string getProvince() const; //Declaration of get function for province
    private:
    string province; //province string variable
};

//Sub-Class for InternationalStudents
class ToeflScore
{
    public:
    ToeflScore(int Reading, int Listening, int Speaking, int Writing); //Declaration of class
    ToeflScore(); //Declaration of empty toeflscore class
    void set(int Reading, int Listening, int Speaking, int Writing);
    int getReading() const;   //Declaration of get function for reading int variable     
    int getListening() const; //Declaration of get function for listening int variable
    int getSpeaking() const;  //Declaration of get function for speaking int variable
    int getWriting() const;   //Declaration of get funtion for writing int variable
    int getTotal() const;
    private: 
    int reading;    //reading score int variable
    int listening;  //listening score int variable
    int speaking;   //speaking score int variable
    int writing;    //writing score int variable
    int total;
};

//Child Class of Student Class for InternationalStudents
class InternationalStudent : public Student
{
    public:
    friend ostream& operator <<(ostream& outs, const InternationalStudent& student);
    InternationalStudent(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId); //Declaration of international student class
    InternationalStudent(); //Declaration of empty international student class
    void set(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId); //Declaration set internation student function
    string getCountry() const; //Declaration get country function
    ToeflScore getToeflScore() const; //Declaration get toefl score function
    private:
    string country;          //country string variable
    ToeflScore toeflScore;   //toefl score of a toeflscore class variable
};


