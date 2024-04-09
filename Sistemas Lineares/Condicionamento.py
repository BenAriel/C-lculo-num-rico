import numpy as np

def matriz_info(matriz):
    # Configuração para mostrar números em formato decimal
    
    # Calcula o número de condicionamento para as normas 2, inf e Frobenius
    condicao_norma_2 = np.linalg.cond(matriz, p=2)
    condicao_norma_inf = np.linalg.cond(matriz, p=np.inf)
    condicao_norma_frobenius = np.linalg.cond(matriz, p='fro')
    
    # Calcula as normas
    norma_linha = np.linalg.norm(matriz, ord=1)
    norma_coluna = np.linalg.norm(matriz, ord=np.inf)
    norma_frobenius = np.linalg.norm(matriz, ord='fro')
    
    # Calcula o determinante
    determinante = np.linalg.det(matriz)
    
    # Calcula a matriz inversa
    try:
        inversa = np.linalg.inv(matriz)
    except np.linalg.LinAlgError:
        inversa = "A matriz não é invertível."
    
    return (condicao_norma_2, condicao_norma_inf, condicao_norma_frobenius,
            norma_linha, norma_coluna, norma_frobenius,
            determinante, inversa)

# Exemplo de uso
matriz_exemplo = np.array([[1, 2, 3],
                           [4, 5, 6],
                           [7, 8, 9]])

(condicao_norma_2, condicao_norma_inf, condicao_norma_frobenius,
 norma_linha, norma_coluna, norma_frobenius,
 determinante, inversa) = matriz_info(matriz_exemplo)

print(f"Número de Condicionamento (Norma 2): {condicao_norma_2}")
print(f"Número de Condicionamento (Norma Inf): {condicao_norma_inf}")
print(f"Número de Condicionamento (Norma Frobenius): {condicao_norma_frobenius}")

print(f"Norma L1: {norma_linha}")
print(f"Norma Inf: {norma_coluna}")
print(f"Norma Frobenius: {norma_frobenius}")

print(f"Determinante: {determinante}")
print(f"Inversa:\n{inversa}")
