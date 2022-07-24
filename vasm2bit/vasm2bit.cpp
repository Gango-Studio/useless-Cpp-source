#include<iostream>
#include<stdlib.h> 
#include<string>
#define MAXN 1050
using namespace std;
bool ram[16] = {0};
int top = 1;
bool OverFlow = false; 
void oand(){
	ram[top+1] = ram[top-1] && ram[top];
	return;
}
void oor(){
	ram[top+1] = ram[top-1] || ram[top];
	return;
}
void nor(){
	ram[top+1] = ram[top-1] || ram[top];
	ram[top+1] = !ram[top+1];
	return;
}
void nand(){
	ram[top+1] = ram[top-1] && ram[top];
	ram[top+1] = !ram[top+1];
	return;
}
void vasm(const string op){
	if (top < 15 && OverFlow == false){
		if (op == "NAND"){
			nand();
			top++;
			return;
		}
		if (op == "AND"){
			oand();
			top++;
			return;
		}
		if (op == "OR"){
			oor();
			top++;
			return;
		}
		if (op == "XOR"){
			nor();
			top++;
			return;
		}
	}
	else{
		OverFlow = true;
	}
	return;
}
void print(){
	if(OverFlow){
		cout <<"Err." <<"\n";
	}else{
		for(int i = 0; i <= 15;i++){
			cout << ram[i]<< " ";
		}
	}
}
int main(){
	vasm("NAND"); 
	vasm("AND");
	vasm("XOR");
	print();
	return 0;
}
