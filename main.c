#include <stdio.h>
#include <string.h>

// Definição do tipo de função que será associada às rotas
// typedef void (*route_function);
typedef void (*route_function)(char* param);

// Estrutura que vincula uma URL a uma função
typedef struct {
    const char *url;
    route_function func;
} Route;

// Funções controladoras
// void home() {
void home(char* param) {
    printf("Param: %s\n", param);
    printf("Home page\n");
}

// void about() {
void about(char* param) {
    printf("Param: %s\n", param);
    printf("About page\n");
}

// void not_found() {
void not_found(char* param) {
    printf("Param: %s\n", param);
    printf("404 Not Found\n");
}

// Lista de rotas que mapeia URLs para funções
Route routes[] = {
    {"/", home},
    {"/about", about}
};

// Função de roteamento
// void route_request(const char *url) {
void route_request(const char *url, char* param) {
    int num_routes = sizeof(routes) / sizeof(Route);
    for (int i = 0; i < num_routes; i++) {
        if (strcmp(routes[i].url, url) == 0) {
            // routes[i].func();
            routes[i].func(param);
            return;
        }
    }
    not_found(param);  // Se a URL não foi encontrada
}

// Função principal
int main() {
    const char *url1 = "/";
    const char *url2 = "/about";
    const char *url3 = "/contact";

    // route_request(url1);  // Deve imprimir "Home page"
    // route_request(url2);  // Deve imprimir "About page"
    // route_request(url3);  // Deve imprimir "404 Not Found"

    route_request(url1, "HOME");  // Deve imprimir "Param: HOME" e "Home page"
    route_request(url2, "ABOUT"); // Deve imprimir "Param: ABOUT" e "About page"
    route_request(url3, "NOT FOUND");  // Deve imprimir "Param: NOT FOUND" e "404 Not Found"

    return 0;
}
