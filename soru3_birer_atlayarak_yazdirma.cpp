/*
 * VERİ YAPILARI ÖDEVİ - SORU 3
 * Birer Atlayarak Tersinden Yazdırma
 * 
 * Bu program, tek yönlü bağlı listedeki elemanları birer atlayarak
 * tersinden yazdırma işlemini gösterir.
 * 
 * Örnek: Liste: 4 -> 8 -> 5 -> 7 -> 2 -> NULL
 * Sonuç: "2 5 4" (birer atlayarak tersinden)
 */

#include <iostream>
#include <cstdlib>
#include <stack>
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

// SORU 3: Birer atlayarak tersinden yazdırma fonksiyonu
void birerAtlamaTersYazdir(struct Node* head) {
    if (head == NULL) {
        cout << "Liste boş!" << endl;
        return;
    }
    
    // Elemanları bir stack'e ekle (ters sıra için)
    stack<int> elemanlar;
    struct Node* gecici = head;
    
    while (gecici != NULL) {
        elemanlar.push(gecici->data);
        gecici = gecici->next;
    }
    
    // Stack'ten birer atlayarak elemanları çıkar
    cout << "Birer atlayarak tersinden yazdırma: ";
    
    // İlk elemanı yazdır
    if (!elemanlar.empty()) {
        cout << elemanlar.top();
        elemanlar.pop();
    }
    
    // Birer atlayarak diğer elemanları yazdır
    while (!elemanlar.empty()) {
        elemanlar.pop();  // Bir elemanı atla
        
        if (!elemanlar.empty()) {
            cout << " " << elemanlar.top();
            elemanlar.pop();
        }
    }
    cout << endl;
}

// Ana fonksiyon
int main() {
    struct Node* head = NULL;
    
    cout << "=== BİRER ATLAYARAK TERSİNDEN YAZDIRMA DEMOSU ===" << endl << endl;
    
    // Örnek verilen liste: 4 -> 8 -> 5 -> 7 -> 2
    cout << "1. Örnek liste oluşturuluyor..." << endl;
    basaEkle(&head, 2);  // Son eleman
    basaEkle(&head, 7);
    basaEkle(&head, 5);
    basaEkle(&head, 8);
    basaEkle(&head, 4);  // İlk eleman
    
    cout << "Oluşturulan liste:" << endl;
    listeyiYazdir(head);
    
    // Birer atlayarak tersinden yazdırma
    cout << "\n2. Birer atlayarak tersinden yazdırma:" << endl;
    birerAtlamaTersYazdir(head);
    
    // Açıklama
    cout << "\n3. Açıklama:" << endl;
    cout << "   Liste: 4 -> 8 -> 5 -> 7 -> 2" << endl;
    cout << "   Ters sıra: 2 -> 7 -> 5 -> 8 -> 4" << endl;
    cout << "   Birer atlayarak: 2, 5, 4" << endl;
    
    cout << "\n=== PROGRAM TAMAMLANDI ===" << endl;
    return 0;
}
