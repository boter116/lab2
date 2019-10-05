/*
 * Filename: student.cpp
 * Author: Robert Respicio & Joshua Yeh
 * Date Created: Sept 20, 2019
 * Last Updated: Sept 25, 2019
 *
 * Description:
 * C process file to implement all classes and its declared member functions.
 *
 */
 
//--------------------------------------------------------- 
//INCLUDES 
//--------------------------------------------------------- 
#include "student.hpp"
#include <iostream>
#include <cstdlib>

//-----------------------------------
// STUDENT CLASS IMPLEMENTATIONS
//-----------------------------------
Student::Student(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId)   //Intialize student class
{
  if(Cgpa < 0 || Cgpa > 4.33)//CGPA error checking if not valid, exit program 
    {
        cout << "Illegal values for CGPA inputted. Exiting program\n";
        exit(1);
    }
  if(ResearchScore < 0 || ResearchScore > 100)// Research score error checking if not valid, exit program
    {
        cout << "Illegal values for research score inputted. Exiting program\n";
        exit(1);
    }
  firstName = FirstName;  			//intialize firstname
  lastName = LastName; 				//intialize lastname
  cgpa = Cgpa; 						//intialize cgpa
  researchScore = ResearchScore;	//intialize researchscore
  studentId = StudentId;			//intialize studentID
}
//Intialize empty student class
Student::Student() : firstName("NULL"), lastName("NULL"), cgpa(0), researchScore(0), studentId(0) {/*intentionally empty*/}; //Intialize *empty* student class

//sets student members values 
void Student::set(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId) 
{
  if(Cgpa < 0 || Cgpa > 4.33)//CGPA error checking if not valid, exit program 
    {
        cout << "Illegal values for CGPA inputted. Exiting program\n";
        exit(1);
    }
    if(ResearchScore < 0 || ResearchScore > 100)// Research score error checking if not valid, exit program
    {
        cout << "Illegal values for research score inputted. Exiting program\n";
        exit(1);
    }
    firstName = FirstName; //set first name
    lastName = LastName; //set last name
    cgpa = Cgpa; //set cgpa
    researchScore = ResearchScore; //set researchScore
    studentId = StudentId; //set studentID
}
//set cgpa student member value
void Student::set(float Cgpa) { cgpa = Cgpa; };

//recieves first name value
string Student::getFirstName()
{
  return firstName; //access and return firstname
}
//recieves last name value
string Student::getLastName()
{
  return lastName; //access and return lastname
}
//recieves cgpa value
float Student::getCgpa() 
{
  return cgpa; //access and return cgpa
}
//recieves researchscore value
int Student::getResearchScore()
{
  return researchScore; //access and return ResearchScore
}
//recieves studentID value
int Student::getStudentId()
{
  return studentId; //access and return student ID
}
//--------------------------------------------
// DOMESTIC STUDENT CLASS IMPLEMENTATIONS
//--------------------------------------------
//Intialize domestic student class
DomesticStudent::DomesticStudent(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId)
: Student(FirstName, LastName, Cgpa, ResearchScore, StudentId)
{
    province = Province; //intialize province
};
//Intialize empty domestic student class
DomesticStudent::DomesticStudent() : Student(), province("NULL") { /*intentionally empty*/ };
//sets domestic student members values and student parent class members
void DomesticStudent::set(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId)
{
  Student::set(FirstName, LastName, Cgpa, ResearchScore, StudentId); //uses student set function to set student class memebers
  province = Province; //set province
}
//recieves province value 
string DomesticStudent::getProvince()
{
  return province; //access and return province
}

//--------------------------------------------
// TOEFLScore CLASS IMPLEMENTATIONS
//--------------------------------------------
// Intialize empty toeflscore class
ToeflScore::ToeflScore() : reading(0), listening(0), speaking(0), writing(0) {/*intentionally empty*/};
// Intialize toeflscore class
ToeflScore::ToeflScore(int Reading, int Listening, int Speaking, int Writing)
{
    reading = Reading;
    listening = Listening;
    speaking = Speaking;
    writing = Writing;
    if (Reading < 0 || Reading > 30)  //error checking for reading score
    {
        cout << "Illegal values for TOEFL Reading score inputted. Exiting program\n";
        exit(1);
    }
    if (Listening < 0 || Listening > 30) //error checking listening score
    {
        cout << "Illegal values for TOEFL Listening score inputted. Exiting program\n";
        exit(1);
    }
    if (Speaking < 0 || Speaking > 30) //error checking for speaking score
    {
        cout << "Illegal values for TOEFL Speaking score inputted. Exiting program\n";
        exit(1);
    }
    if (Writing < 0 || Writing > 30) //error checking for writing score
    {
        cout << "Illegal values for TOEFL Writing score inputted. Exiting program\n";
        exit(1);
    }
}
//set 
void ToeflScore::set(int Reading, int Listening, int Speaking, int Writing)
{
    reading = Reading;      //set reading value 
    listening = Listening;	//set listening value
    speaking = Speaking;	//set speaking value
    writing = Writing;		//set writing value
    if (reading < 0 || reading > 30)//error checking
    {
        cout << "Illegal values for TOEFL Reading score inputted. Exiting program\n";
        exit(1);
    }
    if (listening < 0 || listening > 30)//error checking
    {
        cout << "Illegal values for TOEFL Listening score inputted. Exiting program\n";
        exit(1);
    }
    if (speaking < 0 || speaking > 30)//error checking
    {
        cout << "Illegal values for TOEFL Speaking score inputted. Exiting program\n";
        exit(1);
    }
    if (writing < 0 || writing > 30)//error checking
    {
        cout << "Illegal values for TOEFL Writing score inputted. Exiting program\n";
        exit(1);
    }
}
//recieves reading score value
int ToeflScore::getReading()
{
  return reading; //access and returns reading score
}
//recieves listening score value
int ToeflScore::getListening()
{
  return listening; //access and returns listening score
}
//recieves speaking score value
int ToeflScore::getSpeaking()
{
  return speaking; //access and returns speaking score
}
//recieves writing score value
int ToeflScore::getWriting()
{
  return writing; //access and returns writing scores
}
//recieves total toeflscore
int ToeflScore::addScores()
{
  return reading + listening + speaking + writing; //accessand and returns the calculated sum of all s scor
}
//--------------------------------------------
// INTERNATIONAL STUDENT CLASS IMPLEMENTATIONS
//--------------------------------------------
//Intialize internation student class
InternationalStudent::InternationalStudent(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId)
: Student(FirstName, LastName, Cgpa, ResearchScore, StudentId)
{
    country = Country;
}
//Intialize empty internation student class
InternationalStudent::InternationalStudent() : Student(), country("NULL")
{
    toeflScore.set(0, 0, 0, 0);
}
//sets toeflscore and country value for international student class as well as student parent members
void InternationalStudent::set(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId)
{
    Student::set(FirstName, LastName, Cgpa, ResearchScore, StudentId);
    toeflScore.set(TOEFLScore.getReading(), TOEFLScore.getListening(), TOEFLScore.getSpeaking(), TOEFLScore.getWriting());
    country = Country;
}
//recieves country data
string InternationalStudent::getCountry()
{
  return country; //access and reutrns country
}
//recieves toeflscore values
ToeflScore InternationalStudent::getToeflScore()
{
  return toeflScore; //access and returns toeflscore class
}







