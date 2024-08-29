// REMOVE NODO NO FINAL DA LISTA
if (tail != nullptr) {
Node* aux = tail;
tail = tail->prev;
if (tail == nullptr) { head = nullptr;
}else {tail->next = nullptr;}
delete aux;
}