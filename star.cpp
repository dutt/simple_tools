#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


void print_options() {
 	cout <<"Welcome to simple tar" <<endl;
 	cout <<"Usage:" <<endl;
 	cout <<"\tstar pack FILE|DIR [ARCHIVE] - pack file, default archive is the same name as file + .tar" <<endl;
 	cout <<"\tstar compress FILE|DIR [ARCHIVE] - compress file, same as pack but runs it through gzip as well" <<endl;
 	cout <<"\tstar unpack FILE|DIR- unpack file" <<endl;
 }

string run_cmd_oneline(const char* cmd) {
	FILE* fp = popen(cmd, "r");
	if(fp == NULL)
		return "";
	string retr = "";
	char buff[255];
	while(fgets(buff, 255, fp) != NULL) {
		for(int i = 0; i < 255; ++i)
			if(buff[i] == 0)
				break;
			else if(buff[i] == '\n')
				buff[i] = 0;
		retr += buff;
	}
	pclose(fp);
	return retr;
}
string run_cmd_multiline(const char* cmd) {
	FILE* fp = popen(cmd, "r");
	if(fp == NULL)
		return "";
	string retr = "";
	char buff[255];
	while(fgets(buff, 255, fp) != NULL) {
		retr += buff;
	}
	pclose(fp);
	return retr;
}

void pack(string& tarpath, string& file, string& target) {
	string cmd = tarpath + " czf " + target + " " +  file + " 2>&1";
	cout <<"running \"" <<cmd <<"\"" <<endl;
	string res = run_cmd_multiline(cmd.c_str());
}
void compress(string& tarpath, string& file, string& target) {
	string cmd = tarpath + " czf " + target + " " +  file + " 2>&1";
	cout <<"running \"" <<cmd <<"\"" <<endl;
	string res = run_cmd_multiline(cmd.c_str());
}
void unpack(string& tarpath, string& file) {
	string cmd = tarpath + " xzf " +  file + " 2>&1";
	cout <<"running \"" <<cmd <<"\"" <<endl;
	string res = run_cmd_multiline(cmd.c_str());
}

int main(int argc, char** argv) {
	if(argc < 2) {
		print_options();
		return -1;
	}
	string op = argv[1];
	string tarpath = run_cmd_oneline("which tar");
	if(tarpath == "") {
		cout <<"tar not found" <<endl;
		return -1;
	}
	if(op == "pack") {
		string file = argv[2];
		string target = "";
		if(argc > 3) //archive specified
			target = argv[3];
		else
			target = file + ".tar";
	
		pack(tarpath, file, target);
	} else if(op == "compress") {
		string file = argv[2];
		string target = "";
		if(argc > 3) //archive specified
			target = argv[3];
		else
			target = file + ".tar.gz";
		compress(tarpath, file, target);
	} else if(op == "unpack") {
		string file = argv[2];
		unpack(tarpath, file);
	}
	else {
		cout <<"Unknown operation: " <<op <<endl;
		return -1;
	}
	return 0;
}
