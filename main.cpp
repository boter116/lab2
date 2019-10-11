/*
 * Filename: main.cpp
 * Original Author: Zhenman Fang
 * Edited By: Robert Respicio & Joshua Yeh
 * Date Created: Sept 20, 2019
 * Last Updated: Sept 25, 2019
 *
 * Description:
 * Main file, containing driver code. Program reads domestic-stu.txt and 
 * international-stu.txt files, then declares and creates the appropriate
 * class for given data and prints off the data according to Domestic Students
 * and International Students.
 * 
 */

//---------------------------
//  INCLUDES
//---------------------------
//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <ctime> //time
#include "student.hpp" //include student header file

//----------------------------------------------------------------------------- 
//  HELPER FUNCTIONS (Mainly used for random number generator and checker)
//-----------------------------------------------------------------------------
int getRandStudentNumber(int ary[]); 
bool checkValidNumber(int num, int ary[]);

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

//--------------
// MAIN 
//--------------
int main(){
  //Read the domestic-stu.txt file and exit if failed
  srand(time(NULL));// random seed generator
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line);
  cout << "File format: " << line << endl;
  int StudentNumLibrary[10000]; //create empty array of all zeros. Size 10000, assuming less than 100000 students
  fill_n(StudentNumLibrary,10000,-1); //Initalize and fill the array with a constant number (-1) besides 0 because its in the range of the random num. generator
  int d_stu_count = 1; //student count;
  int j = 0;
  int studentNumber = getRandStudentNumber(StudentNumLibrary); //generates a random student number in the appropriate range
 
 DomesticStudent D_Student[100];
  //Keep reading the rest of the lines in domestic-stu.txt
  while( getline(domesticFile, line) ) {
    /*process each line, get each field separated by a comma.
     *We use istringstream to handle it.
     */
    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    //get firstName separated by comma
    getline(ss, firstName, ',');
    //get lastName separated by comma
    getline(ss, lastName, ',');
    //get province separated by comma
    getline(ss, province, ',');
    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    D_Student[j].set(firstName, lastName, province, cgpa, researchScore, studentNumber);



    //print the student info to the screen
    //cout << "Domestic student " << stu_count << " " << D_Student[j].getFirstName() << " " 
    // << D_Student[j].getLastName() << " from " << D_Student[j].getProvince() << " province has cgpa of "
    //	 << D_Student[j].getCgpa() << ", and research score of " << D_Student[j].getResearchScore() 
    //   << ". Assigned Student ID: " << D_Student[j].getStudentId() << endl;
  
    d_stu_count++; //increment student count
    studentNumber=getRandStudentNumber(StudentNumLibrary); //generate randome student number
    j++;
  }
  //close your file
  domesticFile.close();
  //read internation file and exit if failed
  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open())
  {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }
  




  getline(internationalFile, line);
  cout << "File format: " << line << endl;
  
  int i_stu_count = 1; //intialize student count back to 1 for international student 
  j = 0;
  InternationalStudent I_Student[100]; //create internationalstudent class variable
  ToeflScore TOEFLScore; //create toeflscore class variable

  while(getline(internationalFile, line))
  {
    istringstream ss(line);

    string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
    float cgpa;
    int researchScore, reading, listening, speaking, writing;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, country, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    
    //get reading score seperated by comma, and convert to int 
    getline(ss, s_reading, ',');
    reading = atoi(s_reading.c_str());
    
    //get listening score seperated by comma, and convert to int
    getline(ss, s_listening, ',');
    listening = atoi(s_listening.c_str());

    //get speaking score seperated by comma, and convert to int
    getline(ss, s_speaking, ',');
    speaking = atoi(s_speaking.c_str());

    //get writing score seperated by comma, and convert to int
    getline(ss, s_writing, ',');
    writing = atoi(s_writing.c_str());

    //set 
    TOEFLScore.set(reading, listening, speaking, writing);
    I_Student[j].set(firstName, lastName, country, cgpa, researchScore, TOEFLScore, studentNumber);

    i_stu_count++;//Increment student count
    studentNumber=getRandStudentNumber(StudentNumLibrary); //generator random student number
    j++;
  }
  internationalFile.close(); // close file

  //Case function  for user input/interface
  cout << compareCGPA(D_Student[0],D_Student[1]) << endl;
  sortGPA(D_Student,d_stu_count);  cout << compareCGPA(D_Student[0],D_Student[1])<< endl;
  //cout << I_Student[0] << endl;
  //cout << D_Student[0] << endl;
  //cout << "hi" << endl;
  return 0;
}
