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
## 🎁 Parte Bonus: Flags y modificadores

La parte bonus de **ft_printf** amplía la funcionalidad básica añadiendo **flags de formateo** que controlan el alineamiento, relleno y precisión de la salida.  Estos modificadores permiten un control más fino sobre cómo se imprimen los datos, replicando el comportamiento de la `printf()` estándar.

### 📌 Flags de formateo disponibles

| Flag | Descripción | Aplicable a |
|------|-------------|-------------|
| `-` | Alineamiento a la izquierda | Todos los especificadores |
| `0` | Relleno con ceros (ignorado si se usa con `-`) | `d`, `i`, `u`, `x`, `X` |
| `. ` | Precisión (precision) | `s`, `d`, `i`, `u`, `x`, `X` |
| `#` | Forma alternativa (añade `0x` o `0X`) | `x`, `X` |
| ` ` | Espacio antes de números positivos | `d`, `i` |
| `+` | Signo para números positivos (prevalece sobre ` `) | `d`, `i` |

### 📏 Anchura de campo (field width)

Número mínimo de caracteres a imprimir.  Si el resultado es más corto, se añade padding (relleno). 

**Sintaxis:** `%[width][specifier]` → Ejemplo: `%10d`

---

## 🔤 Especificador `%c` - char

### ✅ Flags aplicables

- **Anchura de campo** (`%5c`)
- **Flag `-`** (alineamiento izquierda)

### ❌ Flags NO aplicables

- `0`, `. `, `#`, ` `, `+` → Ignorados o comportamiento indefinido

### 📋 Ejemplos de uso

```c
// Uso básico
ft_printf("%c\n", 'A');
// Output: A

// Anchura mayor que el tamaño del carácter (padding a la derecha por defecto)
ft_printf("%5c\n", 'A');
// Output: "    A" (4 espacios a la izquierda)

// Alineamiento a la izquierda
ft_printf("%-5c\n", 'A');
// Output: "A    " (4 espacios a la derecha)

// Combinación con delimitadores
ft_printf("[%10c]\n", 'X');
// Output: "[         X]"

ft_printf("[%-10c]\n", 'X');
// Output: "[X         ]"

// Carácter nulo (edge case importante)
ft_printf("%c\n", '\0');
// Output: (carácter vacío, pero se escribe el byte)
// Longitud retornada: 1

ft_printf("%5c\n", '\0');
// Output: "    \0" (4 espacios + null byte)
// Longitud retornada: 5
```

### 🎯 Comportamiento esperado

- **Sin flags:** Imprime el carácter tal cual
- **Con anchura:** Rellena con espacios hasta alcanzar la anchura especificada
- **Con `-`:** El padding se coloca a la **derecha** en lugar de la izquierda
- **Caracteres especiales:** `\0`, `\n`, `\t` se imprimen correctamente (aunque no sean visibles)

---

## 📝 Especificador `%s` - string

### ✅ Flags aplicables

- **Anchura de campo** (`%10s`)
- **Flag `-`** (alineamiento izquierda)
- **Precisión `. `** (`%. 5s`) → Máximo número de caracteres a imprimir

### 📋 Ejemplos de uso

```c
// Uso básico
ft_printf("%s\n", "Hola");
// Output: Hola

// Anchura de campo
ft_printf("%10s\n", "42");
// Output: "        42" (8 espacios a la izquierda)

// Alineamiento a la izquierda
ft_printf("%-10s\n", "42");
// Output: "42        " (8 espacios a la derecha)

// Precisión (limita la longitud)
ft_printf("%.3s\n", "Barcelona");
// Output: Bar (solo los primeros 3 caracteres)

// Combinación anchura + precisión
ft_printf("%10.3s\n", "Barcelona");
// Output: "       Bar" (anchura 10, pero imprime solo 3 caracteres)

ft_printf("%-10.3s\n", "Barcelona");
// Output: "Bar       " (izquierda + anchura 10, imprime 3 caracteres)

// Precisión mayor que longitud del string
ft_printf("%.20s\n", "42");
// Output: 42 (la precisión no trunca si el string es más corto)

// Puntero NULL (comportamiento estándar)
ft_printf("%s\n", NULL);
// Output: (null)

ft_printf("%10s\n", NULL);
// Output: "    (null)" (anchura aplicada a "(null)")

ft_printf("%. 3s\n", NULL);
// Output: (nu) (precisión aplicada a "(null)")

// String vacío
ft_printf("%s\n", "");
// Output: (línea vacía)

ft_printf("%10s\n", "");
// Output: "          " (10 espacios)
```

