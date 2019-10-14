/*
 * Filename: main.cpp
 * Original Author: Zhenman Fang
 * Edited By: Robert Respicio & Joshua Yeh
 * Date Created: Sept 20, 2019
 * Last Updated: Oct 12, 2019
 * Description:
 * Program reads domestic-stu.txt and international-stu.txt files, then
 * asks user for what type of sorting and what type of students to be 
 * sorted, and prints off sorted list.
 */

//---------------------------
//  INCLUDES
//---------------------------
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <ctime> //time
#include "student.hpp" //include student header file

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
  int d_stu_count = 0; //student count;
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
  int i_stu_count = 0;
  int total; 
  j = 0;
  InternationalStudent I_Student[100]; //create internationalstudent class variable
  ToeflScore TOEFLScore; //create toeflscore class variable
  while(getline(internationalFile, line)){
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
    total = reading + listening + speaking + writing; 

    //TOEFL SCORE checking:
    //Checks whether the student read from the file has an adequate TOEFL score for competitive admission.
    //If not, ignores the student in the file and does not put them into the admissions system.
    //Also keeps track of the number of students in competitive admission via i_stu_count.
    if(total>=93 && reading >= 20 && listening >= 20 && speaking >= 20 && writing >= 20){
      TOEFLScore.set(reading, listening, speaking, writing); //set
      I_Student[j].set(firstName, lastName, country, cgpa, researchScore, TOEFLScore, studentNumber);
      i_stu_count++;//Increment student count
      studentNumber=getRandStudentNumber(StudentNumLibrary); //generator random student number
      j++;
    }
  }
  internationalFile.close(); // close file
  
  //USER INTERFACE:
  //The main user interface of the program is contained within the infinite while loop.
  //After the arrays have been set and initialized via the code above, the user will be prompted to input values.
  //The first value determines the parameter the sorting algorithm will sort by.
  //The second value determines which set of students the program will sort.
  //After the sorting has finished, the user may continue to sort and re-sort the arrays as they wish.

  char stuChoice, sortChoice;
  char contChoice;
  while(true)
  {
    cout << "Enter number to sort by:\n" << "[1] CGPA\n[2] Research score\n[3] First name\n[4] Last name\n[5] Overall\nEnter Number: ";
    cin >> sortChoice;
    cout << "Enter number to choose which students to sort:\n" << "[1] Domestic students\n[2] International students\nEnter Number: ";
    cin >> stuChoice;
    while(stuChoice != '1' && stuChoice != '2')
    {
      cout << "Did not input 1 or 2, please try again\n[1] Domestic students\n[2] International students\nEnter Number: ";
      cin >> stuChoice;
    }
    if(stuChoice == '1')
    {
      sortArray(D_Student, sortChoice, d_stu_count);
      printALLDomestic(D_Student, d_stu_count);
    }
    if(stuChoice == '2')
    {
      sortArray(I_Student, sortChoice, i_stu_count);
      printALLInternational(I_Student, i_stu_count);
    }
    cout << "Continue sorting? Y/N\n";
    cin >> contChoice;
    if(contChoice != 'Y' && contChoice != 'y')
    {
      break;
    }
  }
  return 0;
}
