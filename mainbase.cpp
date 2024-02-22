#include <stdio.h>
#include <glew.h>
#include <glfw3.h>
#include <cstdlib> // Para la función rand() Random

// Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;

// Función para generar un color RGB aleatorio
void generarColorAleatorio(float& r, float& g, float& b) {
    r = static_cast<float>(rand()) / RAND_MAX;
    g = static_cast<float>(rand()) / RAND_MAX;
    b = static_cast<float>(rand()) / RAND_MAX;
}

int main() {
    // Inicialización de GLFW
    if (!glfwInit()) {
        printf("Falló inicializar GLFW");
        glfwTerminate();
        return 1;
    }

    // Asignando variables de GLFW y propiedades de ventana
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // CREAR VENTANA
    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Primer ventana", NULL, NULL);

    if (!mainWindow) {
        printf("Fallo en crearse la ventana con GLFW");
        glfwTerminate();
        return 1;
    }

    // Obtener tamaño de Buffer
    int BufferWidth, BufferHeight;
    glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

    // Asignar el contexto
    glfwMakeContextCurrent(mainWindow);

    // Permitir nuevas extensiones
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        printf("Falló inicialización de GLEW");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // Asignar valores de la ventana y coordenadas
    // Asignar Viewport
    glViewport(0, 0, BufferWidth, BufferHeight);
    printf("Version de Opengl: %s \n", glGetString(GL_VERSION));
    printf("Marca: %s \n", glGetString(GL_VENDOR));
    printf("Renderer: %s \n", glGetString(GL_RENDERER));
    printf("Shaders: %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    // Bucle principal
    while (!glfwWindowShouldClose(mainWindow)) {
        // Recibir eventos del usuario
        glfwPollEvents();

        // Obtener el tiempo transcurrido desde el inicio del programa
        double tiempoActual = glfwGetTime();

        // Calcular color RGB aleatorio
        float r, g, b;
        generarColorAleatorio(r, g, b);

        // Establecer el color de fondo
        glClearColor(r, g, b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Intercambiar los buffers
        glfwSwapBuffers(mainWindow);

        // Esperar 2 segundos antes de cambiar de nuevo el color
        while (glfwGetTime() - tiempoActual < 2.0) {
            glfwPollEvents();
        }
    }

    glfwDestroyWindow(mainWindow);
    glfwTerminate();

    return 0;
}