### 🎯 Comportamiento esperado

- **Sin flags:** Imprime el string completo
- **Con anchura:** Rellena con espacios si el string es más corto
- **Con precisión:** Trunca el string al número especificado de caracteres
- **Precisión 0:** Imprime string vacío (`%. 0s` → "")
- **NULL pointer:** Imprime `(null)` como la printf estándar

---

## 🔢 Especificadores `%d` y `%i` - signed int

### ✅ Flags aplicables

- **Anchura de campo** (`%5d`)
- **Flag `-`** (alineamiento izquierda)
- **Flag `0`** (relleno con ceros, ignorado si se usa `-`)
- **Precisión `.`** (`%. 5d`) → Mínimo número de dígitos (padding con ceros)
- **Flag `+`** (mostrar siempre el signo)
- **Flag ` `** (espacio antes de números positivos)

### 📋 Ejemplos de uso

```c
// Uso básico
ft_printf("%d\n", 42);
// Output: 42

ft_printf("%d\n", -42);
// Output: -42

// Anchura de campo
ft_printf("%5d\n", 42);
// Output: "   42" (3 espacios a la izquierda)

ft_printf("%5d\n", -42);
// Output: "  -42" (2 espacios, el signo cuenta en la anchura)

// Alineamiento a la izquierda
ft_printf("%-5d\n", 42);
// Output: "42   " (3 espacios a la derecha)

// Relleno con ceros
ft_printf("%05d\n", 42);
// Output: 00042

ft_printf("%05d\n", -42);
// Output: -0042 (el signo va ANTES de los ceros)

// Flag 0 es ignorado con flag -
ft_printf("%-05d\n", 42);
// Output: "42   " (equivalente a %-5d)

// Precisión
ft_printf("%.5d\n", 42);
// Output: 00042 (mínimo 5 dígitos)

ft_printf("%.5d\n", -42);
// Output: -00042 (el signo NO cuenta en la precisión)

ft_printf("%.3d\n", 12345);
// Output: 12345 (la precisión no trunca si el número es más largo)

// Combinación anchura + precisión
ft_printf("%10.5d\n", 42);
// Output: "     00042" (anchura 10, precisión 5)

ft_printf("%-10. 5d\n", 42);
// Output: "00042     " (izquierda + anchura 10, precisión 5)

// Flag + (mostrar signo siempre)
ft_printf("%+d\n", 42);
// Output: +42

ft_printf("%+d\n", -42);
// Output: -42

ft_printf("%+5d\n", 42);
// Output: "  +42"

ft_printf("%+05d\n", 42);
// Output: +0042 (signo antes de los ceros)

// Flag espacio (espacio para positivos)
ft_printf("% d\n", 42);
// Output: " 42" (espacio antes del número)

ft_printf("% d\n", -42);
// Output: -42 (el signo menos reemplaza al espacio)

ft_printf("% 5d\n", 42);
// Output: "   42" (el espacio NO afecta a la anchura adicionalmente)

// Flag + prevalece sobre flag espacio
ft_printf("%+ d\n", 42);
// Output: +42 (+ tiene prioridad)

// Casos especiales (edge cases)
ft_printf("%d\n", 0);
// Output: 0

ft_printf("%. 0d\n", 0);
// Output: (string vacío) ← IMPORTANTE

ft_printf("%5. 0d\n", 0);
// Output: "     " (5 espacios)

ft_printf("%d\n", INT_MIN);
// Output: -2147483648

ft_printf("%d\n", INT_MAX);
// Output: 2147483647
```

### 🎯 Comportamiento esperado

- **Anchura:** Padding con espacios (o ceros con flag `0`)
- **Precisión:** Número mínimo de dígitos, rellena con ceros a la izquierda
- **Precisión 0 con valor 0:** Imprime string vacío (caso especial)
- **Flag `+`:** Añade `+` a números positivos
- **Flag ` `:** Añade espacio a números positivos (ignorado si hay `+`)
- **Prioridad:** `-` > `0`, `+` > ` `, precisión > `0` para números

---

## 🔓 Especificador `%u` - unsigned int

### ✅ Flags aplicables

