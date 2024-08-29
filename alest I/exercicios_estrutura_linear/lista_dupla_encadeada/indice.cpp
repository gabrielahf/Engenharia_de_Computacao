// INSERE A LETRA ESPECIFICADA NO INDICE ESPECIFICADO DA LISTA
Node* node = new Node(c);
if (pos == 0) {
  // Insere no início
if (head == nullptr) { head = tail = node; 
}else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}else {
// Encontra o nó na posição especificada
Node* index = head;
unsigned e = 0;
while (index != nullptr && e < pos - 1) {index = index->next;e++;}
if (index == nullptr) {cout << "ERRO" << endl;
} else {
    // Insere após o nó na posição especificada
    node->prev = index;
    node->next = index->next;
    if (index->next != nullptr) {index->next->prev = node;
    }else {tail = node;}
    index->next = node;
}
}

// REMOVE A LETRA ESPECIFICADA NO INDICE ESPECIFICADO DA LISTA
if (head == nullptr) {cout << "ERRO" << endl;
} else if (pos == 0) {
Node* aux = head; // Remove o primeiro elemento
head = head->next;
if (head == nullptr) {tail = nullptr;
} else { head->prev = nullptr;}
delete aux;
} else{
Node* index = head;  // Encontra o nó na posição especificada
unsigned e = 0;
while (index != nullptr && e < pos) { index = index->next; e++;
} if (index == nullptr) { cout << "ERRO" << endl;
} else{
index->prev->next = index->next; // Remove o nó na posição especificada
if (index->next != nullptr) { index->next->prev = index->prev;
} else{ tail = index->prev;}
delete index;
}
}