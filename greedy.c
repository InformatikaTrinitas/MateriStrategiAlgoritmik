#include <stdio.h>

int jumlahPecahan = 0;
void minPecahan(int jumlah){
	int uang[10] = {100,200,500,1000,2000,5000,10000,20000,50000,100000};
	int i;

	for(i = 9;i >=0;i--){
		if(jumlah >= uang[i]){
			jumlah = jumlah-uang[i];
			jumlahPecahan = jumlahPecahan + 1;
		}
	}
}
int main(){
	int jumlah = 50000;
	minPecahan(jumlah);
	printf("%d",jumlahPecahan);
	return 0;
}
