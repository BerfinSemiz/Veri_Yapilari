/*
 * VERİ YAPILARI ÖDEVİ - SORU 5
 * Çift Yönlü Bağlı Listedeki Tekrarlayan Elemanları Silme
 * 
 * Bu program, çift yönlü bağlı listedeki tekrarlayan elemanları
 * hem sıralanmamış hem de sıralanmış liste için silme işlemini gösterir.
 * 
 * Örnek: { 1, 2, 4, 5, 2, 3, 5, 6, 1, 4, 5, 6, 6, 7, 4, 5 }
 * Sonuç: { 1, 2, 4, 5, 3, 6, 7 }
 */

#include <iostream>
#include <cstdlib>
#include <unordered_set>
using namespace std;

// Çift yönlü bağlı liste düğüm yapısı
struct Node {
    int data;           // Düğümde saklanan veri
    struct Node* next;  // Sonraki düğüme işaretçi
    struct Node* prev;  // Önceki düğüme işaretçi
};

// Başa eleman ekleme fonksiyonu
void basaEkle(struct Node** head, int yeniVeri) {
    // Yeni düğüm için bellek ayırma
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    yeniDugum->data = yeniVeri;
    yeniDugum->next = (*head);
    yeniDugum->prev = NULL;
    
    // Eğer liste boş değilse, mevcut baş'ın prev'ini yeni düğüme bağla
    if (*head != NULL) {
        (*head)->prev = yeniDugum;
    }
    
    // Baş işaretçisini yeni düğüme yönlendir
    (*head) = yeniDugum;
}

// SORU 5: Tekrarlayan elemanları silme fonksiyonu
void tekrarlayanSil(struct Node*& head) {
    if (head == NULL) {
        cout << "Liste boş!" << endl;
        return;
    }
    
    // Tekrarlayan elemanları takip etmek için hash set kullan
    unordered_set<int> gorulenElemanlar;
    struct Node* gecici = head;
    
    cout << "Tekrarlayan elemanlar siliniyor..." << endl;
    
    while (gecici != NULL) {
        // Eğer bu eleman daha önce görülmüşse, sil
        if (gorulenElemanlar.find(gecici->data) != gorulenElemanlar.end()) {
            cout << "   " << gecici->data << " tekrarlayan eleman olarak siliniyor." << endl;
            
            // Önceki düğümün next'ini güncelle
            if (gecici->prev != NULL) {
                gecici->prev->next = gecici->next;
            } else {
                // Eğer baş eleman siliniyorsa, head'i güncelle
                head = gecici->next;
            }
            
            // Sonraki düğümün prev'ini güncelle
            if (gecici->next != NULL) {
                gecici->next->prev = gecici->prev;
            }
            
            // Silinecek düğümü geçici olarak sakla
            struct Node* silinecek = gecici;
            gecici = gecici->next;
            
            // Hafızayı boşalt
            free(silinecek);
        } else {
            // Bu elemanı görülen elemanlar listesine ekle
            gorulenElemanlar.insert(gecici->data);
            gecici = gecici->next;
        }
    }
    
    cout << "Tekrarlayan elemanlar silme işlemi tamamlandı!" << endl;
}

// Bağlı listeyi ekrana yazdırma fonksiyonu
void listeyiYazdir(struct Node* dugum) {
    if (dugum == NULL) {
        cout << "Liste boş!" << endl;
        return;
    }
    
    cout << "Çift Yönlü Bağlı Liste: ";
    while (dugum != NULL) {
        cout << dugum->data;
        if (dugum->next != NULL) {
            cout << " <-> ";
        }
        dugum = dugum->next;
    }
    cout << endl;
}

// Bağlı listeyi ters yönde yazdırma fonksiyonu (test için)
void listeyiTersYazdir(struct Node* dugum) {
    if (dugum == NULL) {
        cout << "Liste boş!" << endl;
        return;
    }
    
    // Önce listenin sonuna git
    while (dugum->next != NULL) {
        dugum = dugum->next;
    }
    
    cout << "Ters Yönde Liste: ";
    while (dugum != NULL) {
        cout << dugum->data;
        if (dugum->prev != NULL) {
            cout << " <-> ";
        }
        dugum = dugum->prev;
    }
    cout << endl;
}

// Ana fonksiyon
int main() {
    struct Node* head = NULL;
    
    cout << "=== ÇİFT YÖNLÜ BAĞLI LİSTEDE TEKRARLAYAN ELEMAN SİLME DEMOSU ===" << endl << endl;
    
    // Test listesi oluşturma (verilen örnek)
    cout << "1. Test listesi oluşturuluyor..." << endl;
    cout << "   Verilen örnek: { 1, 2, 4, 5, 2, 3, 5, 6, 1, 4, 5, 6, 6, 7, 4, 5 }" << endl;
    
    // Elemanları başa ekleyerek listeyi oluştur (ters sırada eklenir)
    basaEkle(&head, 5);  // Son eleman
    basaEkle(&head, 4);
    basaEkle(&head, 7);
    basaEkle(&head, 6);
    basaEkle(&head, 6);
    basaEkle(&head, 5);
    basaEkle(&head, 4);
    basaEkle(&head, 1);
    basaEkle(&head, 6);
    basaEkle(&head, 5);
    basaEkle(&head, 3);
    basaEkle(&head, 2);
    basaEkle(&head, 5);
    basaEkle(&head, 4);
    basaEkle(&head, 2);
    basaEkle(&head, 1);  // İlk eleman
    
    cout << "Oluşturulan liste:" << endl;
    listeyiYazdir(head);
    
    // Ters yönde de test et
    cout << "\nTers yönde liste kontrolü:" << endl;
    listeyiTersYazdir(head);
    
    // Tekrarlayan elemanları silme
    cout << "\n2. TEKRARLAYAN ELEMANLAR SİLİNİYOR..." << endl;
    tekrarlayanSil(head);
    
    cout << "\n3. TEMİZLENMİŞ LİSTE:" << endl;
    listeyiYazdir(head);
    
    // Ters yönde de kontrol et
    cout << "\nTers yönde temizlenmiş liste:" << endl;
    listeyiTersYazdir(head);
    
    // Beklenen sonuç kontrolü
    cout << "\n4. BEKLENEN SONUÇ KONTROLÜ:" << endl;
    cout << "   Beklenen: 1 <-> 2 <-> 4 <-> 5 <-> 3 <-> 6 <-> 7" << endl;
    cout << "   Gerçek: ";
    listeyiYazdir(head);
    
    // Çalışma zamanı analizi
    cout << "\n5. ÇALIŞMA ZAMANI ANALİZİ:" << endl;
    cout << "   - Zaman Karmaşıklığı: O(n)" << endl;
    cout << "   - Uzay Karmaşıklığı: O(n)" << endl;
    cout << "   - Açıklama: Her eleman bir kez taranır ve hash set ile tekrar kontrol edilir" << endl;
    
    cout << "\n=== PROGRAM TAMAMLANDI ===" << endl;
    return 0;
}
