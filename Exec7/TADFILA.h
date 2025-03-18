#define MAXFILA 1000

struct TpElemento
{
	char idVeic[16], corVeic[15], fabVeic[20], prior;
};

struct TpFilaP
{
	int FIM;
	TpElemento FILA[MAXFILA];
};

void Inicializar(TpFilaP &FP);

void LerArqInserir(TpFilaP &FP, TpElemento Elem);
TpElemento Retirar(TpFilaP &FP);
int Cheia(int TOPO);
int Vazia(int TOPO);
void Exibir(TpFilaP FP);

void Inicializar(TpFilaP &FP)
{
	FP.FIM = -1;
}

void LerArqInserir(TpFilaP &FP, TpElemento reg)
{
	    	
	FP.FILA[++FP.FIM] = reg;
	int i = FP.FIM;
	
	while(i > 0 && FP.FILA[i-1].prior > FP.FILA[i].prior)
	{
		FP.FILA[i] = FP.FILA[i - 1];
		FP.FILA[i - 1] = reg;
		i--;
	}
}

TpElemento Retirar(TpFilaP &FP)
{
	TpElemento elem = FP.FILA[0];  

    for (int i = 0; i < FP.FIM; i++) {
        FP.FILA[i] = FP.FILA[i + 1];
    }

    FP.FIM--;  
    return elem;  
}

int Cheia(int FIM)
{
	return FIM == MAXFILA - 1;
}

int Vazia(int FIM)
{
	return FIM == -1;
}

void Exibir(TpFilaP FP)
{
	while(!Vazia(FP.FIM))
	{
		TpElemento reg = Retirar(FP);
		
		printf("\t%s\t%s\t%s\t%c\n",reg.corVeic,reg.fabVeic,reg.idVeic,reg.prior);
	}
		
}


