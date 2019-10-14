/*
 * Filename: student.cpp
 * Author: Robert Respicio & Joshua Yeh
 * Date Created: Sept 20, 2019
 * Last Updated: Oct 12, 2019
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
#include <stdio.h>
#include <string.h>

//-----------------------------------
// STUDENT CLASS IMPLEMENTATIONS
//-----------------------------------
Student::Student(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId)   //Intialize student class
{
  errorCheckStudent(Cgpa,ResearchScore);
  firstName = FirstName;  			//intialize firstname
  lastName = LastName; 				//intialize lastname
  cgpa = Cgpa; 						//intialize cgpa
  researchScore = ResearchScore;	//intialize researchscore
  studentId = StudentId;			//intialize studentID
}

//Intialize empty student class
Student::Student() : firstName("NULL"), lastName("NULL"), cgpa(0), researchScore(0), studentId(0) {/*intentionally empty*/};

//sets student members values 
void Student::set(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId) 
{
  errorCheckStudent(Cgpa,ResearchScore);
  firstName = FirstName; //set first name
  lastName = LastName; //set last name
  cgpa = Cgpa; //set cgpa
  researchScore = ResearchScore; //set researchScore
  studentId = StudentId; //set studentID
}

//set cgpa student member value
void Student::set(float Cgpa) { cgpa = Cgpa; };

//recieves first name value
string Student::getFirstName() const
{
  return firstName; //access and return firstname
}
//recieves last name value
string Student::getLastName() const
{
  return lastName; //access and return lastname
}
//recieves cgpa value
float Student::getCgpa() const
{
  return cgpa; //access and return cgpa
}
//recieves researchscore value
int Student::getResearchScore() const
{
  return researchScore; //access and return ResearchScore
}
//recieves studentID value
int Student::getStudentId() const
{
  return studentId; //access and return student ID
}

//COMPARE FUNCTIONS: Lab 2 Part 1
//These functions compare the member variables of two domestic students or two international students.
//If student1.membervariable > student2.membervariable, outputs a 1
//Output is a 0 or -1 for = and <, respectively

