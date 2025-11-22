<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=venom&height=250&color=0:83a4d4,100:b6fbff&text=ft_printf&fontSize=70&fontColor=ffffff&stroke=000000&strokeWidth=2" />
</p>

<div align="center">

![42 School Project](https://img.shields.io/badge/Project-00babc?style=flat-square&logo=42)
![Language](https://img.shields.io/badge/language-C-blue?style=flat-square)
![Norminette](https://img.shields.io/badge/norminette-passing-success?style=flat-square)
![Score](https://img.shields.io/badge/score-100%2F100-success?style=flat-square)

**Reimplementación de la función printf() de la librería estándar de C**

[Descripción](#descripción) • [Instalación](#instalación) • [Uso](#uso) • [Conversiones](#conversiones) • [Implementación](#implementación)

</div>

---

## 📋 Descripción

**ft_printf** es un proyecto de la escuela 42 que consiste en recrear la función `printf()` de la biblioteca estándar de C. Este proyecto profundiza en el conocimiento de funciones variádicas, gestión de tipos de datos y escritura en buffers.

### 🎯 Objetivos del proyecto

- Entender el funcionamiento de funciones variádicas (`va_list`, `va_start`, `va_arg`, `va_end`)
- Implementar múltiples conversiones de formato
- Manejar diferentes tipos de datos (char, string, int, unsigned, hex, pointer)
- Crear una biblioteca estática compilable con `ar`
- Cumplir con la normativa Norminette de 42

---

## ⚙️ Instalación

### Requisitos previos
- GCC compiler
- Make

### Compilación

```bash
# Clonar el repositorio
git clone https://github.com/Knowledge82/ft_printf.git
cd ft_printf

# Compilar la biblioteca
make

# Limpiar archivos objeto
make clean

# Limpiar todo (incluido libftprintf.a)
make fclean

# Recompilar desde cero
make re
```

Esto generará la biblioteca estática **libftprintf.a** en el directorio raíz.

---

## 🚀 Uso

### Incluir en tu proyecto

1. Incluye el header:
```c
#include "ft_printf.h"
```

2. Compila tu programa con la biblioteca:
```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o programa
```

### Ejemplo básico

```c
#include "ft_printf.h"

int main(void)
{
    int len;
    
    len = ft_printf("Hola %s, tienes %d años\n", "Valera", 42);
    ft_printf("Caracteres impresos: %d\n", len);
    
    ft_printf("Hexadecimal: %x\n", 255);        // ff
    ft_printf("Hexadecimal: %X\n", 255);        // FF
    ft_printf("Puntero: %p\n", &len);           // 0x7ffd5c8e4a3c
    ft_printf("Sin signo: %u\n", -1);           // 4294967295
    ft_printf("Porcentaje: %%\n");              // %
    
    return (0);
}
```

---

## 🔧 Conversiones soportadas

| Especificador | Descripción | Tipo | Ejemplo |
|---------------|-------------|------|---------|
| `%c` | Carácter individual | `char` | `ft_printf("%c", 'A')` → A |
| `%s` | String (terminado en null) | `char *` | `ft_printf("%s", "42")` → 42 |
| `%p` | Puntero en hexadecimal | `void *` | `ft_printf("%p", ptr)` → 0x7ffd... |
| `%d` | Entero decimal con signo | `int` | `ft_printf("%d", -42)` → -42 |
| `%i` | Entero en base 10 (igual que %d) | `int` | `ft_printf("%i", 42)` → 42 |
| `%u` | Entero decimal sin signo | `unsigned int` | `ft_printf("%u", -1)` → 4294967295 |
| `%x` | Hexadecimal minúsculas | `unsigned int` | `ft_printf("%x", 255)` → ff |
| `%X` | Hexadecimal mayúsculas | `unsigned int` | `ft_printf("%X", 255)` → FF |
| `%%` | Símbolo de porcentaje literal | - | `ft_printf("%%")` → % |

---

## 🏗️ Implementación

### Estructura del proyecto

```
ft_printf/
├── ft_printf.c          # Función principal y dispatcher
├── ft_printf.h          # Header con prototipos
├── print_char.c         # Impresión de caracteres (%c)
├── print_str.c          # Impresión de strings (%s)
├── print_int.c          # Impresión de enteros (%d, %i)
├── print_unsigned.c     # Impresión sin signo (%u)
├── print_hexa.c         # Impresión hexadecimal (%x, %X)
├── print_pointer.c      # Impresión de punteros (%p)
├── Makefile             # Compilación automática
└── README.md            # Este archivo
```

### Arquitectura

```
ft_printf()
    ↓
    ├─→ Parseo del formato string
    ├─→ Detección de '%'
    ├─→ ft_check() ─────┬─→ %c: print_char()
    │                   ├─→ %s: print_str()
    │                   ├─→ %p: print_pointer()
    │                   ├─→ %d/%i: print_int()
    │                   ├─→ %u: print_unsigned()
    │                   ├─→ %x/%X: print_hexa()
    │                   └─→ %%: print_char('%')
    └─→ Retorna longitud total
```

### Funciones variádicas utilizadas

```c
va_list params;              // Declaración de la lista de argumentos
va_start(params, str);       // Inicialización (str = último parámetro fijo)
va_arg(params, tipo);        // Extracción del siguiente argumento del tipo especificado
va_end(params);              // Limpieza y finalización
```

**Flujo de ejecución:**

1. `va_start` inicializa el puntero a los argumentos variádicos
2. Para cada `%` en el string:
   - `va_arg` extrae el argumento del tipo correspondiente
   - Se llama a la función de impresión específica
3. `va_end` limpia la lista de argumentos
4. Se retorna el número total de caracteres impresos

---

## 📊 Testing

### Comparación con printf original

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int len1, len2;
    
    len1 = printf("Original: %d %s %p\n", 42, "test", &len1);
    len2 = ft_printf("Custom:   %d %s %p\n", 42, "test", &len2);
    
    printf("Longitudes: %d vs %d\n", len1, len2);
    
    return (0);
}
```

### Casos edge

```c
ft_printf("%");           // % al final del string
ft_printf("%%");          // Doble porcentaje
ft_printf("%s", NULL);    // String NULL (comportamiento undefined)
ft_printf("%p", NULL);    // Puntero NULL → 0x0
ft_printf("%d", INT_MIN); // -2147483648
ft_printf("%u", -1);      // 4294967295
```

---

## 🧠 Conceptos clave aprendidos

### 1. **Funciones variádicas**
- Cómo C maneja argumentos de cantidad variable
- Paso de argumentos por stack
- Type safety manual (el programador debe conocer los tipos)

### 2. **Gestión de tipos**
- Conversión entre tipos (int → unsigned, int → hex)
- Representación de números en diferentes bases
- Manejo de punteros y direcciones de memoria

### 3. **Manipulación de strings**
- Parsing de format strings
- Concatenación y construcción de output
- Escritura eficiente con `write()`

### 4. **Recursión**
- Impresión de números mediante recursión
- Conversión de bases numéricas recursivamente

---

## 📚 Recursos útiles

- [Manual de stdarg.h](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [Printf format specification](https://cplusplus.com/reference/cstdio/printf/)
- [42 Docs - ft_printf](https://harm-smits.github.io/42docs/projects/ft_printf)

---

## 👨‍💻 Autor

**Valeriy Darsuyev**  
42 Barcelona | Campus 42  
GitHub: [@Knowledge82](https://github.com/Knowledge82)

---

## 📝 Licencia

Este proyecto es parte del currículo de 42 School y está destinado solo para fines educativos.

---

<div align="center">

**⭐ Si te ha sido útil este proyecto, dale una estrella! ⭐**

Made with ❤️ and lots of ☕ at 42 Barcelona

</div>

