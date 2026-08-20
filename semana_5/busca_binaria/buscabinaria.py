


def forcaBruta(protocolos, protocoloProcurado):
    for indice in range(len(protocolos)):
        if(protocolos[indice] == protocoloProcurado):
            return indice
        
        return -1
    
    
def buscaBinaria(protocolos, protocoloProcurado):
    inicio = 0
    fim = len(protocolos) - 1
    
    while inicio <= fim:
        meio = (inicio + fim) // 2
        valorAtual = protocolos[meio]
        
        if valorAtual == protocoloProcurado:
            return meio
        
        if valorAtual < protocoloProcurado:
            inicio = meio + 1 # Atualiza o início para a metade direita
        else:
            fim = meio - 1 # Atualiza o fim para a metade esquerda

    return -1 # Retorna -1 se o protocolo não for encontrado


protocolos = [1001, 1008, 1012, 1019, 1024, 1030, 1038]
protocoloProcurado = 1024

print("Protocolos disponíveis:", protocolos)
print("Protocolo procurado:", protocoloProcurado)
posicao = buscaBinaria(protocolos, protocoloProcurado)
print("Posição do protocolo procurado:", posicao)