int compareCGPA(DomesticStudent student1, DomesticStudent student2)
{
  if(student1.getCgpa() > student2.getCgpa())
    {
      return 1;
    }
  else if(student1.getCgpa() < student2.getCgpa())
    {
      return -1;
    }
  else return 0;
}
int compareCGPA(InternationalStudent student1, InternationalStudent student2)
{
  if(student1.getCgpa() > student2.getCgpa())
    {
      return 1;
    }
  else if(student1.getCgpa() < student2.getCgpa())
    {
      return -1;
    }
  else return 0;
}
int compareResearchScore(DomesticStudent student1, DomesticStudent student2)
{
  if(student1.getResearchScore() > student2.getResearchScore())
    {
      return 1;
    }
  else if(student1.getResearchScore() < student2.getResearchScore())
    {
      return -1;
    }
  else return 0;
}
int compareResearchScore(InternationalStudent student1, InternationalStudent student2)
{
  if(student1.getResearchScore() > student2.getResearchScore())
    {
      return 1;
    }
  else if(student1.getResearchScore() < student2.getResearchScore())
    {
      return -1;
    }
  else return 0;
}
int compareLastName(DomesticStudent student1, DomesticStudent student2)
{
  if(strcmp(student1.getLastName().c_str(), student2.getLastName().c_str()) > 0)
    {
      return -1;
    }
  else if(strcmp(student1.getLastName().c_str(), student2.getLastName().c_str()) < 0)
    {
      return 1;
    }
  else return 0;
}
int compareLastName(InternationalStudent student1, InternationalStudent student2)
{
  if(strcmp(student1.getLastName().c_str(), student2.getLastName().c_str()) > 0)
    {
      return -1;
    }
  else if(strcmp(student1.getLastName().c_str(), student2.getLastName().c_str()) < 0)
    {
      return 1;
    }
  else return 0;
}
int compareFirstName(DomesticStudent student1, DomesticStudent student2)
{
  if(strcmp(student1.getFirstName().c_str(), student2.getFirstName().c_str()) > 0)
    {
      return -1;
    }
  else if(strcmp(student1.getFirstName().c_str(), student2.getFirstName().c_str()) < 0)
    {
      return 1;
    }
  else return 0;
}
int compareFirstName(InternationalStudent student1, InternationalStudent student2)
{
  if(strcmp(student1.getFirstName().c_str(), student2.getFirstName().c_str()) > 0)
    {
      return -1;
    }
  else if(strcmp(student1.getFirstName().c_str(), student2.getFirstName().c_str()) < 0)
    {
      return 1;
    }
  else return 0;
}
int compareProvince(DomesticStudent student1, DomesticStudent student2)
{
  if(strcmp(student1.getProvince().c_str(), student2.getProvince().c_str()) > 0)
    {
      return -1;
    }
  else if(strcmp(student1.getProvince().c_str(), student2.getProvince().c_str()) < 0)
    {
      return 1;
    }
  else return 0;
}
int compareCountry(InternationalStudent student1, InternationalStudent student2)
{
  if(strcmp(student1.getCountry().c_str(), student2.getCountry().c_str()) > 0)
    {
      return -1;
    }
  else if(strcmp(student1.getCountry().c_str(), student2.getCountry().c_str()) < 0)
    {
      return 1;
    }
  else return 0;
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
string DomesticStudent::getProvince() const
{
  return province; //access and return province
}

//--------------------------------------------
// TOEFLScore CLASS IMPLEMENTATIONS
//--------------------------------------------
// Intialize empty toeflscore class
ToeflScore::ToeflScore() : reading(0), listening(0), speaking(0), writing(0), total(0) {/*intentionally empty*/};
// Intialize toeflscore class
ToeflScore::ToeflScore(int Reading, int Listening, int Speaking, int Writing)
{
    reading = Reading;
    listening = Listening;
    speaking = Speaking;
    writing = Writing;
    total = Reading + Listening + Speaking + Writing;
    errorCheckTOEFL(Reading,Listening,Speaking,Writing);
}
//set 
void ToeflScore::set(int Reading, int Listening, int Speaking, int Writing)
{
    reading = Reading;      //set reading value 
    listening = Listening;	//set listening value
    speaking = Speaking;	//set speaking value
    writing = Writing;		//set writing value
    total = Reading + Listening + Speaking + Writing;
    errorCheckTOEFL(Reading,Listening,Speaking,Writing);
}
//recieves reading score value
int ToeflScore::getReading() const
{
  return reading; //access and returns reading score
}
//recieves listening score value
int ToeflScore::getListening() const
{
  return listening; //access and returns listening score
}
//recieves speaking score value
int ToeflScore::getSpeaking() const
{
  return speaking; //access and returns speaking score
}
//recieves writing score value
int ToeflScore::getWriting() const
{
  return writing; //access and returns writing scores
}
//recieves total toeflscore
int ToeflScore::getTotal() const
{
  return total;
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
string InternationalStudent::getCountry() const
{
  return country; //access and reutrns country
}
//recieves toeflscore values
ToeflScore InternationalStudent::getToeflScore() const
{
  return toeflScore; //access and returns toeflscore class
}

    //SORT FUNCTION:
    //This function sorts the array of domestic/international students based on the input from the user.
    //Sorts by CGPA if arg = 1, research score if arg = 2, first name if arg = 3, last name if arg = 4.
    //If arg = 5, it will use the overall sort defined in part 5 of lab 2.
    //Else by default, the array sorts with the overall sort.

void sortArray(DomesticStudent student[], char arg, int size)
{
  DomesticStudent temp;
  switch(arg){
    case '1':
    for (int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareCGPA(student[i],student[i+1])==-1){
          arrSwap(student,i);
       }
      }
    }  
    break; 
    case '2':
    for (int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareResearchScore(student[i],student[i+1])==-1){
          arrSwap(student,i);
        }
      }
    } 
    break;
    case '3':
    for (int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareFirstName(student[i],student[i+1])==-1){
          arrSwap(student,i);
        }
      }
    } 
    break;
    case '4':
    for (int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareLastName(student[i],student[i+1])==-1){
          arrSwap(student,i);
        }
      }
    }
    break;
    case '5':
    for(int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareResearchScore(student[i],student[i+1])==-1){
          arrSwap(student,i);
        }
        if(compareResearchScore(student[i],student[i+1])==0){
	  if(compareCGPA(student[i],student[i+1])==-1){
	    arrSwap(student,i);
          }
          if(compareCGPA(student[i],student[i+1])==0){
	    if(compareProvince(student[i],student[i+1])==-1){
	      arrSwap(student,i);
            }
          }
        }
        } 
    }
    break;
    default:
    cout << "Input not 1-5, choosing default (overall) sorting\n";
    for(int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareResearchScore(student[i],student[i+1])==-1){
          arrSwap(student,i);
        }
        if(compareResearchScore(student[i],student[i+1])==0){
	  if(compareCGPA(student[i],student[i+1])==-1){
          arrSwap(student,i);
          }
          if(compareCGPA(student[i],student[i+1])==0){
	    if(compareProvince(student[i],student[i+1])==-1){
	      arrSwap(student,i);
            }
          }
        }
      } 
    }
    break;
  }
}

    //SORT FUNCTION:
    //This function sorts the array of domestic/international students based on the input from the user.
    //Sorts by CGPA if arg = 1, research score if arg = 2, first name if arg = 3, last name if arg = 4.
    //If arg = 5, it will use the overall sort defined in part 5 of lab 2.
    //Else by default, the array sorts with the overall sort.

