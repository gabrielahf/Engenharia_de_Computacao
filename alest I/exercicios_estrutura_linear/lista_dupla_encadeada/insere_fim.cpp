// INSERE LETRA ESPECIFICADA NO FIM DA LISTA
Node* node = new Node(c);
    if (head == nullptr) { head = tail = node;
    }else {
            node->prev = tail;
            tail->next = node;
            tail = node;
}