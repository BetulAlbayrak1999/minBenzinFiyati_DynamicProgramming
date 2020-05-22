/*
 Proje odevi: dynamic programming
*/

#include <stdio.h>
#include <stdlib.h>

#define k 50//arac en az k km kadar gider
#define f 100//arac bir depo benzin ile max f km kadar gidebiliyor
#define yol 200//menzile olan toplam yol
struct benzin{
	int m; //artan uzaklikta benzin istasyonu
	int p; //benzin istasyondaki bir depo benzinin ucrteti
}istasyon[5];
int istasyonSayisi = 5;
int i = 0, j =0;
int solution(struct benzin arr[], int n){
	int globalFiyat = 0, girdi = 0;
	int benzinAlindi = 0, localFiyat = 0;
	if(n < 0)
		return 0;
	for(int i = 0; i < n; i++){
		if(benzinAlindi + f > istasyon[i].m && benzinAlindi + k < istasyon[i].m){
			localFiyat = istasyon[i].p ;
			j = i+1;
			while(j < n && benzinAlindi + f > istasyon[j].m){
				if(istasyon[j].p  > localFiyat)
					benzinAlindi = arr[i].m;
				else{
					benzinAlindi = arr[j].m;
					localFiyat = istasyon[j].p;
				}
				girdi = 1;
			}
			if(girdi == 0){
				benzinAlindi = arr[i].m;
			}
			globalFiyat = globalFiyat + localFiyat;
		}
		else{
			i++;
		}

	}
	return globalFiyat;

}

int main(void) {
    //degerleri belirleme
	istasyon[0].m = 0;
	istasyon[0].p = 3;
    istasyon[1].m = 30;
   	istasyon[1].p = 5;
    istasyon[2].m = 70;
   	istasyon[2].p = 4;
    istasyon[3].m = 130;
    istasyon[3].p = 3;
    istasyon[4].m = 180;
   	istasyon[4].p = 6;

   	solution(istasyon, istasyonSayisi);

   	printf("gereken en az benzin ucreti: %d", solution(istasyon, istasyonSayisi));

   	return 0;
}
