// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <omp.h>
#include <string>
#include <vector>
#include <streambuf>
#define N 100
#define nthreads 10
using namespace std;
void readFile1(const string &filename)
{
	 istream *infile;

    if (filename.empty()) 
    {
      infile = &cin;
    } else 
    {
      infile = new ifstream(filename.c_str());
      //cout<<"file created "<<endl;
     }
    
    
    string line; // current line
    while (getline(*infile, line)) 
    {
    	
	}
}
void readFile2(const string &filename)
{
	istream *t;
	t=new ifstream (filename.c_str());
	string str1(std::istreambuf_iterator<char>(t),
    std::istreambuf_iterator<char>());
    cout<<str1<<"yo"<<endl;
	//str1.assign(((istreambuf_iterator<char>(t)),istreambuf_iterator<char>()));
}
string readFile3(const string &fileName)
{
    ifstream ifs(fileName.c_str(), ios::in | ios::binary | ios::ate);

    ifstream::pos_type fileSize = ifs.tellg();
    ifs.seekg(0, ios::beg);

    vector<char> bytes(fileSize);
    ifs.read(&bytes[0], fileSize);

    //cout<<bytes<<endl;
    return string(&bytes[0], fileSize);
}
int main(int argc,char * argv[])
{
	clock_t start,end;
	start=clock();
	readFile1(argv[1]);
	end=clock();

	cout<<"Reading file line by line: "<<(end - start) / (double)(CLOCKS_PER_SEC / 1000)<<endl;
	start=clock();
	readFile3(argv[1]);
	end=clock();
	cout<<"Reading entire file into a string: "<<(end - start) / (double)(CLOCKS_PER_SEC / 1000)<<endl;
    return 0;
}

