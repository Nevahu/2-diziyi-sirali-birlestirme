#include <stdio.h>
#include <stdlib.h>

int *dizi_birlestir(int[], int, int[], int );

int main()
{
    int liste_1[8]= {1, 3, 5, 7, 9, 11, 13, 15};

    int liste_2[8]= {2, 4, 6, 8, 10, 12, 14, 16};
    //sonucun dondurulmesi icin pointer tanimliyoruz
    int *son;
    son = dizi_birlestir(liste_1, 8, liste_2, 8);

    // son aslinda bir pointer lakin asagýda liste gibi davranicak.

    printf(" iki liste birlesimi:\n{ ");
    for(int i = 0; i<16; i++)
    printf("%d ", son[i]);

    printf("}");

    return;

}

int *dizi_birlestir(int dizi1[], int dizi1_boyut, int dizi2[], int dizi2_boyut)
{
    int *sonuc = (int*)calloc(dizi1_boyut + dizi2_boyut, sizeof(int)); // iki listenin toplami buyuklugunde bir alana ihtiyacimiz var. Bunu da calloc fonk ile hallediyoruz.
    // Ve bu alaný gosteren pointer'a sonuc adini verdim. Asagida liste gibi davranacaktir.

    int i,k;

    for(i=0; i<dizi1_boyut + dizi2_boyut ; i++)//Ilk listeyi sonuca yerlestiriyor.
    {
        if(dizi1[i] < dizi2[i])
        {
            printf("donguye girdi\n");
            sonuc[i] = dizi1[i];
            sonuc[i+1] = dizi2[i];
        }
        else
        {
            sonuc[i] = dizi2[i];
            sonuc[i+1] = dizi1[i];
        }
    }

    return sonuc; // bana fonksiyonu yazmam istenirse sonucu dondurecek


}
