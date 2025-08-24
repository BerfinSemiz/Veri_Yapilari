/*
 * VERİ YAPILARI ÖDEVİ - SORU 4
 * Eleman Sayısını Bulma (İteratif ve Rekürsif)
 * 
 * Bu program, tek yönlü bağlı listedeki eleman sayısını
 * iki farklı yöntemle bulmayı gösterir:
 * 1. İteratif yöntem (döngü kullanarak)
 * 2. Rekürsif yöntem (kendini çağırarak)
 */

#include <iostream>
#include <cstdlib>
using namespace std;

// Bağlı liste düğüm yapısı
struct Node {
    int data;           // Düğümde saklanan veri
    struct Node* next;  // Sonraki düğüme işaretçi
};

// Başa eleman ekleme fonksiyonu (mevcut)
void basaEkle(struct Node** head, int yeniVeri) {
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    yeniDugum->data = yeniVeri;
    yeniDugum->next = (*head);
    (*head) = yeniDugum;
}

// Normal yazdırma fonksiyonu
void listeyiYazdir(struct Node* dugum) {
    cout << "Bağlı Liste: ";
    while (dugum != NULL) {
        cout << dugum->data << " -> ";
        dugum = dugum->next;
    }
    cout << "NULL" << endl;
}

// SORU 4a: İteratif yöntemle eleman sayısını bulma
int elemanSayisiIteratif(struct Node* head) {
    int sayac = 0;
    struct Node* gecici = head;
    
    // Listeyi baştan sona dolaşarak elemanları say
    while (gecici != NULL) {
        sayac++;
        gecici = gecici->next;
    }
    
    return sayac;
}

// SORU 4b: Rekürsif yöntemle eleman sayısını bulma
int elemanSayisiRekursif(struct Node* head) {
    // Temel durum: liste boşsa 0 döndür
    if (head == NULL) {
        return 0;
    }
    
    // Rekürsif durum: 1 + kalan listenin eleman sayısı
    return 1 + elemanSayisiRekursif(head->next);
}

// Ana fonksiyon
int main() {
    struct Node* head = NULL;
    
    cout << "=== ELEMAN SAYISINI BULMA DEMOSU ===" << endl << endl;
    
    // Test listesi oluşturma
    cout << "1. Test listesi oluşturuluyor..." << endl;
    basaEkle(&head, 10);
    basaEkle(&head, 20);
    basaEkle(&head, 30);
    basaEkle(&head, 40);
    basaEkle(&head, 50);
    
    cout << "Oluşturulan liste:" << endl;
    listeyiYazdir(head);
    
    // İteratif yöntemle eleman sayısını bulma
    cout << "\n2. İteratif yöntemle eleman sayısı:" << endl;
    int iteratifSonuc = elemanSayisiIteratif(head);
    cout << "   Eleman sayısı: " << iteratifSonuc << endl;
    
    // Rekürsif yöntemle eleman sayısını bulma
    cout << "\n3. Rekürsif yöntemle eleman sayısı:" << endl;
    int rekursifSonuc = elemanSayisiRekursif(head);
    cout << "   Eleman sayısı: " << rekursifSonuc << endl;
    
    // Sonuçları karşılaştırma
    cout << "\n4. Sonuç karşılaştırması:" << endl;
    if (iteratifSonuc == rekursifSonuc) {
        cout << "   ✓ Her iki yöntem de aynı sonucu verdi!" << endl;
    } else {
        cout << "   ✗ Sonuçlar farklı!" << endl;
    }
    
    // Boş liste testi
    cout << "\n5. Boş liste testi:" << endl;
    struct Node* bosListe = NULL;
    cout << "   İteratif: " << elemanSayisiIteratif(bosListe) << endl;
    cout << "   Rekürsif: " << elemanSayisiRekursif(bosListe) << endl;
    
    // Tek eleman testi
    cout << "\n6. Tek eleman testi:" << endl;
    basaEkle(&bosListe, 100);
    cout << "   Liste: ";
    listeyiYazdir(bosListe);
    cout << "   İteratif: " << elemanSayisiIteratif(bosListe) << endl;
    cout << "   Rekürsif: " << elemanSayisiRekursif(bosListe) << endl;
    
    cout << "\n=== PROGRAM TAMAMLANDI ===" << endl;
    return 0;
}
