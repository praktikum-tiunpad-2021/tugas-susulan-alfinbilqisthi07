#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  int data;
  int priority;
  Element<T>* next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> NewQue;
  NewQue.head = nullptr;
  NewQue.tail = nullptr;
  return NewQue;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> newElm = new Element<T>;
  newElm->next = nullptr;
  newElm->data = value;
  newElm->priority = priority;

  if (q.head == nullptr){
    q.head = newElm;
    q.tail = newElm;
  }
  else{
    ElementPtr<T> temp = q.head;
    ElementPtr<T> temp2 = nullptr;
    
    while (temp->priority >= newElm->priority){
      temp2 = temp;
      temp = temp->next;
      if (temp == nullptr){
        break;
      }
    }
    
    if (temp2 == nullptr){
      q.head = newElm;
      newElm->next = temp;
    }
    else if (temp == nullptr){
      q.tail = newElm;
      temp2->next = newElm;
    }
    else{
      newElm->next = temp;
      temp2->next = newElm;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> temp = q.head;
  q.head = q.head->next;
  temp->next = nullptr;
  delete temp;
}

}  // namespace priority_queue

}  // namespace strukdat
