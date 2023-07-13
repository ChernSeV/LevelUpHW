#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
	cout << "Will load 10 seconds" << endl << "Loading";
	for(int count = 0; count < 10; ++ count){
		cout << ".  ";
		fflush(stdout);
		sleep(1);
	}
	cout << endl << "Done" << endl;
	return 0;
}