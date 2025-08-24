/*
 * VERİ YAPILARI ÖDEVİ - SORU 2
 * Bağlı Listenin Sonundaki Elemanı Silme
 * 
 * Bu program, tek yönlü bağlı listeden eleman silme işlemlerini gösterir:
 * 1. Başa eleman ekleme (mevcut)
 * 2. Sondan eleman silme (yeni eklenen)
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

// SORU 2: Sondan eleman silme fonksiyonu
void sondanSil(struct Node** head) {
    // Eğer liste boşsa, hiçbir şey yapma
    if (*head == NULL) {
        cout << "Liste zaten boş!" << endl;
        return;
    }
    
    // Eğer sadece bir eleman varsa, onu sil
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        cout << "Son eleman silindi. Liste artık boş." << endl;
        return;
    }
    
    // Listenin sondan bir önceki elemanını bul
    struct Node* gecici = *head;
    while (gecici->next->next != NULL) {
        gecici = gecici->next;
    }
    
    // Son elemanı sil ve sondan bir önceki elemanın next'ini NULL yap
    free(gecici->next);
    gecici->next = NULL;
    cout << "Son eleman başarıyla silindi." << endl;
}

// Bağlı listeyi ekrana yazdırma fonksiyonu
void listeyiYazdir(struct Node* dugum) {
    if (dugum == NULL) {
        cout << "Liste boş!" << endl;
        return;
    }
    
    cout << "Bağlı Liste: ";
    while (dugum != NULL) {
        cout << dugum->data << " -> ";
        dugum = dugum->next;
    }
    cout << "NULL" << endl;
}

// Ana fonksiyon
int main() {
    struct Node* head = NULL;
    
    cout << "=== BAĞLI LİSTE SONDAN ELEMAN SİLME DEMOSU ===" << endl << endl;
    
    // Başlangıç listesi oluşturma
    cout << "1. Başlangıç listesi oluşturuluyor..." << endl;
    basaEkle(&head, 5);
    basaEkle(&head, 4);
    basaEkle(&head, 3);
    basaEkle(&head, 2);
    basaEkle(&head, 1);
    listeyiYazdir(head);
    
    // Sondan eleman silme işlemleri
    cout << "\n2. Sondan eleman silme işlemleri:" << endl;
    
    cout << "\n   İlk silme işlemi:" << endl;
    sondanSil(&head);
    listeyiYazdir(head);
    
    cout << "\n   İkinci silme işlemi:" << endl;
    sondanSil(&head);
    listeyiYazdir(head);
    
    cout << "\n   Üçüncü silme işlemi:" << endl;
    sondanSil(&head);
    listeyiYazdir(head);
    
    cout << "\n   Dördüncü silme işlemi:" << endl;
    sondanSil(&head);
    listeyiYazdir(head);
    
    cout << "\n   Son elemanı silme:" << endl;
    sondanSil(&head);
    listeyiYazdir(head);
    
    cout << "\n=== PROGRAM TAMAMLANDI ===" << endl;
    return 0;
}
