/*
Cria arvore
	Recebe:
		Uma chave que sera inserida na arvore
	Retorna:
		Um ponteiro para a arvore criada
	Passo a passo:
		-Criar um ponteiro do tipo da arvore
		-Malocar o ponteiro para o tamanho da arvore
		-Iniciar a chave como o valor recebido
		-Iniciar o ramo esquerdo como NULL
		-Iniciar o ramo direito como NULL
		-Retornar o ponteiro
*/
//Codigo de Cria arvore:
Tree* criaArv(int n)
{
	Tree* nova = (Tree*)malloc(sizeof(Tree));
	if(nova==NULL)
	{
		printf("Sem memoria\n");
		exit(1);
	}

	nova->chave=n;
	nova->e=NULL;
	nova->d=NULL;

	return nova;
}
/*
Insere na arvore
	Recebe:
		Uma chave que sera inserida na arvore
		A arvore que se deseja adicionar a chave
	Retorna:
		A arvore com a nova chave inserida
	Passo a passo:
		-Caso a arvore esteja sem nenhum elemento ainda a funçao criaArv sera chamada,
		ela por sua vez ira adicionar a chave na raiz da arvore e devolve-la a funçao
		insereArv. A funçao iguala o valor de retorno a arvore que foi passada como parametro
		e a retorna.
		-Caso a chave recebida como parametro seja menor que a chave atual da arvore 
		a funçao iguala o ramo esquerdo da arvore a funçao insereArv, porem dessa vez com 
		o ramo esquerdo como parametro.
		-Caso contrario a funçao iguala o ramo direito da arvore a funçao insereArv, 
		porem dessa vez com o ramo direito como parametro.
		-Retorna a arvore
*/
//Codigo de Insere na Arvore:
Tree* insereArv(Tree *a, int n)
{
	if(a==NULL)
	{
		a=criaArv(n);
		return a;
	}
	if(a->chave>n)
		a->e=insereArv(a->e, n);

	else
		a->d=insereArv(a->d, n);

	return a;
}
*******************************************************************************
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int getBalance(Tree *a) 
{ 
    if (a == NULL) 
        return 0; 
    return height(a->e) - height(a->d); 
} 

int height(Tree *a) 
{ 
    if (a == NULL) 
        return 0; 
    return a->fb; 
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
  
    a->fb = 1 + max(height(a->e), height(a->d)); 
  
    int balance = getBalance(a); 
  
    if (balance > 1 && chave < a->e->chave) 
        return rightRotate(a); 
  
    if (balance < -1 && chave > a->d->chave) 
        return leftRotate(a); 
  
    if (balance > 1 && chave > a->e->chave) 
    { 
        a->e =  leftRotate(a->e); 
        return rightRotate(a); 
    } 
  
    if (balance < -1 && chave < a->d->chave) 
    { 
        a->d = rightRotate(a->d); 
        return leftRotate(a); 
    } 
  
    return a; 
}

Tree* leftRotate(Tree *x) 
{ 
    Tree *y = x->d; 
    Tree *T2 = y->e; 
  
    y->e = x; 
    x->d = T2; 
  
    x->fb = max(height(x->e), height(x->d))+1; 
    y->fb = max(height(y->e), height(y->d))+1; 
   
    return y; 
} 

Tree* rightRotate(Tree *y) 
{ 
    Tree *x = y->e; 
    Tree *T2 = x->d; 
  
    x->d = y; 
    y->e = T2; 
  
    y->fb = max(height(y->e), height(y->d))+1; 
    x->fb = max(height(x->e), height(x->d))+1; 
  
    return x; 
}