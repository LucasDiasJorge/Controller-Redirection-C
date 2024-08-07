#include <stdio.h>
#include <string.h>

// Definição do tipo de função que será associada às rotas
typedef void (*route_function);

// Estrutura que vincula uma URL a uma função
typedef struct {
    const char *url;
    route_function func;
} Route;

// Funções controladoras
void home() {
    printf("Home page\n");
}

void about() {
    printf("About page\n");
}

void not_found() {
    printf("404 Not Found\n");
}

// Lista de rotas que mapeia URLs para funções
Route routes[] = {
    {"/", home},
    {"/about", about}
};

// Função de roteamento
void route_request(const char *url) {
    int num_routes = sizeof(routes) / sizeof(Route);
    for (int i = 0; i < num_routes; i++) {
        if (strcmp(routes[i].url, url) == 0) {
            routes[i].func();
            return;
        }
    }
    not_found();  // Se a URL não foi encontrada
}

// Função principal
int main() {
    const char *url1 = "/";
    const char *url2 = "/about";
    const char *url3 = "/contact";

    route_request(url1);  // Deve imprimir "Home page"
    route_request(url2);  // Deve imprimir "About page"
    route_request(url3);  // Deve imprimir "404 Not Found"

    return 0;
}
