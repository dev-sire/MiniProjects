#include<iostream>
int main(){
	int temp = 1, i = 1;
	do{
//		std::cout<<(temp%2)<<std::endl;
		temp = (temp%2) ? 1:2;
		std::cout<<temp;
		temp++;
		i++;
	}while(i!=10);
	std::cout<<" "<<temp<<std::endl;
//	std::cout<<--temp<<std::endl;
//	std::cout<<++temp<<std::endl;
//	std::cout<<temp--<<std::endl;
//	std::cout<<temp++<<std::endl;
	return 0;
}