Los mismos que `%d` y `%i`, **EXCEPTO** `+` y ` ` (espacio) que son ignorados.

### 📋 Ejemplos de uso

```c
ft_printf("%u\n", 42);
// Output: 42

ft_printf("%u\n", -1);
// Output: 4294967295 (overflow sin signo)

ft_printf("%10u\n", 42);
// Output: "        42"

ft_printf("%-10u\n", 42);
// Output: "42        "

ft_printf("%010u\n", 42);
// Output: 0000000042

ft_printf("%. 5u\n", 42);
// Output: 00042

ft_printf("%.0u\n", 0);
// Output: (string vacío)

// Flags + y espacio son ignorados
ft_printf("%+u\n", 42);
// Output: 42 (+ ignorado)

ft_printf("% u\n", 42);
// Output: 42 (espacio ignorado)
```

### 🎯 Comportamiento esperado

Idéntico a `%d` pero **sin interpretación de signo**. Los flags `+` y ` ` (espacio) no tienen efecto. 

---

## 🔶 Especificadores `%x` y `%X` - hexadecimal

### ✅ Flags aplicables

- **Anchura de campo**
- **Flag `-`**
- **Flag `0`**
- **Precisión `.`**
- **Flag `#`** (forma alternativa: añade prefijo `0x` o `0X`)

### 📋 Ejemplos de uso

```c
ft_printf("%x\n", 255);
// Output: ff

ft_printf("%X\n", 255);
// Output: FF

// Anchura
ft_printf("%5x\n", 42);
// Output: "   2a"

// Relleno con ceros
ft_printf("%05x\n", 42);
// Output: 0002a

// Precisión
ft_printf("%.5x\n", 42);
// Output: 0002a

// Flag # (forma alternativa)
ft_printf("%#x\n", 42);
// Output: 0x2a

ft_printf("%#X\n", 42);
// Output: 0X2A

ft_printf("%#x\n", 0);
// Output: 0 (flag # ignorado para cero)

ft_printf("%#10x\n", 255);
// Output: "      0xff" (0x cuenta en la anchura)

ft_printf("%#010x\n", 255);
// Output: 0x000000ff (ceros DESPUÉS del 0x)

// Combinación anchura + precisión + #
ft_printf("%#10.5x\n", 42);
// Output: "   0x0002a" (0x + 5 dígitos, total 10 caracteres)

ft_printf("%. 0x\n", 0);
// Output: (string vacío)

ft_printf("%#. 0x\n", 0);
// Output: (string vacío, # ignorado)
```

### 🎯 Comportamiento esperado

- **`%x`:** Hexadecimal en minúsculas (`a-f`)
- **`%X`:** Hexadecimal en mayúsculas (`A-F`)
- **Flag `#`:** Añade prefijo `0x` (para `%x`) o `0X` (para `%X`)
- **Flag `#` con 0:** No añade prefijo (comportamiento estándar)
- **Precisión:** Número mínimo de dígitos hexadecimales

---

## 📍 Especificador `%p` - pointer

### ✅ Flags aplicables

- **Anchura de campo**
- **Flag `-`**

### ❌ Flags NO aplicables

- `0`, `.`, `#`, `+`, ` ` → Comportamiento no definido o ignorados

### 📋 Ejemplos de uso

```c
int x = 42;

ft_printf("%p\n", &x);
// Output: 0x7ffd5c8e4a3c (depende de la dirección de memoria)

ft_printf("%p\n", NULL);
// Output: 0x0 o (nil) (depende de la implementación del sistema)

ft_printf("%20p\n", &x);
// Output: "    0x7ffd5c8e4a3c" (padding a la izquierda)

ft_printf("%-20p\n", &x);
// Output: "0x7ffd5c8e4a3c    " (padding a la derecha)
```

### 🎯 Comportamiento esperado

- Siempre imprime con prefijo `0x`
- Formato hexadecimal en minúsculas
- NULL pointer → `0x0` o `(nil)` según sistema

---

## ⚖️ Tabla de compatibilidad de flags

| Flag / Especificador | %c | %s | %p | %d/%i | %u | %x/%X |
|----------------------|----|----|----| ------|----| ------|
| **-** (izquierda) | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| **0** (ceros) | ❌ | ❌ | ❌ | ✅ | ✅ | ✅ |
| **.** (precisión) | ❌ | ✅ | ❌ | ✅ | ✅ | ✅ |
| **#** (forma alt.) | ❌ | ❌ | ❌ | ❌ | ❌ | ✅ |
| **+** (signo) | ❌ | ❌ | ❌ | ✅ | ❌ | ❌ |
| **' '** (espacio) | ❌ | ❌ | ❌ | ✅ | ❌ | ❌ |
| **width** (anchura) | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |

