/*
 * VERİ YAPILARI ÖDEVİ - SORU 1
 * Bağlı Listenin Sonuna Eleman Ekleme
 * 
 * Bu program, tek yönlü bağlı listeye eleman ekleme işlemlerini gösterir:
 * 1. Başa eleman ekleme (mevcut)
 * 2. Sona eleman ekleme (yeni eklenen)
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
    // Yeni düğüm için bellek ayırma
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    
    // Yeni düğümün verilerini ayarlama
    yeniDugum->data = yeniVeri;
    yeniDugum->next = (*head);
    
    // Baş işaretçisini yeni düğüme yönlendirme
    (*head) = yeniDugum;
}

// SORU 1: Sona eleman ekleme fonksiyonu
void sonaEkle(struct Node** head, int yeniVeri) {
    // Yeni düğüm için bellek ayırma
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    yeniDugum->data = yeniVeri;
    yeniDugum->next = NULL;  // Son düğüm olduğu için next = NULL
    
    // Eğer liste boşsa, yeni düğümü baş yap
    if (*head == NULL) {
        *head = yeniDugum;
        return;
    }
    
    // Listenin sonuna kadar git
    struct Node* gecici = *head;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }
    
    // Son düğümün next'ini yeni düğüme bağla
    gecici->next = yeniDugum;
}

// Bağlı listeyi ekrana yazdırma fonksiyonu
void listeyiYazdir(struct Node* dugum) {
    cout << "Bağlı Liste: ";
    while (dugum != NULL) {
        cout << dugum->data << " -> ";
        dugum = dugum->next;
    }
    cout << "NULL" << endl;
}

// Ana fonksiyon
int main() {
    struct Node* head = NULL;  // Baş işaretçisi
    
    cout << "=== BAĞLI LİSTE SONA ELEMAN EKLEME DEMOSU ===" << endl << endl;
    
    // Başa elemanlar ekleme
    cout << "1. Başa elemanlar ekleniyor..." << endl;
    basaEkle(&head, 10);
    basaEkle(&head, 20);
    basaEkle(&head, 30);
    listeyiYazdir(head);
    
    // Sona elemanlar ekleme
    cout << "\n2. Sona elemanlar ekleniyor..." << endl;
    sonaEkle(&head, 40);
    sonaEkle(&head, 50);
    sonaEkle(&head, 60);
    listeyiYazdir(head);
    
    cout << "\n=== PROGRAM TAMAMLANDI ===" << endl;
    return 0;
}
