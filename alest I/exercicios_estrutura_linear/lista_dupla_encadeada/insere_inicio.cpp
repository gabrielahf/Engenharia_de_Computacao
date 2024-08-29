// INSERE LETRA ESPECIFICADA NO INICIO DA LISTA
Node* node = new Node(c);
    if (head == nullptr) { head = tail = node;
    }else {
            node->next = head;
            head->prev = node;
            head = node;
 }