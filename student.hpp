/*
 * Filename: student.hpp
 * Author: Robert Respicio & Joshua Yeh
 * Date Created: Sept 20, 2019
 * Last Updated: Oct 12, 2019
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
    
    //COMPARE FUNCTIONS: Lab 2 Part 1
    //These functions compare the member variables of two domestic students or two international students.
    //If student1.membervariable > student2.membervariable, outputs a 1
    //Output is a 0 or -1 for = and <, respectively
    friend int compareCGPA(DomesticStudent student1, DomesticStudent student2);
    friend int compareCGPA(InternationalStudent student1, InternationalStudent student2);
    friend int compareResearchScore(DomesticStudent student1, DomesticStudent student2);  
    friend int compareResearchScore(InternationalStudent student1, InternationalStudent student2);
    friend int compareFirstName(DomesticStudent student1, DomesticStudent student2);
    friend int compareFirstName(InternationalStudent student1, InternationalStudent student2);
    friend int compareLastName(DomesticStudent student1, DomesticStudent student2);
    friend int compareLastName(InternationalStudent student1, InternationalStudent student2);
    
    //SORT FUNCTION:
    //This function sorts the array of domestic/international students based on the input from the user.
    //Sorts by CGPA if arg = 1, research score if arg = 2, first name if arg = 3, last name if arg = 4.
    //If arg = 5, it will use the overall sort defined in part 5 of lab 2.
    //Else by default, the array sorts with the overall sort.
    friend void sortArray(DomesticStudent student[], char arg, int size);
    friend void sortArray(InternationalStudent student[], char arg, int size);

    /* Function: arrSwap(DomesticStudent student[], int start)
    *  Recieves a student array and a int location value, to swap contents of the given location and the next appropriate
    *  location with respect to the class type. This function is used in the above sort function*/
    friend void arrSwap(DomesticStudent student[], int start);
    friend void arrSwap(InternationalStudent student[], int start);

    //Function to print the data and members of every object in the student[] array.
    //Used in main() to print out the data of the sorted arrays.
    friend void printALLDomestic(DomesticStudent student[], int size);
    friend void printALLInternational(InternationalStudent student[], int size);
    
    //Class constructors:
    //Used to initialize the class at the start of the main() before the program reads from the text file.
    //NOTE: Curently not used anywhere in the program since we will never initialize a Student object;
    //we will only ever initialize its child classes i.e. DomesticStudent, InternationalStudent
    Student(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId);   
    Student(); //Initializes empty class (default constructor)

    //Set and get functions:
    //Two set functions; one to set every member of the object and another to set just the CGPA.,
    //Presumably the CGPA member is the only one that will change throughout the student's graduate degree.
    //All other members are presumably set and used upon admission only.
    //Get functions used to retrieve private members outside of the class.
    void set(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId);
    void set(float Cgpa);	
    string getFirstName() const;  //Declaration of get function to get firstname string variable
    string getLastName() const;   //Declaration of get function to get lastname string variable
    float getCgpa() const;   	//Declaration of get function to get cgpa float variable
    int getResearchScore() const; //Declaration of get function to get researchScore variable
    int getStudentId() const;     //Declaration of get function to get studentID int variable
   
    //Private member variables:
    //Consist of the student's full name and their CGPA, as well as their research score and their student ID upon admission.
    //Cannot be accessed directly outside of class member functions.
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

    //OPERATOR OVERLOADING: Lab 2 part 2
    //Overloads the << insertion operator to print out the data and member variables of an object.
    //Allows the user to simply write 
    //std::cout << student1;
    //to print out the data members of the student1 object to the console.
    //Alternatively can use any output stream with this operator (file streams, user-defined streams, etc.)
    friend ostream& operator <<(ostream& outs, const DomesticStudent& student);
    
    //Class constructors:
    //Used to initialize the class at the start of the main() before the program reads from the text file.
    DomesticStudent(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId); //Declaration of class
    DomesticStudent(); //Initializes empty class (default constructor)
   
    //Set and get functions:
    //Two set functions; one to set every member of the object and another to set just the CGPA.,
    //Presumably the CGPA member is the only one that will change throughout the student's graduate degree.
    //All other members are presumably set and used upon admission only.
    //Get functions used to retrieve private members outside of the class. 
    void set(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId);
    string getProvince() const; //Declaration of get function for province
    
    //Private member variables:
    //Consists of the Canadian province which the student came from.
    //Cannot be accessed directly outside of class member functions.
    private:
    string province; //province string variable
};

//Sub-Class for InternationalStudents
class ToeflScore
{
    public:
    
    //Class constructors:
    //Used to initialize the class at the start of the main() before the program reads from the text file.
    ToeflScore(int Reading, int Listening, int Speaking, int Writing);
    ToeflScore(); //Initializes empty class (default constructor)

    //Set and get functions:
    //Only one set function; once all these members are set, there should be no reason to change them individually.
    //Once the student takes the TOEFL exam, their scores are decided and cannot be changed unless the student
    //takes the exam again, in which case they will have to presumably rewrite the WHOLE exam.
    //Get functions used to retrieve private members outside of the class. 
    void set(int Reading, int Listening, int Speaking, int Writing);
    int getReading() const;   //Declaration of get function for reading int variable     
    int getListening() const; //Declaration of get function for listening int variable
    int getSpeaking() const;  //Declaration of get function for speaking int variable
    int getWriting() const;   //Declaration of get funtion for writing int variable
    int getTotal() const;

    //Private member variables:
    //Consist of the total TOEFL score, as well as the individual reading, listening, speaking, and writing scores.
    //Cannot be accessed directly outside of class member functions.
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
    
    //OPERATOR OVERLOADING: Lab 2 part 2
    //Overloads the << insertion operator to print out the data and member variables of an object.
    //Allows the user to simply write 
    //std::cout << student1;
    //to print out the data members of the student1 object to the console.
    //Alternatively can use any output stream with this operator (file streams, user-defined streams, etc.)
    friend ostream& operator <<(ostream& outs, const InternationalStudent& student);

    //Class constructors:
    //Used to initialize the class at the start of the main() before the program reads from the text file.
    InternationalStudent(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId); //Declaration of international student class
    InternationalStudent(); //Initializes empty class (default constructor)
    
    //Set and get functions:
    //Two set functions; one to set every member of the object and another to set just the CGPA.,
    //Presumably the CGPA member is the only one that will change throughout the student's graduate degree.
    //All other members are presumably set and used upon admission only.
    //Get functions used to retrieve private members outside of the class.
    void set(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId); //Declaration set internation student function
    string getCountry() const; //Declaration get country function
    ToeflScore getToeflScore() const; //Declaration get toefl score function
    
    //Private member variables:
    //Consist of the country which the student came from, and their TOEFL score upon application.
    //Cannot be accessed directly outside of class member functions.
    private:
    string country;          //country string variable
    ToeflScore toeflScore;   //toefl score of a toeflscore class variable
};

//-----------------------------
// HELPER FUNCTION DECLARATION
//-----------------------------

/* Function: int getRandStudentNumber 
 * -Assigns a random generated student number rather than a linear count
 * -Assume the range is from 20200000 to 20210000 
 */
int getRandStudentNumber(int ary[]);
/* Function: bool checkValidNumber
 * Receives given number and array to find and check if the number given does not exist
 * in the given array. Onces it reaches the end, meaning that the number has not been   
 * found, it intialize that spot to the according number given.
 */
bool checkValidNumber(int num, int ary[]);
void errorCheckStudent(int cgpa, int rs);
void errorCheckTOEFL(int reading, int listening, int speaking, int writing);


