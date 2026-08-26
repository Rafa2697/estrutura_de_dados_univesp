typedef int TipoItem;
const int max_itens = 100;

class pilha{
    private:
        int tamanho;
        TipoItem* estrutura;
    
    public:
        pilha();
        ~pilha();
        bool estacheia();
        bool estavazia();
        void inserir(TipoItem item)
}