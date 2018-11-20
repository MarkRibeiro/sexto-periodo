int maior(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int getBalance(Tree *a) 
{ 
    if (a == NULL) 
        return 0; 

    return altura(a->e) - altura(a->d); 
} 

int altura(Tree *a) 
{ 
    if (a == NULL) 
        return 0; 
    
    return a->fb; 
}

Tree* giraEsq(Tree *x) 
{ 
    Tree *y = x->d; 
    Tree *T2 = y->e; 
  
    y->e = x; 
    x->d = T2; 
  
    x->fb = maior(altura(x->e), altura(x->d))+1; 
    y->fb = maior(altura(y->e), altura(y->d))+1; 
   
    return y; 
} 

Tree* giraDir(Tree *y) 
{ 
    Tree *x = y->e; 
    Tree *T2 = x->d; 
  
    x->d = y; 
    y->e = T2; 
  
    y->fb = maior(altura(y->e), altura(y->d))+1; 
    x->fb = maior(altura(x->e), altura(x->d))+1; 
  
    return x; 
}

Tree* insereArv(Tree* a, int chave) 
{ 
    if (a == NULL) 
        return(criaArv(chave)); 
  
    if (chave < a->chave) 
        a->e  = insereArv(a->e, chave);

    else if (chave > a->chave) 
        a->d = insereArv(a->d, chave);

    else 
        return a; 
  
    a->fb = 1 + maior(altura(a->e), altura(a->d)); 
  
    int balance = getBalance(a); 
  
    if (balance > 1 && chave < a->e->chave) 
        return giraDir(a); 
  
    if (balance < -1 && chave > a->d->chave) 
        return giraEsq(a); 
  
    if (balance > 1 && chave > a->e->chave) 
    { 
        a->e =  giraEsq(a->e); 
        return giraDir(a); 
    } 
  
    if (balance < -1 && chave < a->d->chave) 
    { 
        a->d = giraDir(a->d); 
        return giraEsq(a); 
    } 
  
    return a; 
}