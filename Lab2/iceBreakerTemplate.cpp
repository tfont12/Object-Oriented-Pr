#include<iostream>
#include<fstream>

/**
 * TO DO: 
 * Add <vector>, <cstdlib>, and <ctime>​
 */
#include<vector>
#include<ctime>
#include<cstdlib>
#include<random>

using namespace std;

/**
 * TO DO: 
 * Create function prototypes for all the functions.
 * Write their function declarations below mai()).
 * 
 * See promptFile(...) and printVec(...), which serve as examples.
 * 
 */


//------------------------PROTOTYPE-------------------------------------------
void promptFile(vector<string> &);
void printVec(vector<string>);
int ranGen();
bool readFile(string filename, vector<string> & vec);
bool writeFile(string filename, const vector<string> & v0, const vector<string> & v1);

/**
 * @brief randomly returns a number from 0 to 5.
 * - It is hardcoded to be from 0 to 5.
 * - Uses srand(nullptr) in main()
 * TO DO:
 * Modify it so that randGen() reads in 
 * the size of the questions instead of 6 (e.g. questions.size())
 * 
 * TO DO:
 * Use <random> for modern C++ random generation instead 
 * 
 * @return int: index of question
 */
int ranGen(size_t numQuestions){
    // error catch
    if (numQuestions == 0) return 0;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, numQuestions - 1);

    int randomNumber = dist(mt);  // 0 through 5
    return randomNumber;
}

/**
 * @brief reads contents of filename and populates into vec
 * 
 * @param filename :string 
 * @param vec: vector<string> &
 * 
 * TO DO: 
 * ​​​Return a bool instead in order to indicate whether the operation
 * succeeded or not
 */
bool readFile(string filename, vector<string> & vec) {

   ifstream inputFile(filename);

    //error handling
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file\n";
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
    return true;
}
/**
 * @brief writes to filename with the first column from v0, second column from v1
 * 
 * @param filename: string
 * @param v0: vector<string> (for students names)
 * @param v1: vector<string> (for questions)
 * 
 * TO DO: 
 * ​​​Return a bool instead in order to indicate whether the operation
 * succeeded or not
 * 
 * TO DO:
 * ​​Use pass by const reference (const vector<string> & v0, const vector<string> & v1)
 * as opposed to pass by value (vector<string> v0, vector<string> v1). 
 * 
 * What is the differennce between:
 * -  pass by reference (e.g. vector<string> & v0),
 * -  pass by value (e.g. vector<string> v0),
 * -  pass by const reference (e.g. const vector<string> & v0),
 */
bool writeFile(string filename, const vector<string> & v0, const vector<string> & v1){
    // catch empty file error
    if (v1.empty() || v0.empty()) {
        cerr << "v1 or v0 not loaded yet";
        return false;
    }


    ofstream outputFile(filename);
     if (!outputFile) {
        cout << "Error: Could not create data.csv" << endl;
        return false;
    }

    // write under the structure:
    // Student_Name, Question_#
    for(int i = 0; i < v0.size(); i++){
        outputFile << v0[i] << "," << v1[ranGen(v1.size())] << endl;
    }
    outputFile.close();

    return true;

}


int main()
{
    srand(time(nullptr));
    vector<string> roster;
    vector<string> qBank;
    readFile("2310_F26_Rosters.csv", roster);
    readFile("Questions.csv", qBank);
    // printVec(roster);
    // printVec(qBank);

    // cout << "Size of roster: " << roster.size() << endl; 
    // cout << "Size of qBank: " << qBank.size() << endl;

    writeFile("Student_question_bank.csv",roster, qBank);

}

//------------------------DECLARATIONS-------------------------------------------
/**
 * @brief prompts the user to give a file to read
 * 
 */
void promptFile(vector<string> & v){
    cout << "file to read?\n";
    string myFile = "";
    cin >> myFile;
    readFile(myFile, v);
}


/**
 * @brief prints out the elements in v
 * 
 * @param v: vector<string>
 */
void printVec(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}