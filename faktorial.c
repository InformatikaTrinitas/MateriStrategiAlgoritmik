#include <stdio.h>

int factorial(int angka){
	
	if(angka == 1 || angka == 0){
		return 1; //Keluar dari proses factorial
	}else{
		return angka * factorial(angka-1);
	}
	
	
}

int main(){
	//Penerapan Algoritma rekursif pada kasus factorial
	//Fungsi Rekursif adalah fungsi yang memanggil dirinya sendiri
	//Operasi faktorial hanya bisa dilakukan pada bilangan positif (0,1,2,3...)
	//Misal 5 faktorial. 5 x 4 x 3 x 2 x 1
	printf("%d",factorial(5));
	return 0;
		
}
