// REMOVE NODO O INICIO DA LISTA
if (head != nullptr) {
Node* aux = head;
head = head->next;
if (head == nullptr) {tail = nullptr;
}else { head->prev = nullptr;}
delete aux;
} 