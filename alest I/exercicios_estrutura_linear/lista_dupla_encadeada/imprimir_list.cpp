// IMPRIMIR SENTIDO DIREITO
void imprimirlista(Node* head) {
    cout << "|";
    Node* aux = head;
    while (aux != nullptr) { cout << aux->info << "|";aux = aux->next;}
    cout << endl;
}

//IMPRIMIR SENTIDO REVERSO
void Reverse(Node* tail) {
    cout << "|";
    Node* aux = tail;
    while (aux != nullptr) { cout << aux->info << "|"; aux = aux->prev;}
    cout << endl;
}