---

## 🎯 Prioridad de flags en caso de conflicto

Cuando varios flags pueden entrar en conflicto, el comportamiento es el siguiente:

### 1. **`-` vs `0`**
El flag `-` (alineamiento izquierda) prevalece, `0` es ignorado.

```c
ft_printf("%-05d\n", 42);
// Output: "42   " (equivalente a %-5d)
```

### 2. **`+` vs ` ` (espacio)**
El flag `+` prevalece, el espacio es ignorado.

```c
ft_printf("%+ d\n", 42);
// Output: +42
```

### 3. **Precisión vs `0`**
Para números, la precisión determina el padding con ceros, la anchura determina el padding con espacios.

```c
ft_printf("%08.5d\n", 42);
// Output: "   00042" (precisión añade ceros, anchura añade espacios)
```

---

## 🧪 Ejemplos de testing

### Comparación con printf original

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int len1, len2;
    
    // Test con flags combinados
    len1 = printf("[%+10.5d]\n", 42);
    len2 = ft_printf("[%+10.5d]\n", 42);
    printf("Longitud: printf=%d, ft_printf=%d\n\n", len1, len2);
    
    // Test con string y precisión
    len1 = printf("[%-15.8s]\n", "Barcelona");
    len2 = ft_printf("[%-15.8s]\n", "Barcelona");
    printf("Longitud: printf=%d, ft_printf=%d\n\n", len1, len2);
    
    // Test con hexadecimal y #
    len1 = printf("[%#010x]\n", 42);
    len2 = ft_printf("[%#010x]\n", 42);
    printf("Longitud: printf=%d, ft_printf=%d\n\n", len1, len2);
    
    return (0);
}
```

### Casos edge importantes

```c
// Precisión 0 con valor 0
ft_printf("%.0d", 0);        // → "" (vacío)
ft_printf("%. 0u", 0);        // → "" (vacío)
ft_printf("%.0x", 0);        // → "" (vacío)

// Flag # con cero
ft_printf("%#x", 0);         // → "0" (sin 0x)

// NULL pointer en %s
ft_printf("%s", NULL);       // → "(null)"
ft_printf("%.3s", NULL);     // → "(nu)"

// Combinaciones complejas
ft_printf("%+010d", -42);    // → "-000000042"
ft_printf("%-+10d", 42);     // → "+42       "
ft_printf("%#-10x", 255);    // → "0xff      "
```

---

## 📚 Diferencias con printf estándar

### Funcionalidad NO implementada en ft_printf

- **Buffering:** `ft_printf` escribe directamente con `write()`, sin buffer interno
- **Flags adicionales:** `*` (anchura/precisión variable), `l`, `ll`, `h`, `hh` (modificadores de tamaño)
- **Especificadores float:** `%f`, `%e`, `%g` no están implementados
- **Especificador `%n`:** No soportado

### Comportamiento idéntico a printf

- Manejo de flags básicos (`-`, `0`, `.`, `#`, `+`, ` `)
- Prioridad de flags
- Casos edge (precisión 0 con valor 0, NULL strings, etc.)
- Valor de retorno (número total de caracteres impresos)

---

## 💡 Tips de implementación

### Parsing de flags

```c
typedef struct s_flags
{
    int minus;      // Flag '-'
    int zero;       // Flag '0'
    int width;      // Anchura de campo
    int precision;  // Precisión
    int hash;       // Flag '#'
    int plus;       // Flag '+'
    int space;      // Flag ' '
}   t_flags;
```

### Orden de procesamiento

1. **Parsear flags** (`-`, `0`, `#`, `+`, ` `)
2. **Parsear anchura** (dígitos hasta que llegue `. ` o especificador)
3. **Parsear precisión** (después de `.`)
4. **Identificar especificador** (`c`, `s`, `d`, `i`, `u`, `x`, `X`, `p`)
5. **Aplicar flags según prioridad**
6. **Generar output** con padding apropiado


<div align="center">


</div>
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

**Valeriy Darsuyev a.k.a. vdarsuye**  
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

