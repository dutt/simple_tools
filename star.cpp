#include <iostream>
using namespace std;

 void print_options() {
 	cout <<"Welcome to simple tar" <<endl;
 	cout <<"Usage:" <<endl;
 	cout <<"\tstar pack FILE|DIR [ARCHIVE] - pack file, default archive is the same name as file + .tar" <<endl;
 	cout <<"\tstar compress FILE|DIR [ARCHIVE] - compress file, same as pack but runs it through gzip as well" <<endl;
 	cout <<"\tstar unpack FILE|DIR- unpack file" <<endl;
 }

int main(int argc, char** argv) {
	if(argc < 2) {
		print_options();
	}
	string op = argv[1];
	if(op == "pack") {
		string file = argv[2];
		string target = "";
		if(argc > 3) //archive specified
			target = argv[3];
		else
			target = file + ".tar";
		cout <<"packing " <<file <<" as " <<target <<endl;
	} else if(op == "compress") {
		string file = argv[2];
		string target = "";
		if(argc > 3) //archive specified
			target = argv[3];
		else
			target = file + ".tar";
		cout <<"compressing " <<file <<" as " <<target <<endl;
	} else if(op == "unpack") {
		string file = argv[2];
		cout <<"unpacking " <<file <<endl;
	}
	else
		cout <<"Unknown operation: " <<op <<endl;
}