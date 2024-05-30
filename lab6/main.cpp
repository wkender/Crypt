#include <iostream>


void powmod(int x, int y, int z){
	int num = x,pows = x, ost = 1, step = 1, counter = 0;
	while (y>0){
		std::cout <<num << "^" << step << "\t";
		std::cout << pows << "\t";
		pows %=z;
		std::cout << pows << "\t";
		if (y&1){
			std::cout << "1\t";
			ost = (ost*pows);
			if (counter == 0) std::cout << " \t";
			else std::cout << ost << "\t";
			ost %=z;
			std::cout << ost;
				
		}
		else{
			std::cout << "0\t";
			std::cout << "-\t";
			std::cout << "-";
		}
		std::cout << std::endl;
		pows *= pows;
		y>>=1;
		step *=2;
		counter++;
	}
	std::cout << std::endl << "Result is " << ost << std::endl;
}

int main(){
	int x = 5, y = 701, z = 11;
	std::cout << x << "^" << y << "mod(" << z << ")\n\n";
	powmod(x, y, z);	
}