void sortArray(InternationalStudent student[], char arg, int size)
{ 
  InternationalStudent temp;
  int start = 0;
  switch(arg){
    case '1':
    for (int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareCGPA(student[i],student[i+1])==-1){
          arrSwap(student,i);
       }
      }
    }
    break;  
    case '2':
    for (int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareResearchScore(student[i],student[i+1])==-1){
          arrSwap(student,i);
        }
      }
    }
    break; 
    case '3':
    for (int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareFirstName(student[i],student[i+1])==-1){
          arrSwap(student,i);
        }
      }
    }
    break; 
    case '4':
    for (int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareLastName(student[i],student[i+1])==-1){
          arrSwap(student,i);
        }
      }
    }
    break;
    case '5':
    for(int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareResearchScore(student[i],student[i+1])==-1){
          arrSwap(student,i);

        }
        if(compareResearchScore(student[i],student[i+1])==0){
	  if(compareCGPA(student[i],student[i+1])==-1){
	    arrSwap(student,i);

          }
          if(compareCGPA(student[i],student[i+1])==0){
	    if(compareCountry(student[i],student[i+1])==-1){
	      arrSwap(student,i);
            }
          }
        }
        } 
    }
    break;
    default:
    cout << "Input not 1-5, choosing default (overall) sorting\n";
    for(int j=0;j<size-1;j++){
      for(int i=0;i<size-j-1;i++){
        if(compareResearchScore(student[i],student[i+1])==-1){
          arrSwap(student,i);
        }
        if(compareResearchScore(student[i],student[i+1])==0){
	  if(compareCGPA(student[i],student[i+1])==-1){
	    arrSwap(student,i);
          }
          if(compareCGPA(student[i],student[i+1])==0){
	    if(compareCountry(student[i],student[i+1])==-1){
	      arrSwap(student,i);
            }
          }
        }
      } 
    }
    break;
  }
}
//---------------------------
// PRINT FUNCTIONS
//---------------------------

    //OPERATOR OVERLOADING: Lab 2 part 2
    //Overloads the << insertion operator to print out the data and member variables of an object.
    //Allows the user to simply write 
    //std::cout << student1;
    //to print out the data members of the student1 object to the console.
    //Alternatively can use any output stream with this operator (file streams, user-defined streams, etc.)

