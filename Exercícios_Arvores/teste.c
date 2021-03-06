void insere_preordem(No *raiz, char info){
  if (raiz !=NULL){
    if (info > raiz->info){
      if (raiz->esq == NULL){
        raiz->esq = nova_raiz(info);
      }
      else if (raiz->esq != NULL && raiz->dir == NULL){
        if (info > raiz->esq->info){
          raiz->dir = nova_raiz(info);
        }
        else if (info < raiz->esq->info){
          int aux = raiz->esq->info;
          raiz->esq->info = info;
          raiz->dir = nova_raiz(aux);
        }
      }
      else if (raiz->esq != NULL && raiz->dir != NULL){
        if (info < raiz->esq->info){
          int aux2 = raiz->esq->info;
          raiz->esq->info = info;
          insere_preordem(raiz->esq, aux2);
        }
        else if (info > raiz->dir->info){
          insere_preordem(raiz->dir, info);
        }
        else if (info > raiz->esq->info && info < raiz->dir->info){
          int distance_to_esq = (unsigned) (info - raiz->esq->info);
          int distance_to_dir = (unsigned) (info - raiz->dir->info);
          if (distance_to_esq <= distance_to_dir){
            insere_preordem(raiz->esq, info);
          }
          else if (distance_to_esq > distance_to_dir){
            int aux3 = raiz->dir->info;
            raiz->dir->info = info;
            insere_preordem(raiz->dir, aux3);
          }
        }
      }
    }
    else if (info < raiz->info){
      int aux4 = raiz->info;
      raiz->info = info;
      insere_preordem(raiz, aux4);
    }
  }
}





void insere_inorder(No *raiz, char info) {
  if (raiz != NULL) {
    if (info > raiz->info) {
      if (raiz->dir != NULL) {
        insere_inorder(raiz->dir, info);
      } else {
        raiz->dir = nova_raiz(info);
      }
    } else {
      if (raiz->esq != NULL) {
        insere_inorder(raiz->esq, info);
      } else {
        raiz->esq = nova_raiz(info);
      }
    }
  }
}





void insere_posordem(No *raiz, char info){
  if (raiz != NULL) {
    if (info <= raiz->info) {
      if (raiz->esq == NULL) {
        raiz->esq = nova_raiz(info);
      }
      else if (raiz->esq != NULL && raiz->dir == NULL) {
        if (info > raiz->esq->info){
          raiz->dir = nova_raiz(info);
        }
        else {
          int aux = raiz->esq->info;
          raiz->esq->info = info;
          raiz->dir = nova_raiz(aux);
        }

      }
      else if (raiz->esq != NULL && raiz->dir != NULL) {
        if (info > raiz->dir->info) {
          int aux2 = raiz->dir->info;
          raiz->dir->info = info;
          insere_posordem(raiz->dir, aux2);
        } else if (info < raiz->esq->info){
          insere_posordem(raiz->esq, info);
        } else if (info > raiz->esq->info && info < raiz->dir->info){
          insere_posordem(raiz->dir, info);
        }
      }
    } else if (info > raiz->info) {
      int aux = raiz->info;
      raiz->info = info;
      insere_posordem(raiz, aux);
    }
  }
}