#include <stdio.h>
#include <math.h>

// Função para calcular a distância do ponto ao plano
float distanciaPontoPlano(float x0, float y0, float z0, float A, float B, float C, float D) {
    float numerador = fabsf(A * x0 + B * y0 + C * z0 + D);
    float denominador = sqrtf(A * A + B * B + C * C);
    return numerador / denominador;
}

// Função para encontrar o maior quadrado perfeito que divide um número
int maiorQuadradoPerfeito(int n) {
    for (int i = (int)sqrtf(n); i > 1; i--) {
        if (n % (i * i) == 0) {
            return i * i;
        }
    }
    return 1;
}

// Função para simplificar a raiz quadrada
void simplificarRaiz(float valor) {
    int inteiro = (int)roundf(valor * valor);
    int coeficiente = 1;
    for (int i = 2; i * i <= inteiro; i++) {
        while (inteiro % (i * i) == 0) {
            coeficiente *= i;
            inteiro /= i * i;
        }
    }
    if (coeficiente == 1) {
        printf("√%d\n", inteiro);
    } else if (inteiro == 1) {
        printf("%d\n", coeficiente);
    } else {
        printf("%d√%d\n", coeficiente, inteiro);
    }
}

// Função para simplificar uma fração
void simplificarFracao(float numerador, float denominador) {
    int num = (int)roundf(numerador);
    int den = (int)roundf(denominador);
    int gcd = 1;
    for (int i = 2; i <= num && i <= den; ++i) {
        if (num % i == 0 && den % i == 0) {
            gcd = i;
        }
    }
    num /= gcd;
    den /= gcd;
    printf("%d/%d\n", num, den);
}

int main() {
    float x0, y0, z0;
    float A, B, C, D;
    
    printf("Digite as coordenadas do ponto P (X, Y, Z): \n");
    printf("Informe X: ");
    scanf("%f", &x0);
    printf("Informe Y: ");
    scanf("%f", &y0);
    printf("Informe Z: ");
    scanf("%f", &z0);
    
    printf("Digite os coeficientes do plano (A, B, C, D) da equação Ax + By + Cz + D = 0: \n");
    printf("Informe o A: ");
    scanf("%f", &A);
    printf("Informe o B: ");
    scanf("%f", &B);
    printf("Informe o C: ");
    scanf("%f", &C);
    printf("Informe o D: ");
    scanf("%f", &D);
    
    float distancia = distanciaPontoPlano(x0, y0, z0, A, B, C, D);
    
    printf("A distância do ponto P ao plano é: %.2f\n", distancia);
    printf("A distância como raiz é: ");
    simplificarRaiz(distancia);
    printf("A distância como fração é: ");
    simplificarFracao(distancia * 3, 3);
    
    return 0;
}