ostream& operator <<(ostream& outs, const DomesticStudent& student){
 return outs << "Domestic student: " << student.getFirstName() << " " 
       << student.getLastName() << " from " << student.getProvince() << " province has cgpa of "
       << student.getCgpa() << ", and research score of " << student.getResearchScore() 
       << ". Assigned Student ID: " << student.getStudentId();
}

ostream& operator <<(ostream& outs, const InternationalStudent& student){
  return outs << "International student: " <<  student.getFirstName() <<  " " 
       << student.getLastName() << " from " << student.getCountry() << " has cgpa of "
       << student.getCgpa() << ", and research score of " << student.getResearchScore() 
       << ". Assigned Student ID: " << student.getStudentId() << endl
       << "Their TOEFL Scores are: reading = " << student.getToeflScore().getReading()
       << ", listening = " << student.getToeflScore().getListening() << ", speaking = "
       << student.getToeflScore().getSpeaking() << ", writing = " << student.getToeflScore().getWriting()
       << "\n" << "Total TOEFL Score = " << student.getToeflScore().getTotal();  
}

    //Function to print the data and members of every object in the student[] array.
    //Used in main() to print out the data of the sorted arrays.

void printALLDomestic(DomesticStudent student[], int size){
  for(int i=0;i<size;i++){
    cout << i+1 << ") ";
    cout << student[i] << endl;
  }
}

void printALLInternational(InternationalStudent student[], int size){
    for(int i=0;i<size;i++){
      cout << i+1 << ") ";
      cout << student[i] << endl;
 }
}

//---------------------------------------
// HELPER FUNCTIONS
//---------------------------------------

/* Function: int getRandStudentNumber 
 * -Assigns a random generated student number rather than a linear count
 * -Assume the range is from 20200000 to 20210000 
 */
int getRandStudentNumber(int ary[]){
  int temp = rand()%10000 + 20200000; //randomize number from 0 to 10000 and added to 20200000 ie. range from 20200000 to 20210000
  if (checkValidNumber(temp,ary)==true){ //if valid returns value
     return temp;
  }
  else{
    return getRandStudentNumber(ary); //if number was not valid goes through the same function (recursive)
  }
}

/* Function: bool checkValidNumber
 * Receives given number and array to find and check if the number given does not exist
 * in the given array. Onces it reaches the end, meaning that the number has not been   
 * found, it intialize that spot to the according number given.
 */
bool checkValidNumber(int num, int ary[]){
  for(int i=0;i<10000;i++){
    if (ary[i]==num){  //if number already exist in library return false (not valid number)
      return false;
    }
    if (ary[i]==-1){ //if number has not been found set the number to list and return true (valid number)
      ary[i]=num;
      return true;
    }
  }   
} 

/* Function: arrSwap(DomesticStudent student[], int start) and void arrSwap(InternationalStudent student[], int start)  
*  Recieves a student array and a int location value, to swap contents of the given location and the next appropriate
*  location with respect to the class type.
*/
void arrSwap(DomesticStudent student[], int start){
  DomesticStudent temp = student[start];
  student[start] = student[start+1]; 
  student[start+1]=temp;
}
void arrSwap(InternationalStudent student[], int start){
  InternationalStudent temp = student[start];
  student[start] = student[start+1]; 
  student[start+1]=temp;
}

//Error checking functions:
//If the values inputted into the CGPA or research score members are invalid numbers,
//prints out an error message and exits the program.
void errorCheckStudent(int cgpa, int rs){
  if(cgpa < 0 || cgpa > 4.33)//CGPA error checking if not valid, exit program 
    {
        cout << "Illegal values for CGPA inputted. Exiting program\n";
        exit(1);
    }
  if(rs < 0 || rs > 100)// Research score error checking if not valid, exit program
    {
        cout << "Illegal values for research score inputted. Exiting program\n";
        exit(1);
    }
}

//If the values inputted into the TOEFL score categories are invalid,
//prints out an error message and exits the program.
void errorCheckTOEFL(int reading, int listening, int speaking, int writing){
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
